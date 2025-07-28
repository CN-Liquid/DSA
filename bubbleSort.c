#include<stdio.h>

void bubbleSort(int * list , int size)
{
    for(int i=0 ; i<size-1;i++)
    {
        for(int j=0;j<size-1-i;j++)
        {
            if(list[j] > list[j])
            {
                int temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}



int main()
{
    int list[5] = {2,3,4,5,1};

    bubbleSort(list , sizeof(list)/sizeof(int));

    for(int i=0;i<5;i++)
    {
        printf("%d  ",list[i]);
    }
    printf("\n");

    return 0 ;
}