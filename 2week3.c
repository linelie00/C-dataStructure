#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5

// 학생 구조체 선언
struct Student {
    int id;
    char name[10];
    float marks;
};


// 학생 정보 입력 함수
void inputStudentData(struct Student *s) {
    scanf("%d", &s->id);
    scanf("%s", &s->name);
    scanf("%f", &s->marks);
}

// 학생 상세 정보 출력 함수
void displayStudentData(const struct Student *s) {
    printf("Student_Number: %d\n", s->id);
    printf("Name: %s\n", s->name);
    printf("Marks: %.2f\n\n", s->marks);
}

// 학생 점수 평균 계산 함수
float calculateAverageMarks(const struct Student *students, int numStudents) {
    float sum = 0;
    for(int i = 0; i < numStudents; i++) {
        sum += students[i].marks;
    }
    return sum/(float)numStudents;
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents;

    scanf("%d", &numStudents);

    // 학생 정보 입력
    for(int i=0; i<numStudents; i++) {
        inputStudentData(students+i);
    }

    // 학생 상세 정보 출력
    for(int i=0; i<numStudents; i++) {
        printf("Details for Student %d:\n", i+1);
        displayStudentData(students+i);
    }

    // 학생들의 점수 평균 계산
    float average = calculateAverageMarks(students, numStudents);
    printf("Average Marks of students: %.2f\n", average);

    return 0;
}