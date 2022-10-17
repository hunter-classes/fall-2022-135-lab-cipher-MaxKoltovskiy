#include <iostream>
#include "vigenere.h"
#include "caesar.h"

std::string encryptVigenere(std::string original, std::string keyword) 
{
    int keyIndex = 0;
    std::string result;

    for(int i = 0; i < original.size(); i++) {
        char shift;
        char text = original[i];

        if(isalpha(text)) {

            char key = keyword[keyIndex];
            shift = shiftChar(text, key-'a');
            keyIndex++;
            keyIndex %= keyword.size();
        }
        else {
            shift = text;
        }

        result += shift;
    }

    return result;
}