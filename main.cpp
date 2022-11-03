#include <iostream>
#include "funcs.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"
#include "solve.h"

int main()
{

  std::cout<< "solve(encryptCaesar(\"feels\",5)) == " << solve(encryptCaesar("feels",5)) << "\n";

  std::cout<< "solve(encryptCaesar(\"Way to Go!\",9)) == " << solve(encryptCaesar("Way to Go!",9)) << "\n";

  std::cout<< "solve(encryptCaesar(\"A Light-Year Apart\",24)) == " << solve(encryptCaesar("A Light-Year Apart",24))<< "\n";
}
