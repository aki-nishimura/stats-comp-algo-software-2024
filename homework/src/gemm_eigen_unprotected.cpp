#include <RcppEigen.h>
// [[Rcpp::depends(RcppEigen)]]

using Eigen::Map;
using Eigen::MatrixXd;  
using Eigen::VectorXd;

// [[Rcpp::export]]
MatrixXd dgemm_eigen(Map<MatrixXd> A, Map<MatrixXd> B) {
  return A * B;
}

// [[Rcpp::export]]
VectorXd dgemv_eigen(Map<MatrixXd> A, Map<VectorXd> v) {
  return A * v;
}