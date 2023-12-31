#include <stdio.h>
 
void function (int *x, int n) {
    int i, t, j = n, s = 1;
    while (s) { // breaks when s == 0 and loop iterates back to beginning
        s = 0;
        for (i = 1; i < j; i++) {
            if (x[i] < x[i - 1]) { // if x[i] less than x[i - 1], swap vals
                t = x[i];
                x[i] = x[i - 1];
                x[i - 1] = t;
                s = 1;
            }
        }
        j--;
    }
}
// sorting alg ^ (selection sort..?)
 
int main () {
    int x[] = {15, 56, 12, -21, 1, 659, 3, 83, 51, 3, 135, 0};
    int n = sizeof(x) / sizeof(x[0]);
    int i;
    for (i = 0; i < n; i++)
        printf("%d%s", x[i], i == n - 1 ? "\n" : " ");
    function(x, n);
    for (i = 0; i < n; i++)
        printf("%d%s", x[i], i == n - 1 ? "\n" : " ");
    return 0;
}