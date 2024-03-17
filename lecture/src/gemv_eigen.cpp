#include <RcppEigen.h>
// [[Rcpp::depends(RcppEigen)]]

using Eigen::Map;
using Eigen::MatrixXd;
using Eigen::VectorXd;

// [[Rcpp::export]]
VectorXd dgemv_eigen(Map<MatrixXd> A, Map<VectorXd> v) {
  if (A.cols() != v.size()) {
    Rcpp::stop("Incompatible matrix-vector dimensions.");
  }
  return A * v;
}