#include "simplelist.h"

#include <iostream>

using namespace std;

SimpleList::SimpleList()
{
    cout << "create list" << endl;

    start = NULL;
}

SimpleList::~SimpleList()
{
    Element *curEl = start;
    Element *delEl;

    while(curEl->next != NULL)
    {
        delEl = curEl->next;
        curEl->next = delEl->next;

        cout << "delete element" << endl;
        delete delEl;
    }

    delete curEl;
    cout << "delete first element" << endl;

    cout << "delete list" << endl;
}

void SimpleList::push_down(int val)
{
    Element *curEl, *newEl;

    newEl = new Element;

    newEl->data = val;
    newEl->next = NULL;

    if(start != NULL)
    {
        curEl = start;

        while(curEl->next != NULL)
            curEl = curEl->next;

        curEl->next = newEl;
    }
    else
        start = newEl;

}

void SimpleList::show()
{
    Element *el = start;
    while(el != NULL)
    {
        cout << el->data << endl;

        el = el->next;
    }
}
