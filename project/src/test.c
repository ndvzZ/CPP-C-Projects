
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main_module.h"

void test_write_to_file() {
    const char *filename = "Test_config.dat.gold";
    Data expected_data = {1, "Denis", "Naga", "Addres", "88005553535", 90, 165, 28};
    write_to_file(filename, &expected_data);
    const char *filename1 = "Test_config.dat";
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
    write_to_file(filename1, &got_data);
    read_from_file(filename, &expected_data);
    read_from_file(filename1, &got_data);
    if (&expected_data == &got_data) {
        printf("%s", "Succeed\n");
    }
    printf("%s", "Error\n");
}

void write_to_file(const char *filename, Data *data) {
    int f_d = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (f_d == -1) {
        perror("error");
    }
    write(f_d, data, sizeof(data));
    if (f_d > 0) {
        printf("%s", "Write Succeed\n");
    }
    printf("%s", "Write Error\n");
    close(f_d);
}

void read_from_file(const char *filename, Data *data) {
    int f_d = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (f_d == -1) {
        perror("error");
    }
//   char buffer[sizeof(data)+1];
    while (f_d > 0) {
    f_d = read(f_d, &data, sizeof(Data));
    }
    if (f_d > 0) {
        printf("%s", "Read Succeed\n");
    }
    printf("%s", "Read Error\n");
    close(f_d);
}
