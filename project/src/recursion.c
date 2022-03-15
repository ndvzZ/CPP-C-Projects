#include <stdio.h>

int rec(int count, int n) {
    
    printf("%d",count);
    if (count >= n)
        return n;
   return rec(count + 1, n);

}
