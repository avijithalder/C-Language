#include <stdio.h>
int main()
{
    int arr[] = {10, 2, 4, 5, 67, 100, 102};

    int item, pos = -1;

    printf("Enter your value ");
    scanf("%d", &item);

    for (int i = 0; i < 7; i++)
    {
        if (item == arr[i])
        {
            pos = i + 1;
            break;
        }
    }

    if (pos == -1)
    {
        printf("Item not found");
    }
    else
    {
        printf("Item found at index : %d", pos);
    }

    return 0;
}
