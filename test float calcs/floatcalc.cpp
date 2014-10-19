#include <iostream>

float array[20][20][1][1];

int main()
{
array[1][1][1] = -1.0f;
array[1][1][1][1] = 0.9f;
std::cout << "First grid element top left == " << array[1][1][1] << "\n\n";
std::cout << "First grid element bottom left == " << array[1][1][1][1] << "\n\n";
std::cout << "calculated that the top right == " << (array[1][1][1] - 0.1f) << " (that should say 0.9)\n\n";
std::cout << "Calculated that the bottom right == " << (array[1][1][1][1] - 0.1f) << " (that should say 0.8)\n\n";

return 0;


}
