#include<iostream>
#include "List.h"
using namespace std;
int main(){
	List<int> list1;
	
	//Part A
	for(int curr1: list1){
		int i = 0;
		for(int curr2: list1){
			//Might equal each other at first
			if (i != 0){
				if(&curr1 == &curr2){
				cout << "Cycle Encountered"<<endl;
				return 0;
				}
			}
			
		}
	}
	
	
	//Part B
	List<int>:: iterator iter1;
	List<int>:: iterator iter2;
	for(iter1 = list1.begin(); iter1!=list1.end();++iter1)
			for(iter2 = iter1; iter2!=list1.end();++iter2)
				if(iter1 == iter2)
					cout << "Cycle Encountered"<<endl;
	return 0;
}