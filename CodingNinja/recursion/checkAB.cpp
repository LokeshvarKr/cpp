/*
Check AB
Suppose you have a string made up of only 'a' and 'b'. Write a recursive function that checks if the string was generated using the following rules:

a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'

If all the rules are followed by the given string, return true otherwise return false.
Sample Input:

abb

Sample Output:

true

*/

bool checkAB(char input[]) {
	// Write your code here
  if(input[0]=='\0')
    return true;
  if(input[0]=='a')
  {
    if(input[1]=='a'|| input[1]=='\0')
    checkAB(input+1);
    else if(input[1]=='b' && input[2]=='b')
    checkAB(input+3);
    else return false;
  }
  else return false;
}



/*
#include<string.h>
bool checkAB(char input[])
{
  if(input[0]=='\0')
    return true;
  if(input[0]!='a')
    return false;
  if(input[1]!='\0' && input[2]!='\0')
  {
 	 if(input[1]=='b' && input[2]=='b')
      return checkAB(input+3);
  }
   return checkAB(input+1);
}

*/
/*bool checkAB(char input[])
{
 if(strlen(input)==0)
    return true;
	if(strlen(input)==1)
    {
     	if(input[0]=='a')
          return true;
    }
  if(strlen(input)==2)
  {
   if(input[0]=='a' && input[1]=='a')
      return true;
    else return false;
  }
  
  if(strlen(input)==3)
  {
  	if(input[0]=='a'&& input[1]=='b' && input[2]=='b')
    	return true;
    else if(input[0]=='a'&&input[1]=='a'&&input[2]=='a')
      return true;
    else return false;
  }
  
  if(input[0]=='a' && input[1]=='a')
      checkAB(input+1);
  else if(input[0]=='a'&& input[1]=='b' && input[2]=='b')
    checkAB(input+3);
 	else return false;
}
*/



