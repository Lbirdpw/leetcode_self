#include <stdio.h>

//return parent positon of member iPos
int parent(int iPos)
{
    return iPos / 2;
}

//return the left child postion if member iPos
int leftChild(int iPos)
{
    return 2 * iPos;
}

//return the right child postion if member iPos
int rightChild(int i)
{
    return 2 * i + i;
}

//place member i in the right position if the max heap
void MaxHeapify(int *p, int iHeapSize, int i)
{
    int iLargestInd = i;
    if (2 * i <= iHeapSize && p[2 * i] > p[iLargestInd])
    {
        iLargestInd = 2 * i;
    }
    if (2 * i  + 1 <= iHeapSize && p[2 * i + 1] > p[iLargestInd])
    {
        iLargestInd = 2 * i + 1;
    }
    if (iLargestInd != i)
    {
        int iTmp = p[i];
        p[i] = p[iLargestInd];
        p[iLargestInd] = iTmp;
        MaxHeapify(p, iHeapSize, iLargestInd);
    }
}

//build a max heap
void buildMaxHeap(int *p, int iArraySize)
{
    int iHeapSize = iArraySize - 1;
    for (int i = (iHeapSize) / 2; i >= 1; --i)
    {
        MaxHeapify(p, iHeapSize, i);
    }
}

void printArray(int *p, int iArraySize)
{
    for (int i = 0; i < iArraySize; ++i)
    {
        printf("%d,", p[i]);
    }
    printf("\n");
}

int main()
{
    int iArr[] = {-1, 4, 1, 5, 3, 7, 6};
    int iArrSize = sizeof(iArr) / sizeof (int);
    buildMaxHeap(iArr, iArrSize);
    printArray(iArr, iArrSize);

    return 0;
}
