//-----------------------------------------------------------------------------
// Maria Fernanda Becerra
// mfbecerr
// CSE101
// pa7
// ListTest.cpp
//-----------------------------------------------------------------------------
#include<iostream>
#include<string>
#include"List.h"

using namespace std;

int main(){
  List List1,List2,List3;
  for(int i=1; i<=15; i++){
      List1.insertAfter(i);
      List2.insertBefore(i);
   }

   cout << endl;
   cout << "List1 = " << List1 << endl;
   cout << "List1.isEmpty() = " << List1.isEmpty() << endl;
   cout << "List1.size() = " << List1.size() << endl;
   cout << "List1.position() = " << List1.position() << endl;
   //up to here:
   //inser insertAfter works
   //isEmpty works
   //position works
   //to string works

   cout << "List2 = " << List2 << endl;
   cout << "List2.isEmpty() = " << List1.isEmpty() << endl;
   cout << "List2.size() = " << List1.size() << endl;
   cout << "List2.position() = " << List2.position() << endl;
   //up to here:
   //insert before works

   List1.moveFront();
   List2.moveFront();
   cout << "List1 = " << List1 << endl;
   cout << "List1.position() = " << List1.position() << endl;
   cout << "List2 = " << List2 << endl;
   cout << "List2.position() = " << List2.position() << endl;
   //moveFront works

   cout << "List1.peekNext() = " << List1.peekNext() << endl;
   cout << "List1.moveNext() = " << List1.moveNext() << endl;
   cout << "List2.peekNext() = " << List1.peekNext() << endl;
   cout << "List2.moveNext() = " << List1.moveNext() << endl;
   //peekNext works
   //moveNext works
   //peekNext works
   //moveNext works

   List1.moveBack();
   List2.moveBack();
   cout << "List1 = " << List1 << endl;
   cout << "List1.position() = " << List1.position() << endl;
   cout << "List2 = " << List2 << endl;
   cout << "List2.position() = " << List2.position() << endl;
   //moveBack works

   cout << "List1.peekPrev() = " << List1.peekPrev() << endl;
   cout << "List1.movePrev() = " << List1.movePrev() << endl;
   cout << "List2.peekPrev() = " << List1.peekPrev() << endl;
   cout << "List2.movePrev() = " << List1.movePrev() << endl;
   //peekNext works
   //moveNext works

   List1.moveBack();
   for(int i=1; i<=15; i++){
      List1.insertBefore(i);
   }
   List2.moveFront();
   for(int i=1; i<=15; i++){
      List2.insertAfter(i);
   }
   cout << "List1 = " << List1 << endl;
   cout << "List2 = " << List2 << endl;
   cout << "List1==List2 is " << (List1==List2?"true":"false") << endl;
   //equals works
   //== operator works

   List1.moveBack();
   List2.moveFront();
   List1.eraseBefore();
   List2.eraseAfter();
   cout << "List1 = " << List1 << endl;
   cout << "List2 = " << List2 << endl;
   //erase before
   //erase after

   List2.moveBack();
   List1.moveFront();
   List1.findNext(5);
   List2.findPrev(3);
   cout << "List1.findNext(5) = " << List1.findNext(5) << endl;
   cout << "List2.findPrev(3) = " << List1.findPrev(3) << endl;
   //find Next works
   //find prev works

   List1.cleanup();
   cout << "List1 = " << List1 << endl;
   //cleanup works

   List3=List1.concat(List2);
   cout << "List3 = " << List3 << endl;
   //concat works

   List1.clear();
   List2.clear();
   List3.clear();
   cout << "List1.isEmpty() = " << List1.isEmpty() << endl;
   cout << "List1.size() = " << List1.size() << endl;
   cout << "List2.isEmpty() = " << List1.isEmpty() << endl;
   cout << "List2.size() = " << List1.size() << endl;
   cout << "List3.isEmpty() = " << List1.isEmpty() << endl;
   cout << "List3.size() = " << List1.size() << endl;
   //clear works
   //all fucntions checked

   return(0);
}
