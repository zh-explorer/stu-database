//
// Created by explorer on 15-12-11.
//

#include <stddef.h>
#include "main.h"
#include "BRTree.h"

int nodeNumber;

int addData(unsigned int stuNum, studentData *dataPtr) {
    studentTable *p = malloc(nodeSize);
    if (!p) {
        puts("Error: malloc failed.");
        exit(1);
    }
    p->stuNum = stuNum;
    memcpy((int) p + offsetof(studentTable, data), dataPtr, dataSize);
    insert((node *) p);
    nodeNumber++;
    return 1;
}

int deleteData(unsigned int stuNum) {
    studentTable *p;

    p = (studentTable *) treeSearch(stuNum);
    if (p == NULL) {
        puts("Maybe you enter a wrong student number");
        return 0;
    }

    dropNode((node *) p);
    free(p->data.information);
    free(p);
    nodeNumber--;
    return 1;
}

studentTable *queryData(unsigned int stuNum) {
    int i;
    studentTable *p;
    if (stuNum == 0) {
        puts("somethong wrong");
        return NULL;
    }
    p = (studentTable *) treeSearch(stuNum);
    return p;
}