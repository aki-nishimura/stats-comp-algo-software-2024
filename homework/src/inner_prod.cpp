#include <Rcpp.h>
using Rcpp::NumericVector;

// [[Rcpp::export]]
double inner_prod(const NumericVector& v, const NumericVector& w) {
  if (v.size() != w.size()) {
    Rcpp::stop("Incompatible vector lengths.");
  }
  double result = 0;
  for (int i = 1; i <= v.size(); ++i) {
    result += v[i] * w[i];
  }
  return result;
}
