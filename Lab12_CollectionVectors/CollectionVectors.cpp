#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{

vector<int> vect;
int number;
char character;

do{

cout<<"enter operation [a/r/q] and number: ";

cin>>character;

if(character == 'q' || character == 'Q')
break;
cin>>number;
switch(character)
{
case 'a':
case 'A':
vect.push_back(number);
break;
case 'r':
case 'R':
{ vector<int>::iterator it;
it = find(vect.begin(),vect.end(),number);
if(it != vect.end())
vect.erase(it);
break;
   }
default:
cout<<"ERROR: invalid input!"<<endl;

}

cout<<"your numbers: ";
for(vector<int>::iterator ip = vect.begin(); ip != vect.end(); ++ip)
cout<<*ip<<" ";
cout<<endl;
}while(character != 'q' && character != 'Q');

return 0;  
}
