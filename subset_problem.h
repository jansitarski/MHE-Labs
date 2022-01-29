#ifndef __SUBSET_PROBLEM_IMPLEMENTATION___
#define __SUBSET_PROBLEM_IMPLEMENTATION___

#include <functional>
#include <tuple>
#include <vector>
#include <string>

using my_set = std::vector<int>;

my_set get_next_point(my_set p);

my_set next_solution(my_set set, my_set prevoiusSolution, int sum);

int loadProblemSizeFromFile(std::string fname);

void bruteforce(my_set arr, my_set data, int sum,
               int start, int end,
               int index, int r);

my_set loadProblemFromFile(std::string fname);

bool subsetProblem(my_set set, int sum);

my_set generate_random_problem(int n, int size);

void hill_climb(my_set set, int sum, int q, int r, int count,
                std::function<void(int c, double dt)> on_statistics = [](int c, double dt) {},
                std::function<void(int i, double current_goal_val, double goal_val)>
                on_iteration = [](int i, double current_goal_val, double goal_val) {});

std::pair<int, double> tabu_search(my_set set, int sum, int q, int r,
                                   int count, int tabu_length,
                                   std::function<void(int c, double dt)> on_statistics = [](int c, double dt) {},
                                   std::function<void(int i, double current_goal_val, double goal_val)>
                                   on_iteration = [](int i, double current_goal_val, double goal_val) {});

std::istream &operator>>(std::istream &stream, my_set mySet);

void printSubset(bool *arr, int n, int m);

std::ostream &operator<<(std::ostream &o, const my_set &mySet);


#endif