#include <iostream>
using namespace std;
int first(int arr[], int beg, int end, int key)
{
	
	int mid = (beg+end)/2;
	while(beg<=end)
	{
		if(key == arr[mid])
		{	
			if(mid==0 || arr[mid-1]!=key)
				return mid;

			return first(arr, beg, mid-1, key);
		}
		else if(key < arr[mid])
			return first(arr, beg, mid-1, key);
		else
			return first(arr, mid+1, end, key);
	}
	return -1;
}
int last(int arr[], int beg, int end, int key)
{

	int mid = (beg+end)/2;
	while(beg<=end)
	{
		if(key == arr[mid])
		{	
			if(arr[mid+1]!=key)
				return mid;

			return last(arr, mid+1, end, key);
		}
		else if(key < arr[mid])
			return last(arr, beg, mid-1, key);
		else
			return last(arr, mid+1, end, key);
	}
	return -1;
}

int main()
{
	int arr[10], n, key, count=0, flag=0, found[10], j=0, fir=-1, las =-1;
	cout<<"Enter the number of elements and the elements of the array\n";
	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	cout<<"Enter key ";
	cin>>key;
	int beg = 0, end = n-1;
	fir=first(arr, beg, end, key);
	las=last(arr, beg, end, key);
	if(fir!=-1 && las!=-1)
		cout<<"First:"<<fir+1<<" Last:"<<las+1<<" Count:"<<las-fir+1;
	else
		cout<<"Element not present in list\n";
	return 0;
}