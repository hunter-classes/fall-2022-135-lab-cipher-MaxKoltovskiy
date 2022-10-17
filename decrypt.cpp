#include <iostream>
#include "decrypt.h"

char deshiftChar(char c, int lshift)
{
    if(isalpha(c)) {

        if( c <= 'Z') {

            if(c-lshift < 'A') {
                lshift -= (c - 'A') +1;
                c = deshiftChar('Z', lshift);
            }
            else {
                c -= lshift;
            }

        }
        else {

            if(c-lshift < 'a') {
                lshift -= (c - 'a') +1;
                c = deshiftChar('z', lshift);
            }
            else {
                c -= lshift;
            }
        }
    }

    return c;
}

std::string decryptCaesar(std::string cipher, int lshift)
{
    std::string decrypted;
    for(int i = 0; i< cipher.size(); i++) {
        decrypted += deshiftChar(cipher[i],lshift);
    }
    return decrypted;
}

std::string decryptVigenere(std::string cipher, std::string keyword)
{
    int keyIndex = 0;
    std::string original;

    for(int i = 0; i < cipher.size(); i++) {
        char deshift;
        char text = cipher[i];

        if(isalpha(text)) {

            char key = keyword[keyIndex];
            deshift = deshiftChar(text, key-'a');
            keyIndex++;
            keyIndex %= keyword.size();
        }
        else {
            deshift = text;
        }

        original += deshift;
    }

    return original;
}