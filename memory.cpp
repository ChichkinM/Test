#include "memory.h"
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <new>
#include <memory> //auto_ptr

using namespace std;

Memory::Memory()
{

}

void Memory::smartPtr()
{
    auto_ptr<int> i (new int(20));
    cout << *i << endl;
}

void Memory::placementNew()
{
    char *buf  = new char[sizeof(string)]; // выделение памяти
    string *p = new (buf) string("hi");    // иницивализация (вызов конструктора) с использованием placement new
    cout << *p << endl;


    int *n = NULL;
    for(int i = 0; i < 5; i++)
    {
        cout << n << endl;
        if (n != NULL)
        {
            delete n;
            cout << i << " del" << endl;
        }

        n = new int(2);
    }
}

void Memory::mallocTest()
{
    int size = 1024 * 1024 * 1024; //1 гб
    char *buffer = (char*)malloc(size);

    if(buffer != NULL)
    {
        for(int i = 0; i < size; i++)
            buffer[i] = 0xFF;

//        free(buffer);

        sleep(3);

        free(buffer);
    }
    else
        cout << "error" << endl;
}

void Memory::callocTest()
{
    int size = 1024 * 1024 * 1024 / 2;

    char *buffer = (char*)calloc(size, sizeof(char));

    if(buffer != NULL)
    {
        for(int i = 0; i < size; i++)
            buffer[i] = 0xFF;

        sleep(3);

        free(buffer);
    }
    else
        cout << "error" << endl;
}
