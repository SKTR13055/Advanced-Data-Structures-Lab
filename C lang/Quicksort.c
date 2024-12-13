//This program performs the Quick Sort for the given values
#include<stdio.h>
void swap(int*a, int*b);

int partition(int arr[],int low, int high)
{
     int pivot = arr[high];
     int i = low - 1;
     for(int j = low; j<= high; j++)
     {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
     }
     swap(&arr[i+1],&arr[high]);
     return i+1;
}

void QuickSort(int arr[],int low, int high)
{
     if(low<high)
     {
         int pi = partition(arr,low,high);
         QuickSort(arr,low,pi-1);
         QuickSort(arr,pi+1,high);
     }
}

void swap(int*a, int*b)
{
     int temp = *a;
     *a = *b;
     *b = temp;

}

void printarray(int arr[],int n)
{
     for(int i =0;i<n;i++)
     {
         printf("%d ",arr[i]);
     }
     printf("\n");
}

int main()
{ 
    int arr[] = {10,80,30,90,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    printarray(arr,n);
    QuickSort(arr,0,n-1);
    printf("The sorted array is\n");
    printarray(arr,n);
    return 0;
}
