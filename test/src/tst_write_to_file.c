#include <stdio.h>
#include "main_mod.h"

void write_to_file(const char *test_filename, Data writing_data) {
    FILE *File_ptr = fopen(test_filename, "w+");
    if (File_ptr == NULL) {
        puts("Not acess");
    }
    if (fprintf(File_ptr, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",
                writing_data.number,
                writing_data.name,
                writing_data.surname,
                writing_data.addres,
                writing_data.telNumber,
                writing_data.indebtedness,
                writing_data.credit_limit,
                writing_data.cash_payments) < 0)
                perror("error");
    fclose(File_ptr);
}
