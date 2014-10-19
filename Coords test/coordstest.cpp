#include <iostream>
#include <stdio.h>

int elementsW = 16;
int elementsH = 9;

int pixPerElementW;
int pixPerElementH;

int width;
int height;

int locationX;
int locationY;

int topleft;
int topright;
int bottomleft;
int bottomright;

int main( int argc, char* argv[] )
{

    std::cout << "Enter screen width: ";
    std::cin >> width;
    std::cout << "Enter screen height: ";
    std::cin >> height;
    std::cout << "Enter locaion X: ";
    std::cin >> locationX;
    std::cout << "Enter location Y: ";
    std::cin >> locationY;

    pixPerElementW = (width / elementsW);
    pixPerElementH = (height / elementsH);
    
        
    if (locationY > elementsH)
    {
    std::cout << "locationY is larger than amount of elements.";
    return 0;
    }
    if (locationX > elementsW)
    {
    std::cout << "locationX is larger than amount of elements.";
    return 0 ;
    }
    std::cout << "Screen width: "<< width << "\n";
    std::cout << "Screen height: "<< height << "\n";
    std::cout <<"pixels per element width == " << pixPerElementW << "\n";
    std::cout << "Pixels per element height ==" << pixPerElementH << "\n";
    

    std::cout << "Top left == "<< (width * locationX) << "\n";
    std::cout << "Top right == "<< ((width * locationX) + width) << "\n";
    std::cout << "Bottom left == "<< (height * locationY) <<"\n";
    std::cout << "Bottom right == "<< ((height * locationY) + width) <<"\n";
    return 0;
}
