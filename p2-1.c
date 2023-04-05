#include <stdio.h>

#define MAX_SIZE 100

float sum1(float list[], int);
float sum2(float *list, int);
float sum3(int n, float *list);

float input[MAX_SIZE], answer;
int i;

void main(void) {

    printf("[----- [choi_yoolim] [2020022001] -----]\n");

    for(i=0; i < MAX_SIZE; i++){ // 0~99까지
        input[i] = i; // i번째 배열에 i 대입
    }
        
    /* for checking call by reference */
    printf("--------------------------------------\n");
    printf(" sum1(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input); // 배열의 이름은 주소를 의미함(004070A0)
    
    answer = sum1(input, MAX_SIZE); // 함수 sum1의 반환값을 answer에 대입
    printf("The sum is: %f\n\n", answer); // answer 값 출력
    
    printf("--------------------------------------\n");
    printf(" sum2(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input); // 22번째 라인과 동일
    
    answer = sum2(input, MAX_SIZE); // 함수 sum2의 반환값을 answer에 대입
    printf("The sum is: %f\n\n", answer); // answer 값 출력
    
    printf("--------------------------------------\n");
    printf(" sum3(MAX_SIZE, input) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input); // 22번째 라인과 동일
    
    answer = sum3(MAX_SIZE, input); // 함수 sum3의 반환값을 answer에 대입
    printf("The sum is: %f\n\n", answer); // answer 값 출력

}

float sum1(float list[], int n){
    /* 첫 번째 parameter : list는 call-by-reference 방식으로 argument의 주소를 받아 그 배열에 접근
       두 번째 parameter : n은 call-by-value 방식을 통해 변수 n의 값을 그대로 복사
    */
    printf("list \t= %p\n", list);     // argument인 input의 시작 주소와 동일(22번째 라인과 동일)
    printf("&list \t= %p\n\n", &list); // 함수를 호출하며 parameter가 위치한 주소(0061FF00)

    int i;
    float tempsum = 0;
    for(i=0; i<n; i++){ // 0 ~ 99까지
        tempsum += list[i]; // 배열 list의 i번째 요소의 값을 tempsum에 누적
    }
    return tempsum; // tempsum 값을 반환
}

float sum2(float *list, int n){
    /* 첫 번째 parameter : list는 call-by-reference 방식을 통해 argument의 주소를 받아 접근
       두 번째 parameter : n은 call-by-value 방식을 통해 변수 n의 값을 그대로 복사
    */
    printf("list \t= %p\n", list);     // argument인 *input의 주소와 동일(22번째 라인과 동일)
    printf("&list \t= %p\n\n", &list); // 함수를 호출하며 parameter가 쌓인 곳의 주소(0061FF00)

    int i;
    float tempsum = 0;
    for(i=0; i<n; i++){
        tempsum += *(list+i);
        // list의 시작 주소로부터 i*(sizeof(float))만큼 떨어진 주소가 가리키는 값을 tempsum에 누적
    }
    return tempsum;
}

/* stack variable reuse test */
float sum3(int n, float *list){
    /* sum2의 argument 순서 바꾼 결과
    */
    printf("list \t= %p\n", list);     // 22번째 라인과 동일
    printf("&list \t= %p\n\n", &list);
    /* argument는 stack의 높은 주소에서부터 메모리 할당을 받는다.
       그 결과 sum2와 달리 list에 들어간 주소값이 먼저 높은 주소에 할당되어
       sum2의 list(0061FF00)보다 4bytes 높은 자리의 주소값 할당 받음(0061FF04) 
    */
   
    int i;
    float tempsum = 0;
    for(i=0; i<n; i++){
        tempsum += *(list+i);
    }
    return tempsum;
}

