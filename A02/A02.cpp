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

#define CBL 64

char codebook[] = {'Z', 'z', 'Y', 'y', 'X', 'x', 'W', 'w', 'V', 'v', 'U', 'u',
                   'T', 't', 'S', 's', 'R', 'r', 'Q', 'q', 'P', 'p', 'O', 'o',
                   'N', 'n', 'M', 'm', 'L', 'l', 'K', 'k', 'J', 'j', 'I', 'i',
                   'H', 'h', 'G', 'g', 'F', 'f', 'E', 'e', 'D', 'd', 'C', 'c',
                   'B', 'b', 'A', 'a', '9', '8', '7', '6', '5', '4', '3', '2',
                   '1', '0', '#', '!'};

//Todo A2: encrypt using stf::string
void encrypt(string &plaintext, int k);

//Todo A2: decrypt using std::string
void decrypt(std::string &ciphertext, int k);

int main(int argc, char *argv[])
{
  int key;
  string plaintext;
  string ciphertext;

  for (int i = 0; i < argc; i++)
  {
    if (string(argv[i]) == "-p")
    {
      plaintext = argv[i + 1];
    }
    if (string(argv[i]) == "-k")
    {
      key = stoi(argv[i + 1]);
    }
    if (string(argv[i]) == "-c" || string(argv[i]) == "-C")
    {
      ciphertext = argv[i + 1];
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

  cout << "Press enter to exit" << endl;

  cin.get();

  return 0;
}

void encrypt(string &plaintext, int k)
{

  cout << "Encrypt entered, plaintext was: " << plaintext << endl;

  string newString;

  for (int i = 0; i < plaintext.length(); i++)
  {
    for (int j = 0; j < CBL; j++)
    {
      if (plaintext[i] == codebook[j])
      {
        if (j + k > CBL)
        {
          newString += codebook[(j + k) % CBL];
        }
        else
        {
          newString += codebook[j + k];
        }
      }
    }
  }

  cout << "The ciphertext is: " << newString << endl;
  // iterate through plaintext elements
  // for each char, check it's value in codebook by iterating through codebook
  // if char match codebook, take the index value
  // add index value with the key value
  // attach new letter to string
}

void decrypt(string &ciphertext, int k)
{

  cout << "Decrypt entered, ciphertext is: " << ciphertext << endl;

  string newString;

  for (int i = 0; i < ciphertext.length(); i++)
  {
    for (int j = 0; j < CBL; j++)
    {
      if (ciphertext[i] == codebook[j])
      {
        if ((j - k) < 0)
        {
          newString += codebook[(((j - k) % CBL) + CBL)];
        }
        else
        {
          newString += codebook[j - k];
        }
      }
    }
  }

  cout << "The plaintext is: " << newString << endl;
}
