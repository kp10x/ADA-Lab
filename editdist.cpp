#include<bits/stdc++.h>
using namespace std;
 
int editDist(string s1, string s2, int m, int n)
{
	if(m==0)
		return n;
	if(n==0)
		return m;

	if(s1[m-1]==s2[n-1])
		return editDist(s1, s2, m-1, n-1);

	return 1+min(min(editDist(s1, s2, m, n-1), editDist(s1, s2, m-1, n)), editDist(s1, s2, m-1, n-1));
}

int main()
{	
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	cout<<editDist(s1, s2, s1.length(), s2.length());

	return 0;
}