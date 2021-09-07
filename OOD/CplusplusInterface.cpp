#include <iostream>
#include <string>
#include <vector>
using namespace std;

class shape
{
private:
   string name;
public:
   virtual double getArea()=0;
   void print()
   {
     cout<<"the area is:"<<getArea()<<endl;
   }
};

class circle:public shape
{
 private:
   int mRadius;
 public:
   circle(int radius)
   {
     this->mRadius = radius;
   }
   double getArea()
   {
     return 3.14*mRadius*mRadius;
   };
};

class rectangle:public shape
{
  private:
    int width;
    int height;
 public:
   rectangle(int w,int h)
   {
     this->width = w;
     this->height = h;
   };
   double getArea()
   {
     return width*height;
   };
};


int main()
{
 vector<shape*> shapelist;
 shape* rec = new rectangle(3,5);
 shape* round = new circle(4);
 shapelist.push_back(rec);
 shapelist.push_back(round);
 for(auto item:shapelist)
 {
   item->print();
 }
 return 0;

}
