//
// Created by explorer on 15-12-15.
//

#ifndef STUDENT_MAIN_H
#define STUDENT_MAIN_H
#include "main.h"
#endif //STUDENT_QUERYEX_H




int cmp(int *a, int *b) {
    return *a > *b ? 1 : (*a < *b ? -1 : 0);
}

typedef struct cmd{
    int offset;
    int cmpFlag;
    void * cmpFunc;
    unsigned char cmpData[50];
}cmd;

void queryExtent(void);
int decodeCmd(char *str,cmd * retData,int len);
void selectData(cmd selectCtrl, studentTable *pTable[1000]);

typedef struct menber {
    char name[10];
    int offset;
    void *cmpFunc;
} menber;



