

#include <stdio.h>
#include <string.h>

// Encrypt the plaintext using the Vigenère cipher
void encrypt(const char* plaintext, const char* key, char* ciphertext) {
    int textLen = strlen(plaintext);
    int keyLen = strlen(key);
    for (int i = 0; i < textLen; i++) {
        ciphertext[i] = ((plaintext[i] - 'a') + (key[i % keyLen] - 'a')) % 26 + 'a';
    }
    ciphertext[textLen] = '\0';
}

// Decrypt the ciphertext using the Vigenère cipher
void decrypt(const char* ciphertext, const char* key, char* plaintext) {
    int textLen = strlen(ciphertext);
    int keyLen = strlen(key);
    for (int i = 0; i < textLen; i++) {
        plaintext[i] = ((ciphertext[i] - 'a') - (key[i % keyLen] - 'a') + 26) % 26 + 'a';
    }
    plaintext[textLen] = '\0';
}

int main() {
    char key[256];
    char plaintext[256];
    char ciphertext[256];
    char decryptedtext[256];

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    printf("Plaintext: %s\n", plaintext);
    printf("Key: %s\n", key);

    encrypt(plaintext, key, ciphertext);
    printf("Encrypted: %s\n", ciphertext);

    decrypt(ciphertext, key, decryptedtext);
    printf("Decrypted: %s\n", decryptedtext);

    return 0;
}
