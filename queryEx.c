//
// Created by explorer on 15-12-15.
//
#include <stddef.h>
#include <unistd.h>
#include "main.h"
#include "queryEx.h"
#include "BRTree.h"

#define offData offsetof(studentTable,data)
menber men[] = {{"name",   offData + offsetof(studentData, name),    strcmp,},
                {"age",    offData + offsetof(studentData, age),     cmp},
                {"mark1",  offData + offsetof(studentData, mark[0]), cmp},
                {"mark2",  offData + offsetof(studentData, mark[1]), cmp},
                {"mark3",  offData + offsetof(studentData, mark[2]), cmp},
                {"mark4",  offData + offsetof(studentData, mark[3]), cmp},
                {"mark5",  offData + offsetof(studentData, mark[4]), cmp},
                {"number", offsetof(studentTable, stuNum), cmp}};

extern node *root;

void queryEx(void) {
    char choose;
    puts("So do you want a advanced query?[Y?N]");
    for (; ;) {
        choose = getchar();
        choose = choose | 0x20;
        for (; getchar() != '\n';);
        if (choose == 'n') {
            query();
            break;
        }
        else if (choose == 'y') {
            queryExtent();
            break;
        }
        else {
            puts("I don't think it's a good choose");
            puts("Be serious");
        }
    }
}

void queryExtent(void) {
    char *cmd = malloc(0x500);
    char *subStr;
    char *p = cmd;
    int i, j;
    int len;

    struct cmd retData;
    puts("I have a write a extend query,but do you know how to use it?");
    studentTable **pTable = malloc(MAXSIZE * sizeof(p));

    treeWalk((node **) pTable, root, 1);

    read(0, cmd, 0x500);
    if (!strncmp("select:", p, 7)) {
        p += 7;
        subStr = strip(p,&len);
        do {
            if (decodeCmd(subStr, &retData,len)) {
                return;
            }
            selectData(retData, pTable);
            free(subStr);
            subStr = strip(NULL,&len);
        } while (subStr != NULL);

        for (i = 0; pTable[i] != 0; i++) {
            showData(pTable[i]);
        }
    }
    free(cmd);
    //free(pTable);

}

void selectData(cmd selectCtrl, studentTable *pTable[]) {
    int end, i;

    for (end = 0; pTable[end] != 0; end++);
    end--;
    for (i = 0; pTable[i] != 0;) {
        if (selectCtrl.cmpFlag ==
            ((int (*)(void *, void *)) selectCtrl.cmpFunc)((int) pTable[i] + selectCtrl.offset, selectCtrl.cmpData)) {
            i++;
            continue;
        }
        pTable[i] = pTable[end];
        pTable[end--] = 0;
    }
}

int decodeCmd(char *str, cmd *retData,int len) {
    int i;
    char *p;
    for (i = 0; i < 8; i++) {
        if (strncmp(str, men[i].name, strlen(men[i].name))) {
            continue;
        }
        if (i == 9) {
            return -1;
        }
        p = str + strlen(men[i].name);

        retData->cmpFlag = (*p == '<' ? -1 : (*p == '>' ? 1 : (*p == '=' ? 0 : -2)));
        if (retData->cmpFlag == -2) {
            return -1;
        }

        retData->offset = men[i].offset;
        retData->cmpFunc = men[i].cmpFunc;

        if (i == 0) {
            memcpy(retData->cmpData, p + 1,len);
        }
        else {
            *(int *) (retData->cmpData) = atol(p + 1);
        }

        break;
    }
    return 0;
}
