#include <hash_maps.h>
#include <decoding.h>
#include <encoding.h>
#include <transform.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 10000  // max input

int get_choice() {
    int choice;
    printf("Enter your choice (1 - encode, 2 - decode): ");
    if (scanf("%d", &choice) != 1) { 
        printf("Invalid input. Please enter a number.\n");
        return 1;
    }
    while (getchar() != '\n');

    return choice;
}

int main() {
    char secret_str[16] = "BrejchaDCZHoodik"; 
    char input_str[MAX_INPUT_SIZE];  
    int choice;

    choice = get_choice();

    if (choice == 1) {
        printf("Enter the string to encode: ");
        if (fgets(input_str, MAX_INPUT_SIZE, stdin) != NULL) {
            input_str[strcspn(input_str, "\n")] = '\0';
            char* input_binary = string_to_binary(input_str);
            char* input_hex = binary_to_hex(input_binary);
            
            printf("####################\n");
            printf("Input binary: %s\n", input_binary);
            printf("Input Hex: %s\n", input_hex);
            printf("####################\n");

        }
    } else if (choice == 2) {
        printf("Enter the string to decode: ");
        if (fgets(input_str, MAX_INPUT_SIZE, stdin) != NULL) {
            input_str[strcspn(input_str, "\n")] = '\0';

        }
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
