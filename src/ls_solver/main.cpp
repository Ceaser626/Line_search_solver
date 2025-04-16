// function f(x,y) = (x−2)^4 + (x−2y)^2
// function gradient g(x,y) = [4(x−2)^3 + 2(x−2y), -4(x-2y)]

#include <iostream>
#include "solver_api.hpp"

#define NVAR 2


int main(){
    LsSolver *solver;

    ls_setup(&solver, NVAR);

    ls_solve(solver);

    if (solver->solution->solved == 1) {
        std::cout << "Solution found in " << solver->work->iter << " iterations:" << std::endl;
        std::cout << "s = " << solver->work->s.transpose() << std::endl;  // 打印解向量
        std::cout << "Final gradient norm: " << solver->work->g.norm() << std::endl;
    } else {
        std::cout << "Failed to converge after " << solver->work->iter << " iterations." << std::endl;
        std::cout << "s = " << solver->work->s.transpose() << std::endl;  // 打印解向量
        std::cout << "Final gradient norm: " << solver->work->g.norm() << std::endl;
    }

    return 0;
}





