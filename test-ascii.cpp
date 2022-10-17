#include <iostream>

int main() 
{
    std::string input;
    std::cout<< "Input: ";
    getline(std::cin, input);

    char c;
    for(int i=0; i<input.size(); i++) {
        c = input[i];
        std::cout<< c << " "<< (int)c<< "\n";
    }

}