#include "functions.h"

#include <typeinfo>

using namespace std;
using namespace function_namespace;

Functions::Functions() /*: OtherClass(5)*/
{
    cout << "create function class" << endl;
}

Functions::~Functions()
{
    cout << "delete function class" << endl;
}

// тут формальные параметры
void Functions::func_val(int arg) // передача по значению
{
    cout << "func_val arg " << arg << endl;
}

void Functions::func_link(int &arg) // передача по ссылке
{
    arg++;
    cout << "func_link arg " << arg << endl;
}

void Functions::func_pointer(int *arg) // передача по указателю
{
    (*arg)++; // разыменование
    arg = new int(0); // испортим указатель (для доказательства, что он копируется)
    cout << "func_pointer arg " << *arg << endl;
}


void Functions::staticFunc()
{
    cout << "static function" << endl;
}
