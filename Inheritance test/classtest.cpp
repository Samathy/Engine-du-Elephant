#include <iostream>

class base
{
    public:
        virtual void method();
};

class A:public base
{
    public:
        virtual void method();
};

void base::method()
{
    std::cout << "base method\n";
}

void A::method()
{
    std::cout << "A method\n";
}


int main()
{
base* array[1];
array[0] = new A;

array[0]->method();

delete array[0];


}
