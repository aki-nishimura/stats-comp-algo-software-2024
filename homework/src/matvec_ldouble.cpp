#include <RcppEigen.h>
// [[Rcpp::depends(RcppEigen)]]

using Eigen::Map;
using Eigen::VectorXd; 
using Eigen::MatrixXd;  
typedef Eigen::Matrix<long double, Eigen::Dynamic, 1> VectorXld;
typedef Eigen::Matrix<long double, Eigen::Dynamic, Eigen::Dynamic> MatrixXld;

// [[Rcpp::export]]
VectorXd matvec_ldouble(Map<MatrixXd> A, Map<VectorXd> v) {
  if (A.rows() != v.size()) {
    Rcpp::stop("Incompatible matrix-vector dimensions.");
  }
  MatrixXld A_ld = A.cast<long double>();
  VectorXld v_ld = v.cast<long double>();
  VectorXd Av = (A_ld * v_ld).cast<double>();
  return Av;
}