
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

enum actions {
    ENTER_DATA_CLIENT = 1,
    ENTER_DATA_TRANSACTION,
    UPDATE_BASE,
    EXIT = -1
};

int main(void) {
    int choice = 0;
    FILE *Ptr_1, *Ptr_2, *Ptr_3;
    printf("%s", "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n");
    while (scanf("%d", &choice) != EXIT) {
        switch (choice) {
            case ENTER_DATA_CLIENT:
            Ptr_1 = fopen(origin_record, "r+");
            if (Ptr_1 == NULL) {
                puts("Not acess");
            } else {
                masterWrite(Ptr_1);
                fclose(Ptr_1);
            }
            break;
            case ENTER_DATA_TRANSACTION:
            Ptr_2 = fopen(transaction, "r+");
            if (Ptr_2 == NULL) {
                puts("Not acess");
            } else {
                transactionWrite(Ptr_2);
                fclose(Ptr_2);
            }
            break;
            case UPDATE_BASE:
            Ptr_1 = fopen(origin_record, "r");
            Ptr_2 = fopen(transaction, "r");
            Ptr_3 = fopen(updated, "a+");
            if ((Ptr_1 == NULL) || (Ptr_2 == NULL) || (Ptr_3 == NULL)) {
                puts("exit");
            } else {
                updateRec(Ptr_1, Ptr_2, Ptr_3);
                fclose(Ptr_1);
                free(Ptr_1);
                fclose(Ptr_2);
                fclose(Ptr_3);
            }
            break;
        default:
            puts("error");
            break;
        }
        printf("%s", "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n");
    }
    return 0;
}
