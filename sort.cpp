#include "sort.h"
#include <iostream>

using namespace std;

Sort::Sort()
{

}

void Sort::treeSort(int *arr, int size)
{
    int siftCount = 0;

    //первоначальное формирование
    for(int i = (size - 1) / 2; i >= 0; i--)
        sift(siftCount, arr, i, size - 1);

    //перемещение большего (нулевого) эл-та в конец и просеивание для нулевого элемента
    for(int i = size - 1; i > 0; i--)
    {
        int copy = arr[0];
        arr[0] = arr[i];
        arr[i] = copy;

        sift(siftCount, arr, 0, i - 1);
    }

    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl << "working cycles = " << siftCount << endl << endl;
}

//возможно улучшение, если не менять элементы местами, рекурсивно проверяя новое положение,
//а в while искать новое положение для заданного элемента, при необходимости перемещая дочерние узлы,
//и только после этого производить копирование
void Sort::sift(int &siftCount, int *arr, int rootIndex, int lastIndex)
{
    int leftIndex = rootIndex * 2 + 1;
    int rightIndex = rootIndex * 2 + 2;
    int maxChildrenIndex;
    bool childrenExist = true;

    if(rightIndex <= lastIndex)
        maxChildrenIndex = arr[leftIndex] > arr[rightIndex] ? leftIndex : rightIndex;
    else
        if(leftIndex == lastIndex)
            maxChildrenIndex = leftIndex;
        else
            childrenExist = false;

    if(childrenExist && arr[rootIndex] < arr[maxChildrenIndex])
    {
        int copy = arr[rootIndex];
        arr[rootIndex] = arr[maxChildrenIndex];
        arr[maxChildrenIndex] = copy;

        sift(siftCount, arr, maxChildrenIndex, lastIndex);
    }

    if(childrenExist)
        siftCount++;
}
