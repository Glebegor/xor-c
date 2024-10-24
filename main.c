#include <hash_maps.h>
#include <decoding.h>
#include <encoding.h>

int main() {
    char *str,choise;

    str = "BrejchaDCZHoodik";
    
    printf("Enter your choise: ");
    scanf("%s", choise); 

    if(choise == '1') {

    } else if(choise == '2') {

    } else{
        printf("Invalid choise\n");
        main();
    }

    return 0;
}