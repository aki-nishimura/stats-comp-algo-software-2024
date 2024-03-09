#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

using arma::mat;  

// [[Rcpp::export]]
mat dgemm_arma(mat A, mat B) {
  return A * B;
}
