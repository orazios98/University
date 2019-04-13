#include <iostream>
#include <string>
#include <math.h>
#include <typeinfo>
using namespace std;

class A
{
private:
    float x;
    string st;
public:
    A(int *vec, short n)
    {
        float tot=0;
        string temp="";
        for(int i=0; i<n; i++)
        {
            int t=*(vec+i);
            tot=tot+t;
            temp+=(char)t;
        }
        st=temp;
        x=tot/n;
    }
    virtual int f() const=0;
    virtual ostream& put(ostream &stream) const
    {
        stream<<"Class "<<typeid(*this).name()<<" x="<<x<<", st="<<st<<" { ";
        return stream;
    }
protected:
    short getFirstVowel() const
    {
        for(int i=0;i<st.length();i++)
        {
            char c=st[i];
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
            {
                return i;
            }
        }
        return -1;
    }
};

ostream& operator<<(ostream& stream, const A &a)
{
    return a.put(stream);
}

class B : public A
{
private:
    float *values;
    short len;
public:
    B(int *vec, short n):A(vec,n)
    {
        values=new float[n];
        for(int i=0;i<n;i++)
        {
            values[i]=log(*(vec+i));
        }
        len=n;
    }
    int f() const
    {
        float min=*(values);
        for(int i=1;i<len;i++)
        {
            float t=*(values+i);
            if(t<min)
                min=t;
        }
        min+=0.5;
        int r=(int)min;
        return r;
    }
    virtual ostream& put(ostream &stream) const
    {
        A::put(stream);
        stream<<"values=[";
        for(int i=0;i<len;i++)
            stream<<values[i]<<" ";
        stream<<"], len = "<<len<<endl;
        stream<<"\t\tf()="<<f();
        return stream;
    }
};

class C :public A
{
private:
    int i;
public:
    C(int *vec,short n):A(vec,n)
    {
        int r=rand()%n;
        i=vec[r]%50;
    }
    int f() const
    {
        int t=getFirstVowel();
        return t+i;
    }
    bool moreThan(int y)
    {
        if(i>=y)
            return true;
        return false;
    }
    virtual ostream& put(ostream &stream) const
    {
        A::put(stream);
        stream<<"i="<<i<<"}\n";
        stream<<"\t\tf()="<<f();
        return stream;
    }
};

int main()
{
    int const DIM=30;
    srand(111222333);
    A *vett[DIM];
    short l, select;
    int *vec;

    for(int i=0; i<DIM; i++)
    {
        l = rand()%8 + 5;
        select = rand()%2;
        vec = new int[l];

        for(int c=0; c<l; c++)
            vec[c] = 97 + rand()%25;

        if(select)
            vett[i] = new B(vec, l);
        else
            vett[i] = new C(vec, l);
    }
    cout<<"Punto I (visualizzare gli oggetti):"<<endl;
    for(int i=0;i<DIM;i++)
    {
       cout<<i<<") "<<*vett[i]<<endl;
    }
    cout<<"Punto II (minimo, media e massimo dei valori di f()):"<<endl;
    int min=vett[0]->f();
    int max=min;
    float avg=max;
    for(int i=1;i<DIM;i++)
    {
        int t=vett[i]->f();
       if(t<min)
        min=t;
       if(t>max)
        max=t;
       avg+=t;
    }
    avg/=30.0;
    cout<<"min: "<<min<<", max:"<<max<<", avg:"<<avg<<endl;
    cout<<"Punto III (indici degli oggetti per cui moreThan(10) e' true):"<<endl;
    for(int i=0;i<DIM;i++)
    {
       if(typeid(*vett[i])==typeid(C))
       {
           if(((C*)vett[i])->moreThan(10))
            cout<<i<<" ";
       }
    }
    return 0;
}


