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
void encrypt(string &plaintext, int k);

//Todo A2: decrypt using std::string
void decrypt(std::string &ciphertext, int k);

int main(int argc, char *argv[])
{
  int key;
  string keystring;
  string plaintext;
  string ciphertext;

  // access argc
  cout << "Argument Count " << argc << endl;

  // access command line arguments
  for (int i = 0; i < argc; i++)
  {
    cout << "argument contents: " << argv[i] << endl;
  }

  for (int i = 0; i < argc; i++)
  {
    if (string(argv[i]) == "-p")
    {
      plaintext = argv[i + 1];
    }
    if (string(argv[i]) == "-k")
    {
      key = stoi(argv[i + 1]);
      // cout << key << endl;
    }
    if (string(argv[i]) == "-c" || string(argv[i]) == "-C")
    {
      ciphertext = argv[i + 1];
      cout << "ciphertext was: " << plaintext << endl;
    }
    if (string(argv[i]) == "-E")
    {
      encrypt(plaintext, key);
    }
    if (string(argv[i]) == "-D")
    {
      decrypt(ciphertext, key);
    }
  }

  return 0;
}

void encrypt(string &plaintext, int k)
{
  cout << "Encrypt entered, plaintext was: " << plaintext << endl;

  string newString;

  for (int i = 0; i < plaintext.length(); i++)
  {
    // cout << "iteration: [" << i << "] " << plaintext[i] << endl;

    int num = (int)plaintext[i];

    // cout << "casted value of char: " << num << endl;

    num = num + k;

    // cout << "New value of char after adding key: " << num << endl;

    char newChar = (char)num;

    // cout << "Converted letter: " << newChar << endl;

    newString += newChar;
  }

  cout << "The ciphertext is: " << newString << endl;
  // iterate through plaintext X
  // each iteration convert char to ascii number X
  // each iteration add the key value to ascii value X
  // each iteration convert ascii value back to char
  // push char value into array
  // return array
}

void decrypt(string &ciphertext, int k)
{
  cout << "Decrypt entered, ciphertext is: " << ciphertext << endl;

  string newString;

  for (int i = 0; i < ciphertext.length(); i++)
  {
    // cout << "iteration: [" << i << "] " << plaintext[i] << endl;

    int num = (int)ciphertext[i];

    // cout << "casted value of char: " << num << endl;

    num = num - k;

    // cout << "New value of char after adding key: " << num << endl;

    char newChar = (char)num;

    // cout << "Converted letter: " << newChar << endl;

    newString += newChar;
  }

  cout << "The plaintext is: " << newString << endl;
  // iterate through ciphertext
  // each iteration convert char to ascii number
  // each iteration subtract the key value to ascii value
  // each iteration convert ascii value back to char
  // push char value into array
  // return array
}