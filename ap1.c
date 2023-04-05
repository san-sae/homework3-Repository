#include <stdio.h>
#include <stdlib.h> // malloc() 포함된 헤더파일

void main() {

    printf("[----- [choi_yoolim] [2020022001] -----]\n");
    
    int list[5]; // 값을 저장하기 위한 배열
    int *plist[5] = {NULL,}; // 주소를 저장하기 위한 포인터 배열
    
    plist[0] = (int *)malloc(sizeof(int)); // 4bytes 동적할당
    
    list[0] = 1;   // 배열 list의 0번째 요소에 1(value) 대입 
    list[1] = 100; // 배열 list의 1번째 요소에 100(value) 대입 
    
    *plist[0] = 200; // 포인터 배열의 0번째 요소가 가리키는 address에 200(value) 대입
    
    printf("list[0] = %d\n", list[0]);   // list[0]의 value인 1 출력
    printf("&list[0] = %p\n", &list[0]); // list[0]의 address 0061FF0C 출력
    printf("list = %p\n", list);         // 배열 list의 시작주소인 list[0]의 address와 동일
    printf("&list = %p\n", &list);       // 배열 list의 address
    printf("----------------------------------------\n\n");
    printf("list[1] = %d\n", list[1]);       // list[1]의 value인 100 출력
    printf("&list[1] = %p\n", &list[1]);     // list[0]의 address인 0061FF0C에서 4만큼 떨어진 0061FF10 출력
    printf("*(list+1) = %d\n", *(list + 1)); // list의 시작주소에서 1*sizeof(int)만큼 떨어진 address가 가리키는 value 출력
    printf("list+1 = %p\n", list+1);         // list의 시작주소에서 1*sizeof(int)만큼 떨어진 address 출력
    printf("----------------------------------------\n\n");
    printf("*plist[0] = %d\n", *plist[0]); // 14번째 라인에서 대입한 값 출력
    printf("&plist[0] = %p\n", &plist[0]); // 배열 포인터 plist의 address 출력
    printf("&plist = %p\n", &plist);       // 배열 포인터 plist의 시작주소 출력
    printf("plist = %p\n", plist);         // 28번째 라인과 동일한 값 출력
    printf("plist[0] = %p\n", plist[0]);   // *plist[0]을 찾아갈 수 있는 주소(00891598)
    printf("plist[1] = %p\n", plist[1]);   // 7번째 라인에서 포인터 배열을 null로 초기화함
    printf("plist[2] = %p\n", plist[2]);   // 7번째 라인에서 포인터 배열을 null로 초기화함
    printf("plist[3] = %p\n", plist[3]);   // 7번째 라인에서 포인터 배열을 null로 초기화함
    printf("plist[4] = %p\n", plist[4]);   // 7번째 라인에서 포인터 배열을 null로 초기화함
    
    free(plist[0]); // 동적할당 해제
}
