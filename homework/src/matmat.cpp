#include <Rcpp.h>

using Rcpp::NumericMatrix;
using Rcpp::NumericVector;
using Rcpp::_;

// [[Rcpp::export]]
NumericMatrix row_col_dot_matmat(
    const NumericMatrix& A, const NumericMatrix& B
  ) {
  if (A.ncol() != B.nrow()) {
    Rcpp::stop("Incompatible dimensions");
  }
  int n_row_out = A.nrow();
  int n_col_out = B.ncol();
  int n_length = A.ncol();
  NumericMatrix result(n_row_out, n_col_out);
  // Fill in; remember to use (,) instead of [,] for accessing matrix elements
  for (int row = 0; row < n_row_out; ++row) {
    for (int col = 0; col < n_col_out; ++col) {
      double sum = 0;
      for (int i = 0; i < n_length; ++i) {
        sum += A(row, i) * B(i, col);
      }
      result(row, col) = sum;
    }
  }
  return result;
}



// [[Rcpp::export]]
NumericMatrix col_oriented_matmat(
    const NumericMatrix& A, const NumericMatrix& B
  ) {
  if (A.ncol() != B.nrow()) {
    Rcpp::stop("Incompatible dimensions");
  }
  int n_row_out = A.nrow();
  int n_col_out = B.ncol();
  NumericMatrix result(n_row_out, n_col_out);
  for (int j = 0; j < n_col_out; ++j) {
    // Calculate result[, j] = A %*% B[, j] in column-oriented manner for each j
    // Fill in
    
    NumericVector Bcol = B(_, j);
    for (int i = 0; i < A.ncol(); ++i) {
      for (int k = 0; k < n_row_out; ++k) {
        result(k, j) += A(k, i) * B(i, j);
      }
    }
  }
  return result;
}
