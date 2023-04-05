#include <stdio.h>

void print_one(int *ptr, int rows);

int main() {

    printf("[----- [choi_yoolim] [2020022001] -----]\n");

    int one[] = {0, 1, 2, 3, 4}; // 배열 선언

    printf("one = %p\n", one);         // 배열 one의 시작 주소(0061FF0C) 출력
    printf("&one = %p\n", &one);       // 9번째 라인과 동일한 값 출력
    printf("&one[0] = %p\n", &one[0]); // 배열 0번째 요소의 주소 즉, 시작 주소 출력
    printf("\n");

    printf("------------------------------------\n");
    printf(" print_one(&one[0], 5) \n");
    printf("------------------------------------\n");
    print_one(&one[0], 5); // 함수 print_one()에 one[0]의 주소값과 5(value) 전달

    printf("------------------------------------\n");
    printf(" print_one(one, 5) \n");
    printf("------------------------------------\n");
    print_one(one, 5); // 함수 print_one()에 one의 주소값과 5(value) 전달

    return 0;

}

void print_one(int *ptr, int rows) { // ptr는 call-by-reference, rows는 call-by-value 방식으로 parameter 전달받음
    /* print out a one-dimensional array using a pointer */
    int i;
    printf ("Address \t Contents\n");
    for (i = 0; i < rows; i++){ // i가 0부터 (rows-1)까지
                                // rows는 전달받은 값(5)
        printf("%p \t %5d\n", ptr + i, *(ptr + i)); // ptr(address)로부터 i*4bytes(i*sizeof(int))만큼 떨어진 주소 값 출력
                                                    // (ptr + i)가 가리키는 주소에 들어있는 값 출력
    }
    printf("\n");
}