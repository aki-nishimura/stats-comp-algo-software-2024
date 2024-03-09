#include <RcppEigen.h>
// [[Rcpp::depends(RcppEigen)]]

using Eigen::Map;
using Eigen::MatrixXd;
using Eigen::VectorXd;

// [[Rcpp::export]]
MatrixXd dgemv_eigen(Map<MatrixXd> A, VectorXd v) {
  int n_col_left_mat = A.cols();
  int length_v = v.size();
  if (n_col_left_mat != length_v) {
    Rcpp::stop("Incompatible matrix dimensions.");
  }
  return A * v;
}