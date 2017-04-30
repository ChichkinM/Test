#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

namespace function_namespace
{

class OtherClass
{
public:
    OtherClass(/*int arg*/) {std::cout << "create other class with arg = " << 5 << std::endl;}
    ~OtherClass() {std::cout << "delete other class" << std::endl;}
};

class Base
{
public:
    Base()
    {
        std::cout << "create base class" << std::endl;
    }

    virtual void hello() {}

    virtual ~Base()
    {
        std::cout << "delete base class" << std::endl;
    }
};

class Functions : public Base, public OtherClass
{
public:
    Functions();
    void func_val(int arg);
    static void staticFunc();
    void func_link(int &arg);
    void func_pointer(int *arg);


    void hello()
    {
        std::cout << "hello from virtual function" << std::endl;
    }

    ~Functions();
private:
    int privateVal = 77;

    friend int getPrivateVal(Functions* f)
    {
        return f->privateVal;
    }
};

}

#endif // FUNCTIONS_H
