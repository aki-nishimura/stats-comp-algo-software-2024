#include <RcppEigen.h>
// [[Rcpp::depends(RcppEigen)]]

using Eigen::Map;
using Eigen::MatrixXd;  

// [[Rcpp::export]]
MatrixXd dgemm_eigen(Map<MatrixXd> A, Map<MatrixXd> B) {
  return A * B;
}
