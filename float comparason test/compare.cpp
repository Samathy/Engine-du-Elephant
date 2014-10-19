#include <iostream>

    float f = -0.5f;
    float b = -0.5f;
    float c = -0.4f;
    float d = -0.4f;



float return_f()
{
    return f;
}

float return_b()
{
    return c;

}

int main ()
{
    int fi = (return_f() * 10);
    int bi = (return_b() * 10);
    std::cout << "bi = " << bi << "\n";
    std::cout << "bi + 1 = " << (bi+1) << "\n";
    std::cout << "fi = " << fi << "\n";
 
    if (fi  == (bi-1) && c == d )
    {
        std::cout << "floats are equal\n";
    }
    else if (f != b || c != d )
    {
        std::cout << "floats are nnot equal\n";
    }

    return 0;

}
