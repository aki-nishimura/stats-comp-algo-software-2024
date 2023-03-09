pre_allocate_error_list <- function(array_len, metrics) {
  error_list <- list()
  for (metric in metrics) {
    error_list[[metric]] <- rep(0, array_len)
  }
  return(error_list)
}

calc_rel_error <- function(v, v_approx, metric) {
  if (metric == "norm") {
    rel_error <- sqrt(sum((v - v_approx)^2) / sum(v^2))
  } else {
    coordwise_err <- abs((v - v_approx) / v)
    rel_error <- switch(metric,
      five_percentile = { quantile(coordwise_err, 0.05) },
      median = { median(coordwise_err) },
      ninety_five_percentile = { quantile(coordwise_err, 0.95) }
    )
  }
  return(rel_error)
}