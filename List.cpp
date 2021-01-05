//-----------------------------------------------------------------------------
// Maria Fernanda Becerra
// mfbecerr
// pa 7 CSE101
// List.cpp
// Implementation file for List ADT
//-----------------------------------------------------------------------------
#include<iostream>
#include<string>
#include"List.h"
using namespace std;

// Private Constructor --------------------------------------------------------

// Node constructor
List::Node::Node(int x){
   data = x;
   next = nullptr;
   prev = nullptr;
}
// Class Constructors & Destructors -------------------------------------------

// Creates a new List in the empty state.
List::List(){
   frontDummy = new Node(-1);
   backDummy = new Node(-2);
   beforeCursor=frontDummy;
   afterCursor=backDummy;
   (frontDummy)->next=backDummy;
   (backDummy)->prev=frontDummy;
   pos_cursor=0;
   num_elements = 0;
}
// Copy Constructor.
List::List(const List& L){
   // make this an empty List
   frontDummy = new Node(-1);
   backDummy = new Node(-2);
   beforeCursor=frontDummy;
   afterCursor=backDummy;
   (frontDummy)->next=backDummy;
   (backDummy)->prev=frontDummy;
   pos_cursor=0;
   num_elements = 0;

   // load elements of L into this
   Node* N = (L.frontDummy)->next;
   while( N!=L.backDummy ){
      this->insertBefore(N->data);
      N = N->next;
   }
}
// Destructor
List::~List(){
      moveFront();
      while(num_elements>0){
       eraseAfter(); 
      }
      delete frontDummy;
      delete backDummy;
}
// Access functions -----------------------------------------------------------

// isEmpty()
// Returns true if Queue is empty, otherwise returns false.
bool List::isEmpty(){
   if(num_elements==0){
     return true;
   }
   else{
     return false;
   }
}
// size()
   // Returns the size of this List.
int List::size(){
  return (num_elements);
}
// position()
   // Returns the position of the cursor in this List. The value returned
   // will be in the range 0 to size().
int List::position(){
  return (pos_cursor);
}
// Manipulation procedures -------------------------------------------------

   // moveFront()
   // Moves cursor to position 0 in this List.
void List::moveFront(){
    beforeCursor=frontDummy;
    afterCursor=(frontDummy->next);
    pos_cursor=0;
}
// moveBack()
// Moves cursor to position size() in this List.
void List::moveBack(){
  beforeCursor=backDummy->prev;
  afterCursor=backDummy;
  pos_cursor=num_elements;
}
// peekNext()
// Returns the element after the cursor.
// pre: position()<size()
int List::peekNext(){
  if(position() >size() || position() ==size()){
      cerr << "Lisr Error: calling peekNext() on an invalid position" << endl;
      exit(EXIT_FAILURE);
   }
   return (afterCursor->data);
}
// peekPrev()
// Returns the element before the cursor.
// pre: position()>0
int List::peekPrev(){
  if(position()<0 ||position()==0){
      cerr << "Lisr Error: calling peekPrev() on an invalid position" << endl;
      exit(EXIT_FAILURE);
   }
   return (beforeCursor->data);
}
// moveNext()
// Advances cursor to next higher position. Returns the List element that
// was passed over. 
// pre: position()<size() 
int List::moveNext(){
   if(position()>size() ||position()==size() ){
      cerr << "Lisr Error: calling moveNext() on an invalid position" << endl;
      exit(EXIT_FAILURE);
   }
   int element=afterCursor->data;
   Node* B=afterCursor;
   Node* A=afterCursor->next;
   beforeCursor=B;
   afterCursor=A;
   pos_cursor++;
   return element;
}
// movePrev()
// Advances cursor to next lower position. Returns the List element that
// was passed over. 
// pre: position()>0
int List::movePrev(){
  if(position()<0 ||position()==0 ){
    cerr << "Lisr Error: calling movePrev() on an invalid position" << endl;
    exit(EXIT_FAILURE);
  }
  int element=beforeCursor->data;
  Node* A=beforeCursor;
  Node* B=beforeCursor->prev;
  beforeCursor=B;
  afterCursor=A;
  pos_cursor--;
  return element;
}
// insertAfter()
// Inserts x after cursor.
void List::insertAfter(int x){
  Node* N=new Node(x);
  N->prev=beforeCursor;
  N->next=afterCursor;
  beforeCursor->next=N;
  afterCursor->prev=N;
  afterCursor=N;
  num_elements++;
}
// insertBefore()
// Inserts x before cursor.
void List::insertBefore(int x){
  Node* N=new Node(x);
  N->prev=beforeCursor;
  N->next=afterCursor;
  beforeCursor->next=N;
  afterCursor->prev=N;
  beforeCursor=N;
  num_elements++;
  pos_cursor++;
}
// eraseAfter()
// Deletes element after cursor.
// pre: position()<size()
void List::eraseAfter(){
  if(position()>size() ||position()==size() ){
    cerr << "Lisr Error: eraseAfter() on an invalid position" << endl;
    exit(EXIT_FAILURE);
  }
  Node* D=afterCursor;
  Node* N=D->next;
  beforeCursor->next=N;
  N->prev=beforeCursor;
  afterCursor=N;
  num_elements--;
  delete D;
}
// eraseBefore()
// Deletes element before cursor.
// pre: position()>0
void List::eraseBefore(){
  if(position()<0 ||position()==0 ){
    cerr << "Lisr Error: eraseBefore() on an invalid position" << endl;
    exit(EXIT_FAILURE);
  }
  Node* D=beforeCursor;
  Node* P=D->prev;
  afterCursor->prev=P;
  P->next=afterCursor;
  beforeCursor=P;
  num_elements--;
  pos_cursor--;
  delete D;
}
// findNext()
// Starting from the current cursor position, performs a linear search (in 
// the direction front-to-back) for the first occurrence of the element x.
// If x is found, places the cursor immediately after the found element (so 
// eraseBefore() would remove the found element), and returns the final 
// cursor position. If x is not found, places the cursor at position size(),
// and returns -1. 
int List::findNext(int x){
  int pos=-1;
  int i=-1;
  while(position()<size()){
    i=moveNext();
    if(i==x){
      pos=position();
      break;
    }
  }
  return pos;
}
// findPrev()
// Starting from the current cursor position, performs a linear search (in 
// the direction back-to-front) for the first occurrence of the element x.
// If x is found, places the cursor immediately before the found element (so 
// eraseAfter() would remove the found element), and returns the final 
// cursor position. If x is not found, places the cursor at position 0, and 
// returns -1. 
int List::findPrev(int x){
  int pos=-1;
  int i=-1;
  while(position()>0){
    i=movePrev();
    if(i==x){
      pos=position();
      break;
    }
  }
  return pos;
}
// cleanup()
// Removes any repeated elements in this List, leaving only unique data
// values. The order of the remaining elements is obtained by retaining
// the frontmost occurrance of each element, and removing all other 
// occurances. The cursor is not moved with respect to the retained 
// elements, i.e. it lies between the same two retained elements that it 
// did before cleanup() was called.
void List::cleanup(){
  Node* R = nullptr;
  Node* A = nullptr;
  Node* P = nullptr;
  Node* N = nullptr;
  int i=-1;
  bool before=true;
  for(R=frontDummy->next;R!=backDummy;R=R->next){
    i=R->data;
    A=R->next;
    before=true;
    if(pos_cursor==0){
     before=false; 
    }
    while(A!=backDummy){
      if(A==afterCursor){
       before=false; 
      }
      if(A->data==i){
        Node* D= A;
        P=A->prev;
        N=A->next;
        if(A==beforeCursor){
          beforeCursor=P;
//          before=true;
        }
        if(A==afterCursor){
          afterCursor=N;
//          before=false;
        }
        if(before==true){
         pos_cursor--;
//cout<<"pos cursor "<<pos_cursor<<endl; 
        }
        A=A->next;
        P->next=N;
        N->prev=P;
        num_elements--;
        delete D;
      }
      else{
        A=A->next;
      }
    }
  }
}
// clear()
// Deletes all elements in this List, setting it to the empty state.
void List::clear(){
  beforeCursor=frontDummy;
  afterCursor=backDummy;
  Node* N=(frontDummy->next);
  while(N!=backDummy){
    Node* D=N;
    N=N->next;
    delete D;
  }
  pos_cursor=0;
  num_elements = 0;
}
// concat()
// Returns a new List consisting of the elements of this List, followed
// the elements of L. The returned List's cursor will be at its front
// (position 0).
List List::concat(const List& L){
  List C;
  Node* N=(this->frontDummy)->next;
  Node* M=(L.frontDummy)->next;
  while(N!=this->backDummy){
    C.insertBefore(N->data);
    N=N->next;
  }
  while(M!=L.backDummy){
    C.insertBefore(M->data);
    M=M->next;
  }
 // C.beforeCursor=C.frontDummy;
 // C.afterCursor=(C.frontDummy)->next;
  C.moveFront();
//cout<<"c pos "<<C.position()<<endl;
  return C;
}
 // Other Functions ---------------------------------------------------------

// to_string()
// Returns a string representation of this List consisting of a comma 
// separated sequence of elements, surrounded by parentheses.
string List::to_string(){
  Node* N=nullptr;
  string s="(";
  Node* start= frontDummy->next;
  for(N=start;N->next!=backDummy;N=N->next){
    s+= std::to_string(N->data)+", ";
  }
  s+= std::to_string(N->data)+")";
  return s;
}
// equals()
// Returns true if and only if this List is the same integer sequence as R.
// The cursors in this List and in R are unchanged.
bool List::equals(const List& R){
  bool eq = false;
  Node* N = nullptr;
  Node* M = nullptr;
  eq = ( this->num_elements== R.num_elements);
  N=(this->frontDummy)->next;
  M=(R.frontDummy)->next;
  while(eq && M!=R.backDummy){
    eq = (N->data==M->data);
    N = N->next;
    M = M->next;
  }
  return eq;
}
// Overriden Operators -----------------------------------------------------
   
// operator<<()
// Inserts string representation of L into stream.
ostream& operator<< ( ostream& stream,  List& L ) {
   return stream << L.List::to_string();
}
// operator==()
// Returns true if and only if A is the same integer sequence as B. The 
// cursors in both Lists are unchanged are unchanged.
bool operator== (List& A, const List& B){
   return A.List::equals(B);
}
// operator=()
// Overwrites the state of this List with state of L.
List& List::operator=( const List& L  ) {
   if( this != &L ){ // not self assignment
      // make a copy of Q
      List temp = L;
      
      // then swap the copy's fields with fields of this
      std::swap(frontDummy, temp.frontDummy);
      std::swap(backDummy, temp.backDummy);
      std::swap(beforeCursor, temp.beforeCursor);
      std::swap(afterCursor, temp.afterCursor);
      std::swap(num_elements, temp.num_elements);
      std::swap(pos_cursor, temp.pos_cursor);

   }

   // return this with the new data installed
   return *this;

   // the copy, if there is one, is deleted upon return
}
