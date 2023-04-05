#include <stdio.h>
#include <stdlib.h>

void main() {

    printf("[----- [choi_yoolim] [2020022001] -----]\n");

    int list[5];   // 배열 list 선언
    int *plist[5]; // 배열 포인터 plist 선언
    
    list[0] = 10; // 배열 list의 0번째 요소에 10 대입
    list[1] = 11; // 배열 list의 1번째 요소에 11 대입
    
    plist[0] = (int*)malloc(sizeof(int)); // 동적할당
    
    printf("list[0] \t= %d\n", list[0]);   // 9번째 라인의 결과
    printf("list \t\t= %p\n", list);       // 배열 list의 시작주소 출력
    printf("&list[0] \t= %p\n", &list[0]); // 0번째 요소의 address
    printf("list + 0 \t= %p\n", list+0);   // 16번째 라인과 동일
    printf("list + 1 \t= %p\n", list+1);   // 시작주소로부터 1*(sizeof(int))만큼 떨어짐
    printf("list + 2 \t= %p\n", list+2);   // 시작주소로부터 2*(sizeof(int))만큼 떨어짐
    printf("list + 3 \t= %p\n", list+3);   // 시작주소로부터 3*(sizeof(int))만큼 떨어짐
    printf("list + 4 \t= %p\n", list+4);   // 시작주소로부터 4*(sizeof(int))만큼 떨어짐
    printf("&list[4] \t= %p\n", &list[4]); // 배열 list의 4번째 요소의 address이며 21번째 라인과 동일함
    
    free(plist[0]); // 동적 할당 해제
}