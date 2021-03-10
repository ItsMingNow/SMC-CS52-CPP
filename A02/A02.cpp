// Name: Yanming Yu
// SSID: 1748671
// Assignment #: 2
// Submission Date: 3/16/2021
//
// Description: A program to encrypt and decrypt a message using a shift cipher
// The plaintext message must only contain lowercase alpha and digits 0-9
//
// command line arguments
// -p ThePla!Nt#xTM#ss2ge1 - the plaintext (p) message to be encrypted
// -C pC9lG1VjOwSpiwNNXB9x - the cipher (C) text to be decrypted
// -k 9                    - the key (k) shift value
// -E                      - the option to encrypt (E)
// -D                      - the option to decrypt (D)

#include <iostream> //std::cout, std::cin, etc.
#include <cstdlib>  //C++ version of stdlib.h
#include <cstring>  //C++ version of string.h
#include <string>

//Todo A2: encrypt using stf::string
void encrypt(std::string &plaintext, int k);

//Todo A2: decrypt using std::string
void decrypt(std::string &ciphertext, int k);

int main(int argc, char *argv[])
{
}