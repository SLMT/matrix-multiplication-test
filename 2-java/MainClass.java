import java.util.Random;

public class MainClass {
  private static final int n = 4096;

  private static double[][] A = new double[n][n];
  private static double[][] B = new double[n][n];
  private static double[][] C = new double[n][n];

  public static void main(String[] args) {
    Random r = new Random();

    // Generate matrices
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        A[i][j] = r.nextDouble();
        B[i][j] = r.nextDouble();
        C[i][j] = 0;
      }
    }

    long startTime = System.nanoTime();

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          C[i][j] += A[i][k] * B[k][j];
        }
      }
    }

    long endTime = System.nanoTime();

    double diff = (endTime - startTime) * 1e-9;
    System.out.println(String.format("Execution time: %.6f seconds", diff));
  }
}