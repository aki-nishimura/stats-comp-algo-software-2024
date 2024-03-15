#include <Rcpp.h>
using Rcpp::NumericVector;

// [[Rcpp::export]]
NumericVector axpy_c(double a, NumericVector& x, NumericVector& y) {
  int n = x.size();
  for (int i = 0; i < n; ++i) {
    y[i] += a * x[i];
  }
  return y;
}

// [[Rcpp::export]]
NumericVector safe_axpy_c(double a, NumericVector& x, NumericVector& y) {
  int n = x.size();
  if (x.size() != y.size()) {
    Rcpp::stop("x and y have different lengths.");
  }
  for (int i = 0; i < n; ++i) {
    y[i] += a * x[i];
  }
  return y;
}
