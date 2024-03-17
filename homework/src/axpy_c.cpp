#include <Rcpp.h>
using Rcpp::NumericVector;

// [[Rcpp::export]]
NumericVector axpy_c(double a, NumericVector& x, NumericVector& y) {
  if (x.size() > y.size()) {
    Rcpp::stop("Incompatible vector lengths.");
  }
  int n = x.size();
  for (int i = 0; i < n; ++i) {
    y[i] += a * x[i];
  }
  return y;
}
