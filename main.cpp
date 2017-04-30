#include <iostream>
#include "variables.h"
#include "functions.h"
#include "graph.h"
#include "memory.h"
#include "exception.h"

using namespace std;

void variablesTest();
void functionsTest();
void graphTest();
void memTest();
void exceptionTest();

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;

    //    variablesTest();
    functionsTest();
    //    memTest();
    //    exceptionTest();
    //    graphTest();

    return 0;
}

void exceptionTest()
{
    Exception e;
}

void memTest()
{
    Memory m;

    m.placementNew();
    m.smartPtr();
    m.mallocTest();
    m.callocTest();
}

void graphTest()
{
    Graph g;

    int **arr = new int*[6];
    arr[0] = new int[6]{ 0, 1, 8, 0, 0, 0 };
    arr[1] = new int[6]{ 1, 0, 2, 0, 20, 0 };
    arr[2] = new int[6]{ 8, 2, 0, 0, 3, 5 };
    arr[3] = new int[6]{ 0, 0, 0, 0, 0, 4 };
    arr[4] = new int[6]{ 0, 20, 3, 0, 0, 3 };
    arr[5] = new int[6]{ 0, 0, 5, 4, 3, 0 };

    g.setGraph(arr, 6);

    int resultSize;
    int *result = g.findWay_deycstra(0, 5, resultSize);

    for(int i = 0; i < resultSize; i++)
        cout << result[i] << " ";
    cout << endl;
}


void functionsTest()
{    
    using namespace function_namespace;

    // создание указателя на объект базового класса. Если деструктор не виртуальный, то не
    // будет вызван деструктор класса-наследника
    Base *f = new Functions();

    int localArg = 5;

    // тут фактические параметры
//    f->func_val(localArg); // передача по значению (копирование аргумента)
//    f->func_link(localArg); // передача по ссылке
//    f->func_pointer(&localArg); // передача по указателю (копирование указателя)

    cout << "localArg " << localArg << endl;

//    function_namespace::Functions::staticFunc();
//    cout << "using friend function " << getPrivateVal(f) << endl;

    f->hello();

    delete f;
}

int Variables::id = 0;
void variablesTest()
{
    extern int globalValue;
    cout << "globalValue (using extern)" << globalValue << endl;

    Variables v;
    for(int i = 0; i < 5; i++)
        v.showValues();

    for(int i = 0; i < 5; i++)
    {
        Variables newVar;
        cout << "new variables id (using static in class)" << Variables::id << endl;
    }
}
