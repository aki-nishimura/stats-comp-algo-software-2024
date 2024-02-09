# Planning further development of `hiperglm`

Code will produce some output, even if there is a bug in the code and the output is _not_ the intended one.
When implementing a statistical model and estimation procedure --- especially one you implement for the first time) --- how can we be confident about the correctness of its output?
We can, and generally should, check things like consistency of estimators the package produces as well as coverage of the confidence intervals.
When the goal is to enhance the computational speed or to extend the functionality of existing code, then we can also check the output against the existing code on a smaller dataset or simpler model.

Our goal is to build a package for large-scale logistic regression and later extend it to other generalized linear models. 
The main computational workhorse will be iteratively re-weighted least squares. 
Let's consider getting there in smaller steps so that, when we get there, we will be pretty confident about its output.
To this end, our approach will be to start with a pre-packaged `stats::optim()` because 1) we then only need to make sure that we feed it with a function that correctly calculate the log-likelihood and its gradient and 2) gradient calculations are amenable to unit-testing.

In fact, for extra caution we will even test the optimizer on the linear model, where the analytical solution is available as $\hat{\boldsymbol{\beta}}_\textrm{mle} = (\boldsymbol{X}^\intercal \boldsymbol{X})^{-1} \boldsymbol{X}^\intercal \boldsymbol{y}$, before moving onto the logistic model.
In other words, we first makes sure that, when applied to the linear model log-likelihood, the output of `stats::optim()` coincides with that obtained via the analytical linear algebra expression.

**Comment on test design:**

Software's behavior can be, and should be, tested/validated at different scales. 
You can check if a single routine does what you intended for it to do. You can also check if how multiple routines fit together. 
_Unit testing_ validates behavior of each unit &mdash; the smallest piece of code that can be logically isolated in a system.
