#include <iostream>

#include "subset_problem.h"

///Subset sum problem

using namespace std; ///< bad practice, but useful in examples for MHE


int main(int argc, char **argv) {
    //for (int i = 0; i < argc; ++i) {
    //    cout << argv[i] << "\n";
    //}
    int choice, n, size, sum, q, r, tabu_length, count;
    if (argc > 8) {
        string argv1 = argv[1];
        if (argv1 == "Hill") {
            choice = 1;
        } else if (argv1 == "Tabu") {
            choice = 2;
            tabu_length = atoi(argv[7]);
        }
        n = atoi(argv[2]);
        size = atoi(argv[3]);
        sum = atoi(argv[4]);
        q = atoi(argv[5]);
        r = atoi(argv[6]);
        count = atoi(argv[7]);
    } else {
        cout << "1.Hill, 2.Tabu" << endl;
        cin >> choice;
        cout << "n, size, sum" << endl;
        cin >> n >> size >> sum;
        cout << "q, r, tabu_length" << endl;
        cin >> q >> r >> tabu_length;
    }

    auto on_finish =
            [](int c, double dt) {
                cout << "# count: " << c << "; dt:  " << dt << endl;
            };
    auto on_step = [&](int i, double current_goal_val, double goal_v) {
        cout << i << " " << current_goal_val << " " << goal_v << endl;
    };

    switch (choice) {
        case 1:
            //hill_climb({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 20, 30, 40, 50, 51}, 24, 100, 1000);
            hill_climb(generate_random_problem(n, size), sum, q, r, count, on_finish, on_step);
            break;
        case 2:
            //tabu_search({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 20, 30, 40, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 50},204, 100, 100, 100);
            tabu_search(generate_random_problem(n, size), sum, q, r, count, tabu_length, on_finish, on_step);
            break;
        default:
            break;
    }
    //my_set generated = generate_random_problem(10,5);
    //for(int x : generated){
    //    cout<<x<<" ";
    //}
    ///Working :subsetProblem({3, 4, 5, 2}, 6);
    ///Working: subsetProblem(loadProblemFromFile("../Lab3/example1.txt"),5);
    ///bool n = false;
    ///while (!n) {
    ///    n = subsetProblem(generate_random_problem(100, 100), 10);
    ///}
    //hill_climb({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 20, 30, 40, 50, 51}, 24, 100, 1000);
    //tabu_search({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 20, 30, 40, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 50},204, 100, 100, 100);

    return 0;
}