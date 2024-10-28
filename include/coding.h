#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char* xor_binary(char* input_binary, char* secret_binary) {
    char* res_binary = (char*)malloc(strlen(input_binary) + 1);

    for(int i=0;i<strlen(input_binary);i++) {
        res_binary[i] = !(input_binary[i] ^ secret_binary[i%(strlen(secret_binary)-1)]) ? '0' : '1';
    }
    return res_binary;
}