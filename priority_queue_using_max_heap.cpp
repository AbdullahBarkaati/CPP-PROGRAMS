
/* CPP PROGRAM TO IMPLEMENT PRIORITY QUEUE USING MAX HEAP */

	#include<iostream>
	#include<vector>
	
	using namespace std;

vector<int> arr;
//function to return the index of parent node of given index

	int getParent(int index){

		if((index > 0) && index < arr.size() ){		
		return (index-1) /2 ;
		}
		return -1;
	}

//function to return index of left child of given index
	int getLeftChild(int index){
	
		if((index >= 0) && index < arr.size()){
			return (index*2)+1 ;
		}
		return -1;
	}

//function to return index of left child of given index
	int getRightChild(int index){
	
		if((index >= 0) && index < arr.size()){
			return (index*2)+2 ;
		}
		return -1;
	}

//function to return max element of heap
	int getMax(){

		return arr[1];
	}

//function to swap two elements
	void swap(int *x, int *y){

		int temp;
		temp = *x;
		*x = *y;
		*y = temp ;
	}

//function to heapify the elements in ascending order
	void maxHeapify(int index){

		int leftChildIndex = getLeftChild(index) ;
		int rightChildIndex = getRightChild(index) ;

		int largest = index ;

		if( leftChildIndex < arr.size() &&  leftChildIndex >= 0){
		
			if(arr[leftChildIndex] > arr[largest] ){
				largest = leftChildIndex ;
			}
		}

		if( rightChildIndex < arr.size() &&  rightChildIndex >= 0){
		
			if(arr[rightChildIndex] > arr[largest] ){
				largest = rightChildIndex ;
			}
		}

		if(largest!=index){

			swap( &arr[index] , &arr[largest] ) ;
			maxHeapify(largest) ;		
		}
	}

//function to build Max heap
	void buildMaxHeap(){

		int index;
		for(index = (arr.size() / 2)-1 ; index>=0 ; index-- ){
			maxHeapify(index) ;
		}
	}


//function to extract max element from heap
	int extractMax(){

		int max=arr[0];
		arr[0]=arr[arr.size()-1];
		arr.pop_back();
		maxHeapify(0);
		return max;	
	}


//function to increase the priority of element
	void increaseKey(int index,int key){
	
		arr[index]=key;
		while(index>=0 && arr[index] > arr[getParent(index)]){

			swap(&arr[index], &arr[getParent(index)]) ;
			index=getParent(index) ;			
		}	
}

//function to decrease the priority of element
	void decreaseKey(int index , int key){

		arr[index]=key;
		maxHeapify(index);
	}

//function to insert an element in priority queue
	void insertInPriorityQueue(int key){

		arr.push_back(-10000);
		increaseKey(arr.size()-1,key);
	}

//function to remove the element from priority queue
	void remove(int index){

		arr[index] = getMax();
 
    		// Shift the node to the root of the heap
		maxHeapify(index);
 
 		// Extract the node
    		extractMax();
	}

//function to print the heap
	void printHeap(){

		int i;
		for(i=0; i<arr.size(); i++){
			cout << arr[i] << "\t" ;
		}
	}

//Driver code
	int main(){
		int choice,key,priority;
		do{
			cout << "\n 1---Insert Element \t2---Change Priority \t3---Print Heap \n4---Remove Element" ;
			cout <<	"\t5---Extract Max Priority Element \t6---Exit " ;
			cout << "\n Enter Choice....." ;
			cin >> choice ;
			switch(choice){
				
				case 1 :
						cout << "\n Enter Elements...." ;
						cin >> key ;
						insertInPriorityQueue(key);
						break;							
				
				case 2 :
						cout << "\n Enter The Index And New Priority Of An Element....";
						cin >> key >> priority ;
						if(priority > arr[key]){
							increaseKey(key,priority);
						}
						else{
							decreaseKey(key,priority);
						}
						break;

				case 3 :
						printHeap();
						break;		
				
				case 4 :
						cout << "\n Enter The Index Of An Element to Remove....";
						cin >> key;
						remove(key);
						break;

				case 5 :
						cout << "MAX PRIORITY ELEMENT = " << extractMax();
						break;

			}
		}while(choice<6) ;	
		return 0;

	}