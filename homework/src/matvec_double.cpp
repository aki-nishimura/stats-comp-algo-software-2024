#include <RcppEigen.h>
// [[Rcpp::depends(RcppEigen)]]

using Eigen::Map;
using Eigen::VectorXd; 
using Eigen::MatrixXd;

// [[Rcpp::export]]
VectorXd matvec_double(Map<MatrixXd> A, Map<VectorXd> v) {
  if (A.rows() != v.size()) {
    Rcpp::stop("Incompatible matrix-vector dimensions.");
  }
  return A * v;
}