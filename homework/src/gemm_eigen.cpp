#include <RcppEigen.h>
// [[Rcpp::depends(RcppEigen)]]

using Eigen::Map;
using Eigen::MatrixXd;  
using Eigen::VectorXd;

// [[Rcpp::export]]
VectorXd dgemv_eigen(Map<MatrixXd> A, Map<VectorXd> B) {
  if (A.cols() != B.size()) {
    Rcpp::stop("Incompatible matrix and vector dimensions.");
  }
  return A * B;
}