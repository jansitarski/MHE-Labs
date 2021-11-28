#ifndef __SUBSET_PROBLEM_IMPLEMENTATION___
#define __SUBSET_PROBLEM_IMPLEMENTATION___

#include <functional>
#include <tuple>
#include <vector>
#include <string>

using my_set = std::vector<int>;




my_set loadProblemFromFile(std::string fname);

bool subsetProblem(my_set set, int sum);

my_set generate_random_problem(int n, int size);

void hill_climb(my_set set, int sum, int q, int r);

void tabu_search(my_set set, int sum, int q, int r, int tabu_length);

std::istream& operator>>(std::istream& stream, my_set mySet);

void printSubset(bool *arr, int n, int m);

std::ostream& operator<<(std::ostream& o, const my_set &mySet);


#endif