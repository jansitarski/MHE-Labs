//
// Created by malar on 1/29/22.
//
#include "subset_problem.h"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <random>
#include <set>
#include <string>
#include <iterator>
#include <chrono>
#include "annealing.h"
#include "subset_problem.h"
#include "genetic.h"

vector<my_set> neighbors(my_set set, my_set subset) {
    vector<my_set> neigbors;
    if (subset.size() > 1) {
        my_set tempSet;
        //neighbor with shorter by 1
        for (int i = 0; i < subset.size(); i++) {
            tempSet = subset;
            tempSet.erase(tempSet.begin() + i);
            neigbors.push_back(tempSet);
        }
    }

    //Neighbor longer by one
    if (subset.size() < set.size()) {
        for (int num: set) {
            my_set tempSet;
            if (std::find(subset.begin(), subset.end(), num) == subset.end()) {
                tempSet = subset;
                tempSet.push_back(num);
                neigbors.push_back(tempSet);
            }
        }
    }
    return neigbors;
}


my_set
simulated_annealing(my_set set, my_set solution, my_set solution_best, int sum, int initial_temp, double final_temp,
                    int temp_length, double cooling_ratio, int iteration,int count,
                    function<void(int i, double current_goal_val, double goal_val)>
                    on_iteration = [](int i, double current_goal_val, double goal_val) {},
                    function<void(int c, double dt)> on_statistics = [](int c, double dt){}) {

    int bestsolsum = 0;
    for (int num: solution_best) {
        bestsolsum += num;
    }

    if (bestsolsum == 0) {
        return solution_best;
    }
    if (initial_temp <= final_temp) {
        return solution_best;
    }
    if (iteration == temp_length) {
        return solution_best;
    }

    cout << "\n~~~Iteration: {" << iteration << "}~~~" << endl;

    vector<my_set> hood = neighbors(set, solution);

    int smallestresidue=1000;
    my_set smallestNeighbour;
    cout << "Neighbours" << endl;
    for (my_set mySet: hood) {
        cout << "( ";
        int thisSum=0;
        for (int num: mySet) {
            cout << num << " ";
            thisSum+=num;
        }
        cout << "), ";
        if(abs(thisSum-sum)<smallestresidue){
            smallestresidue = abs(thisSum-sum);
            smallestNeighbour = mySet;
        }
    }
    cout << endl;

    /*int randomIndex = rand() % hood.size();
    my_set randomNeighbour = hood.at(randomIndex);
    int randomSum = 0;
    cout << "Random neighbour: ( ";
    for (int num: randomNeighbour) {
        randomSum += num;
        cout << num << " ";
    }
    cout << ") - " << randomSum << endl;
    */
    int solsum = 0;
    for (int num: solution) {
        solsum += num;
    }


/*
    if (abs(solsum - sum) > abs(randomSum - sum)) {
        solution = randomNeighbour;
        solution_best = solution;
    } else {
        double ran = rand() / (RAND_MAX + 1.);
        cout << "exp: "<<exp(-abs(randomSum - solsum) / float(initial_temp))<<endl;

        if (exp(-abs(randomSum - solsum) / float(initial_temp)) > ran) {
            solution = randomNeighbour;
        }
    }*/
    int neiSum=0;
    for (int num:smallestNeighbour) {
        neiSum+=num;
    }

    if (abs(solsum - sum) > abs(neiSum - sum)) {
        solution = smallestNeighbour;
        solution_best = solution;
    } else {
        double ran = rand() / (RAND_MAX + 1.);
        cout << "exp: "<<exp(-abs( - solsum) / float(initial_temp))<<endl;

        if (exp(-abs(neiSum - solsum) / float(initial_temp)) > ran) {
            solution = smallestNeighbour;
        }
    }
    iteration++;
    initial_temp = cooling_ratio * initial_temp;
    cout << "Temperature: " << initial_temp << endl;
    cout << "Solution: ( ";
    solsum = 0;
    for (int num: solution) {
        cout << num << " ";
        solsum += num;
    }
    cout << "): " << solsum << " - " << abs(solsum - sum) << endl;
    cout << "Best Solution: ( ";
    solsum = 0;
    for (int num: solution_best) {
        cout << num << " ";
        solsum += num;
    }
    cout << "): " << solsum << " - " << abs(solsum - sum) << endl;

    //auto finish = chrono::steady_clock::now();
    //chrono::duration<double> duration = finish - start;
    //on_statistics(count, duration.count());
    //cout << "result " << abs(sum-solsum) << endl;


    //return solution_best;
    return simulated_annealing(set, solution, solution_best, sum, initial_temp, final_temp, temp_length,
                               cooling_ratio, iteration, count+1);



}
/*
int main() {
    my_set problem = generate_random_problem(10, 10);
    my_set solution = generate_random_solution(problem, 4);
    my_set best_solution = solution;
    int initial_temp = 1500;
    int temp_length = 500;
    double cooling_ratio = 0.9;
    double final_temp = 0.01;

    int solutionSum = 0;
    for (int num: solution) {
        solutionSum += num;
    }

    //cout<<"Random solution: "<<solution<<" "<<solutionSum<<endl;
    my_set final_solution = simulated_annealing(problem, solution, best_solution, 7, initial_temp, final_temp,
                                                temp_length, cooling_ratio);
}*/