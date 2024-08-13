
#include <stdio.h> 
#include <math.h>

// Function to return value of a^b mod P
long long int power(long long int a, long long int b, long long int P) {
    if (b == 1)
        return a;
    else
        return (((long long int)pow(a, b)) % P);
}

// Driver program
int main() {
    long long int P, G, a, b, x, y, ka, kb;

    // Take input for prime number P
    printf("Enter the value of P (prime number): ");
    scanf("%lld", &P);

    // Take input for primitive root G
    printf("Enter the value of G (primitive root for P): ");
    scanf("%lld", &G);

    // Take input for Alice's private key a
    printf("Enter the private key for Alice (a): ");
    scanf("%lld", &a);

    // Take input for Bob's private key b
    printf("Enter the private key for Bob (b): ");
    scanf("%lld", &b);

    printf("\n");
    printf("The value of P: %lld\n", P);
    printf("The value of G: %lld\n\n", G);
    printf("The private key a for Alice: %lld\n", a);
    printf("The private key b for Bob: %lld\n\n", b);

    x = power(G, a, P); // Alice's public key
    y = power(G, b, P); // Bob's public key

    // Generating the secret key after the exchange of keys
    ka = power(y, a, P); // Secret key for Alice
    kb = power(x, b, P); // Secret key for Bob

    printf("Secret key for Alice: %lld\n", ka);
    printf("Secret key for Bob: %lld\n", kb);

    return 0;
}
