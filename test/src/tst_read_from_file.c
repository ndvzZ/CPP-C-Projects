#include <stdio.h>
#include <string.h>
#include "main_mod.h"

void read_from_file(const char *test_filename, const char *gold_filename) {
    Data data,compare_base;
    FILE *File_ptr_test = fopen(test_filename, "r+");
    FILE *File_ptr_gold = fopen(gold_filename, "r+");
    if ((File_ptr_test == NULL) || (File_ptr_gold == NULL)) {
        puts("Not acess");
        return;
    }
    if  ((fscanf(File_ptr_test, "%d%20s%20s%30s%15s%lf%lf%lf",
                &data.number,
                data.name,
                data.surname,
                data.addres,
                data.telNumber,
                &data.indebtedness,
                &data.credit_limit,
                &data.cash_payments) == -1) ||
                (fscanf(File_ptr_gold, "%d%20s%20s%30s%15s%lf%lf%lf",
                &compare_base.number,
                compare_base.name,
                compare_base.surname,
                compare_base.addres,
                compare_base.telNumber,
                &compare_base.indebtedness,
                &compare_base.credit_limit,
                &compare_base.cash_payments) == -1)) {
                perror("error");
                return;      
    }  
    if (
        ((data.number != compare_base.number) +
        strncmp(data.name, compare_base.name, 20) +
        strncmp(data.surname, compare_base.surname, 20) +
        strncmp(data.addres, compare_base.addres, 30) +
        is_equal(data.indebtedness, compare_base.indebtedness) +
        is_equal(data.credit_limit, compare_base.credit_limit) +
        is_equal(data.cash_payments, compare_base.cash_payments)) == 0) {
        printf("%s", "Succeed\n");
        return;
    }
    printf("%s", "Error\n");
    fclose(File_ptr_gold);
    fclose(File_ptr_test);
}
