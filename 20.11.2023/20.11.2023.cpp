#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

void caesarCipher(FILE* inputFile, FILE* outputFile, int shift) {
    char ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            fputc('a' + (ch - 'a' + shift) % 26, outputFile);
        }
        else if (ch >= 'A' && ch <= 'Z') {
            fputc('A' + (ch - 'A' + shift) % 26, outputFile);
        }
        else {
            fputc(ch, outputFile);
        }
    }
}

int main() {
    const char* inputFile = "CaesarCipher.txt";
    const char* outputFile = "EncryptedFile.txt";
    int shift = 3;

    FILE* input = fopen(inputFile, "r");
    FILE* output = fopen(outputFile, "w");

    if (!input || !output) {
        printf("Ошибка при открытии файла.\n");
        return 1;
    }

    caesarCipher(input, output, shift);

        fclose(input);
        fclose(output);
    

    return 0;
}