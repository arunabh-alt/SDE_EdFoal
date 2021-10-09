/*Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

 

Example 1:
Input: nums = [1,2,0]
Output: 3

Example 2:
Input: nums = [3,4,-1,1]
Output: 2

Example 3:
Input: nums = [7,8,9,11,12]
Output: 1 */

#include<iostream>
using namespace std;

int main(){
    int arr[100],n,i,index;
    int smallest;
    cout<<"Enter the array size: \n";
    cin>>n;
    cout<<"Enter the array elements: \n";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    smallest=arr[0];
    for(i=0;i<n;i++){
        if(arr[i]<smallest){
            smallest=arr[i];
            index = i;
        }
    }
    cout<<index+1;
    return 0;

}
