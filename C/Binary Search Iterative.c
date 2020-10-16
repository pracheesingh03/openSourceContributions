#include <stdio.h>
#include <stdlib.h>
//binary search iterative
int main()
{
    int key;
    int a[100]; //= {3, 6, 8, 12, 14, 17, 25, 29, 31, 36, 42, 47, 53, 55, 62};
    int n;//= sizeof(a)/sizeof(a[0]);
    printf("Hello world!\n");
    printf("\nBinary Search Program Using Iterative Method.\n");
    printf("Enter no of elements:\n");
    scanf("%d", &n);
    printf("\nArray:\n");
    for(int i = 0; i<n; i++){
        scanf("%d", &a[i]);
    }
    printf("Array:\n");
    for(int i = 0; i<n; i++){
        printf("%d", a[i]);
    }
    printf("\nEnter the number to be searched:");
    scanf("%d", &key);
    int result = BinSearch(a, n, key);
    if(result==0)
        printf("\nElement Not Found!\n");
    else
        printf("\nElement Found at position %d.\n", result + 1);
    return 0;
}

int BinSearch(int a[], int n, int key)
{
    int low = 0;
    int high = n-1;
    while(low<=high)
    {
        int mid = (low + high)/2;
        if(key==a[mid])
            return mid;
        else if(key<a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return 0;
}
