#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
arma::mat dgemm_arma(arma::mat& A, arma::mat& B) { 
    // '&' makes difference here
  int n_col_left_mat = A.n_cols;
  int n_row_right_mat = B.n_rows;
  if (n_col_left_mat != n_row_right_mat) {
    Rcpp::stop("Incompatible matrix dimensions.");
  }
  return A * B;
}