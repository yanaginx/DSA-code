#include<iostream>
#include<stack>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
};

class Stack
{
    public:
    Node* top = NULL;
    int count = 0;
    void Push( int data );
    int Pop();
    void Print();
    Node* Top();
};

void Stack::Push( int data )
{
    Node* temp = new Node();
    ++count;
    temp->data = data;
    temp->next = this->top;
    this->top = temp;
}

void Stack::Print()
{
    Node* temp = this->top;
    std::cout << "Stack is: ";
    while ( temp != NULL )
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}

int Stack::Pop()
{
    Node* temp = this->top;
    int data = temp->data;
    this->top = temp->next;
    delete temp;
    return data;
}

class LinkedList
{
public:
   Node* head = NULL;
   int count = 0;
   // METHOD 
   void Insert( int data ); // insert at the beginning of the list
   void Insert( int data, int n ); // insert the data to the list on the position nth
   void Delete( int n ); // delete the nth node
   void Reverse(); // Reversing the linked list
   void Print();
   void PrintRecursion( Node* p ); // Print the linkedlist using recursion
   void ReverseRecursion( Node* p ); // Reverseing the linked list using recursion
   void ReverseS(); // Reversing the linked list using stack
};

//========IMPLEMENTING==========//
void LinkedList::Insert( int data ) 
{
   Node* temp = new Node();
   temp->data = data;
   temp->next = head;
   head = temp;
   this->count++;
    
}

void LinkedList::Insert( int data, int n )  
{
   Node* temp = new Node();
   temp->data = data;
   temp->next = NULL;
   if ( n == 1 )
   {
      temp->next = head;
      head = temp;
      ++this->count;
      return;
   }
   else
   {
      if ( n > count + 1 || n < 1 )
      {
         cout << " Overflow! \n";
         return;
      }
      Node* temp_traverse = head;
      for (int i = 1; i < n-1; ++i )
      {
         cout << i << " "; 
         cout << temp_traverse->data << "\n"; 
         temp_traverse = temp_traverse->next;   
      }
      temp->next = temp_traverse->next;
      temp_traverse->next = temp;
      ++this->count;
   }
}

void LinkedList::Delete( int n )
{
   Node* temp = this->head;
   if ( n > count || n < 1 )
      cout << "Overflow!";
   else
   {
      if ( n == 1 )
      {
         Node* loc = this->head;
         head = loc->next;
         delete loc;
         --this->count;
      } 
      else
      {
         for ( int i = 1; i < n-1; i++ )   
            temp = temp->next;
         Node* loc = temp->next;
         temp->next = loc->next; 
         delete loc; 
         --this->count;
      }  
   }
}

void LinkedList::Print()
{
   Node* temp = head;
   cout << "List is: ";
   while ( temp != NULL )
   {
      cout << temp->data << " ";
      temp = temp->next;
   }
   cout << "\n";
}

void LinkedList::Reverse()
{
   Node* current = this->head;
   Node* prev = NULL;
   Node* next = NULL;
   while ( current != NULL )
   {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
   }
   this->head = prev;
}

void LinkedList::PrintRecursion( Node* p )
{
   if ( p == NULL ) return; // Exit condition
   PrintRecursion( p->next ); // Recursive call
   cout << p->data << " " ; // First print the data
}

void LinkedList::ReverseRecursion( Node* p )
{
   if ( p->next == NULL ) // Going to the last node, set the head to the last node then return
   {
      this->head = p;
      return;
   }
   ReverseRecursion( p->next );
   Node* q = p->next;
   q->next = p;
   p->next = NULL;
}

void LinkedList::ReverseS()
{
    stack<Node*> S;
    if ( this->head == NULL )
        return;
    Node* temp = this->head;
    while ( temp != NULL )
    {
        S.push(temp);
        temp = temp->next;
    }
    this->head = S.top();
    temp = S.top();
    S.pop();
    while ( !S.empty() )
    {
       temp->next = S.top();
       S.pop();
       temp = temp->next; 
    }
    temp->next = NULL;
}
//===================MAIN==================//
int main()
{
    stack<Node> S;
    LinkedList list;
    list.Insert( 1, 1 );
    list.Insert( 2, 1 );
    list.Insert( 3, 1 );
    list.Insert( 4, 4 );
    list.Print();
    list.ReverseS();
    list.Print();
}