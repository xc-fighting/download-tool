#include <iostream>
#include <string>

using namespace std;

struct Info {
 string id;
 int rank;
 bool operator < (const Info& other) {
 	  return this->rank < other.rank;
 }

 friend ostream& operator<<(ostream& os, const Info& item) {
 	os<<item.id<<","<<item.rank<<endl;
 	return os;
 }
};


template<typename T>
void swap(T arr[], int left, int right) {
	T temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
	return;
}

template<typename T>
void selectionSort(T arr[], int len) {
	for(int idx = 0; idx < len; idx++) {
		int candidateIdx = idx;
		for(int nextIdx = idx + 1; nextIdx < len; nextIdx++) {

			if(arr[nextIdx] < arr[candidateIdx]) {
				candidateIdx = nextIdx;
			}
		}

        swap(arr, candidateIdx, idx);
	}
}

template<typename T>
void insertionSort(T arr[], int len) {
	for(int curIdx = 1; curIdx < len; curIdx++) {
		T value = arr[curIdx];
		int prev = curIdx - 1;
		for(; prev >= 0; prev--) {
			if(arr[prev] > value) {
				arr[prev+1] = arr[prev];
			}
			else {
				break;
			}
		}
		arr[prev+1] = value;
	}
	return;
}

template<typename T>
void bubbleSort(T arr[], int len) {
	for(int end = len - 1; end >= 1; end--) {
		for(int idx = 0; idx < end; idx++) {
             if(arr[idx] < arr[idx+1]) {
             	 continue;
             }
             else {
             	swap(arr, idx, idx+1);
             }
		}
	}
	return;
}

template<typename T>
void shellSort(T arr[], int len) {
	for(int gap = len/2; gap > 0; gap = gap/2) {

		for(int idx = gap; idx < len; idx += gap) {
			
			int prev = idx - gap;
			int temp = arr[idx];
			for(;prev >= 0; prev -= gap) {
				if(arr[prev] > temp) {
					arr[prev+gap] = arr[prev];
				}
				else {
					break;
				}
			}
			arr[prev+gap] = temp;
		}
	}
	return;
}

int main() {
   int test[10] = {5,3,2,4,90,87,6,8,9,10};
   selectionSort(test, 10);
   for(int idx = 0; idx < 10; idx++) {
   	   cout<<test[idx]<<endl;
   }

   Info data[4] = {{"D", 90}, {"C", 100}, {"B", 95}, {"A", 95}};
   selectionSort(data, 4);
   for(int idx = 0; idx < 4; idx++) {
   	   cout<<data[idx];
   }
   
   cout<<"insertion sort result"<<endl;
   int test2[10] = {5,3,2,4,90,87,6,8,9,10};
   insertionSort(test2, 10);
   for(int idx = 0; idx < 10; idx++) {
   	   cout<<test2[idx]<<endl;
   }
   
   cout<<"bubble sort result"<<endl;
   int test3[10] = {5,3,2,4,90,87,6,8,9,10};
   bubbleSort(test3, 10);
   for(int idx = 0; idx < 10; idx++) {
   	  cout<<test3[idx]<<endl;
   }

   cout<<"shell sort result"<<endl;
   int test4[11] = {5,3,2,4,90,87,6,8,9,10,25};
   shellSort(test4, 11);
   for(int idx = 0; idx < 11; idx++) {
   	  cout<<test4[idx]<<endl;
   }
}