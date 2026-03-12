#include <stdio.h>

int main(int argc, char *argv[]) {

    int i = 10;
    int *p;
    p = &i;
    *p = 5;
    printf("%i - %i - %p \n", i, *p, p);

    return 0;

}