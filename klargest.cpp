#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> v;

	int n, k;
    cin >> n >> k;
    
    for (int i = 0; i < n; ++i) 
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end(), greater<int>());
    for(int i = 0; i < k; i++)
    	cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}