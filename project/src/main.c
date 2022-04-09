
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "print.h"

enum actions {
    ENTER_DATA_CLIENT = 1,
    ENTER_DATA_TRANSACTION,
    UPDATE_BASE,
    EXIT = -1
};

int main(void) {
    int choice = 0;
    show_options();
    while (scanf("%d", &choice) != EXIT) {
        switch (choice) {
            case ENTER_DATA_CLIENT:
                personDataWrite(origin_record);
            break;
            case ENTER_DATA_TRANSACTION:
                transactionWrite(transaction);
            break;
            case UPDATE_BASE:
                updateRec(origin_record, transaction, updated);
            break;
        default:
            puts("error");
            break;
        }
        show_options();
    }
    return 0;
}
