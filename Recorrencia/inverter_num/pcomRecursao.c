#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void reverse_rec(char *array, int i, int f){
    swap(&array[i++], &array[f--]);
}
void reverse(char *array){

}