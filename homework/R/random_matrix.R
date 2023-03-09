rand_positive_def_matrix <- function(
    size, cond_num = 1e3, eigval_beta_dist_param = c(1, 1)
) {
  U <- rand_orthog_matrix(size)
  shape1 <- eigval_beta_dist_param[1]
  shape2 <- eigval_beta_dist_param[2]
  eigval <- 1 + (cond_num - 1) * rbeta(size - 2, shape1, shape2)
  eigval <- c(1, cond_num, eigval)
  A <- t(U) %*% diag(eigval) %*% U
  return(A)
}

# Sample from a uniform dist on a Stiefel manifold. For more details, see:
# https://en.wikipedia.org/wiki/Stiefel_manifold
rand_orthog_matrix <- function(mat_size) {
  iid_gauss_mat <- matrix(rnorm(mat_size^2), nrow = mat_size, ncol = mat_size)
  U <- qr_wrapper(iid_gauss_mat)$Q
  return(U)
}

# Returns un-pivoted (Q, R) factors so that X == Q %*% R
qr_wrapper <- function(X) {
  qr_result <- qr(X)
  Q <- qr.Q(qr_result)
  R <- qr.R(qr_result)
  R <- R[ , order(qr_result$pivot)]
  return(list(Q = Q, R = R))
}
