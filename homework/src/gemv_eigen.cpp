#include <RcppEigen.h>
// [[Rcpp::depends(RcppEigen)]]

using Eigen::Map;
using Eigen::MatrixXd;
using Eigen::VectorXd;

// [[Rcpp::export]]
VectorXd dgemv_eigen(Map<MatrixXd> A, Map<VectorXd> v) {
  int n_col_left_mat = A.cols();
  int n_row_right_mat = A.rows(); // Corrected the variable name to get the number of rows of A
  if (n_col_left_mat != v.size()) { // Changed to check the size of the vector v
    Rcpp::stop("Incompatible matrix and vector dimensions.");
  }
  return A * v;
}
