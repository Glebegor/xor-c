#include <coding.h>
#include <transform.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <filetotable.h>


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
    char *secret_str; 
    char input_str[MAX_INPUT_SIZE];  
    int choice;
    
    secret_str = (char *)malloc(17 * sizeof(char));
    strcpy(secret_str, "BrejchadCZHoodink");
    // Text to encode: "Tohle by jsi neměl číst, jak se ti to vůbec povedlo?"
    choice = get_choice();

    char chars_table = file_to_table();

    if (choice == 1) {
        printf("Enter the string to encode: ");
        if (fgets(input_str, MAX_INPUT_SIZE, stdin) != NULL) {
            // Input data
            input_str[strcspn(input_str, "\n")] = '\0';
            char* input_binary = string_to_binary(chars_table, input_str);
            char* input_hex = binary_to_hex(input_binary);
            
            
            // Secret Data
            char* secret_binary = string_to_binary(chars_table, secret_str);
            char* secret_hex = binary_to_hex(secret_binary);

            // Result data
            char* res_binary = xor_binary(input_binary, secret_binary);
            char* res_hex = binary_to_hex(res_binary);
            char* res_win = hex_to_win(chars_table, res_hex);

            printf("####################\n");
            printf("# Secret String: %s\n", secret_str);
            printf("# Secret Binary: %s\n", secret_binary);
            printf("# Secret Hex:    %s\n", secret_hex);
            printf("# --------------------\n");
            printf("# Input  Binary: %s\n", input_binary);
            printf("# Input  Hex:    %s\n", input_hex);
            printf("# --------------------\n");
            printf("# Result Binary: %s\n", res_binary);
            printf("# Result Hex:    %s\n", res_hex);
            printf("# Result Win:    %s\n", res_win);
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


