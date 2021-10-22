#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> array) {
  // Write your code here.
	
	//[0,curIndex-1] keeps a sorted array
	//sortedIndex + 1 -> end
	int curIndex = 1;
	while( curIndex < array.size() ) {
		  int elem = array[curIndex];
		  int index = curIndex - 1;
		  if( elem >= array[index] ) {
				  curIndex++;
				  continue;
			}
		  while( index >= 0 && elem < array[index] ) {
				  array[index+1] = array[index];
				  index--;
			}
		  array[index+1] = elem;
		  curIndex++;
	}
  return array;
}
