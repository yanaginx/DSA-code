#include<iostream>
using namespace std;

//========DEFINING===========// 
class Node
{  
public:
   int data;
   Node* next;
};

class LinkedList
{
public:
   Node* head;
   int count = 0;
   // METHOD 
   void Insert( int data ); // insert at the beginning of the list
   void Insert( int data, int n ); // insert the data to the list on the position nth
   void Delete( int n ); // delete the nth node
   void Reverse(); // Reversing the linked list
   void Print();
   void PrintRecursion( Node* ); // Print the linkedlist using recursion
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

//==========MAIN PROGRAM===========//
int main()
{
   int n = 0;
   int x = 0;
   bool confirm = 1;
   LinkedList list;
   list.head = NULL; // empty list;
   while( confirm )
   {
      cout << "Enter the number: ";
      cin >> x;
      cout << "Enter the positions: ";
      cin >> n;
      list.Insert( x, n );
      list.Print(); 
      cout << "Continue? (1 to proceed, 0 to cancel) ";
      cin >> confirm;
   }
   cout << "The number of element in the list is: " << list.count << "\n";
   confirm = 1;
   while ( confirm )
   {
      cout << "Choose a number from 1 to " << list.count << " to delete 1 node: "; 
      cin >> n;
      list.Delete(n); 
      list.Print();
      cout << "Continue? (1 to proceed, 0 to cancel) ";
      cin >> confirm;
   } 
   //list.Reverse();
   //list.Print();
   //list.Reverse();
   //list.Print();
   list.PrintRecursion( list.head );
    
}



