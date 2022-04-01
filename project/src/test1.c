
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main_module.h"

#define filename "Test_config.dat"
#define filename1 "Test_config.dat.gold"

void test_write_to_file() {
    Data expected_data = {1, "Denis", "Naga", "Addres", "88005553535", 90, 165, 28};
    FILE *Test = fopen(filename, "w+");
    FILE *Gold = fopen(filename1, "w+");
    if ((Test == NULL) || (Gold == NULL)) {
        puts("Not acess");
        return;
    } else {
        write_to_file(Gold, expected_data);
        Data got_data;
        scanf("%d%20s%20s%30s%15s%lf%lf%lf",
                &got_data.number,
                got_data.name,
                got_data.surname,
                got_data.addres,
                got_data.telNumber,
                &got_data.indebtedness,
                &got_data.credit_limit,
                &got_data.cash_payments);
        write_to_file(Test, got_data);
        fclose(Gold);
    read_from_file(Test, got_data);
    fclose(Test);
    }
}

void write_to_file(FILE *File_ptr, Data writing_data) {
    fprintf(File_ptr, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",
                writing_data.number,
                writing_data.name,
                writing_data.surname,
                writing_data.addres,
                writing_data.telNumber,
                writing_data.indebtedness,
                writing_data.credit_limit,
                writing_data.cash_payments);
}

void read_from_file(FILE *File_ptr, Data compare_base) {
    Data data;
    char value_to_str1[16];
    char value_to_str2[16];
    fscanf(File_ptr, "%d%20s%20s%30s%15s%lf%lf%lf",
                &data.number,
                data.name,
                data.surname,
                data.addres,
                data.telNumber,
                &data.indebtedness,
                &data.credit_limit,
                &data.cash_payments);
    if ((
        snprintf(value_to_str1, sizeof(value_to_str1), "%d", data.number) !=
        snprintf(value_to_str2, sizeof(value_to_str2), "%d", compare_base.number)) +
    strncmp(data.name, compare_base.name, 20) +
    strncmp(data.surname, compare_base.surname, 20) +
    strncmp(data.addres, compare_base.addres, 30) +
    (
    snprintf(value_to_str1, sizeof(value_to_str1), "%g", data.indebtedness) !=
    snprintf(value_to_str2, sizeof(value_to_str2), "%g", compare_base.indebtedness)) +
    (
    snprintf(value_to_str1, sizeof(value_to_str1), "%g", data.credit_limit) !=
    snprintf(value_to_str2, sizeof(value_to_str2), "%g", compare_base.credit_limit)) +
    (
    snprintf(value_to_str1, sizeof(value_to_str1), "%g", data.cash_payments) !=
    snprintf(value_to_str2, sizeof(value_to_str2), "%g", compare_base.cash_payments)) == 0) {
        printf("%s", "Succeed\n");
    }
    printf("%s", "Error\n");
}
