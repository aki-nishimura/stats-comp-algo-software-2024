install_and_load_packages <- function(package_names) {
  for (pkg in package_names) {
    if (!(pkg %in% rownames(installed.packages()))) {
      install.packages(pkg)
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