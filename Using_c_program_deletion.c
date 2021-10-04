
#include<stdio.h>

#define size 4

int main()
{
    int arr[size] = {3,2,7,6};
    int key, i, j,k,index = -1;

    printf("Enter element to delete\n");
    scanf("%d",&key);
    for(i = 0; i < size; i++)
    {
        if(arr[i] == key)
        {
                    index=i;
                    break;
                }



    }

    if(index != -1)
    {
        for(i = index; i < size - 1; i++)
               arr[i] = arr[i+1];

        printf("New Array : ");
        for(i = 0; i < size - 1; i++)
            printf("%d ",arr[i]);
    }

    return 0;
}
