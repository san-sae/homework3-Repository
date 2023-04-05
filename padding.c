#include <stdio.h>

struct student {
    char lastName[13]; // 13 bytes
    int studentId;     // 4 bytes
    short grade;       // 2 bytes
};

int main() {

    printf("[----- [choi_yoolim] [2020022001] -----]\n");

    struct student pst;
    
    printf("size of student = %ld\n", sizeof(struct student));
    /* 4bytes 단위로 padding(padding 처리는 compiler마다 다름)
       char형 배열인 lastName는 (4 * 3 + 1)bytes만큼 할당하며 3bytes는 padding 처리
       int형인 studentId는 4bytes 할당(메모리 경계에서 끝나므로 따로 padding 처리 없음)
       short형인 grade는 2bytes 할당하며 메모리 경계에 맞게 끝나야 하므로 2bytes padding 처리 
       => 24(16 + 4 + 4)bytes
    */
    printf("size of int = %ld\n", sizeof(int)); // int 형의 크기는 4bytes
    printf("size of short = %ld\n", sizeof(short)); // short 형의크기는 2bytes
    
    return 0;
}