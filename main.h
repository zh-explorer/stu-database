//
// Created by explorer on 15-12-11.
//

#ifndef STUDENT_MAIN_H
#define STUDENT_MAIN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#endif //STUDENT_MAIN_H

/*********************************************************
 * some struct
 ********************************************************/

//A struct for student data
typedef struct studentData {
    char name[20];
    int sex;
    int age;
    int mark[5];
    char *information;
} studentData;

//A struct for store student
typedef struct studentTable {
    unsigned int stuNum;
    studentData data;
} studentTable;

typedef struct freeStudentTable {
    unsigned int inUser;
    struct freeStudentTable *next;
    struct freeStudentTable *last;
} freeStudentTable;

/********************************************************
 * some define
 ********************************************************/
//Define size of struct
#define dataSize sizeof(studentData)
#define tableSize sizeof(studentTable)
#define MAXSIZE 1000
enum sex {
    male, female
};

/*********************************************************
 * some function
 ********************************************************/

void printMenu(void);

int getStr(char *buffer, unsigned int len);

int getChoose(void);

int getInt(void);

int addData(unsigned int stuNum, studentData *dataPtr);

int deleteData(unsigned int stuNum);

studentTable *queryData(unsigned int stuNum);

void add(void);

void drop(void);

void modify(void);

void query(void);

void queryEx(void);

int initDatabase(void);

int storeDatabase(void);

int showData(studentTable *stu);

int getVstr(char **buffer, unsigned int len);

char *strip(char * src,int *len);