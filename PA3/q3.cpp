#include<iostream>
#include<vector>
#include<cmath>
#include<ctime>
using namespace std;

int insertLinear(int x, vector<int> & linear);
int insertQuad(int x, vector<int> & quad);
int insertDuble(int x, int dubHash, vector<int> & duble);

int main()
{
  int linCollides=0;
  int quadCollides= 0;
  int dubCollides = 0;
  int quadInc;
  int tableSize;
  bool fail = false;
  int x, count=0;
  int doubleHash;

  srand(time(NULL));
  cout<<"enter the size of the table ";
  cin>>tableSize;
  vector<int> linear(tableSize,-1);//initalize each table to -1 for empty
  vector<int> quad(tableSize,-1);  //initalize each table to -1 for empty
  vector<int> duble(tableSize,-1);  //initalize each table to -1 for empty
  do{
   doubleHash = rand()%tableSize;
  }while (doubleHash < tableSize/10 && doubleHash%tableSize==0);

  while(count < tableSize && !fail)
  {
    x= rand()%tableSize;// value to insert
	quadInc=insertQuad(x,quad);
	if (quadInc < 0)
		fail = true;
	else
	{
	 quadCollides += quadInc;
	 linCollides+=insertLinear(x,linear);
	 dubCollides+=insertDuble(x,doubleHash, duble);
	}
	count++;
  }
  cout<<"Num linear collides "<<linCollides<<endl;
  cout<<"Num quadratic collides "<<quadCollides<<endl;
  cout<<"Num double hash collides "<<dubCollides<<endl;
  return 0;
}

int insertLinear(int x, vector<int> & linear)
{
  if((linear[x] >= 0)){
	  while(linear[x] >= 0){
		  x += 1;
	  }
	  linear[x]= x;
	  return 1;
  }else{
	  linear[x] = x;
  }
  return 0;
}

int insertQuad(int x, vector<int> & quad)
{

  if(quad[x] >= 0){
	  int i=1;
	  while(quad[x] >= 0){
		  x += i^2;
		  i+=1;
	  }
	  quad[x]=x;
	  return 1;
  }
  quad[x]=x;
  return 0;
}

int insertDuble(int x, int dubHash, vector<int> & duble)
{

	return 0;
	/*
  if(duble[x]>=0){
	  
	  if((x+1)>=duble.size()){
		insertDuble(0,dubHash,duble);
		return 1;
	  }
	  x +=1;
	  insertDuble(x,dubHash,duble);
	  return 1;
  }else{
	 duble[x]=x;
	 cout << x << endl;
  }
  return 0;*/
}
