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
using namespace std;

//Todo A2: encrypt using stf::string
void encrypt(std::string &plaintext, int k);

//Todo A2: decrypt using std::string
void decrypt(std::string &ciphertext, int k);

int main(int argc, char *argv[])
{
  int key;
  string plaintext;
  string ciphertext;

  // access argc
  cout << "argc = " << argc << endl;

  // access command line arguments
  for (int i = 0; i < argc; i++)
  {
    cout << "argument contents: " << argv[i] << endl;
  }

  // argument list needs to be higher than 5 change later
  if (argc > 1)
  {

    if (string(argv[1]) == "-p")
    {
      cout << "plaintext accessed" << endl;
      // plaintext = string(argv[2]);
      plaintext = argv[2];
      cout << "plaintext was" << plaintext << endl;

      // Get key value

      // run encryption function through the plaintext
      // create new array
      // function iterates through plaintext
      // each letter adds key value
      // push new letter into array
      // ciphertext = newArray
      // return newArray

      // cout << "The ciphertext is: " << ciphertext << endl
    }
    if (string(argv[1]) == "-c")
    {
      cout << "cipher accessed" << endl;
      plaintext = argv[2];
      cout << "ciphertext was" << plaintext << endl;
    }
    if (string(argv[1]) == "-k")
    {
      cout << "key accessed" << endl;
    }
  }

  return 0;
}