#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>
#include "subset_problem.h"

///Subset sum problem

using namespace std; ///< bad practice, but useful in examples for MHE


int main(int argc, char** argv)
{
    //test_if_it_works();
    //auto problem = load_problem("example1.txt");
    //auto problem =
    Working: subsetProblem({3, 34, 4, 12, 5, 2}, 9);
    ///Working: subsetProblem(loadProblemFromFile("../Lab3/example1.txt"),5);
    ///Working: subsetProblem(generate_random_problem(5),7);
    //cout << problem << endl;
    //auto cost_func = cost_function_factory(problem);
    //work_point_t sol_candidate = generate_random_tsp_point(problem);
    //cout << "cost for: " << make_pair(problem, sol_candidate) << "is " << cost_func(sol_candidate) << endl;


    //work_point_t best_solution =  brute_force_tsp(problem, cost_func);

    //cout << "best cost for: " << make_pair(problem, best_solution) << "is " << cost_func(best_solution) << endl;

    return 0;
}