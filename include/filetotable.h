#include <stdio.h>

#define TABLE_SIZE 256

typedef struct {
    char binary[9];
    char hex_win[5];
    char unicode[8];
    char windows1250[3];
    char character[2];
} table_element;

void add_element(table_element table[], int index, char binary[], char hex_win[], char unicode[], char windows1250[], char character[]) {
    strcpy(table[index].binary, binary);
    strcpy(table[index].hex_win, hex_win);
    strcpy(table[index].unicode, unicode);
    strcpy(table[index].windows1250, windows1250);
    strcpy(table[index].character, character);
}

void print_table_element(table_element element) {
    printf("Binary: %s\n", element.binary);
    printf("Hex: %s\n", element.hex_win);
    printf("Unicode: %s\n", element.unicode);
    printf("Windows-1250: %s\n", element.windows1250);
    if (element.character[0] == '\0') {
        printf("Character: (system charset)\n");
    } else {
        printf("Character: %s\n", element.character);
    }
}

table_element* file_to_table() {
    char *filename = "win1250.txt";
    FILE *file = fopen(filename, "r");
    table_element table[TABLE_SIZE];

    if (file == NULL) {
        printf("Error when opening file.\n");
        return table;
    } 

    // Binary;Hex;Unicode;Windows-1250;Character
    // 00100001;0x21;U+0021;21;!

    int index = 0;    
    // Buffers for each field in the file
    char binary[9], hex_win[5], unicode[8], windows1250[3], character[2] = {0};  // Initialize character array to zero

    // Skip the header line
    if (fscanf(file, "%*[^\n]\n") == EOF) {
        printf("Error: File is empty or header line is missing.\n");
        fclose(file);
        return table;
    }

    
    // Read each line until the end of file or until maximum entries reached
    while (index < TABLE_SIZE && 
           fscanf(file, "%8[^;];%4[^;];%7[^;];%2[^;];", binary, hex_win, unicode, windows1250) == 4) {
        if (fscanf(file, "%[^\n]\n", character) == 1) {
            if(character[0] == '#' && (hex_win[2] != '2' || hex_win[3] != '3')) {
                character[0] = '\0';
            }
        }

        add_element(table, index, binary, hex_win, unicode, windows1250, character);
        // print_table_element(table[index]); // Uncomment to see the table elements

        index++;
    }

    if (index == 0) {
        printf("Error: No data could be read. Check the file format or content.\n");
    }
    fclose(file);
    printf("Table got successfully.\n");
    return table;
}