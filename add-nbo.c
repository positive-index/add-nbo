#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

uint32_t read_number(char *filename){ //32bit 숫자를 읽어서 반환
        FILE *file = fopen(filename,"rb");
        if (file == NULL){
                printf("fail");
        }

        uint32_t number;
        size_t result = fread(&number,sizeof(number),1,file);
        if(result!=1){
                printf("fail");
                return 0;
        }

        fclose(file);

        return ntohl(number);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Syntax: add-nbo <file1> <file2>\n");
        return 1;
    }

    uint32_t number1 = read_number(argv[1]);
    uint32_t number2 = read_number(argv[2]);
    uint32_t sum = number1 + number2;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", number1, number1, number2, number2, sum, sum);

    return 0;
}                                                                                                                                                                                                  
