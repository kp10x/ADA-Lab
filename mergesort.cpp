#include <iostream>
#include <chrono>

using namespace std;

void merge(int arr[], int l, int m, int h) { 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  h - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) R[j] = arr[m + 1+ j]; 
  
    i = 0;
    j = 0;  
    k = l;  
    
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int arr[], int l, int h)
{
	if(l<h)
	{
		int m = l+(h-l)/2;

		mergeSort(arr, l, m);
		mergeSort(arr, m+1, h);

		merge(arr, l, m, h);
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
	mergeSort(arr, 0, n-1);
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n"<<chrono::duration<double, milli>(diff).count()<<"ms\n";
	return 0;
}