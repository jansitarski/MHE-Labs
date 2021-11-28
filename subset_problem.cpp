
#include "subset_problem.h"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <random>
#include <set>
#include <string>
#include <iterator>


using namespace std;


random_device device;
mt19937 rand_gen(device());


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

void hill_climb(my_set set, int sum, int q, int r) {
    vector<int> current;
    size_t nelems = 1;
    int smallestresidue = 1000;
    int smallestsum = 0;
    for (int i = 0; i < q; i++) {
        //Choose a random subset (multiset) S′ of S as the “current” subset.
        current.erase(current.begin(), current.end());
        sample(set.begin(), set.end(), back_inserter(current),
               nelems,
               std::mt19937{std::random_device{}()}
        );
        for (int j = 0; j < r; j++) {
            //Find a random neighbor T (see definition of neighbor below) of the current subset.
            vector<int> neighbor = current;
            vector<int> randindices;
            sample(set.begin(), set.end(), back_inserter(randindices),
                   2,
                   std::mt19937{std::random_device{}()}
            );
            /*Subset (multiset) B ⊆S is a neighbor of a subset A of S if you can transform
            A into B by moving one or two integers from A to B, or by moving one or two integers from
            B to A, or by swapping one integer in A with one integer in B.
            An easy way to generate a random neighbor B of a subset A of S is as follows:
                1. Order the elements of S as x1, x2, ..., xn.
                2. Initialize B to be a clone of A.
                3. Choose two distinct random indices i and j, where 1 ≤i, j ≤n.
                4. if xi is in A, remove it from B. Otherwise, add xi to B.
                5. if xj is in A, then with probability 0.5, remove it from B. If xj is not in A, then with
            probability 0.5, add xj to B.*/
            auto iter = find(current.begin(), current.end(), randindices.at(0));
            if (iter != current.end()) {
                neighbor.erase(iter, iter);
            } else {
                neighbor.push_back(randindices.at(0));
            }

            bool TrueFalse = (rand() % 100) < 50;
            iter = find(current.begin(), current.end(), randindices.at(1));
            if (iter != current.end() && TrueFalse) {
                neighbor.erase(iter, iter);
            } else {
                neighbor.push_back(randindices.at(1));
            }

            int neighsum = 0;
            for (int num: neighbor) {
                neighsum += num;
            }
            int currsum = 0;
            for (int num: current) {
                currsum += num;
            }

            //If neighbor T has smaller residue, then make T the current subset
            int currentResidue = abs(currsum - sum);
            int neightborResidue = abs(neighsum - sum);
            //Keep track of the residue of the final “current” subset when starting with subset S′.
            if (currentResidue > neightborResidue) {
                if (smallestresidue > neightborResidue) {
                    smallestresidue = neightborResidue;
                    smallestsum = neighsum;
                }
                current = neighbor;
            } else {
                if (smallestresidue > currentResidue) {
                    smallestresidue = currentResidue;
                    smallestsum = currsum;
                }
            }
            //cout<<sum<<" : "<<currsum-sum<<endl;
            //cout<<sum<<" : "<<neighsum-sum<<endl;
        }
    }
    //Return the smallest residue of the q subsets tested by the algorithm.
    cout << sum << " : " << smallestsum << " - " << smallestresidue << endl;
}

void tabu_search(my_set set, int sum, int q, int r, int tabu_length) {
    vector<int> current;
    size_t nelems = 1;
    int smallestresidue = 1000;
    int smallestsum = 0;
    vector<int> smallestSet;
    vector<vector<int>> tabu;
    tabu.push_back(current);
    for (int i = 0; i < q; i++) {
        //Choose a random subset (multiset) S′ of S as the “current” subset.
        current.erase(current.begin(), current.end());
        sample(set.begin(), set.end(), back_inserter(current),
               nelems,
               std::mt19937{std::random_device{}()}
        );
        for (int j = 0; j < r; j++) {
            //Find a random neighbor T (see definition of neighbor below) of the current subset.
            vector<int> neighbor = current;
            vector<int> randindices;

            //for(int x:current){
            //    cout<<x<<" ";
            //}
            //cout<<endl;

            sample(set.begin(), set.end(), back_inserter(randindices),
                   2,
                   std::mt19937{std::random_device{}()}
            );
            std::sort(current.begin(), current.end());
            std::sort(neighbor.begin(), neighbor.end());

            /*Subset (multiset) B ⊆S is a neighbor of a subset A of S if you can transform
            A into B by moving one or two integers from A to B, or by moving one or two integers from
            B to A, or by swapping one integer in A with one integer in B.
            An easy way to generate a random neighbor B of a subset A of S is as follows:
                1. Order the elements of S as x1, x2, ..., xn.
                2. Initialize B to be a clone of A.
                3. Choose two distinct random indices i and j, where 1 ≤i, j ≤n.
                4. if xi is in A, remove it from B. Otherwise, add xi to B.
                5. if xj is in A, then with probability 0.5, remove it from B. If xj is not in A, then with
            probability 0.5, add xj to B.*/
            auto iter = find(current.begin(), current.end(), randindices.at(0));
            if (iter != current.end()) {
                neighbor.erase(iter, iter);
                //neighbor.erase(std::find(neighbor.begin(),neighbor.end(),randindices.at(0)));
            } else {
                neighbor.push_back(randindices.at(0));
            }

            bool TrueFalse = (rand() % 100) < 50;
            iter = find(current.begin(), current.end(), randindices.at(1));
            if (iter != current.end() && TrueFalse) {
                neighbor.erase(iter, iter);
                //neighbor.erase(std::find(neighbor.begin(),neighbor.end(),randindices.at(1)));
            } else {
                neighbor.push_back(randindices.at(1));
            }

            std::sort(neighbor.begin(), neighbor.end());

            int neighsum = 0;
            for (int num: neighbor) {
                neighsum += num;
            }
            int currsum = 0;
            for (int num: current) {
                currsum += num;
            }

            //If neighbor T has smaller residue, then make T the current subset
            int currentResidue = abs(currsum - sum);
            int neightborResidue = abs(neighsum - sum);
            //Keep track of the residue of the final “current” subset when starting with subset S′.

            auto tabuIter = find(tabu.begin(), tabu.end(), neighbor);

            //if (tabuIter != tabu.end()) {
            //    cout << ".";
            //}

            if (tabuIter == tabu.end() && currentResidue > neightborResidue) {
                if (smallestresidue > neightborResidue) {
                    smallestresidue = neightborResidue;
                    smallestsum = neighsum;
                    smallestSet = neighbor;
                }
                current = neighbor;
                tabu.push_back(current);
            } else {
                if (smallestresidue > currentResidue) {
                    smallestresidue = currentResidue;
                    smallestsum = currsum;
                    smallestSet = current;
                }
            }
            if (tabu.size() > tabu_length) {
                tabu.erase(tabu.begin());
            }
            //cout<<sum<<" : "<<currsum-sum<<endl;
            //cout<<sum<<" : "<<neighsum-sum<<endl;
        }
    }
    //Return the smallest residue of the q subsets tested by the algorithm.
    cout << sum << " : " << smallestsum << " - " << smallestresidue << endl;
    for (int x: smallestSet) {
        cout << x << " ";
    }
}

my_set generate_random_problem(int n, int size) {
    uniform_int_distribution<int> distr(0, size);
    my_set numbers;
    for (int i = 0; i < n; i++) {
        numbers.push_back((int) distr(rand_gen));
    }
    std::sort(numbers.begin(), numbers.end());
    return numbers;
}

std::istream &operator>>(std::istream &stream, my_set mySet) {
    std::copy(std::istream_iterator<int>(stream), std::istream_iterator<int>(),
              std::back_inserter(mySet));
    return stream;
}

void printSubset(bool *arr, my_set set, int n, int m) {
    int i, j;
    //cout << endl << "  | ";
    printf("%7s", "|");
    for (i = 1; i <= m; i++) {
        printf("%4d", i);
    }
    printf("%9s", "|");
    for (i = 1; i <= m; i++) {
        printf("%4s", "-");
    }
    cout << endl;
    for (i = 0; i < n; i++) {
        printf("%4d %s", set.at(i), " | ");
        //cout << set.at(i) << " | ";
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

    //printSubset(reinterpret_cast<bool *>(&part), set, n, sum);
    if (part[n][sum]) {
        int i, j;
        printf("%7s", "|");
        for (i = 0; i <= sum; i++) {
            printf("%4d", i);
        }
        cout << endl;
        printf("%7s", "|");
        for (i = 0; i <= sum; i++) {
            printf("%4s", "-");
        }
        cout << endl;

        // Add zero at the beginning to print last row of part[][]
        set.insert(set.begin(), 0);

        for (i = 0; i <= n; i++) {
            printf("%4d %s", set.at(i), " | ");
            for (j = 0; j <= sum; j++) {
                printf("%4d", part[i][j]);
                //printf("%4d%d", i,j);
            }
            printf("\n");
        }

        //printf("%d %s %d", n, " ", sum);
        cout << endl << part[n][sum] << endl;
        //cout << endl << part[3][6] << endl;
    }
    return part[n][sum];
}