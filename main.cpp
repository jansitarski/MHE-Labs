#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>
#include "subset_problem.h"

///Subset sum problem

using namespace std; ///< bad practice, but useful in examples for MHE


int main(int argc, char **argv) {
    //test_if_it_works();
    //auto problem = load_problem("example1.txt");
    //auto problem =
    ///Working :subsetProblem({3, 4, 5, 2}, 6);
    ///Working: subsetProblem(loadProblemFromFile("../Lab3/example1.txt"),5);
    ///bool n = false;
    ///while (!n) {
    ///    n = subsetProblem(generate_random_problem(100, 100), 10);
    ///}
    hill_climb({1, 2, 3, 4, 5, 6, 7, 8}, 20, 100, 300);
    //cout << problem << endl;
    //auto cost_func = cost_function_factory(problem);
    //work_point_t sol_candidate = generate_random_tsp_point(problem);
    //cout << "cost for: " << make_pair(problem, sol_candidate) << "is " << cost_func(sol_candidate) << endl;


    //work_point_t best_solution =  brute_force_tsp(problem, cost_func);

    //cout << "best cost for: " << make_pair(problem, best_solution) << "is " << cost_func(best_solution) << endl;

    return 0;
}