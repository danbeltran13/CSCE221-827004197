#include<iostream>
#include "List.h"
//2 stacks into array
using namespace std;
int main(){
	
	int arraySize = 100;
	
	int array[arraySize];
	List<int> list1;
	list1.push_back(1);	
	list1.push_back(2);	
	list1.push_back(3);	
	list1.push_back(4);	
	
	List<int> list2;
	list2.push_back(9);	
	list2.push_back(8);	
	list2.push_back(7);	
	list2.push_back(6);
	
	if(list1.size() + list2.size() > arraySize){
		cout << "Overflow Error" <<endl;
	} else{
		int i = 0;
		for(int currentValue: list1){
			array[i] = currentValue;
			++i;
		}
		i = arraySize-1;
		for(int currentValue: list2){
			array[i] = currentValue;
			--i;
		}
	}
	

	return 0;
}