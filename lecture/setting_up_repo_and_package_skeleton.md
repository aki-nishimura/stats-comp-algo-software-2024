# Setting up a Git repo and GitHub remote for an R package

**Note**: In class, we started with a package name `hiperLogit` and variable names `*logit*`; this was mainly to demonstrate the tools like `grep` and `find` you can use to refactor code later. 
In setting up the package for your assignment, you can start directly with a package `hiperglm` and variable names `*glm*`.

- Initialize `hiperLogit` package skeleton
  * `usethis::create_package("~/hiperLogit")`
  * Create a Github repo `hiper-logit-demo` and set it as a remote
  * `usethis::use_mit_license()`
    - Open the repo on GitKraken for visual diff
    - Permissive vs. copyleft
    - Personal view: Use MIT license as as a default, Apache if your employer asks for it, and GPL if you have to
  * Edit DESCRIPTION
    - "Title: High-performance logistic regression for large data sets"
    - Set author and creator (more details on these roles [here](https://journal.r-project.org/archive/2012/RJ-2012-009/RJ-2012-009.pdf))
    - "Description: TBA"
- Top-down programming: start with a high-level overview of what the program does and then recursively break it down into sub-routines
- Outline function signatures:
  * `R/hiper_logit.R`
  * `hiper_logit <- function() {...}`
    - What input args should the function take?
    - Input `design` and `outcome`
    - Check for supported models
    - Warn that the function is yet to be implemented
    - Make a todo note to implement model fitting
    - Return an empty list: `hlogit_out <- list()`
  * `model_output.R`
    - No need to write a feature-rich package right from the beginning, but what are the min required outputs for this package to be a valuable resource for statistical analysis?
    - `coef`, `vcov`, (and `print` since that's kinda obligatory)
- Now install the package via `R CMD build/install` and try calling `hiper_logit()`
- Oops, I forgot to export functions...
  * `#' @export`
  * Roxygenize
- Oops, I overwrote `base::print()`...
  * Turn the output into an S3 object: `class(hlogit_out) <- "hlogit"`
  * Add `.hlogit` to the model output functions
  * (After forgetting to do so,) Roxygenize again
- Decide, out of whim, to change the package name from `hiperLogit` to `hiperglm`
  * Gotta replace all the "logit" word from the repo: `git grep --ignore-case logit`
  * Rename variables with `find R -type f -name "*.R" -exec gsed -i 's/glm/logit/g' {} \;` (since RStudio currently doesn't support refactoring)
  * Also need to change all the file names: `find * -iname "*logit*"`
  * Rename git repo
  * Change remote url `git remote set-url origin ...`
- Clean up the git history via `git rebase -i` before pushing
  * Is the record of this change of some value to others and my future self?

# Planning further development
Question: when implementing a statistical model and estimation procedure (especially one you implement for the first time), how can we be more confident about its output?
- Consistency of the estimator
- Confidence interval coverage
- If the goal is to enhance the computational speed or to extend the functionality of existing code, then we can check the output against the existing code on a smaller dataset or simpler model.

Our goal is to build a package for large-scale logistic regression and, later, for other generalized linear models. The main computational workhorse will be iteratively re-weighted least squares. How should we get there in steps?
- Let's start with a pre-packaged `stats::optim()`
  * We only need to make sure that we feed it with a function that correctly calculate the log-likelihood and its gradient.
  * And gradient calculations are amenable to unit-testing.
- We can also test the optimizer on the linear model, where the analytical solution is available, before moving onto the logistic model.

Software's behavior can be (and should be) tested/validated at different scales. You can check if a single routine does what you intended for it to do. You can also check if how multiple routines fit together. _Unit testing_ validates behavior of each unit &mdash; the smallest piece of code that can be logically isolated in a system.

# Reading assignments
* Licensing: permissive vs. copyleft
  - Choosing among three representative licenses: https://www.exygy.com/blog/which-license-should-i-use-mit-vs-apache-vs-gpl
  - Perspective on the current trend toward more permissive licensing: https://www.r-bloggers.com/2020/04/why-dash-uses-the-mit-license-and-not-a-copyleft-gpl-license/
* R package basics:
  - Short but clear tutorial by Hilary Parker: https://hilaryparker.com/2014/04/29/writing-an-r-package-from-scratch/
  - "Minimal" (but longer than Hilary's) tutorial by Karl Broman: https://kbroman.org/pkg_primer/
* S3 object: https://adv-r.hadley.nz/s3.html

<!--- Useful code snippets
n_obs <- 32; n_pred <- 4
X <- matrix(rnorm(n_obs * n_pred), nrow = n_obs)
beta <- rnorm(n_pred)
y <- X %*% beta + rnorm(n_obs)
--->
