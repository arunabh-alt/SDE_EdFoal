#include <iostream>
using namespace std;

int main(){
    int arr[100], count, i, num,B[100];

    cout << "Enter Number of Elements in Array\n";
    cin >> count;

    cout << "Enter " << count << " numbers \n";

    for(i = 0; i < count; i++){
        cin >> arr[i];
    }

    cout << "Enter a number to serach in Array\n";
    cin >> num;
    for(i = 0; i < count; i++){
        if(arr[i] == num){
            cout << "Element found at index: \n" << i;
            break;
        }
    }

    if(i == count){
        cout  << "-1";
    }
     for(i=0;i<count;i++){
             B[(i+num)%count]=arr[i];

     }
     cout<<"\n\nThe rotated array will be from the target: \n";
     for(i=0;i<count;i++)
        cout<<B[i];

    return 0;
}
