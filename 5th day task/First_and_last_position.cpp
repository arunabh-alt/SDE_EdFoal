#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int firstOc(int arr[], int low, int high, int x, int n)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            return firstOc(arr, (mid + 1), high, x, n);
        else
            return firstOc(arr, low, (mid - 1), x, n);
    }
    return -1;
}

int lastOc(int arr[], int low, int high, int x, int n)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if ((mid == n - 1 || x < arr[mid + 1]) && arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            return lastOc(arr, low, (mid - 1), x, n);
        else
            return lastOc(arr, (mid + 1), high, x, n);
    }
    return -1;
}

int main()
{
    int arr[] = { 5,7,7,8,8,10 };
    int n = sizeof(arr) / sizeof(int);

    int x;
    cout<<"Enter the target value: \n";
    cin>>x;
    printf("First Occurrence = %d\t",firstOc(arr, 0, n - 1, x, n));
    printf("\nLast Occurrence = %d\n",lastOc(arr, 0, n - 1, x, n));

    return 0;
}
