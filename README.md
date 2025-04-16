# Line_search_solver
This implementation performs a line search algorithm to locate the minimum of an explicitly defined multivariate function.

Current example is function $f(x,y)=(x−2)^4+(x−2y)^2$, which is a smooth, non-convex function with a unique global minimum at $\left( 2,1 \right) $.

The algorithm utilizes gradient descent combined with backtracking line search to ensure sufficient decrease along the descent direction, and iteratively updates the solution until a specified convergence tolerance is satisfied.


