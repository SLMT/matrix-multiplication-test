#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#define n 1024

double A[n][n];
double B[n][n];
double C[n][n];

float time_diff(struct timeval *start, struct timeval *end) {
  return (end->tv_sec - start->tv_sec) +
    1e-6 * (end->tv_usec - start->tv_usec);
}

int main(int argc, const char *argv[]) {
  // Generate matrices
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      A[i][j] = (double) rand() / (double) RAND_MAX;
      B[i][j] = (double) rand() / (double) RAND_MAX;
      C[i][j] = 0;
    }
  }

  struct timeval start_time, end_time;
  gettimeofday(&start_time, NULL);

  // Optimization: change loop order (j and k)
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      for (int j = 0; j < n; j++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  gettimeofday(&end_time, NULL);

  printf("Execution time: %.6f seconds\n", time_diff(&start_time, &end_time));

  return 0;
}
