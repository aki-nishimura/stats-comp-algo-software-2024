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