#include<stdio.h>
#include <math.h>

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

int countDigits(int n) {
    if (n == 0)
        return 1;
    return (int)log10(n) + 1;
}

void radixSort(int * list , int sizeList)
{
    int maxDigits = 0;
    for(int i=0;i<sizeList;i++)
    {
        int digits = countDigits(list[i]);
        if(digits > maxDigits)
        {
            maxDigits = digits;
        }
    }

    for(int i =1 ; maxDigits/i >0;i=i*10)
    {
        countingSort(list,sizeList,i);
    }


}

int main()
{
    int list[5] = {2,3,4,5,1};

    radixSort(list , sizeof(list)/sizeof(int));

    for(int i=0;i<5;i++)
    {
        printf("%d  ",list[i]);
    }
    printf("\n");

    return 0 ;
}