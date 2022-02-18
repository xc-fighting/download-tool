#include <iostream>
#include <vector>

using namespace std;

enum Color {
	BLACK,
	WHITE
};

enum Direction {
	TOPLEFT,
	TOPRIGHT,
	BOTTOMLEFT,
	BOTTOMRIGHT
};

struct Player {

	Color color;
	int score;

	Player(Color c, int s) {
		this->color = c;
		this->score = s;
	} 
};

struct Piece {

  Piece(Color color) {

     this->pieceColor = color;
  }

  Color pieceColor;

};

struct Coordinate {

   Coordinate(int x, int y) {
       this->x = x;
       this->y = y;
   }

   Coordinate(const Coordinate& other) {

   	  this->x = other.x;
   	  this->y = other.y;
   }

   Coordinate getTopLeft() {
   	  return Coordinate(x-1, y-1);
   }

   Coordinate getTopRight() {
   	  return Coordinate(x-1, y+1);
   }

   Coordinate getBottomLeft() {
   	  return Coordinate(x+1, y-1);

   }

   Coordinate getBottomRight() {
   	  return Coordinate(x+1, y+1);
   }

   bool isValid() {
   	 if(x >= 0 && x <= 7 && y >= 0 && y <= 7) {
   	 	 return true;
   	 }

   	 return false;
   }

   int x;
   int y;

};



struct Cell {

  Cell(const Coordinate& pos): coord(pos) {

       this->topPiece = nullptr;
      
  }
  
  
  Piece* topPiece;
  Coordinate coord;

};

struct Move {

  Move(const Coordinate& s, const Coordinate& d): src(s), dst(d) {

  }

  Coordinate src;
  Coordinate dst;

};

class Board {

private:

	vector<vector<Cell*>> cells;
	vector<Piece*> removedPieces;

public:

	Board() {
       
       this->cells = vector<vector<Cell*>>(8, vector<Cell*>(8, nullptr));
       this->removedPieces = vector<Piece*>();
	}

	void init() {
       
       for(int row = 0; row < 8; row++) {

       	   for(int col = 0; col < 8; col++) {

       	   	    cells[row][col] = new Cell(Coordinate(row, col));

       	   }
       }
	}

	void setPieces(int startRow, int endRow, Color c) {
		for(int r = startRow; r <= endRow; r++) {
            
            int pieceCol = 0;
			if(r % 2 == 0) {
                pieceCol = 1;
			}

			while(pieceCol < 8) {

                cells[r][pieceCol] = new Cell(Coordinate(r, pieceCol));
                cells[r][pieceCol]->topPiece = new Piece(c);
				pieceCol += 2;
			}
		}
	}


	void displayBoard() {
		for(int row = 0; row < 8; row++) {

			for(int col = 0; col < 8; col++) {
                
                Cell* curCell = cells[row][col];
                if(curCell->topPiece == nullptr) {
                	cout<<"O ";
                }
                else if(curCell->topPiece->pieceColor == Color::WHITE) {
                	cout<<"W ";
                }
                else {
                	cout<<"B ";
                }
			}

			cout<<endl;
		}
	}

	
    
   

    void move(Move& mov) {
    	Coordinate src = mov.src;
    	Coordinate dst = mov.dst;
    	this->removedPieces.push_back(cells[dst.x][dst.y]->topPiece);
        cells[dst.x][dst.y]->topPiece = cells[src.x][src.y]->topPiece;
        cells[src.x][src.y]->topPiece = nullptr;

    }

	vector<Move> movePiece(const Coordinate& pos) {
		 vector<Move> ans;

		 if(cells[pos.x][pos.y]->topPiece == nullptr) {
		 	 return ans;
		 }

		 Piece* piece = cells[pos.x][pos.y]->topPiece;
         if(piece->pieceColor == Color::WHITE) {
              getNextMove(ans, pos, pos.getBottomLeft());
              getNextMove(ans, pos, pos.getBottomRight());
         }
         else {
              getNextMove(ans, pos, pos.getTopLeft());
              getNextMove(ans, pos, pos.getTopRight());
         }

         return ans;

	}

	void getNextMove(vector<Move>& curMoves, const Coordinate& src, const Coordinate& dst) {

         if(dst.isValid() == false) {
         	 return curMoves;
         }
         
         Color src_color = cells[src.x][src.y]->topPiece->pieceColor;
         Color dst_color = cells[dst.x][dst.y]->topPiece->pieceColor;

         if(src_color == dst_color) {
         	return curMoves;
         }

         //not the save color
         Coordinate dst_next 
         
	}

};

class Game {

private:
  
  Board* board;

  int curPlayer;

  vector<Player*> players;

public:

  Game() {

    board = new Board();
    
    players = vector<Player*>(2, nullptr);
    players[0] = new Player(Color::WHITE, 0);
    players[1] = new Player(Color::BLACK, 1);

    this->curPlayer = 0;

  }

  void start() {
     
     board->init();
     board->setPieces(0, 2, Color::BLACK);
     board->setPieces(5, 7, Color::WHITE);
     board->displayBoard();

  }

  void changePlayer() {

  	 if(curPlayer == 0) {

  	 	curPlayer = 1;
  	 }
  	 else {

  	 	curPlayer = 0;
  	 }

  }
};


int main() {

	Game* game = new Game();
	game->start();
	return 0;
}