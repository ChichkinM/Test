#ifndef VARIABLES_H
#define VARIABLES_H

class ProtectedTest
{
protected:
    int protectedVal;

private:
    int privateVal;
};

class Variables : private ProtectedTest
{
public:
    Variables();

    int value;
    void showValues();

    static int id;
    void arrayChangeVal(int array[]);
};

#endif // VARIABLES_H
