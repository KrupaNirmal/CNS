#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/aes.h>

#define AES_KEY_SIZE 128 // AES key size in bits
#define AES_BLOCK_SIZE 16 // AES block size in bytes

unsigned char aes_key[AES_KEY_SIZE / 8] = "0123456789abcdef"; // AES key (16 bytes)

void aes_encrypt(const unsigned char *plaintext, unsigned char *ciphertext) {
    AES_KEY key;
    AES_set_encrypt_key(aes_key, AES_KEY_SIZE, &key);
    AES_encrypt(plaintext, ciphertext, &key);
}

void aes_decrypt(const unsigned char *ciphertext, unsigned char *plaintext) {
    AES_KEY key;
    AES_set_decrypt_key(aes_key, AES_KEY_SIZE, &key);
    AES_decrypt(ciphertext, plaintext, &key);
}

int main() {
    unsigned char plaintext[AES_BLOCK_SIZE] = "welcome to ISE"; // Must be 16 bytes
    unsigned char ciphertext[AES_BLOCK_SIZE];
    unsigned char decryptedtext[AES_BLOCK_SIZE];

    // Ensure plaintext length is 16 bytes
    if (strlen((char *)plaintext) > AES_BLOCK_SIZE) {
        printf("Plaintext is too long!\n");
        return 1;
    }
    // Pad plaintext with spaces if it's shorter than 16 bytes
    size_t pad_len = AES_BLOCK_SIZE - strlen((char *)plaintext);
    memset(plaintext + strlen((char *)plaintext), ' ', pad_len);

    aes_encrypt(plaintext, ciphertext);

    printf("Original message: %s\n", plaintext);
    printf("Encrypted message: ");
    for (int i = 0; i < AES_BLOCK_SIZE; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    aes_decrypt(ciphertext, decryptedtext);

    // Remove padding from decrypted text
    for (int i = AES_BLOCK_SIZE - 1; i >= 0; i--) {
        if (decryptedtext[i] != ' ') {
            decryptedtext[i + 1] = '\0';
            break;
        }
    }

    printf("Decrypted message: %s\n", decryptedtext);

    return 0;
}
