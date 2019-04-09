#include <iostream>
#include <fstream>

using namespace std;

template <class F> class Coda
{
private:
    int len, n, tail, head;
    G **v;
public:
    Coda(int len)
    {
        n=0;
        this->len = len;
        v=new G*[len];
        tail = head = 0;
    }

    Coda<G>* enqueue(G*)
    {
        if(n==len) return this;
        v[tail] = new G(x);
        tail++;
        n++;
        return this;
    }

    G dequeue()
    {
        if(n==0) return EMPTY;
        G r = *v[head];
        head++;
        n--;
        return r;
    }

};

int main()
{

    return 0;
}
