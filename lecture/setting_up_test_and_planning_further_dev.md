# Planning further development of `hiperglm`
Question: when implementing a statistical model and estimation procedure (especially one you implement for the first time), how can we be more confident about its output?
We can (and generally should) check things like consistency of estimators the package produces as well as coverage of the confidence intervals .
When the goal is to enhance the computational speed or to extend the functionality of existing code, then we can also check the output against the existing code on a smaller dataset or simpler model.

Our goal is to build a package for large-scale logistic regression and, later, for other generalized linear models. 
The main computational workhorse will be iteratively re-weighted least squares. 
How should we get there in steps?
- Let's start with a pre-packaged `stats::optim()`
  * We only need to make sure that we feed it with a function that correctly calculate the log-likelihood and its gradient.
  * And gradient calculations are amenable to unit-testing.
- We can also test the optimizer on the linear model, where the analytical solution is available, before moving onto the logistic model.

Software's behavior can be (and should be) tested/validated at different scales. You can check if a single routine does what you intended for it to do. You can also check if how multiple routines fit together. _Unit testing_ validates behavior of each unit &mdash; the smallest piece of code that can be logically isolated in a system.