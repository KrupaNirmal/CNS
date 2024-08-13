#include <stdio.h>
#include <string.h>

void caesar(char text[], int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = 'a' + (text[i] - 'a' + shift) % 26;
        else if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = 'A' + (text[i] - 'A' + shift) % 26;
    }
}
int main() {
    char message[256];
    int key;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the key: ");
    scanf("%d", &key);

    size_t len = strlen(message);
    if (len > 0 && message[len-1] == '\n') {
        message[len-1] = '\0';
    }

    printf("Original message: %s\n", message);

    // Encryption
    caesar(message, key);
    printf("Encrypted message: %s\n", message);

    // Decryption
    caesar(message, -key);
    printf("Decrypted message: %s\n", message);

    return 0;
}
