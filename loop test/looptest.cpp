#include <iostream>


int main ()
{

    for (int in=0; in<16; in++) //for loop 16 times.
        {
            std::cout << "in = " << in << "\n";
            
            for (int i=0; i<9; i++) //for loop 9 times
            {
                std::cout << "i = " << i << "\n\n";                
            }
        }

return 0;
}
