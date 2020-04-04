#include <fstream>
#include <cctype>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string line, filename, word;
    int pos;

    ifstream in;
    set<string> idents;
    set<string> reserved;
    string reserveArray[]= {"for", "if","else", "fstream", "set","string",
        "include", "main", "using", "namespace","std", "iostream", "string", 
        "ifstream","char","auto","size","open","while","return","int","endl"};
    
    for (int i = 0; i <22; i++)
        reserved.insert(reserved.end(),reserveArray[i]);

    cout<<"enter the file name: ";
    cin>>filename;

    in.open(filename.c_str());
    getline(in,line);
	bool isComment = false;
    while (in)
    {
		//Removes comments
		for(int i =0; i < line.size(); ++i){
		
			string t;
			string c;
			c +=line[i];
			t+= line[i];
			t+=line[i+1];
			if(t=="//"){
				line.erase(i,line.size());
			}else if(t=="/*" ){
				
				int index = line.find("*/",i+1);
				
				if( index == -1){
					line.erase(i,line.size());
					
				}else{
					line.erase(i,index+3-i);
				}
				i-=1;
			}
			else if(c=="\""){
				int index = line.find("\"",i+1);
				if( index == -1){
					line.erase(i,line.size());
				}else{
					line.erase(i,index+1-i);
				}
				i-=1;
			}
			
		}
		
      // Replace all ;,+,-,#,:,<,>,(,), etc... in line with a space
	  for(int i = 0; i < line.size();++i){
		  switch(line[i]){
			  case ';':
			  case ':':
			  case '+':
			  case '-':
			  case '<':
			  case '>':
			  case '(':
			  case ')':
			  case '{':
			  case '}':
			  case '#':
			  case '=':
			  case ',':
			  case '\'':
			  case '[':
			  case ']':
			  case '.':
			  case '&':
			  case '!':
			  case '\\':
			  line[i] = ' ';
		  }
		  
	  }
	   
	   
	   //Using stringstream to split line into words
	   stringstream f;
	   f<< line;
	   
	   //Appends to indents
	   while(f){
		string t;
		f>>t;
		if(!reserved.count(t) && !isdigit(t[0]) ){
			idents.insert(idents.end(),t);
		}
	   }
		getline(in,line);
    }

    for (auto x:idents)
        cout<<x<<endl;
    return 0;
}
