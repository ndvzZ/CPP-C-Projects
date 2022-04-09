#include "main_mod.h"

#define filename "Test_config.dat"
#define filename_gold "Test_config.dat.gold"

int main(void) {
    Data expected_data = {1, "Denis", "Naga", "Addres", "88005553535", 90, 165, 28};
  //  write_to_file(filename_gold, expected_data);
    write_to_file(filename, expected_data);
    read_from_file(filename,filename_gold);
    return 0;
}