#include <RcppEigen.h>
// [[Rcpp::depends(RcppEigen)]]

using Eigen::Map;
using Eigen::MatrixXd;
using Eigen::VectorXd;

// [[Rcpp::export]]
MatrixXd dgemv_eigen(Map<MatrixXd> A, Map<VectorXd> v) {
  int n_col_left_mat = A.cols();
  int n_elem_vec = v.size();
  if (n_col_left_mat != n_elem_vec) {
    Rcpp::stop("Incompatible matrix-vector dimensions.");
  }
  return A * v;
}
