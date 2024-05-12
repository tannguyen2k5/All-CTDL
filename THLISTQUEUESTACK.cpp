#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �?nh nghia c?u tr�c cho sinh vi�n
typedef struct Student {
    int student_id;
    char name[100];
    int age;
    struct Student *next;
} Student;

// H�m t?o m?t n�t m?i cho danh s�ch li�n k?t
Student *createNode(int student_id, char *name, int age) {
    Student *newNode = (Student *)malloc(sizeof(Student));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->student_id = student_id;
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->next = NULL;
    return newNode;
}

// H�m th�m sinh vi�n v�o cu?i danh s�ch li�n k?t
void addStudent(Student **head, int student_id, char *name, int age) {
    Student *newNode = createNode(student_id, name, age);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Student *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// H�m hi?n th? danh s�ch sinh vi�n
void displayStudents(Student *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Student *temp = head;
    while (temp != NULL) {
        printf("ID: %d, Name: %s, Age: %d\n", temp->student_id, temp->name, temp->age);
        temp = temp->next;
    }
}

// H�m x�a sinh vi�n kh?i danh s�ch
void removeStudent(Student **head, int student_id) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Student *temp = *head, *prev = NULL;
    if (temp != NULL && temp->student_id == student_id) {
        *head = temp->next;
        free(temp);
        printf("Student with ID %d removed.\n", student_id);
        return;
    }
    while (temp != NULL && temp->student_id != student_id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Student not found.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Student with ID %d removed.\n", student_id);
}

int main() {
    Student *head = NULL;
    int student_id, age;
    char name[100];
    char choice;

    // Nh?p th�ng tin sinh vi�n t? b�n ph�m v� th�m v�o danh s�ch
    printf("Enter student information (ID, Name, Age), enter -1 to finish:\n");
    while (1) {
        printf("Enter student ID: ");
        scanf("%d", &student_id);
        if (student_id == -1) break;
        printf("Enter student name: ");
        scanf("%s", name);
        printf("Enter student age: ");
        scanf("%d", &age);
        addStudent(&head, student_id, name, age);
    }

    // Hi?n th? danh s�ch sinh vi�n
    printf("\nList of students:\n");
    displayStudents(head);

    // X�a sinh vi�n theo ID
    do {
        printf("\nDo you want to remove a student? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            printf("Enter student ID to remove: ");
            scanf("%d", &student_id);
            removeStudent(&head, student_id);
            printf("\nList of students after removal:\n");
            displayStudents(head);
        }
    } while (choice == 'y' || choice == 'Y');

    // Gi?i ph�ng b? nh?
    while (head != NULL) {
        Student *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

