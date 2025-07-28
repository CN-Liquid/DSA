#include<stdio.h>

int countingSort(int *list , int sizeList,int exp)
{
    int output[sizeList];
    int digitFrequencyBuffer[10] = {0};
    
    for(int i=0;i<sizeList;i++)
    {
        digitFrequencyBuffer[(list[i]/exp)%10]++;
    }

    for(int i=1;i<10;i++)
    {
        digitFrequencyBuffer[i] +=digitFrequencyBuffer[i-1]; 
    }

    for(int i=sizeList-1;i>=0;i--)
    {
        int digit = (list[i]/exp) %10;
        output[digitFrequencyBuffer[digit]-1] =list[i];
        digitFrequencyBuffer[digit]--; 
    }

    for(int i=0;i<sizeList;i++)
    {
        list[i] = output[i];
    }
}