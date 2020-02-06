#include<iostream>
using namespace std;
void hanoi(int n, char src, char tmp, char dest)
{
 if(n==1)
 {
  cout<<"Move disk "<<n<<" from "<<src<<" to "<<dest<<"\n";
  return;
 }
 hanoi(n-1, src, dest, tmp);
 cout<<"Move disk "<<n<<" from "<<src<<" to "<<dest<<"\n";
 hanoi(n-1, tmp, src, dest);
}
int main()
{
 int n=3;
 hanoi(n, 'A', 'B', 'C');
 return 0;
} 
  
