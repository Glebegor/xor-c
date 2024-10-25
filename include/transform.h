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

void change_last_unsigned_element(char win_res[], char input_str[], int i) {
    printf("add /x\n");
    int free_index = 0;
    while (win_res[free_index] != '\0' && free_index < 10000) {
        free_index++;
    }
    win_res[free_index] = '/';
    win_res[free_index + 1] = 'x';
    win_res[free_index + 2] = input_str[i];
    win_res[free_index + 3] = input_str[i+1];
}

void change_last_element(char win_res[], char input_str[], int i) {
    printf("add char from win1250\n");
    int free_index = 0;
    while (win_res[free_index] != '\0' && free_index < 10000) {
        free_index++;
    }
    win_res[free_index] = input_str[i];
    win_res[free_index+1] = input_str[i+1];
}


char* hex_to_win(char input_str[]) {
    char win_res[10000];

    for (int i = 0; i < strlen(input_str)-1; i+=2) {
        if(input_str[i] <= '1') {            
            change_last_unsigned_element(win_res, input_str, &i);
        } else if (input_str[i] == '2' && input_str[i+1] == '0') {
            change_last_unsigned_element(win_res, input_str, &i);
        } else if ((input_str[i] == '7' && input_str[i+1] == 'F') \
            || (input_str[i] == '8' && input_str[i+1] == '1') \
            || (input_str[i] == '8' && input_str[i+1] == '3') \
            || (input_str[i] == '8' && input_str[i+1] == '8') \
            || (input_str[i] == '9' && input_str[i+1] == '8') \
            || (input_str[i] == '9' && input_str[i+1] == '0') \
            || (input_str[i] == 'A' && input_str[i+1] == '0') \
            || (input_str[i] == 'A' && input_str[i+1] == 'D')) {
            // add /x
            change_last_unsigned_element(win_res, input_str, &i);
        } else {
            // add char from win1250
            change_last_element(win_res, input_str, &i); // change on win1250
        }
    }

    return win_res;

}