#include <stdio.h>

typedef struct{
    char name[50];
    char grade;
}student_t;

int main(void){
    student_t stu[2] = {{"Tan",'F'},{"Kim",'B'}};

    func1(stu);
    func2(&stu[1].grade);

    printf("%s %c ", stu[0].name,stu[0].grade);
    printf("%s %c ", stu[1].name,stu[1].grade);

    return 0;
}

void func1(student_t *stu){
    stu->name[0] = 'S';
}

void func2(char *grade){
    *grade += 2;
}
