//
// Created by malar on 1/30/22.
//

#include "genetic.h"

#include <vector>
#include <random>
#include <functional>
#include <iostream>
#include <algorithm>
#include <numeric>

#include <chrono>
#include "subset_problem.h"
#include "genetic.h"


using chromosome_t = std::vector<char>;

using namespace std;

random_device rdevice;
mt19937 randgen(rdevice());


string chromosome_to_string(chromosome_t c) {
    string s = "";
    for (auto i: c) s = s + to_string((int) i);
    return s;
}

int tournament_selection(const vector<chromosome_t> &pop, const vector<double> &pop_fit) {
    int tournament_size = 2;
    uniform_int_distribution<int> dist(0, pop.size() - 1);
    vector<int> tournament;
    for (int t = 0; t < tournament_size; t++) {
        tournament.push_back(dist(randgen));
    }
    sort(
            tournament.begin(), tournament.end(), [&](auto a, auto b) { return pop_fit[a] < pop_fit[b]; });
    return tournament.at(0);
}

int roulette_selection(const vector<chromosome_t> &pop, const vector<double> &pop_fit) {
    double s = 0.0;
    for (int i = 0; i < pop.size(); i++) s += pop_fit[i];
    uniform_real_distribution<double> dist(0, s);
    double p_sum = 0.0;
    double r = dist(randgen);
//    cout << pop.size() << " s:" << s << " r:" << r ;
    for (int i = 0; i < pop.size(); i++) {
        p_sum += pop_fit[i];
//        cout << " [" << i << "]" << p_sum;
        if (r < p_sum) {
//            cout << endl;
            return i;
        }
    }
//    cout << " -> " << " s:" << s << " r:" << r << endl;
    throw std::invalid_argument("you cannot have r out of range");
}

vector<chromosome_t> one_point_crossover(double p_cross, const chromosome_t &a_, const chromosome_t &b_) {
    uniform_int_distribution<int> dist(0, (int) a_.size() - 1);
    int pp = dist(randgen);
    auto a = a_;
    auto b = b_;
    for (int l = pp; l < a.size(); l++) {
        swap(a[l], b[l]);
    }
//    cout << "["<< pp <<"]: " << chromosome_to_string(a_) << " -> " << chromosome_to_string(a) << endl;
//    cout << "["<< pp <<"]: " << chromosome_to_string(b_) << " -> " << chromosome_to_string(b) << endl;
    return {a, b};
}

chromosome_t uniform_mutation(double p_mut, chromosome_t c) {
    return c;
}


vector<chromosome_t> genetic_alg(my_set set, int sum, int population_size, int chromosome_size, int iterations,
                                 function<double(chromosome_t, my_set, int)> fitness_f,
                                 double p_cross, double p_mut,
                                 function<int(const vector<chromosome_t> &, const vector<double> &)> selection,
                                 function<vector<chromosome_t>(double, const chromosome_t &,
                                                               const chromosome_t &)> crossover,
                                 function<chromosome_t(double, const chromosome_t &)> mutation) {
    uniform_int_distribution<char> distr(0, 1);
    vector<chromosome_t> pop(population_size);
    vector<double> pop_fit(population_size);

    // populacja początkowa
    for (auto &c: pop) {
        c.resize(chromosome_size);
        for (auto &g: c) {
            g = distr(randgen);
        }
    }

    for (int iteration = 0; iteration < iterations; iteration++) {
        // liczymy fitness dla wszystkich elementow
        for (unsigned i = 0; i < pop.size(); i++) {
            pop_fit[i] = fitness_f(pop[i], set, sum);
        }
        cout << "[" << iteration << "]";
        for (int i = 0; i < pop.size(); i++) {
            cout << " " << pop_fit[i] << ":" << chromosome_to_string(pop[i]);
        }
        cout << endl;

        vector<chromosome_t> parents;
        vector<chromosome_t> children;
        for (int i = 0; i < pop.size(); i++)
            parents.push_back(pop[selection(pop, pop_fit)]);
        int parents_idx = 1;
        while ((children.size() < pop.size()) && (parents_idx < pop.size())) {
            for (auto e: crossover(p_cross, parents.at(parents_idx), parents.at(parents_idx - 1)))
                children.push_back(e);
            parents_idx += 2;
        }

        for (auto &c: children) {
            c = mutation(p_mut, c);
        }

        pop = children;

    }
    return pop;
}

/// implementacja zadania

int one_max_function(chromosome_t c, my_set set, int sum) {
    int chromSum = 0;
    int index = 0;
    for (int g: c) {
        if (g == 1) {
            chromSum += set.at(index);
        }
        index++;
    }
    return abs(chromSum-sum);
}
/*
int main() {
    my_set set;
    set.push_back(1);
    set.push_back(2);
    set.push_back(3);
    set.push_back(4);
    set.push_back(5);
    set.push_back(6);
    set.push_back(7);
    genetic_alg(set, 13, 10, set.size(), 25, one_max_function, 0.9, 0.1, tournament_selection);
    return 0;

 }*/