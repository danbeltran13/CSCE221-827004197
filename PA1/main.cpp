#include <iostream>
#include "List.h"
using namespace std;
/*const_iterator operator+ (int k ) const{
	        const_iterator old = *this;
            ( *this + k);
            return old;
	
}*/

int main(){
	List<int> m;
	m.push_back(1);
	m.push_back(2);
	m.push_back(3);
	m.push_back(4);
	
	cout<<*(m.begin()+3) <<endl;
	
	
	
	
	
	return 0;
}
