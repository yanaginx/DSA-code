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
   for ( int i = 0; i < n; i++ )
   {
      int iMin = i;
      for ( int j = i+1; j < n; j++ )
      {
         if ( arr[j] < arr[iMin] )
            iMin = j;
      }
      Swap ( arr[iMin], arr[i] );
   }
}

void InsertionSort( int*& arr, int n )
{
   /* 
    * ============================================
    * input: arr: array to be sorted, n: number
    * output: The array is sorted ascending
    * ============================================
    */
   for ( int i = 1; i < n; i++ )
   {
      int value = arr[i];
      int hole = i;
      while ( hole > 0 && arr[hole-1] > value )
      {
         arr[hole] = arr[hole-1];
         --hole;
      }
      arr[hole] = value;
   }
}


int main ()
{
   int* a;;
   int b[] = {7, 9, 10, 2, 3, 6, 1, 18, 12, 10};
   a = b;
   int n = sizeof(b) / sizeof(int);
   SelectionSort(a, n);
   //InsertionSort(a, n);
   for ( int i = 0; i < n; i++ )
      cout << a[i] << " ";
   return 0;
}
