#include <stdio.h>

#define TABLE_SIZE 256

void file_to_table() {
    char *filename = "win1250.txt";
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error when opening file.\n");
        return;
    } else {
        printf("File opened successfully.\n");
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
        return;
    }

    
    // Read each line until the end of file or until maximum entries reached
    while (index < TABLE_SIZE && 
           fscanf(file, "%8[^;];%4[^;];%7[^;];%2[^;];", binary, hex_win, unicode, windows1250) == 4) {
        
        // Print each field to verify correct parsing
        printf("Binary: %s\n", binary);
        printf("Hex: %s\n", hex_win);
        printf("Unicode: %s\n", unicode);
        printf("Windows-1250: %s\n", windows1250);

        // Read the character field (including empty)
        if (fscanf(file, "%[^\n]\n", character) == 1) {

            if(character[0] == '#' && (hex_win[2] != '2' || hex_win[3] != '3')) {
                character[0] = '\0';
                printf("Character: (system charset)\n");  // Handle empty character field
            } else {
                printf("Character: %s\n", character);
            }
        }


        index++;
    }

    if (index == 0) {
        printf("Error: No data could be read. Check the file format or content.\n");
    }
    fclose(file);
    printf("File closed successfully.\n");

}