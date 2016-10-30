//
// Created by explorer on 15-12-11.
//

#include "main.h"

int main(void) {
    int choose = 1;

    initDatabase();

    printf("Welecome to my student database system\n");
    printf("I promise this system is safe and nevel be pwned(flag)\n");

    setbuf(stdout,NULL);
    setbuf(stderr,NULL);
    setbuf(stdin,NULL);

    while (choose != 0) {
        printMenu();
        choose = getChoose();
        switch (choose) {
            case 1:
                add();
                break;
            case 2:
                drop();
                break;
            case 3:
                modify();
                break;
            case 4:
                queryEx();
                break;
        }
    }

    storeDatabase();
    return 0;
}
