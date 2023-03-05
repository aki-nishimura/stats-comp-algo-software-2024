#include <RcppEigen.h>
// [[Rcpp::depends(RcppEigen)]]

using Eigen::Map;
using Eigen::MatrixXd;  

// [[Rcpp::export]]
MatrixXd dgemm_eigen(Map<MatrixXd> A, Map<MatrixXd> B) {
  int n_col_left_mat = A.cols();
  int n_row_right_mat(B.rows()); // Equivalent to above
  if (n_col_left_mat != n_row_right_mat) {
    Rcpp::stop("Incompatible matrix dimensions.");
      // In C++, you are responsible for your own safety
  }
  return A * B;
}