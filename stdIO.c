//
// Created by explorer on 15-12-11.
//

#include "main.h"

void printMenu(void) {
    printf("\n\n");
    printf("+--------------------------------------------------------------+\n");
    printf("|So what do you want to do?                                    |\n");
    printf("+--------------------------------------------------------------+\n");
    printf("|A(Add)     add a student's data to database                   |\n");
    printf("+--------------------------------------------------------------+\n");
    printf("|D(Delete)  delete a student's data from database              |\n");
    printf("+--------------------------------------------------------------+\n");
    printf("|M(Modify)  change a student's data from database              |\n");
    printf("+--------------------------------------------------------------+\n");
    printf("|Q(Query)   find a student's data use student number           |\n");
    printf("+--------------------------------------------------------------+\n");
    printf("|E(Exit)     Exit                                              |\n");
    printf("+--------------------------------------------------------------|\n");
    printf("Enter you choose\n");
}

// just get a num in a different way
int getInt(void) {
    int num;
    while (scanf("%d", &num) != 1) {
        printf("Please enter a number\ntry again\n");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');

    return num;
}

int getStr(char *buffer, unsigned int len) {
    char ch;
    int i = 0;
    do {
        while ((ch = getchar()) == 0x20); //Delete space before string

        if (ch == '\n') {
            printf("Please at least enter some thing\ntry again\n");
        }

    } while (ch == '\n');

    *buffer = ch;
    if (len == 1) {
        while (getchar() != '\n');
    }
    for (i = 1; (ch = getchar()) != '\n'; i++) {
        if (i < len - 1) {
            buffer[i] = ch;
        }
        else {
            while (getchar() != '\n');
            break;
        }
    }
    buffer[i] = 0;
    return i;
}

int getVstr(char **buffer, unsigned int len) {
    char ch;
    int i = 0;
    int size;
    *buffer = malloc(9);
    if (!*buffer) {
        puts("Error: malloc failed");
        exit(1);
    }
    size = 8;

    do {
        while ((ch = getchar()) == 0x20); //Delete space before string

        if (ch == '\n') {
            printf("Please at least enter some thing\ntry again\n");
        }

    } while (ch == '\n');

    **buffer = ch;
    if (len == 1) {
        while (getchar() != '\n');
    }
    for (i = 1; (ch = getchar()) != '\n'; i++) {
        if (i > size) {
            *buffer = realloc(*buffer, size + 9);
            if (!*buffer) {
                puts("Error: realloc failed.");
                exit(1);
            }
            size += 8;
        }
        if (i < len - 1) {
            (*buffer)[i] = ch;
        }
        else {
            while (getchar() != '\n');
            break;
        }
    }
    (*buffer)[i] = 0;
    return i;
}

int getChoose(void) {
    char choose;
    while (1) {
        choose = getchar();
        while (getchar() != '\n');
        choose = choose | 0x20;
        switch (choose) {
            case 'a':
                return 1;
            case 'd':
                return 2;
            case 'm':
                return 3;
            case 'q':
                return 4;
            case 'e':
                return 0;
            default :
                break;
        }

        printf("I don't know what do you want to do\n");
        printMenu();
        printf("Please enter again:");
    }
}

char *strip(char *src,int * len) {
    int i;
    static char *p;
    char *sub;
    if (src != NULL) {
        p = src;
    }
    else {
        src = p;
    }

    if (*p == '\n') {
        *len = 0;
        return NULL;
    }

    for (; ; p++) {
        if (*p == '&' || *p == '\n') {
            break;
        }
    }

    sub = (char *)malloc(p - src + 1);
    memcpy(sub, src, p - src);
    *len = p - src;
    if (*p == '&') {
        p++;
    }
    return sub;
}

