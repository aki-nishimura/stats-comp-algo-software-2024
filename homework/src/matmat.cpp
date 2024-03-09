#include <Rcpp.h>

using Rcpp::NumericMatrix;
using Rcpp::NumericVector;

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
  for (int i = 0; i < n_row_out; i++) {
    for (int j = 0; j < n_col_out; j++) {
      result(i, j) = sum(A(i, Rcpp::_) * B(Rcpp::_, j));
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
  int n_inner = A.ncol();
  NumericMatrix result(n_row_out, n_col_out);
  for (int j = 0; j < n_col_out; ++j) {
    result(Rcpp::_, j) = A(Rcpp::_, 0) * B(0, j);
    for(int i = 1; i < n_inner; ++i) {
      result(Rcpp::_, j) = result(Rcpp::_, j) + A(Rcpp::_, i) * B(i, j);
      // NumericVector x = result(Rcpp::_, j);
      // Rcpp::Rcout << "i is " << i << std::endl;
      // Rcpp::Rcout << "The value is " << x << std::endl;
    }
  }
  return result;
}
