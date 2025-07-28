#include<stdio.h>

void quickSort(int *list , int sizeList )
{
    int pivot = sizeList-1;
    if(sizeList<=1)
    {
        return;
    }

    for(int i=0;i<pivot;i++)
    {
        if(list[i]>list[pivot])
        {
            int temp = list[i];
            list[i] = list[pivot-1];
            list[pivot - 1] = temp;

            temp = list[pivot - 1];
            list[pivot-1] = list[pivot];
            list[pivot] = temp;

            pivot--;

            i=-1;

        }
    }
    quickSort(list , pivot );
    quickSort(list+pivot+1 , sizeList-pivot-1 );
}

int main()
{
    int list[10] = {2,3,3,6,9,2,1,4,5,1};

    quickSort(list , sizeof(list)/sizeof(int));

    for(int i=0;i<10;i++)
    {
        printf("%d  ",list[i]);
    }
    printf("\n");

    return 0 ;
}