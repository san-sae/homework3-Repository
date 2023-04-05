#include <stdio.h>

struct student1 { // 구조체 이름 student1
/* struct 데이터 타입 생성할 때 typedef 키워드 없다면
   변수 선언 시 struct 키워드 있어야 함
*/
    char lastName; // 구조체 멤버1
    int studentId; // 구조체 멤버2
    char grade;    // 구조체 멤버3
};

typedef struct { // 구조체 이름 student2
/* struct 데이터 타입 생성할 때 typedef 키워드 사용하면
   변수 선언 시 struct 키워드 사용하지 않음
*/  
    char lastName; // 구조체 멤버1
    int studentId; // 구조체 멤버2
    char grade;    // 구조체 멤버3
} student2;

int main() {

    printf("[----- [choi_yoolim] [2020022001] -----]\n");

    struct student1 st1 = {'A', 100, 'A'}; // 변수 선언(4번째 라인 참고)
    
    // 멤버연산자 .를 사용하여 구조체 멤버에 접근
    printf("st1.lastName = %c\n", st1.lastName);   // 'A' 출력
    printf("st1.studentId = %d\n", st1.studentId); // 100 출력
    printf("st1.grade = %c\n", st1.grade);         // 'A' 출력
    
    student2 st2 = {'B', 200, 'B'}; // 변수 선언(13번째 라인 참고)
    
    // 멤버연산자 .를 사용하여 구조체 멤버에 접근
    printf("\nst2.lastName = %c\n", st2.lastName); // 'B' 출력
    printf("st2.studentId = %d\n", st2.studentId); // 200 출력
    printf("st2.grade = %c\n", st2.grade);         // 'B' 출력

    student2 st3; // 변수 선언
    
    st3 = st2; // st2를 st3에 복사
    
    printf("\nst3.lastName = %c\n", st3.lastName); // 33번째 라인과 동일
    printf("st3.studentId = %d\n", st3.studentId); // 34번째 라인과 동일
    printf("st3.grade = %c\n", st3.grade);         // 35번째 라인과 동일

    /* equality test */
    /* now working */
    if(st3.lastName!=st2.lastName){ // 첫번째 멤버 비교한 결과 다를 경우
        printf("not equal\n");
    }
    else if(st3.studentId!=st2.studentId){ // 두번째 멤버 비교한 결과 다를 경우
        printf("not equal\n");
    }
    else if(st3.grade!=st2.grade){ // 세번째 멤버 비교한 결과 다를 경우
        printf("not equal\n");
    }
    else{ // 모든 멤버가 동일한 경우
        printf("equal\n");
    }

    return 0;
}