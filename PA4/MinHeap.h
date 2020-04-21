#ifndef MIN_HEAP_H
#define MIN_HEAP_H


using namespace std;       

class MinHeap
{
  private:

    int *arr; // pointer to array of elements in heap 
    int capacity; // maximum possible size of min heap 
    int heap_size; // Current number of elements in min heap

  public:

    // Constructor for the MinHeap
    MinHeap(int cap) {
        heap_size = 0; 
        capacity = cap; 
        arr = new int[cap]; 
    }

    // to ge the index of parent of node at index i
    inline int parent(int i) { return (i-1)/2; } 
  
    // to get index of left child of node at index i 
    inline int left(int i) { return (2*i + 1); } 
  
    // to get index of right child of node at index i 
    inline int right(int i) { return (2*i + 2); } 

    // Returns the minimum key (key at root) from min heap 
    inline int getMin() {  return arr[0]; } 

    // Inserts a new key 'k' 
    void insertKey(int k) {
		
        if(heap_size +1 > capacity){
			int* newArray = new int [2*capacity];
			capacity *= 2;
			for(int i = 0; i < heap_size;++i){
				newArray[i]=arr[i];
			}
			delete arr;
			arr = newArray;
		}
		
        if(heap_size == 0){
			arr[0] = k;
		}else{
			
			// Adds element to end of array and compares to parent until it is greater than parent
			int pos = heap_size;
			if(k>=arr[parent(pos)]){
				arr[pos] = k;
			}else{
				while(k<arr[parent(pos)]){
					int temp = arr[parent(pos)];
					arr[(pos-1)/2] = k;
					arr[pos] = temp;
					pos = parent(pos);
				
				}
			}
			
			
		}
		heap_size += 1;
    }

    // Extract the root which is the minimum element 
    int extractMin() {
		int min = arr[0];
        if(heap_size==1){
			heap_size =0;
		}else{
			//arr[0] = arr[heap_size-1];
			 
		}
        return min;
    }
  
    // Decreases key value of key at index i to newVal 
    void decreaseKey(int i, int newVal) {
       
        arr[i] = newVal;
    }
  
    // Deletes a key stored at index i 
    void deleteKey(int i) {
        // Remove below line after your implementation
        return;
    }
};

#endif
