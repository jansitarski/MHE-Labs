#include <iostream>
#include <fstream>

#include "subset_problem.h"
#include "genetic.h"
///Subset sum problem

using namespace std; ///< bad practice, but useful in examples for MHE


int main(int argc, char **argv) {
    my_set data;
    //my_set data1 = generate_random_problem(30, 30);

    //for (int i = 2; i < 5; i++) {
    //    data.clear();
    //    bruteforce(data1, data, 20,
    //              0, data1.size()-1,
    //              0, i);
    //}
    //for (int num:data) {
    //    cout<<num<<" ";
    //}
    //cout<<endl;


    int choice, n, size, sum, q, r, tabu_length, count;
    //cout << argc;
    if (argc > 1) {
        string argv1 = argv[1];
        if (argv1 == "-f") {
            string file = argv[2];
            if (argc <= 3) {
                for (int j = 2; j <= 10; j++) {
                    data.clear();
                    bruteforce(loadProblemFromFile(file), data, 13,
                               0, loadProblemSizeFromFile(file)-1,
                               0, j);
                }
            } else {
                string output = argv[3];
                std::ofstream ofs{output};
                auto cout_buff = std::cout.rdbuf();
                std::cout.rdbuf(ofs.rdbuf());

                for (int j = 2; j <= 10; j++) {
                    data.clear();
                    bruteforce(loadProblemFromFile(file), data, 13,
                               0, loadProblemSizeFromFile(file)-1,
                               0, j);
                }
                std::cout.rdbuf(cout_buff);

            }
        } else if (argc > 8) {
            //string argv1 = argv[1];
            if (argv1 == "Hill") {
                choice = 1;
            } else if (argv1 == "Tabu") {
                choice = 2;
                tabu_length = atoi(argv[7]);
            } else if (argv1 == "Genetic") {
                choice = 3;
            }
            n = atoi(argv[2]);
            size = atoi(argv[3]);
            sum = atoi(argv[4]);
            q = atoi(argv[5]);
            r = atoi(argv[6]);
            count = atoi(argv[7]);
        }
    } else {
        cout << "1.Hill, 2.Tabu, 3.Genetic" << endl;
        cin >> choice;
        cout << "n, size, sum" << endl;
        cin >> n >> size >> sum;
        cout << "q, r" << endl;
        cin >> q >> r;
        if (choice == 2) {
            cout << "tabu_length" << endl;
            cin >> tabu_length;
        }
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
        case 3:
            genetic_alg(10, 20, 30, one_max_function);
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