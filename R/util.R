install_and_load_packages <- function(package_names) {
  for (pkg in package_names) {
    if (!(pkg %in% rownames(installed.packages()))) {
      install.packages(pkg)
    }
    library(pkg, character.only = TRUE)
  }
}
