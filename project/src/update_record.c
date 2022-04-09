#include "file_openers.h"
#include "utils.h"

void updateRec(const char *record_filename, const char *transaction_filename,
const char *transact_record_filename) {
    Data client_data, transfer;
    FILE *record_ptr = file_opener_read(record_filename);
    FILE *transact_ptr = file_opener_read(transaction_filename);
    FILE *transact_record_ptr = file_opener_add(transact_record_filename);
    while (fscanf(record_ptr, "%d%20s%20s%30s%15s%lf%lf%lf",
                  &client_data.number,
                  client_data.name,
                  client_data.surname,
                  client_data.addres,
                  client_data.telNumber,
                  &client_data.indebtedness,
                  &client_data.credit_limit,
                  &client_data.cash_payments) != -1) {
        while (fscanf(transact_ptr, "%d %lf", &transfer.number, &transfer.cash_payments) != -1) {
            if ((client_data.number == transfer.number) && (transfer.cash_payments != 0)) {
                client_data.credit_limit += transfer.cash_payments;
            }
        }
        fprintf(transact_record_ptr, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",
                client_data.number,
                client_data.name,
                client_data.surname,
                client_data.addres,
                client_data.telNumber,
                client_data.indebtedness,
                client_data.credit_limit,
                client_data.cash_payments);
        rewind(transact_ptr);
    }
    fclose(record_ptr);
    fclose(transact_ptr);
    fclose(transact_record_ptr);
}
