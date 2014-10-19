#include <iostream>
#include <stdint.h>




int main (int argc, char* argv[] )
    {
        int packed_colour;
        int in;
        uint8_t  R;
        uint8_t  G;
        uint8_t B;
        uint8_t ALPHA;
        uint32_t R2;
        uint32_t G2;
        uint32_t B2;
        uint32_t ALPHA2;
        
        std::cout << "Enter numbers when prompted\n";
        std::cout << "Red: ";
        std::cin >> in;
        R = in;
        std::cout << "Green: ";
        std::cin >> in;
        G = in;
        std::cout << "Blue: ";
        std::cin >> in;
         B = in;
        std::cout << "ALPHA: ";
        std::cin >> in;
        ALPHA = in;
        
        std::cout << "Bit shifting numbers...\n";

        
//        (R << 12); //move data 12 bits to the left.
//        (G << 8); //move data 8 bits to the left.
//        (B << 4);
        
        std::cout << "Red = " << static_cast<int16_t>(R) <<"\nGreen = " << static_cast<int16_t>(G) << "\nBlue = " << static_cast<int16_t>(B) << "\nALPHA = " << static_cast<int16_t>(ALPHA) << "\n\n" ;
        std::cout << "Packing colour...";
        packed_colour = ( R << 24) | (G << 16) | (B << 8) | ALPHA;
        std::cout << "colours have been packed.\n\n";
        std::cout << "packed colour == " << packed_colour << "\n\n";
        
        std::cout << "Unpacking data...\n\n";
        
        ALPHA2 = (packed_colour & 0xFF);
        B2 = (packed_colour >> 8 )& 0xFF;
        G2 = (packed_colour >> 16 ) & 0xFF;
        R2 = (packed_colour >> 24);
        
        std::cout << "Done unpacking.\n\nFinal values are:\n"; 
        std::cout << "Red2 = " << static_cast<int32_t>(R2) <<"\nGreen2 = " << static_cast<int32_t>(G2) << "\nBlue2 = " << static_cast<int32_t>(B2) << "\nALPHA2 = " << static_cast<int32_t>(ALPHA2) << "\n\n" ;
        
return 0;
    }