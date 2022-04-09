#include "utils.h"
#include "file_openers.h"
#include "print.h"

void personDataWrite(const char *new_record) {
    Data Client;
    FILE *new_record_ptr = file_opener_read_plus(new_record);
    print_data_fields();
    while (
        scanf("%d%20s%20s%30s%15s%lf%lf%lf",
              &Client.number,
              Client.name,
              Client.surname,
              Client.addres,
              Client.telNumber,
              &Client.indebtedness,
              &Client.credit_limit,
              &Client.cash_payments) != -1) {
        fprintf(new_record_ptr, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",
                Client.number,
                Client.name,
                Client.surname,
                Client.addres,
                Client.telNumber,
                Client.indebtedness,
                Client.credit_limit,
                Client.cash_payments);
        print_data_fields();
    }
    fclose(new_record_ptr);
}
