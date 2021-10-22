#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> array) {
  // Write your code here.
	//[0,unsortedIndex) 
  int unsortedIndex = 0;
	while( unsortedIndex < array.size() ) {
		 int index = unsortedIndex;
		 int minIndex = unsortedIndex;
		 while( index < array.size() ) {
			  if( array[index] < array[minIndex] ) {
					  minIndex = index;
				}
			  index++;
		 }
		 int temp = array[unsortedIndex];
		 array[unsortedIndex] = array[minIndex];
		 array[minIndex] = temp;
		 unsortedIndex++;
	}
	return array;
}

#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> array) {
  // Write your code here.
  for( int selectPos = 0; selectPos < array.size() - 1; selectPos++ ) {
		  for( int comparePos = selectPos + 1; comparePos < array.size(); comparePos++ ) {
				   if( array[selectPos] > array[comparePos] ) {
						   int temp = array[selectPos];
						   array[selectPos] = array[comparePos];
						   array[comparePos] = temp;
					 }
			}
	}
	return array;
}
