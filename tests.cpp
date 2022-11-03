#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"
#include "solve.h"

// add your tests here
TEST_CASE("Shift Char"){
    CHECK(shiftChar('W', 5) == 'B');
    CHECK(shiftChar('A',10) == 'K');
    CHECK(shiftChar('A',30) == 'E');
    CHECK(shiftChar('x', 10) == 'h');
    CHECK(shiftChar('b',5) == 'g');
    CHECK(shiftChar(' ',5) == ' ');
    CHECK(shiftChar(';',10) == ';');
}
TEST_CASE("Encrypt Caesar"){
    CHECK(encryptCaesar("A Light-Year Apart", 5) == "F Qnlmy-Djfw Fufwy");
    CHECK(encryptCaesar("H",2) == "J");
}
TEST_CASE("Encrypt Vigenere"){
    CHECK(encryptVigenere("Hello, World!", "cake") == "Jevpq, Wyvnd!");
    CHECK(encryptVigenere("ABCD","z") == "ZABC");
}
TEST_CASE("Deshift Char"){
    CHECK(deshiftChar('B',5) == 'W');
    CHECK(deshiftChar('K',10) == 'A');
    CHECK(deshiftChar('E',30) == 'A');
    CHECK(deshiftChar('h', 10) == 'x');
    CHECK(deshiftChar('g',5) == 'b');
    CHECK(deshiftChar(' ',5) == ' ');
    CHECK(deshiftChar(';',10) == ';');

}
TEST_CASE("Decrypt Caesar"){
    CHECK(decryptCaesar("Rovvy, Gybvn!",10) == "Hello, World!");
    CHECK(decryptCaesar("J",2) == "H");
}
TEST_CASE("Decrypt Vigenere"){
    CHECK(decryptVigenere("Jevpq, Wyvnd!", "cake") == "Hello, World!");
    CHECK(decryptVigenere("ZABC","z") == "ABCD");
}
TEST_CASE("Solve Caesar Cipher"){
    CHECK(solve("F Qnlmy-Djfw Fufwy") == "A Light-Year Apart");
    CHECK(solve("Bfd yt Lt!") == "Way to Go!");
}