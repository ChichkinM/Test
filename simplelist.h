#ifndef SIMPLELIST_H
#define SIMPLELIST_H


struct Element
{
    int data;
    Element *next;
};

class SimpleList
{

public:
    SimpleList();

    ~SimpleList();
    void push_down(int val);
    void show();
private:
    Element *start;

};

#endif // SIMPLELIST_H
