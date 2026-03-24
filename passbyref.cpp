#include <stdio.h>
#include <string.h>

typedef struct {
    char name [50];
    int student_id;
    float gpa;
} Student;

void updateStudentInfo (Student *s, char name[], int id, float gpa);

int main () {
    Student student_01;
    Student student_02;
    Student student_03;

    strcpy (student_01.name, "Edward Mercer");
    student_01.student_id = 1001;
    student_01.gpa = 3.81; // 1-5 bulet bawah, 6-9 bulet atas

    printf ("Name: %s\n", student_01.name);
    printf ("ID  : %d\n", student_01.student_id);
    printf ("GPA : %.1f\n", student_01.gpa); //klo .1f dia bakal ngelakuin pembulatan

    printf ("\nRunning Update Function\n\n");
    updateStudentInfo(&student_01, "Kelly Grayson", 1002, 3.95);

    printf ("Name: %s\n", student_01.name);
    printf ("ID  : %d\n", student_01.student_id);
    printf ("GPA : %.1f\n", student_01.gpa);    

    return 0;
}

void updateStudentInfo (Student *s, char name[], int id, float gpa) {
    strcpy (s->name, name);
    s->student_id = id;
    s->gpa = gpa;
}