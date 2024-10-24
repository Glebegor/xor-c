#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_MAP_SIZE 256 // Size of the win 1250 table

// 00000000;0x00;U+0000;00; type

// Lib contains 2 hashmaps, 1 - for charset, 2 - for hex

typedef struct charset_info {
    int *binary; // 00000000
    char *hex; // 0x00
    char *unicode; // U+0000
} charset_info;

// Hashmaps

typedef struct {
    charset_info* buckets[HASH_MAP_SIZE];
} hashmap_charset;

// hashmap_charset functions
unsigned int hash_charset(char *charset_key) {
    unsigned int hash_val = 0;
    for(int i=0;charset_key[i]!='\0';i++) {
        hash_val += charset_key[i];
        hash_val *= 31;
    }
    return hash_val % HASH_MAP_SIZE;
}

