#include <Rcpp.h>
using Rcpp::NumericVector;

// [[Rcpp::export]]
NumericVector axpy_c_alt(double a, NumericVector& x, NumericVector& y) {
  int n = x.size();
  NumericVector result(n); // Allocate a new vector
  for (int i = 0; i < n; ++i) {
    result[i] = y[i] + a * x[i];
  }
  return result;
}
