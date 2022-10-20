//modify tests to use gcovr
#include <iostream>
#include "solve.h"
#include <vector>
#include "caesar.h"

std::string solve(std::string encrypted_string)
{
    const int ALPHA_SIZE = 26;
    std::vector< std::vector<double>> rotations;

    for(int i = 0; i< ALPHA_SIZE; i++) {
        std::vector<double> temp_freqs;
        encrypted_string = encryptCaesar(encrypted_string, 1);

        for(char l = 'a'; l<= 'z'; l++) {
            double freq = countChar(encrypted_string, l) / encrypted_string.size();
            temp_freqs.push_back(freq);
        }
        
        rotations.push_back(temp_freqs);
    }


}

double countChar(std::string text, char c)
{
    double count = 0;
    for(int i = 0; i< text.size(); i++) {
        if(text[i] == c) {
            count++;
        }
    }

    return count;
}
