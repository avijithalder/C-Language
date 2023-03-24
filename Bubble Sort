#include<stdio.h>
int main()
{
    int arr[]={333,63,122,71,86,98,145,45,31};
    int size = 9,n,temp;

    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-1-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            
        }
        
    }
    printf("After Sorting\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ",arr[i]);
    }
    
    return 0;
}
