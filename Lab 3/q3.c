#include <stdio.h>

typedef struct {
    char name[50];
    int roll_no;
    float marks;
} student;

void read(student *students, int n){
    for (int i = 0; i < n; i++) {
        printf("Enter the name of the student: ");
        scanf("%s", &students[i].name);
        printf("Enter student roll number: ");
        scanf("%d", &students[i].roll_no);
        printf("Enter marks of student: ");
        scanf(" %f", &students[i].marks);
        printf("\n");
    }
}

void display(student *students, int n){
    printf("\n_______STUDENT DETAILS_______\n");
    for (int i = 0; i < n; i++) {
        printf("Name of the student: %s\n", students[i].name);
        printf("Roll number of the student: %d\n", students[i].roll_no);
        printf("Marks of the student: %f\n\n", students[i].marks);
    }
}

void highest(student *students, int n){
    int topperIndex = 0;
    for (int i = 1; i < n; i++) {
        if ((students + i)->marks > (students + topperIndex)->marks) {
            topperIndex = i;
        }
    }
    printf("\nTopper Details:\n");
    printf("Name: %s\n", (students + topperIndex)->name);
    printf("Roll Number: %d\n", (students + topperIndex)->roll_no);
    printf("Marks: %.2f\n", (students + topperIndex)->marks);
}

int main(){
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    student students[100];

    read(students, n);
    display(students, n);
    highest(students, n);
}

