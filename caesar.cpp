#include <iostream>
#include "caesar.h"

char shiftChar(char c, int rshift) {
    if(isalpha(c)) {

        if( c <= 'Z') {

            if(c+rshift > 'Z') {
                rshift -= ('Z'- c) +1;
                c = shiftChar('A', rshift);
            }
            else {
                c += rshift;
            }

        }
        else {

            if(c+rshift > 'z') {
                rshift -= ('z'- c) +1;
                c = shiftChar('a', rshift);
            }
            else {
                c += rshift;
            }
        }
    }

    return c;
}

std::string encryptCaesar(std::string text, int rshift) {

    std::string encrypted;
    for(int i = 0; i< text.size(); i++) {
        encrypted += shiftChar(text[i],rshift);
    }
    return encrypted;
}