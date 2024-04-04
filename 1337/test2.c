#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void fun( int*, int* );

int main( int argc, char* argv[] )

{

    int i=5, j=2;

    fun( &i, &j );

    printf( "%d, %d", i, j );

    return 0;

}

void fun( int *i, int *j )

{

    *i = *i * *i;

    *j = *j * *j;

}