install_and_load_packages <- function(package_names) {
  for (pkg in required_packages) {
    if (!(pkg %in% rownames(installed.packages()))) {
      install.packages(pkg)
    }
    library(pkg, character.only = TRUE)
  }
}
