// Name: Katherine Sandoval
/* This program either inputs a text message and a positive integer K less than 26
   and outputs an encrypted version of the message using shift cipher with key K, or
   inputs a text message encrypted and a positive integer K less than 26 and outputs 
   a decrypted version of the message. */

#include <iostream>
#include <string>
using namespace std;

string encrypted(string, int);
string decrypted(string, int);

int main()
{
	string message;
	int k;
	char userChoice;
	
	// Get user's input
	cout << "Enter your message:" << endl;
	getline(cin, message);
	
	cout << "Enter the key (positive integer less than 26):" << endl;
	cin >> k;

	cout << "To encrypt the message press E, to decrypt the message press D:" << endl;
	cin >> userChoice;
		
	if (userChoice == 'E')
		// Call encrypted function
		cout << "Encrypted version of the message: " << encrypted(message, k) << endl; 
	else if (userChoice == 'D')
		// Call decrypted function
		cout << "Decrypted version of the message: " << decrypted(message, k) << endl; 

	system("pause");
	return 0;
}

string encrypted(string message, int key){
	
	int alpha = 26;

	for (int i = 0; i < message.length(); i++){ // Loop through the entered string
		if(message[i] != ' ')
			if(message[i] >= 'A' && message[i] <= 'Z'){ // Check if the characters is between A and Z    
				 message[i] -= 'A'; // If so, substract 'A' from letter position (1 - 26) in the alphabet
				 message[i] = (message[i] + key) % alpha;  // Apply the shift cipher
				 message[i] += 'A';  // Add 'A' to the result of the shift cipher to get actual character
			} 
	}
	
	return message;  // return encrypted message
}

string decrypted(string message, int key){

	int alpha = 26;

	for (int i = 0; i < message.length(); i++){ // Loop through the entered string
		if(message[i] != ' ')
			if(message[i] >= 'A' && message[i] <= 'Z'){  // Check if the characters is between A and Z
				 message[i] -= 'Z'; // If so, substract 'Z' from letter position (1 - 26) in the alphabet 
				 message[i] = (message[i] - key) % alpha;  // Apply F^-1 shift cipher
				 message[i] += 'Z';  // Add 'Z' to the result of the shift cipher to get actual character
			}
	}

	return message;  // return decrypted message
}