#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string line, filename;
    map <string,int> coronamap;

    ifstream in;
    cout<<"enter the file name: ";
    cin>>filename;

    in.open(filename.c_str());
    getline(in,line);

	stringstream f;
	f<<line;
    string partOf;
	string name;
	unsigned long int max;
	unsigned long int temp;
	f>>name;
	f>>max;

    while (in)
    {
	   stringstream f;
	   getline(in,line);
	   f << line;
	   f >>partOf;
	   f >>temp;
	   
	   if(temp>max){
		   max = temp;
		   name = partOf;
	   }

	   
    }
    
    cout << "Most confirmed cases are in "<<name<<endl;
    // E.g. Most confirmed cases are in USA

    return 0;
}
