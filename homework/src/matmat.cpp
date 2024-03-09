#include <Rcpp.h>

using Rcpp::NumericMatrix;
using Rcpp::NumericVector;

// [[Rcpp::export]]
double correct_inner_prod(const NumericVector& v, const NumericVector& w) {
  if (v.size() != w.size()) {
    Rcpp::stop("Incompatible vector lengths.");
  }
  double result = 0;
  for (int i = 0; i < v.size(); ++i) {
    result += v[i] * w[i];
  }
  return result;
}

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
  for (int i = 0; i < n_row_out; ++i) {
    for (int j = 0; j < n_col_out; ++j){
      result(i,j) = correct_inner_prod(A(i,Rcpp::_), B(Rcpp::_,j));
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
    for (int i = 0; i < n_row_out; ++i){
      result(i,j) = correct_inner_prod(A(i,Rcpp::_), B(Rcpp::_,j));
    }
  }
  return result;
}
