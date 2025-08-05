#include <stdio.h>

typedef struct {
    char name[50];
    int roll_no;
    char grade;
} student;

void read(student arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter the name of the student: ");
        scanf("%s", arr[i].name);
        printf("Enter student roll number: ");
        scanf("%d", &arr[i].roll_no);
        printf("Enter grade of student: ");
        scanf(" %c", &arr[i].grade);
        printf("\n");
    }
}

void display(student arr[], int n) {
    printf("\n_______STUDENT DETAILS_______\n");
    for (int i = 0; i < n; i++) {
        printf("Name of the student: %s\n", arr[i].name);
        printf("Roll number of the student: %d\n", arr[i].roll_no);
        printf("Grade of the student: %c\n\n", arr[i].grade);
    }
}

void sort(student arr[], int n) {
    student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].roll_no > arr[j].roll_no) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    student students[100];

    read(students, n);
    sort(students, n);
    display(students, n);

    return 0;
}
