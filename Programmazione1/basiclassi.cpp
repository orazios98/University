#include <iostream>
#include <string>
#include <math.h>
#include <typeinfo>
using namespace std;

class A
{
private:

protected:
    
public:
    A()
    {

    }


    virtual ostream& put(ostream &stream) const
    {
        stream<<"Class "<<typeid(*this).name();
        return stream;
    }

};


ostream& operator<<(ostream& stream, const A &a)
{
    return a.put(stream);
}

class B:public A
{
private:
    
public:
    B():A()
    {

    }

    virtual ostream& put(ostream &stream) const
    {
        A::put(stream);

        return stream;
    }

};



class C:public A
{
private:
    
public:
    C():A()
    {

    }

    virtual ostream& put(ostream &stream) const
    {
        A::put(stream);

        return stream;
    }
};


int main()
{
    int const DIM=  ;


    
    return 0;
}