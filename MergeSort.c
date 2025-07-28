#include<stdio.h>


void merge(int *subList1 , int sizeSubList1 , int* subList2 , int sizeSubList2 , int * parentArray , int sizeParentArray){

    int left = 0;
    int right = 0;
    int parent = 0;

    while(left<sizeSubList1 && right<sizeSubList2)
    {
        if(subList1[left]<subList2[right])
        {
            parentArray[parent] = subList1[left];
            parent++;
            left++;
        }
        else{
            parentArray[parent] = subList2[right];
            parent++;
            right++;
        }
    }

    while(right<sizeSubList2)
    {
        parentArray[parent] = subList2[right];
        parent++;
        right++;
    }

    while(left<sizeSubList1)
    {
        parentArray[parent] = subList1[left];
        parent++;
        left++;
    }

}
void mergeSort(int * list , int listSize)
{
    if(listSize<=1)
    {
        return;
    }

    int middle = listSize/2;

    int subList1[middle];
    int subList2[listSize - middle];

    for(int i=0;i<middle;i++)
    {
        subList1[i]=list[i];
    }

    for(int j=0;j<listSize-middle;j++)
    {
        subList2[j]=list[j+middle];
    }

    mergeSort(subList1,sizeof(subList1)/sizeof(int));
    mergeSort(subList2,sizeof(subList2)/sizeof(int));

    merge(subList1,sizeof(subList1)/sizeof(int),subList2,sizeof(subList2)/sizeof(int),list,listSize);
}