/*
 * =====================================================================================
 *
 *       Filename:  prob-w-stack.cpp
 *
 *    Description:  Using stack to checking the balances of parenthesis
 *
 *        Version:  1.0
 *        Created:  04/07/2020 03:06:44 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Duong V.Chan
 *        Company:  HCMUT
 *
 * =====================================================================================
 */

#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool CheckParanthesis ( char opening, char closing )
{
   if ( opening == '(' && closing == ')' )
      return true;
   else if ( opening == '{' && closing == '}' )
      return true;
   else if ( opening == '[' && closing == ']' )
      return true;
   else 
      return false;
}

bool CheckBalanced ( string exp )
{
   stack<char> S;
   int n = exp.length(); 
   for ( int i = 0; i < n; i++ )
   {
      if ( exp[i] == '{' || exp[i] == '(' || exp[i] == '[' )
         S.push( exp[i] );
      else if ( exp[i] == '}' || exp[i] == ')' || exp[i] == ']' )
      {
         if ( S.empty()  || !CheckParanthesis(S.top(), exp[i]) ) 
            return false;
         else S.pop();
      }
   }      
   if ( S.empty() )
      return true;
   else
      return false;
}

int main()
{
   string a;
   cout << "Insert the string you want to check balanced parenthesis: \n";
   cin >> a;
   cout << CheckBalanced(a);
   return 0;
}
