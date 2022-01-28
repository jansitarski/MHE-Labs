//
// Created by malar on 1/24/22.
//

#ifndef SIMPLE_EXAMPLE_GENETIC_H
#define SIMPLE_EXAMPLE_GENETIC_H

#include <vector>
#include <random>
#include <functional>
#include <iostream>
#include <algorithm>
#include <numeric>

#include <chrono>
#include "subset_problem.h"


using chromosome_t = std::vector<char>;

using namespace std;

string chromosome_to_string(chromosome_t c);
int roulette_selection(const vector<chromosome_t> &pop, const vector<double> &pop_fit);

vector<chromosome_t> one_point_crossover(double p_cross, const chromosome_t &a_, const chromosome_t &b_);

chromosome_t uniform_mutation(double p_mut, chromosome_t c);




vector<chromosome_t> genetic_alg(int population_size, int chromosome_size, int iterations,
                        function<double(chromosome_t)> fitness_f,
                        double p_cross = 0.9, double p_mut = 0.1,
                        function<int(const vector<chromosome_t> &, const vector<double> &)> selection = roulette_selection,
                        function<vector<chromosome_t>(double, const chromosome_t &, const chromosome_t &)> crossover = one_point_crossover,
                        function<chromosome_t(double, const chromosome_t &)> mutation = uniform_mutation);
double one_max_function(chromosome_t c);


double fitness_test(chromosome_t c);

#endif //SIMPLE_EXAMPLE_GENETIC_H
