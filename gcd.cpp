#include <iostream>
using namespace std;
int gcd(int m, int n)
{
	if(n==0)
		return m;
	return gcd(n, m%n);
}
int main()
{	
	int m,n;
	cout<<"Enter 2 nos\n";
	cin>>m>>n;
	cout<<"GCD is:"<<gcd(m, n)<<"\n";
}