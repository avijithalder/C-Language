#include<stdio.h>
int main()
{
    int arr[]={1,2,4,5,67,100,102};
    int item =67;

    int left=0,right=6,middle;

    while(left<=right)
    {
        middle=(left+right)/2;
        if (arr[middle]==item)
        {
            printf("Item found at index : %d\n",middle);
            return 0;
        }
        else if (arr[middle]<item)
        {
            left=middle+1;
        }
        else 
        {
            right=middle-1;
        }
    }
    printf("Item not found\n");
    return 0;
}
