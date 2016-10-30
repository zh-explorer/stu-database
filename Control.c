//
// Created by explorer on 15-12-14.
//
#include "main.h"

extern int nodeNumber;

studentData getData(char *buffer);

unsigned int getNum(void);

unsigned int getNum(void) {
    unsigned int num;
    do {
        num = getInt();
        if (num >= 10000000 && num < 99999999) {
            break;
        }
        else {
            puts("The student's number is 8 digital.");
            puts("enter again");
        }
    } while (1);
    return num;
}

void add(void) {
    unsigned int num;
    studentData data;
    studentTable *table;
    if (nodeNumber == MAXSIZE) {
        puts("There is no place.");
        return;
    }
    puts("So, I need the student's data.");
    puts("First please enter the student's num");

    num = getNum();
    if (num == 0) {
        puts("soem thing wrong");
    }
    table = queryData(num);
    if (table) {
        puts("Student number mast be different");
        return;
    }
    data = getData(0);
    addData(num, &data);
}

void drop(void) {
    unsigned int num;
    puts("So, give me the student's number you want to delete.");
    num = getNum();

    if (num == 0) {
        puts("Some thing wrong");
        return;
    }

    deleteData(num);
}

void modify(void) {
    studentTable *table;
    studentData data;
    unsigned int num;
    puts("So, give me the student's number you want to modify.");
    num = getNum();

    if (num == 0) {
        puts("Some thing wrong");
        return;
    }

    table = queryData(num);
    if (table == NULL) {
        puts("Maybe enyer a wrong student number");
        return;
    }
    data = getData(table->data.information);
    memcpy(&(table->data), &data, dataSize);
}

void query(void) {
    unsigned int num, i;
    studentTable *stu;

    puts("So what student do you want to query from database?");
    puts("Enter the sutdent's num");

    num = getNum();
    if (num == 0) {
        puts("Somethong wrong");
    }

    stu = queryData(num);
    if (stu == NULL) {
        puts("do not find student");
        return;
    }
    showData(stu);

}

int showData(studentTable *stu) {
    int i;

    printf("Student's number   %d\n", stu->stuNum);
    printf("Student's name     %s\n", (stu->data).name);
    printf("Student's sex      %s\n", (stu->data).sex ? (((stu->data).sex == 1) ? "male" : "???") : "female");
    printf("Student's age      %d\n", (stu->data).age);
    printf("Student's mark     ");
    for (i = 0; i < 5; i++) {
        printf("(%d) : %d   ", i + 1, (stu->data).mark[i]);
    }
    printf("Student's info    %s\n", (stu->data).information);
    printf("\nend\n");
}

studentData getData(char *buffer) {
    int len;
    char sex;
    int age;
    int i;
    int mark;

    studentData data;
    char name[20];
    puts("Enter the name of student");
    len = 20;
    do {
        getStr(name,len);
        len = strlen(name);
        if (len > 0 && len < 20) {
            strcpy(data.name, name);
            break;
        }
        else {
            puts("The name maybe wrong");
            puts("try again");
        }
    } while (1);

    puts("The sex of student:");

    do {
        sex = getchar();
        while (getchar() != '\n');
        sex = sex | 0x20;
        if (sex == 'm') {
            data.sex = 1;
            break;
        }
        else if (sex == 'f') {
            data.sex = 0;
            break;
        }
        else if (sex == 'x') {
            data.sex = 2;
            break;
        }
        else {
            puts("I don't know what do you want to do");
            puts("enter again");
        }
    } while (1);

    puts("The age of the student:");
    while (1) {
        age = getInt();
        if (age > 5 && age < 100) {
            data.age = age;
            break;
        }
        else {
            puts("It's not like a student's age");
        }
    }

    puts("now give student's marks");
    for (i = 0; i < 5; i++) {
        for (; ;) {
            printf("Mark %d:", i + 1);
            mark = getInt();
            if (mark >= 0 && mark <= 100) {
                data.mark[i] = mark;
                break;
            }
            else {
                puts("Are you sure the mark is right?");
                puts("Please check it");
            }
        }
    }

    puts("At last,show me some information");
    if (buffer) {
        data.information = buffer;
        getStr(data.information,0x200);
    }
    else {
        getVstr(&data.information, 0x200);
    }
    puts("now I get enough information");
    return data;
}
