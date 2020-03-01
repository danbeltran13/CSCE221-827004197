#include <iostream>
#include "List.h"
using namespace std;


int main(){
	List<int> m;
	m.push_back(1);
	m.push_back(2);
	m.push_back(3);
	m.push_back(4);
	
	cout<<*(m.begin()+3) <<endl;
	
	
	
	
	
	return 0;
}
