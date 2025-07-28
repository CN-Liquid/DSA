#include<stdio.h>

void selectionSort(int* list , int listSize)
{
    for(int i=0;i<listSize-1;i++)
    {
        int min = i;
        for(int j=i;j<listSize;j++)
        {
            if(list[j]<list[min])
            {
                min =j;
            }
        }
        int temp = list[i];
        list[i] = list[min];
        list[min] = temp;
    }
}

int main()
{
    int list[5] = {2,3,4,5,1};

    selectionSort(list , sizeof(list)/sizeof(int));

    for(int i=0;i<5;i++)
    {
        printf("%d  ",list[i]);
    }
    printf("\n");

    return 0 ;
    return 0;
}