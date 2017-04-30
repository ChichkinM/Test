#include "exception.h"
#include "iostream"
#include <string>

using namespace std;

Exception::Exception()
{
    try
    {
        throw (char)404;
    }
    catch(int e)
    {
        cout << "error code " << e << endl;
    }
    catch (...)
    {
        cout << "error" << endl;
    }
}
