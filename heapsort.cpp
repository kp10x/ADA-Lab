#include <iostream>
#include <chrono> 
using namespace std; 
void heapify(int arr[], int n, int i) { 
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
    if (l < n && arr[l] > arr[largest]) largest = l; 
    if (r < n && arr[r] > arr[largest]) largest = r; 
    if (largest != i) { 
        swap(arr[i], arr[largest]); 
        heapify(arr, n, largest); 
    } 
} 
void heapSort(int arr[], int n) {  
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i); 
    for (int i = n - 1; i > 0; i--) {  
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0); 
    } 
}  
int main() {
    int n = 100;
    int arr[1000];
    for (int i = 0; i < n; ++i)
    {
        arr[i] = (rand()%n) + 1;
    }
    auto start = chrono::steady_clock::now();
    heapSort(arr, n);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    for (int i = 0; i < n; ++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n"<<chrono::duration<double, milli>(diff).count()<<"ms\n";
    return 0;
}