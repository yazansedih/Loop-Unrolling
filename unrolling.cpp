#include <immintrin.h>  // portable to all x86 compilers
#include <stdio.h>
#include <time.h>

#define DATA float

const int SIZE = 1024*1024*16;

DATA A[SIZE] ;
DATA B[SIZE] ;

// cd ~/Downloads/hw1-unrolling
// g++ -o z unrolling.cpp

double seconds() {
  struct timespec now;
  clock_gettime(CLOCK_MONOTONIC, &now);
  return now.tv_sec + now.tv_nsec / 1000000000.0;
}

void initialize_array(DATA a[], int size) {
	for (int i = 0 ;  i < size ; i++) 
	{
		a[i] = rand()%2;
	}
}

void normal(DATA a[],int size) {
    for (int i = 0 ; i < size ; i++)
    {
        a[i] = a[i] + 5;
    }
}


void unrolled_4(DATA a[], int size) {
    for (int i = 0; i < size; i += 4) {
        a[i] = a[i] + 5;
		a[i+1] = a[i+1] + 5;
		a[i+2] = a[i+2] + 5;
		a[i+3] = a[i+3] + 5;
    }
}


void unrolled_8(DATA a[], int size) {
    for (int i = 0; i < size; i += 8) {
        a[i] = a[i] + 5;
        a[i+1] = a[i+1] + 5;
        a[i+2] = a[i+2] + 5;
        a[i+3] = a[i+3] + 5;
        a[i+4] = a[i+4] + 5;
        a[i+5] = a[i+5] + 5;
        a[i+6] = a[i+6] + 5;
        a[i+7] = a[i+7] + 5;
    }
}


void unrolled_16(DATA a[], int size) {
    for (int i = 0; i < size; i += 16) {
        a[i] = a[i] + 5;
        a[i+1] = a[i+1] + 5;
        a[i+2] = a[i+2] + 5;
        a[i+3] = a[i+3] + 5;
        a[i+4] = a[i+4] + 5;
        a[i+5] = a[i+5] + 5;
        a[i+6] = a[i+6] + 5;
        a[i+7] = a[i+7] + 5;
        a[i+8] = a[i+8] + 5;
        a[i+9] = a[i+9] + 5;
        a[i+10] = a[i+10] + 5;
        a[i+11] = a[i+11] + 5;
        a[i+12] = a[i+12] + 5;
        a[i+13] = a[i+13] + 5;
        a[i+14] = a[i+14] + 5;
        a[i+15] = a[i+15] + 5;
    }
}


void unrolled_32(DATA a[], int size) {
    for (int i = 0; i < size; i += 32) {
        a[i] = a[i] + 5;
        a[i+1] = a[i+1] + 5;
        a[i+2] = a[i+2] + 5;
        a[i+3] = a[i+3] + 5;
        a[i+4] = a[i+4] + 5;
        a[i+5] = a[i+5] + 5;
        a[i+6] = a[i+6] + 5;
        a[i+7] = a[i+7] + 5;
        a[i+8] = a[i+8] + 5;
        a[i+9] = a[i+9] + 5;
        a[i+10] = a[i+10] + 5;
        a[i+11] = a[i+11] + 5;
        a[i+12] = a[i+12] + 5;
        a[i+13] = a[i+13] + 5;
        a[i+14] = a[i+14] + 5;
        a[i+15] = a[i+15] + 5;
        a[i+16] = a[i+16] + 5;
        a[i+17] = a[i+17] + 5;
        a[i+18] = a[i+18] + 5;
        a[i+19] = a[i+19] + 5;
        a[i+20] = a[i+20] + 5;
        a[i+21] = a[i+21] + 5;
        a[i+22] = a[i+22] + 5;
        a[i+23] = a[i+23] + 5;
        a[i+24] = a[i+24] + 5;
        a[i+25] = a[i+25] + 5;
        a[i+26] = a[i+26] + 5;
        a[i+27] = a[i+27] + 5;
        a[i+28] = a[i+28] + 5;
        a[i+29] = a[i+29] + 5;
        a[i+30] = a[i+30] + 5;
        a[i+31] = a[i+31] + 5;
    }
}


int main() {
    // DATA A[SIZE];
    double before, after;

    initialize_array(A, SIZE);

    // Measure time for normal loop
    before = seconds();
    normal(A, SIZE);
    after = seconds();
    double normal_time = after - before;
    printf("Normal Time: %f\n", normal_time);
    printf("\n");


    // Measure time for unrolled_4 loop
    before = seconds();
    unrolled_4(A, SIZE);
    after = seconds();
    double unrolled_4_time = after - before;
    printf("Unrolled 4 Time: %f\n", unrolled_4_time);

    double speedup_4 = normal_time / unrolled_4_time;
    printf("Speedup for Unrolled 4: %f\n", speedup_4);
    printf("\n");


    // Measure time for unrolled_8 loop
    before = seconds();
    unrolled_8(A, SIZE);
    after = seconds();
    double unrolled_8_time = after - before;
    printf("Unrolled 8 Time: %f\n", unrolled_8_time);

    // Calculate and print speedup for unrolled_8
    double speedup_8 = normal_time / unrolled_8_time;
    printf("Speedup for Unrolled 8: %f\n", speedup_8);
    printf("\n");


    // Measure time for unrolled_16 loop
    before = seconds();
    unrolled_16(A, SIZE);
    after = seconds();
    double unrolled_16_time = after - before;
    printf("Unrolled 16 Time: %f\n", unrolled_16_time);

    // Calculate and print speedup for unrolled_16
    double speedup_16 = normal_time / unrolled_16_time;
    printf("Speedup for Unrolled 16: %f\n", speedup_16);
    printf("\n");


    // Measure time for unrolled_32 loop
    before = seconds();
    unrolled_32(A, SIZE);
    after = seconds();
    double unrolled_32_time = after - before;
    printf("Unrolled 32 Time: %f\n", unrolled_32_time);

    // Calculate and print speedup for unrolled_32
    double speedup_32 = normal_time / unrolled_32_time;
    printf("Speedup for Unrolled 32: %f\n", speedup_32);
    printf("\n");

    return 0;
}

