# Line_search_solver
The C++ version implementation of the line search algorithm to locate the minimum of an explicitly defined multivariate function.

Current example is function $f(x,y)=(x−2)^4+(x−2y)^2$, which is a smooth, non-convex function with a unique global minimum at $\left( 2,1 \right) $.

The algorithm design follows the standard approach outlined in 《Numerical Optimization》 by Jorge Nocedal and Stephen J. Wright (2nd ed., Springer, 2006) [Section 3.1: Line Search Methods].
