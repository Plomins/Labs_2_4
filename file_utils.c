#include "file_utils.h"

// Write and read file
// mode: 1 for writing, 0 for reading
void file_rw(const char* filename, int mode) {
    FILE* file = fopen(filename, mode ? "w" : "r");
    if (!file) {
        perror("File error");
        exit(1);
    }

    if (mode) {  // Writing
        printf("Enter text: ");
        char buffer[MAX_SIZE];
        fgets(buffer, MAX_SIZE, stdin);
        fprintf(file, "%s", buffer);
    }
    else {  // Reading
        printf("File content:\n");
        char ch;
        while ((ch = fgetc(file)) != EOF)
            putchar(ch);
        printf("\n");
    }

    fclose(file);
}

// Count occurrences of a character in the file
void count_char(const char* filename, char target) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("File error");
        exit(1);
    }

    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF)
        if (ch == target)
            count++;

    printf("Character '%c' occurs %d time(s).\n", target, count);
    fclose(file);
}

// Reverse a substring in the file given start and end indices
void reverse_substr(const char* filename, int start, int end) {
    FILE* file = fopen(filename, "r+");
    if (!file) {
        perror("File error");
        exit(1);
    }

    char buffer[MAX_SIZE];
    int len = fread(buffer, 1, MAX_SIZE - 1, file);
    buffer[len] = '\0';

    if (start < 0 || end >= len || start >= end) {
        printf("Invalid indices!\n");
        fclose(file);
        return;
    }

    while (start < end) {
        char temp = buffer[start];
        buffer[start] = buffer[end];
        buffer[end] = temp;
        start++;
        end--;
    }

    freopen(filename, "w", file);
    fputs(buffer, file);
    fclose(file);
}

// Main task with menu
void maintask(const char* filename) {
    int choice;
    char target;
    int start, end;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Write to file\n");
        printf("2. Read file\n");
        printf("3. Count character\n");
        printf("4. Reverse substring\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline

        switch (choice) {
        case 1:
            file_rw(filename, 1);
            break;
        case 2:
            file_rw(filename, 0);
            break;
        case 3:
            printf("Enter character: ");
            scanf("%c", &target);
            count_char(filename, target);
            break;
        case 4:
            printf("Enter start and end indices: ");
            scanf("%d %d", &start, &end);
            reverse_substr(filename, start, end);
            break;
        case 5:
            return;
        default:
            printf("Invalid choice.\n");
        }
    }
}
