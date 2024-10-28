#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <filetotable.h>

char* string_to_binary(table_element char_table[], char input_str[]) {
    
    char* binary_str = (char*)malloc(8 * strlen(input_str) + 1);
    if (binary_str == NULL) {
        printf("Memory error.\n");
        exit(1);
    }

    for(int i=0;i<strlen(input_str);i++) {
        // printf("%c\n", input_str[i]);
        for(int j=0;j<256;j++) {
            if(input_str[i] == char_table[j].character[0]) {
                // printf("%s\n", char_table[j].binary);
                strcat(binary_str, char_table[j].binary);
            }
        }
    }
    return binary_str;
}

char* binary_to_hex(char input_str[]) {
    char* hex_str = (char*)malloc(2 * strlen(input_str) + 1);
    if (hex_str == NULL) {
        printf("Memory error.\n");
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

// Working with Hex to Win
void change_last_unsigned_element(char win_res[], char *input_str, int i) {
    long long free_index = 0;

    while(win_res[free_index] != '\0') {
        free_index++;
    }
    win_res[free_index] = '\\';
    win_res[free_index+1] = 'x';
    win_res[free_index+2] = input_str[i];
    win_res[free_index+3] = input_str[i+1];
}

void change_last_element(table_element *char_table, char win_res[], char *input_str, int i) {
    long long free_index = 0;
    
    while(win_res[free_index] != '\0') {
        free_index++;
    }
    for(int j=0;j<256;j++) {
        if(input_str[i] == char_table[j].windows1250[0] && input_str[i+1] == char_table[j].windows1250[1]) {
            win_res[free_index] = char_table[j].character[0];
            win_res[free_index+1] = '\0';
            break;
        }
    }
}

char* hex_to_win(table_element char_table[], char input_str[]) {
    char win_res[10000] = {0};


    for (int i = 0; i < strlen(input_str)-1; i+=2) {
        
        // Check if char isn't a system command
        if(input_str[i] <= '1') { 
            change_last_unsigned_element(win_res, input_str, i);           
        } else if (input_str[i] == '2' && input_str[i+1] == '0') {
            change_last_unsigned_element(win_res, input_str, i);           
        } else if ((input_str[i] == '7' && input_str[i+1] == 'F') \
            || (input_str[i] == '8' && input_str[i+1] == '1') \
            || (input_str[i] == '8' && input_str[i+1] == '3') \
            || (input_str[i] == '8' && input_str[i+1] == '8') \
            || (input_str[i] == '9' && input_str[i+1] == '8') \
            || (input_str[i] == '9' && input_str[i+1] == '0') \
            || (input_str[i] == 'A' && input_str[i+1] == '0') \
            || (input_str[i] == 'A' && input_str[i+1] == 'D')) {
            change_last_unsigned_element(win_res, input_str, i);           
        } else {
            change_last_element(char_table, win_res, input_str, i);
        }

    }

    return win_res;

}