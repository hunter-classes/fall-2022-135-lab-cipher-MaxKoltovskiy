//modify tests to use gcovr
#include <iostream>
#include "caesar.h"
#include "solve.h"
#include <math.h>

std::string solve(std::string encrypted_string)
{
    std::vector< std::vector<double>> rotations;
    std::vector<std::string> possibilities;

    const std::vector<double> ALPHAFREQS{0.082, 0.015, 0.028, 0.043, 0.13, 0.022, 0.02, 0.061, 0.07, 0.0015,
     0.0077, 0.04, 0.024, 0.067, 0.075, 0.019, 0.00095, 0.06, 0.063, 0.091, 0.028, 0.0098, 0.024, 0.0015,
     0.02, 0.00074
    }; 

    std::vector<double> distances;


    for(int i = 0; i< 26; i++) {
        std::vector<double> temp_freqs;
        encrypted_string = encryptCaesar(encrypted_string, 1);

        makeFreqVect(temp_freqs, encrypted_string);
        rotations.push_back(temp_freqs);
        possibilities.push_back(encrypted_string);

        distances.push_back(distanceFormula(rotations[i], ALPHAFREQS));
    }


    int small_index = 0;
    for(int i = 1; i< distances.size(); i++) {
        if(distances[i] < distances[small_index]) {
            small_index = i;
        }
    }

    
    return possibilities[small_index];
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

void makeFreqVect(std::vector<double>& output, std::string encrypt)
{
    
    for(char l = 'a'; l<= 'z'; l++) {
        double freq = countChar(encrypt, l) / encrypt.size();
        output.push_back(freq);
    }
    
}

double distanceFormula(std::vector<double> rots, const std::vector<double> ALPHAFREQS) {
    double dist = 0;
    for(int j = 0; j < rots.size(); j++) {
    
        dist += pow((rots[j] - ALPHAFREQS[j]) , 2);
    }

    return sqrt(dist);
}