// Aidan Conahan
// Algorithms HW3.cpp : 
// 11/12/18

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int p = 11;
	int q = 29;					//Alice's 2 prime numbers
	int e = 17;					//Alice's random number
	int d;

	int n = p * q;				//Two primes multiplied
	int Φ = ((p - 1)*(q - 1));	//Euler's totient function


	cout << "Prime #1: " << p << "\n";
	cout << "Prime #2: " << q << "\n";
	cout << "Product of Primes: " << n << "\n";
	cout << "Euler's Function Phi(n): " << Φ << "\n";
	cout << "Random #: " << e << "\n";

	for(d = 1; d < n - 1; d++) {
		if (((d * e) % Φ) == 1)	//Brute force to find unique interger d
			break;
	}

	cout << "Secret Integer: " << d << "\n";


	int M = 31;					//Bob's cleartext
	cout << "Bob's Cleartext: " << M << "\n";


	int C = 1, W = 1;

	for (int x = e; x > 0; x=x>>1) {
		if (x % 2 == 1) 		//Encryption 
			C = (C * M) % n;	//Fast Modular for C = (M^e) % n;	
			M = (M * M) % n;	
		
	}		
	cout << "Encrypted Value: " << C << "\n";

	for (int x = d; x > 0; x=x>>1) {
		if (x % 2 == 1) 		//Decryption
			W = (W * C) % n;	//Fast Modular for W = (C^d) % n;
			C = (C * C) % n;
		
	}
	cout << "Decrypted Value: " << W << "\n\n";
	
	system("PAUSE");
    return 0;
}

/*
OUTPUT:

Prime #1: 11
Prime #2: 29
Product of Primes: 319
Euler's Function Phi(n): 280
Random #: 17
Secret Integer: 33
Bob's Cleartext: 31
Encrypted Value: 224
Decrypted Value: 31

Press any key to continue . . .

*/

