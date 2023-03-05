#include <RcppEigen.h>
// [[Rcpp::depends(RcppEigen)]]

using Eigen::VectorXd;
using Eigen::Map; // 'Map' (i.e. reference w/o making copies) R matrices

// [[Rcpp::export]]
void axpy_eigen(double a, const Map<VectorXd> x, Map<VectorXd> y) {
  y += a * x;
}
