//
// Created by explorer on 15-12-16.
//

#include "BRTree.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BLACK 1
#define RED 0

void dropFixup(node *z);

node *successor(node *x);

node *treeMiniNum(struct node *x);

int insertFixup(node *x);

int rightRotate(node *x);

int leftRotate(node *x);


node none = {
        0,
        {"", 0, 0, {0, 0, 0, 0, 0}, ""},
        {NULL, NULL, NULL, BLACK}
};

node *root = &none;

int leftRotate(node *x) {
    if (x == &none) {
        puts("somethong wrong");
        return -1;
    }

    node *y;

    y = x->h.r;
    x->h.r = y->h.l;
    if (y->h.l != &none) {
        y->h.l->h.p = x;
    }

    y->h.p = x->h.p;
    if (x->h.p == &none) {
        root = y;
    }
    else if (x == x->h.p->h.l) {
        x->h.p->h.l = y;
    }
    else {
        x->h.p->h.r = y;
    }

    y->h.l = x;
    x->h.p = y;

}

int rightRotate(node *x) {
    if (x == &none) {
        puts("somethong wrong");
        return -1;
    }
    node *y;
    y = x->h.l;

    x->h.l = y->h.r;
    if (y->h.r != &none) {
        y->h.r->h.p = x;
    }

    y->h.p = x->h.p;
    if (x->h.p == &none) {
        root = y;
    }
    else if (x == x->h.p->h.l) {
        x->h.p->h.l = y;
    }
    else {
        x->h.p->h.r = y;
    }

    y->h.r = x;
    x->h.p = y;
}

int insert(node *z) {
    node *y = &none;
    node *x = root;

    while (x != &none) {
        y = x;
        if (z->id < x->id) {
            x = x->h.l;
        }
        else {
            x = x->h.r;
        }
    }

    z->h.p = y;

    if (y == &none) {
        root = z;
    }
    else if (z->id < y->id) {
        y->h.l = z;
    }
    else {
        y->h.r = z;
    }

    z->h.l = &none;
    z->h.r = &none;
    z->h.color = RED;
    insertFixup(z);
}

int insertFixup(node *z) {

    node *y;
    while (z->h.p->h.color == RED) {
        if (z->h.p == z->h.p->h.p->h.l) {
            y = z->h.p->h.p->h.r;
            if (y->h.color == RED) {
                z->h.p->h.color = BLACK;
                y->h.color = BLACK;
                z->h.p->h.p->h.color = RED;
                z = z->h.p->h.p;
            }
            else {
                if (z == z->h.p->h.r) {
                    z = z->h.p;
                    leftRotate(z);
                }
                z->h.p->h.color = BLACK;
                z->h.p->h.p->h.color = RED;
                rightRotate(z->h.p->h.p);
            }
        }
        else {
            y = z->h.p->h.p->h.l;
            if (y->h.color == RED) {
                z->h.p->h.color = BLACK;
                y->h.color = BLACK;
                z->h.p->h.p->h.color = RED;
                z = z->h.p->h.p;
            }
            else {
                if (z == z->h.p->h.l) {
                    z = z->h.p;
                    rightRotate(z);
                }
                z->h.p->h.color = BLACK;
                z->h.p->h.p->h.color = RED;
                leftRotate(z->h.p->h.p);
            }
        }
    }
    root->h.color = BLACK;
}

node *dropNode(node *z) {
    node *y;
    node *x;
    if (z->h.l == &none || z->h.r == &none) {
        y = z;
    }
    else {
        y = successor(z);
    }

    if (y->h.l != &none) {
        x = y->h.l;
    }
    else {
        x = y->h.r;
    }

    x->h.p = y->h.p;
    if (y->h.p == &none) {
        root = &none;
    }
    else if (y == y->h.p->h.l) {
        y->h.p->h.l = x;
    }
    else {
        y->h.p->h.r = x;
    }

    if (y != z) {
        z->h.l = y->h.l;
        z->h.r = y->h.r;
        z->h.p = y->h.p;
    }
    if (y->h.color == BLACK) {
        dropFixup(x);
    }
    return z;
}

node *successor(node *x) {
    node *y;
    if (x->h.r != &none) {
        return treeMiniNum(x->h.r);
    }
    y = x->h.p;
    while (y != &none && x == y->h.r) {
        x = y;
        y = y->h.p;
    }
    return y;
}

node *treeMiniNum(struct node *x) {
    while (x->h.l != &none) {
        x = x->h.l;
    }
    return x;
}

void dropFixup(node *x) {
    node *w;
    while (x != root || x->h.color == BLACK) {
        if (x == x->h.p->h.r) {
            w = x->h.p->h.r;
            if (w->h.color == RED) {
                w->h.color = BLACK;
                x->h.p->h.color = RED;
                leftRotate(x->h.p);
                w = x->h.p->h.r;
            }
            if (w->h.l->h.color == BLACK && w->h.r->h.color == BLACK) {
                w->h.color = RED;
                x = x->h.p;
            }
            else {
                if (w->h.r->h.color == BLACK) {
                    w->h.l->h.color = BLACK;
                    w->h.color = RED;
                    rightRotate(w);
                    w = x->h.p->h.r;
                }
                w->h.color = x->h.p->h.color;
                x->h.p->h.color = BLACK;
                w->h.r->h.color = BLACK;
                leftRotate(x->h.p);
                x = root;
            }
        }
        else {
            w = x->h.p->h.l;
            if (w->h.color == RED) {
                w->h.color = BLACK;
                x->h.p->h.color = RED;
                rightRotate(x->h.p);
                w = x->h.p->h.l;
            }
            if (w->h.r->h.color == BLACK && w->h.l->h.color == BLACK) {
                w->h.color = RED;
                x = x->h.p;
            }
            else {
                if (w->h.l->h.color == BLACK) {
                    w->h.r->h.color = BLACK;
                    w->h.color = RED;
                    leftRotate(w);
                    w = x->h.p->h.l;
                }
                w->h.color = x->h.p->h.color;
                x->h.p->h.color = BLACK;
                w->h.l->h.color = BLACK;
                rightRotate(x->h.p);
                x = root;
            }
        }
    }
    x->h.color = BLACK;
}

node *treeSearch(int id) {
    node *x = root;
    while (x != &none && id != x->id) {
        if (id < x->id) {
            x = x->h.l;
        }
        else {
            x = x->h.r;
        }
    }
    if (x == &none)
        return NULL;
    return x;
}

int treeWalk(node *pTable[], node *x, int flag) {
    static int i = 0;
    if (x != &none) {
        pTable[i] = x;
        i++;
        treeWalk(pTable, x->h.l, 0);
        treeWalk(pTable, x->h.r, 0);
    }
    if (flag) {
        pTable[i] = 0;
        i = 0;
    }
}
