#include <iostream>
#include <chrono>

using namespace std;

int binSearch(int arr[], int beg, int end, int key) 
{ 
    if (end >= beg) { 
        int mid = beg + (end - beg) / 2; 
  
        if (arr[mid] == key) 
            return mid; 
  
        if (arr[mid] > key) 
            return binSearch(arr, beg, mid - 1, key); 
  
        return binSearch(arr, mid + 1, end, key); 
    } 
  
    return -1; 
}
int linSearch(int arr[], int beg, int end, int key) 
{ 
    if (end < beg) return -1;
    
    if (arr[beg] == key) return beg;
    
    if (arr[end] == key) return end;
    
    return linSearch(arr, beg + 1,  end - 1, key); 
} 
int main() 
{
    int n, key;
    cin >> n >> key;
    
    int arr[n];
    
    for (int i = 0; i < n; ++i) cin >> arr[i];
    auto start = chrono::steady_clock::now();
    cout<<"Linear: "<<linSearch(arr, 0, n-1, key);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout<<" Time: "<<chrono::duration<double,milli>(diff).count()<<" ms\n";

    start = chrono::steady_clock::now();
    cout<<"Binary: "<<binSearch(arr, 0, n-1, key);
    end = chrono::steady_clock::now();
    diff = end - start;
    cout<<" Time: "<<chrono::duration<double,milli>(diff).count()<<" ms\n";

    return 0;
}