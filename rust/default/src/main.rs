use std::time::Instant;
use rand::prelude::*;

const N: usize = 1024;

fn main() {
    let mut A: Vec<Vec<f64>> = vec![vec![0.0; N]; N];
    let mut B: Vec<Vec<f64>> = vec![vec![0.0; N]; N];
    let mut C: Vec<Vec<f64>> = vec![vec![0.0; N]; N];

    // Generate matrices
    for i in 0 .. N {
        for j in 0 .. N {
            A[i][j] = rand::random::<f64>();
            B[i][j] = rand::random::<f64>();
        }
    }

    let start_time = Instant::now();

    // Matrix Multiplication
    for i in 0 .. N {
        for j in 0 .. N {
            for k in 0 .. N {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    let elapsed = start_time.elapsed().as_secs_f64();
    println!("Execution time: {:.6} seconds", elapsed);
}
