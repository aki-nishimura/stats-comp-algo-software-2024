#include <Rcpp.h>
using Rcpp::NumericMatrix;
using Rcpp::NumericVector;

// [[Rcpp::export]]
NumericMatrix row_col_dot_matmat(const NumericMatrix& A, const NumericMatrix& B) {
  if (A.ncol() != B.nrow()) {
    Rcpp::stop("Incompatible dimensions");
  }
  
  int n_row_out = A.nrow();
  int n_col_out = B.ncol();
  int n_new = A.ncol();
  
  NumericMatrix result(n_row_out, n_col_out);
  
  // Loop over rows of A
  for (int i = 0; i < n_row_out; ++i) {
    // Loop over columns of B
    for (int j = 0; j < n_col_out; ++j) {
      double sum = 0.0;
      // Compute dot product of row i of A and column j of B
      for (int k = 0; k < n_new; ++k) {
        sum += A(i, k) * B(k, j);
      }
      result(i, j) = sum;
    }
  }
  
  return result;
}

// [[Rcpp::export]]
NumericMatrix col_oriented_matmat(const NumericMatrix& A, const NumericMatrix& B) {
  if (A.ncol() != B.nrow()) {
    Rcpp::stop("Incompatible dimensions");
  }
  
  int n_row_out = A.nrow();
  int n_col_out = B.ncol();
  int n_new = A.ncol();
  
  NumericMatrix result(n_row_out, n_col_out);
  
  // Loop over columns of B
  for (int j = 0; j < n_col_out; ++j) {
    // Loop over rows of A
    for (int k = 0; k < n_new; ++k) {
      double sum = 0.0;
      // Compute dot product of row i of A and column j of B
      for (int i = 0; i < n_row_out; ++i) {
        result(i, j) += A(i, k) * B(k, j);
      }
    }
  }
  
  return result;
}
