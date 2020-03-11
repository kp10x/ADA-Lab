#include<iostream>
#include<string>

using namespace std;

int match(string str, string patt, int n, int m)
{
	for(int i=0; i<n-m; i++){
		int j = 0;
		while(j<m && str[i+j]==patt[j]){
			j++;
		}
		if(j==m)
			return i;
	}
	return -1;
}

int main()
{
	string str, patt;
	getline(cin, str);
	getline(cin, patt);
	int n = str.length();
	int m = patt.length();
	cout<<"Pos: "<<match(str, patt, n, m)+1;
	return 0;
}