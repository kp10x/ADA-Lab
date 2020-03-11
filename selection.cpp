#include <iostream>
#include <chrono>

using namespace std;

void selSort(int arr[], int n) 
{  
    int i, j, small;  
    for (i = 0; i < n - 1; i++)
    {	
    	small = i;
    	for(j = i+1; j < n; j++)
    		if (arr[j] < arr[small]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
    }      
}

int main()
{
	int n = 100;
	int arr[1000];
	for (int i = 0; i < n; ++i)
	{
		arr[i] = (rand()%n) + 1;
	}
	auto start = chrono::steady_clock::now();
	selSort(arr, n);
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n"<<chrono::duration<double, milli>(diff).count()<<"ms\n";
	return 0;
}