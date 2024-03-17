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
Eigen::MatrixXd dgemv_eigen(Eigen::Map<Eigen::MatrixXd> A, Eigen::Map<Eigen::VectorXd> x){
    return A * x;
}