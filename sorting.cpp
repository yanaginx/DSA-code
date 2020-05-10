/*
 * =====================================================================================
 *
 *       Filename:  sorting.cpp
 *
 *    Description:  Implementing Sorting algorithms w/ mycodeschool
 *
 *        Version:  1.0
 *        Created:  05/08/2020 08:27:39 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Shinyo 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;
void Swap ( int& a, int& b )
{
   int temp = a;
   a = b;
   b = temp;
}

void SelectionSort( int*& arr, int n )
{
   /* 
    * ============================================
    * input: arr: array to be sorted, n: number
    * output: The array is sorted ascending
    * ============================================
    */
   for ( int i = 0; i < n; ++i )
   {
      int iMin = i;
      for ( int j = i; j < n; ++j )
      {
         if ( arr[j] < arr[iMin] )
            iMin = j;
      }
      Swap( arr[iMin], arr[i] );      
   }
}

int main ()
{
   int* a;;
   int b[] = {7, 9, 10, 2, 3, 6, 1, 18, 12, 10};
   a = b;
   int n = sizeof(b) / sizeof(int);
   SelectionSort(a, n);
   for ( int i = 0; i < n; i++ )
      cout << a[i] << " ";
   return 0;
}
