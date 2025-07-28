#include<stdio.h>
struct Heap{
    int *data;
    int size;
};

int getParentIndex(struct Heap * heap ,int currentParentindex )
{
    return (currentParentindex-1)/2;
}

int getLeftChildIndex(struct Heap * heap , int parentIndex)
{
    return (2*parentIndex) + 1;
}

int getRightChildIndex(struct Heap * heap , int parentIndex)
{
    return (2*parentIndex) + 2;
}

void maxHeap(struct Heap *heap , int parentIndex)
{
   int largest = parentIndex;
   int left = getLeftChildIndex(heap , parentIndex);
   int right = getRightChildIndex(heap , parentIndex);

   if(left<heap->size && heap->data[left]>heap->data[largest])
   {
    largest = left;
   }


   if(right<heap->size && heap->data[right]>heap->data[largest])
   {
    largest = right;
   }

   if(largest!=parentIndex)
   {
    int temp = heap->data[parentIndex];
    heap->data[parentIndex] = heap->data[largest];
    heap->data[largest] = temp;

    maxHeap(heap , left);
    maxHeap(heap , right);
   }
}

int main()
{
    int arr[] = {1,2,3,4,5};
    struct Heap heap= {arr , 5};
    for(int i=(heap.size/2)-1;i>=0;i--){
        maxHeap(&heap , 0);}

    for(int i=0;i<5;i++)
    {
        printf("%d  ",heap.data[i]);
    }
    printf("\n");
}
