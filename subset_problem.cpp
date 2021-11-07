
#include "subset_problem.h"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <iterator>

using namespace std;

//}
mt19937 rand_gen(1);

//}

my_set loadProblemFromFile(string fname) {
    int number;
    vector<int> set;

    ifstream input_file(fname);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << fname << "'" << endl;
        return {0};
    }

    while (input_file >> number) {
        set.push_back(number);
    }
    input_file.close();
    return set;
}

//function<double(work_point_t)> cost_function_factory(my_graph_t tsp_problem) {
//    return [=](work_point_t list_of_cities) -> double {
//        double sum = 0;
//        for (int i = 0; i < list_of_cities.size(); i++) {
//            int city1 = list_of_cities[i], city2 = list_of_cities[(i + 1) % list_of_cities.size()];
//            double cost = tsp_problem.at(city1).at(city2);
//            if (cost == 0.0) throw string("no connection between cities");
//            sum = sum + cost;
//        }
//        return sum;
//    };
//void test_if_it_works() {
//    my_graph_t cities = {
//            // 0    1    2    3    4
//            {0.0, 1.0, 2.0, 5.0, 8.0}, // 0
//            {1.0, 0.0, 4.0, 3.0, 9.0}, // 1
//            {2.0, 4.0, 0.0, 2.0, 6.0}, // 2
//            {5.0, 3.0, 2.0, 0.0, 3.0}, // 3
//            {8.0, 9.0, 6.0, 3.0, 0.0}  // 4
//    };
//    // 1 + 4 + 2 + 3 + 8 =  20
//
//    auto cost_func = cost_function_factory(cities);
//    work_point_t sol_candidate = {0, 2, 1, 3, 4};
//    cout << "cost for: ";
//    for (auto c: sol_candidate)
//        cout << c << " ";
//    cout << "is " << cost_func(sol_candidate) << endl;
//work_point_t generate_random_tsp_point(my_graph_t problem) {
//    vector<int> cities_to_take;
//    work_point_t result;
//    for (int i = 0; i < problem.size(); i++)
//        cities_to_take.push_back(i);
//    while (cities_to_take.size()) {
//        uniform_int_distribution<int> distr(0, cities_to_take.size() - 1);
//        int idx = distr(rand_gen);
//        result.push_back(cities_to_take.at(idx));
//        cities_to_take.erase(cities_to_take.begin() + idx);
//    }
//    return result;
//work_point_t generate_first_tsp_point(my_graph_t problem) {
//    work_point_t f;
//    for (int i = 0; i < problem.size(); i++)
//        f.push_back(i);
//    return f;
//work_point_t get_next_point(work_point_t p) {
//    next_permutation(p.begin(), p.end());
//    return p;
//}
//
//work_point_t brute_force_tsp(my_graph_t problem, function<double(work_point_t)> cost) {
//    work_point_t best_p = generate_first_tsp_point(problem);
//    double best_goal_val = cost(best_p);
//    auto p = best_p; // current work point
//    const auto p0 = p;
//    do {
//        if (cost(p) < best_goal_val) {
//            best_goal_val = cost(p);
//            best_p = p;
//            cout << "found better: " << best_goal_val << endl;
//        }
//        p = get_next_point(p);
//    } while (!(p == p0));
//    return best_p;
//}
//
//
//ostream &operator<<(ostream &o, const my_set mySet) {
//    for (auto row: set<>) {
//        o << "[ ";
//        for (auto v: row) {
//            o << v << " ";
//        }
//        o << "]" << endl;
//    }
//    return o;
//}

my_set generate_random_problem(int n) {
    uniform_int_distribution<int> distr(0, n * 2);
    my_set numbers;
    for (int i = 0; i < n; i++) {
        numbers.push_back((int) distr(rand_gen));
    }
    return numbers;
}

std::istream &operator>>(std::istream &stream, my_set mySet) {
    std::copy(std::istream_iterator<int>(stream), std::istream_iterator<int>(),
              std::back_inserter(mySet));
    return stream;
}

void printSubset(bool *arr, int n, int m) {
    int i, j;
    cout << endl << "  | ";
    for (i = 1; i <= m; i++) {
        printf("%4d", i);
    }
    cout << endl << "  | ";
    for (i = 1; i <= m; i++) {
        printf("%4s", "-");
    }
    cout << endl;
    for (i = 0; i < n; i++) {
        cout << i << " | ";
        for (j = 0; j < m; j++)
            printf("%4d", *((arr + i * m) + j));
        printf("\n");
    }
}

bool subsetProblem(my_set set, int sum) {
    int n = set.size();

    bool part[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        part[i][0] = true;
    for (int i = 1; i <= sum; i++)
        part[0][i] = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                part[i][j] = part[i - 1][j];
            if (j >= set[i - 1])
                part[i][j] = part[i - 1][j]
                             || part[i - 1][j - set[i - 1]];
        }
    }

    printSubset(reinterpret_cast<bool *>(&part), n, sum);

    cout << endl << part[n][sum] << endl;
    return part[n][sum];
}


//}

//}

//}


//}
//
//ostream &operator<<(ostream &o, const pair<my_graph_t, work_point_t> graph_w_solution) {
//    /*
//graph G {
//  a1 -- b3 [ label="2" ];
//  a1 -- b2;
//}
//    */
//
//    for (auto e: graph_w_solution.second) {
//        cerr << e << " ";
//    }
//    cerr << endl;
//    o << "graph G {" << endl;
//    // not directed!!
//    for (int row = 0; row < graph_w_solution.first.size(); row++) {
//        for (int col = 0; col < row; col++) { // graph_w_solution.first.at(row).size(); col++) {
//            if (graph_w_solution.first.at(row).at(col) > 0) {
//                bool style = false;
//                for (int i = 0; i < graph_w_solution.second.size(); i++) {
//                    if (((graph_w_solution.second.at(i) == row) &&
//                         (graph_w_solution.second.at((i + 1) % graph_w_solution.second.size()) == col)) ||
//                        ((graph_w_solution.second.at(i) == col) &&
//                         (graph_w_solution.second.at((i + 1) % graph_w_solution.second.size()) == row))) {
//                        style = true;
//                        break;
//                    }
//                }
//                o << row << " -- " << col << " [ label=\"" << graph_w_solution.first.at(row).at(col)
//                  << (style ? "\",color=red" : "\"") << " ]" << endl;
//            }
//        }
//    }
//
//    o << "}" << endl;
//    return o;
//}