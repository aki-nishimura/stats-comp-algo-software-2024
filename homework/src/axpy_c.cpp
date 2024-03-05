#include <Rcpp.h>
using Rcpp::NumericVector;

// [[Rcpp::export]]
NumericVector axpy_c(double a, NumericVector& x, NumericVector& y) {
  if (x.size() != y.size()) {
    if (x.size() < y.size()) {
      Rcpp::warning("The length of x is smaller than the length of y. Only the first %d elements of y are meaningful.\n", x.size());
    } else {
      Rcpp::stop("Incompatible vector lengths (x and y).");
    }
  }
  int n = x.size();
  for (int i = 0; i < n; ++i) {
    y[i] += a * x[i];
  }
  return y;
}
