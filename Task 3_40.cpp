#include <iostream>
using namespace std;

//declaring constants
const int alphaSize = 26;
const int a_key= 7;
const int b_key = 9;

//declaring functions 
void affineCipher(const char*messege, char*ciphered);
bool checkItalian(char ch);
char cipherChar(char ch);


int main() {
	//creating arrays of constant size for both the original message and the ciphered one
	const int MAX = 100;
	char message[MAX];
	char ciphered[MAX];
	cout << "Enter a Message: ";
	cin.getline(message, MAX);
	
	//calling the function to cipher the messeage
	affineCipher(message, ciphered);

	//the output
	cout << "Ciphered Message is: ";
	for (int i = 0; ciphered[i] != '\0'; i++) {
		ciphered[i] = toupper(ciphered[i]);
		cout << ciphered[i] ;
	}


	return 0;
}
// The main function to cipher the text
void affineCipher(const char* message, char* ciphered) {
	//this loop stops till it reach the null terminator \0
	// it stores the each ciphered charcter from messege into the array cipher using the function cipherChar
	while (*message) {
		*ciphered = cipherChar(*message);
		*(message)++;
		*(ciphered)++;
	}
	*ciphered = '\0';
}


char cipherChar(char ch) {
	char base;
	if (checkItalian(ch) || ch == ' ') {
		if (ch >= 'a' && ch <= 'z') {
			base = 'a';
		}
		// the space should be ciphered with the letter with number 0
		//  But as I use ASCII code , I set it to the same value of the first letter 
		else if(ch == ' ') {
			ch = 'A';
			base = 'A';
		}
		else {
			base = 'A';
		}
		ch = char((a_key * (ch - base) + b_key ) % alphaSize + base);
		return ch;
	}
	else {
		return ch;
	}

}

//This function checks if the ASCII code of the characters is in the range of upper and lower case english alphabet
// Then, it excludes the letters  j, k, w, x and y, as they are not included in the italian alphapet 
bool checkItalian(char ch) {
	return (ch >= 'A' && ch <= 'Z' && ch != 'J' && ch != 'K' && ch != 'W' && ch != 'X' && ch != 'Y')
		|| (ch >= 'a' && ch <= 'z' && ch != 'j' && ch != 'k' && ch != 'w' && ch != 'x' && ch != 'y');

}