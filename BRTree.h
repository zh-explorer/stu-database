//
// Created by explorer on 15-12-16.
//

#ifndef BRTREE_MAIN_H
#define BRTREE_MAIN_H


#endif //BRTREE_MAIN_H

typedef struct head {
    struct node *p;
    struct node *l;
    struct node *r;
    int color;
} head;

typedef struct data {
    char name[20];
    int sex;
    int age;
    int mark[5];
    char *information;
} data;

typedef struct node {
    int id;
    data d;
    head h;
} node;
#define nodeSize sizeof(node)

int insert(node *z);

node *treeSearch(int id);

node *dropNode(node *z);

int treeWalk(node *pTable[], node *x, int flag);


