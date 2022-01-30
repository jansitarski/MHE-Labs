//
// Created by malar on 1/29/22.
//
#include "subset_problem.h"
#include "genetic.h"

#ifndef SIMPLE_EXAMPLE_ANNEALING_H
#define SIMPLE_EXAMPLE_ANNEALING_H

vector<my_set> neighbors(my_set set, my_set subset);

my_set
simulated_annealing(my_set set, my_set solution, my_set solution_best, int sum, int initial_temp, double final_temp,
                    int temp_length, double cooling_ratio, int iteration,int count,function<void(int i, double current_goal_val, double goal_val)>
                    on_iteration,
                    function<void(int c, double dt)> on_statistics);


#endif //SIMPLE_EXAMPLE_ANNEALING_H
