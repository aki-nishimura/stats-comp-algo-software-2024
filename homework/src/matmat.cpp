#include <Rcpp.h>

using Rcpp::NumericMatrix;
using Rcpp::NumericVector;

// [[Rcpp::export]]
NumericMatrix row_col_dot_matmat(
    const NumericMatrix& A, const NumericMatrix& B
  ) {
  if (A.ncol() != B.nrow()) {
    Rcpp::stop("Incompatible dimensions");
  }
  int n_row_out = A.nrow();
  int n_col_out = B.ncol();
  NumericMatrix result(n_row_out, n_col_out);
  // Fill in; remember to use (,) instead of [,] for accessing matrix elements
  for (int i=0; i < n_row_out; ++i){
      
      for(int j=0; j < n_col_out; ++j){
          result(i,j) = 0;
          for(int k=0; k < B.nrow(); ++k){
              result(i,j) += A(i,k) * B(k,j);
          }

      }
  }
  return result;
}

// [[Rcpp::export]]
NumericMatrix col_oriented_matmat(
    const NumericMatrix& A, const NumericMatrix& B
  ) {
  if (A.ncol() != B.nrow()) {
    Rcpp::stop("Incompatible dimensions");
  }
  int n_row_out = A.nrow();
  int n_col_out = B.ncol();
  NumericMatrix result(n_row_out, n_col_out);
  for (int j = 0; j < n_col_out; ++j) {
      //NumericVector col_B = B.column(j); 
      for (int i = 0; i < n_row_out; ++i) {
// NumericVector row_A = A.row(i); 
          result(i,j)=0;
          for (int k = 0; k < A.ncol(); ++k) {
              result(i,j) += A(i,k) * B(k,j);
          }
      }
  }
  return result;
}

