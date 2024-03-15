#include <Rcpp.h>

using Rcpp::NumericMatrix;
using Rcpp::NumericVector;
using Rcpp::_;
using Rcpp::sum;

// [[Rcpp::export]]
NumericMatrix row_col_dot_matmat(
    const NumericMatrix& A, const NumericMatrix& B
  ) {
  if (A.ncol() != B.nrow()) {
    Rcpp::stop("Incompatible dimensions");
  }
  int n_row_out = A.nrow();
  int n_col_out = B.ncol();
  NumericMatrix result(n_row_out, n_col_out);
  // Fill in; remember to use (,) instead of [,] for accessing matrix elements
  for (int i=0; i<n_row_out; i++) {
    for (int j=0; j<n_col_out; j++) {
      NumericVector prods = A(i,_) * B(_,j);
      result(i, j) = sum(prods);
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
    for (int l = 0; l < A.ncol(); l++) {
      for (int k  = 0; k < n_row_out; k++) {
        result(k, j) += A(k, l) * B(l,j);
      }
    }
  }
  return result;
}
