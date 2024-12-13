/*PROGRAM TO IMPLEMENT MERGE SORT*/
/* TO UNDERSTAND OR TO EXPLAIN THE MERGE SORT GO IN THE FOLLOWING ORDER 1,2,3,4 */
/* WHEN I IMPLEMENTED THIS PROGRAM THERE WERE SOME MISTAKES SO IF YOU SEE A COMMENT WHICH SAYS MISTAKE IS WHERE I DID MISTAKE AND RECTIFIED IT */
#include<stdio.h>
/* 4.MERGE FUNCTION*/
void merge(int arr[],int left,int mid, int right)
{
    int i,j,k;
    int n1 = mid - left+1;
    int n2 = right - mid;

    int L[n1],R[n2];
    //COPY THE DATA TO TEMPRORAY ARRAYS L[] AND R[]
    for(i=0;i<n1;i++)
    {
         L[i]=arr[left+i]; // THE LEFT SIDE OF THE SUBARRAY
    }
    for(j=0;j<n2;j++)
    {
         R[j]=arr[mid+1+j]; // THE RIGHT SIDE OF THE SUBARRAY
    }
   //MERGING THE SUB-ARRAYS INTO A SINGLE ARRAY
   i=0;
   j=0;
   k=left;
   while(i<n1 && j<n2) //mistake number 2: wrote if instead of while
   {
     if(L[i]<=R[j])
     {
         arr[k]=L[i];
         i++;
     }
     else
     {
        arr[k]=R[j];
        j++;
     }
     k++;
   }
   //Copy the remaining
   while(i<n1)
    {
      arr[k]=L[i];
      i++;
      k++; //mistake number 1: didn't increment the k
    }
   while(j<n2)
    {
     arr[k]=R[j];
     j++;
     k++;
    }
}
/* END OF THE MERGE FUNCTION 
---------3.MERGE SORT FUNCTION START*/
void mergesort(int arr[],int left,int right)
{
    if(left<right)
    {
         //find the middle part
        int mid = left + (right-left)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
/* END OF THE MERGE SORT FUNCTION
2.PRINTING THE ARRAY FUNCTION{YOU CAN EITHER MAKE IT AS A SEPERATE COMMAND OR YOU CAN INCLUDE IT IN THE MAIN COMMAND}*/
void printArray(int arr[],int size)
{
     for(int i=0;i<size;i++)
     {
         printf("%d ",arr[i]);
     }
}
/* END OF THE PRINTARRAY() FUNCTION
---------1.THE MAIN FUNCTION*/
int main()
{
     int arr[] = {12,11,13,5,6,7};
     int arrsize = (sizeof(arr)/sizeof(arr[0])); //SIZE OF ARRAY = 7{HOW MANY NUMBERS ARE PRESENT IN THE ARRAY:7}/SIZE OF OF SINGLE ELEMENT:1 7/1=7
     printf("Given array is: ");
     printArray(arr,arrsize);
     mergesort(arr,0,arrsize-1); 
     printf("\nThe sorted array is: ");
     printArray(arr,arrsize);
     return 0;
}