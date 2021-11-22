#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>
#include "subset_problem.h"

///Subset sum problem

using namespace std; ///< bad practice, but useful in examples for MHE


int main(int argc, char **argv) {
    ///Working :subsetProblem({3, 4, 5, 2}, 6);
    ///Working: subsetProblem(loadProblemFromFile("../Lab3/example1.txt"),5);
    ///bool n = false;
    ///while (!n) {
    ///    n = subsetProblem(generate_random_problem(100, 100), 10);
    ///}
    hill_climb({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 20, 30, 40, 50, 51}, 24, 100, 1000);

    return 0;
}