#include <iostream>
#include <chrono>

using namespace std;

void modBubbleSort(int arr[], int n) {  
    int i, j;  
    for (i = 0; i < n - 1; i++) {
        int flag = 0;
        for (j = 0; j < n - i - 1; j++)  
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                flag++;
            }
        if (flag == 0) break;
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
	// To give best case:
	// modBubbleSort(arr, n);
	auto start = chrono::steady_clock::now();
	modBubbleSort(arr, n);
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n"<<chrono::duration<double, milli>(diff).count()<<"ms\n";
	return 0;
}