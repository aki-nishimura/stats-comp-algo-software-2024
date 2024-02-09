install_and_load_packages <- function(package_names) {
  for (pkg in package_names) {
    if (!(pkg %in% rownames(installed.packages()))) {
      install.packages(pkg, repos = "http://cran.us.r-project.org")
        # `knitr` requires setting a CRAN mirror: https://stackoverflow.com/questions/33969024
    }
    library(pkg, character.only = TRUE)
  }
}

are_all_close <- function(v, w, abs_tol = 1e-6, rel_tol = 1e-6) {
  abs_diff <- abs(v - w)
  are_all_within_atol <- all(abs_diff < abs_tol)
  are_all_within_rtol <- all(abs_diff < rel_tol * pmax(abs(v), abs(w)))
  return(are_all_within_atol && are_all_within_rtol)
}

summarize_benchmark <- function(bench_output, include_expression = FALSE) {
  col_to_print <- c("min", "median", "mem_alloc", "n_itr")
  if (include_expression) {
    col_to_print <- c("expression", col_to_print)
  }
  print_output <- capture.output(print(bench_output[col_to_print]))
  row_to_print <- c(2, 4)
  for (i in row_to_print) {
    cat(paste0(print_output[i], '\n'))
  }
}

simulate_sparse_binary_design <- function(
    n_obs, n_pred, density, repr = "C", seed = NULL
  ) {
  if (!is.null(seed)) {
    set.seed(seed)
  }
  if (density < 0 || density > 1) {
    stop("Density must be between 0 and 1")
  }
  if (n_obs < 1 || n_pred < 1) {
    stop("Number of observations and predictors must be larger than 1")
  }
  n_obs <- floor(n_obs)
  n_pred <- floor(n_pred)
  n_nonzero <- as.integer(n_obs * n_pred * density)
  nnz_linear_index <- sample(n_obs * n_pred, n_nonzero, replace = FALSE)
  row_index <- nnz_linear_index %% n_obs + 1
  col_index <- (nnz_linear_index - 1) %/% n_obs + 1
  design_mat <- sparseMatrix(
    i = row_index, j = col_index, x = 1, dims = c(n_obs, n_pred), repr = repr
  )
  return(design_mat)
}