#include <stdio.h>

int rec(int count, int n) {
    if (n > 0) {
printf("%i\t", count);
    if (count >= n)
        return n;
return rec(count + 1, n);
    } else {
        printf("%i\t", count);
    if (count <= n)
        return n;
return rec(count - 1, n);
    }
}
