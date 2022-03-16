#include <stdio.h>

int rec(int count, int n) {
    if (n > 0) {
    if (count != n)
    {printf("%i ", count);} else {
    printf("%i", count);
}
    if (count >= n)
        return n;
return rec(count + 1, n);} else {
    if (count != n) {
        printf("%i ", count);} else {
        printf("%i", count);
    }
    if (count <= n)
        return n;
return rec(count - 1, n);
    }
}
