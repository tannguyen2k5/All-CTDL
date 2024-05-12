#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ð?nh nghia c?u trúc cho sinh viên
typedef struct Student {
    int student_id;
    char name[100];
    int age;
    struct Student *next;
} Student;

// Hàm t?o m?t nút m?i cho danh sách liên k?t
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

// Hàm thêm sinh viên vào cu?i danh sách liên k?t
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

// Hàm hi?n th? danh sách sinh viên
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

// Hàm xóa sinh viên kh?i danh sách
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

    // Nh?p thông tin sinh viên t? bàn phím và thêm vào danh sách
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

    // Hi?n th? danh sách sinh viên
    printf("\nList of students:\n");
    displayStudents(head);

    // Xóa sinh viên theo ID
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

    // Gi?i phóng b? nh?
    while (head != NULL) {
        Student *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

