#ifndef SORT_H
#define SORT_H


class Sort
{
public:
    Sort();

    static void treeSort(int *arr, int size);
private:
    static void sift(int &siftCount, int *arr, int rootIndex, int lastIndex);
};

#endif // SORT_H
