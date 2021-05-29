#include "menu.h"

int getInt() {
    char buf[256];
    char* ret = fgets(buf, sizeof buf, stdin);
    if (ret == NULL)
        return EOF;
    int value = 0;
    sscanf(buf, "%d", &value);
    return value;
}
int getString(char* to, int max){
    char tmp[max + 2];  //\n e \0
    int tmpSize;
    char* buf = fgets(tmp, max+2, stdin);
    if (buf == NULL) {
        printf("Não foi possível ler. O valor anterior não será alterado\n");
        return EOF;
    }
    tmpSize = strlen(tmp);
    tmp[tmpSize - 1] = 0;  //Remove \n
    memcpy(to, tmp, tmpSize);
    return 0;
}