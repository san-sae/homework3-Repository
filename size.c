#include<stdio.h>
#include<stdlib.h>

void main() {

    printf("[----- [choi_yoolim] [2020022001] -----]\n");
    
    int **x; // double pointer 선언

    printf("sizeof(x) = %lu\n", sizeof(x));     // x에는 *x의 주소값이 저장되어 있으며 1워드(1word)와 동일한 크기임
    printf("sizeof(*x) = %lu\n", sizeof(*x));   // *x에는 **x의 주소값이 저장되어 있으며 1워드(1word)와 동일한 크기임
    printf("sizeof(**x) = %lu\n", sizeof(**x)); // **x에는 값이 저장되어 있으며 int형의 크기와 같음
}