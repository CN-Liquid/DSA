#include<stdio.h>

void shellSort(int * list , int sizeList)
{
    int gap = sizeList/2;
    while(gap>0)
    {
        for(int i=gap;i<sizeList;i++)
        {
             int temp = list[i];
            int j = i;
            while (j >= gap && list[j - gap] > temp) {
            list[j] = list[j - gap];
            j -= gap;
            }
            list[j] = temp;
        }
        gap = gap/2;
    }
}

int main()
{
    int list[5] = {2,3,4,5,1};

    shellSort(list , sizeof(list)/sizeof(int));

    for(int i=0;i<5;i++)
    {
        printf("%d  ",list[i]);
    }
    printf("\n");

    return 0 ;
}