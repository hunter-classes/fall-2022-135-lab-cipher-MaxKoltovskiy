#include <iostream>
#include "funcs.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

int main()
{

  std::cout<< "encryptCaesar(""Way to Go!"", 5) == " << encryptCaesar("Way to Go!", 5)<< "\n";

  std::cout<< "encryptVigenere(""PlainText"", ""key"") == " << encryptVigenere("PlainText", "key")<< "\n";

  std::cout<< "decryptCaesar(""F Qnlmy-Djfw Fufwy"", 5) == " << decryptCaesar("F Qnlmy-Djfw Fufwy", 5)<< "\n";

  std::cout<< "decryptVigenere(""Gew pc Xr!"", keyword) == " << decryptVigenere("Gew pc Xr!", "keyword")<< "\n";
  
}
