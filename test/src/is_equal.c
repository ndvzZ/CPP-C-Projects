
#include <math.h>

int is_equal(double a_compare, double b_compare) {
    double epsilon = 0.0000001;
    if (fabs(a_compare - b_compare) <= epsilon)
        return 0;
    return 1;
}
