//-----------------------------------------------------------------------
// Maria Fernanda Becerra
// mfbecerr
// pa7
// CSE101
// Shuffle.cpp
//------------------------------------------------------------------------
#include<iostream>
#include<string>
#include"List.h"

using namespace std;
void shuffle(List& D){
  List temp;
  int split=(D.size()/2);
//cout<<"split "<<split<<endl;
  D.moveFront();
  for(int i=0;i<split;i++){
    int fake=D.moveNext();
  }
  for(int i=0;i<split;i++){
    temp.insertBefore(D.peekNext());
    D.eraseAfter();
  }
  temp.moveFront();
  D.moveFront();
  for(int i=0;i<temp.size();i++){
    D.insertBefore(temp.moveNext());
    int fake=D.moveNext();
  }
}
int main(int argc, char * argv[]){
  if( argc != 2 ){
    cerr << "Usage: " << argv[0] << " <int> " << endl;
    return(EXIT_FAILURE);
  }
  int n;
//  if(isdigit(stoi(argv[1]))){
    n = stoi(argv[1]);
//  }
//  cout<<"n= "<<n<<endl;
  List L;
  int i;
  cout<<"deck size       shuffle count"<<endl;
  cout<<"------------------------------"<<endl;
  for(i=0;i<n;i++){
    L.insertBefore(i);
    List S=L;
    shuffle(L);
//cout<<"S="<<S<<endl;
//cout<<"L="<<L<<endl;
    int times=1;
    while(!L.equals(S)){
      shuffle(L);
      times++;
    }
    //cout<<"deck size       shuffle count"<<endl;
    cout<<i+1<<"               "<< times<< endl;
  }


return(0);
}
