#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* string_to_binary(char input_str[]) {
    char* binary_str = (char*)malloc(8 * strlen(input_str) + 1);
    if (binary_str == NULL) {
        printf("Memory уккщк.\n");
        exit(1);
    }

    for (int i = 0; i < strlen(input_str); i++) {
        char c = input_str[i];
        for (int j=7;j>=0;j--) {
            binary_str[8 * i + 7 - j] = (c & (1 << j)) ? '1' : '0';
        }
    }
    binary_str[8 * strlen(input_str)] = '\0';

    return binary_str;
}

char* binary_to_hex(char input_str[]) {
    char* hex_str = (char*)malloc(2 * strlen(input_str) + 1);
    if (hex_str == NULL) {
        printf("Memory уккщк.\n");
        exit(1);
    }

    for (int i = 0; i < strlen(input_str); i += 4) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += (input_str[i + j] - '0') << (3 - j);
        }
        if (sum < 10) {
            hex_str[i / 4] = sum + '0';
        } else {
            hex_str[i / 4] = sum - 10 + 'A';
        }
    }
    hex_str[strlen(input_str) / 4] = '\0';

    return hex_str;
}