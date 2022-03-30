
#include "utils.h"

void updateRec(FILE *ofPTR_1, FILE *ofPTR_2, FILE *updateRecord) {
    Data client_data, transfer;
    while (fscanf(ofPTR_1, "%d%20s%20s%30s%15s%lf%lf%lf",
                  &client_data.number,
                  client_data.name,
                  client_data.surname,
                  client_data.addres,
                  client_data.telNumber,
                  &client_data.indebtedness,
                  &client_data.credit_limit,
                  &client_data.cash_payments) != -1) {
        while (fscanf(ofPTR_2, "%d %lf", &transfer.number, &transfer.cash_payments) != -1) {
            if ((client_data.number == transfer.number) && (transfer.cash_payments != 0)) {
                client_data.credit_limit += transfer.cash_payments;
            }
        }
        fprintf(updateRecord, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",
                client_data.number,
                client_data.name,
                client_data.surname,
                client_data.addres,
                client_data.telNumber,
                client_data.indebtedness,
                client_data.credit_limit,
                client_data.cash_payments);
        rewind(updateRecord);
        rewind(ofPTR_2);
    }
}
