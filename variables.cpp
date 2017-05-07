#include "variables.h"
#include <iostream>


using namespace std;

int globalValue = 50;


Variables::Variables()
{
    protectedVal = 5;

    id++;
    value = 5;
}

void Variables::arrayChangeVal(int array[2])
{
    array[0] -= 1;
}

void Variables::showValues()
{
    int value = 20;
    static int count = 0;

    if(count == 0)
    {
        cout << "local value " << value << endl;
        cout << "global value (using ::)" << Variables::value << endl; //операция разрешения области действия
    }

    count++;
    cout << "count (using static in function)" << count << endl;
}
