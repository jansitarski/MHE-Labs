# MHE-Labs
## Subset sum problem
```
g++ subset_problem.cpp subset_problem.h genetic.cpp genetic.h annealing.cpp annealing.h main.cpp
```
### Lab2
```
$ ./a.out -f example1.txt
( 2 11 ) - 0
( 3 10 ) - 0
( 4 9 ) - 0
( 5 8 ) - 0
( 6 7 ) - 0
( 3 4 6 ) - 0

```

### Lab3
```
my_set generate_random_problem(int n, int size) {
    if (n >= size) {
        size = n;
    }
    uniform_int_distribution<int> distr(1, size);
    my_set numbers;
    int generated;
    for (int i = 0; i < n; i++) {
        generated = (int) distr(rand_gen);
        if (find(numbers.begin(), numbers.end(), generated) == numbers.end()) {
            numbers.push_back(generated);
        } else {
            i--;
        }
    }
    std::sort(numbers.begin(), numbers.end());
    return numbers;
}

my_set get_next_point(my_set p)
{
    next_permutation(p.begin(), p.end());
    return p;
}

my_set next_solution(my_set set, my_set prevoiusSolution, int sum){
    my_set working_set = set;
    my_set next_candidate=prevoiusSolution;
    int workingSum=0;
    while(abs(workingSum-sum)!=0){
        workingSum = 0;
        next_candidate.front() = move(next_candidate.back());
        next_candidate.pop_back();
        int randomIndex = rand() % set.size();
        next_candidate.push_back(set.at(randomIndex));
        for (int num:next_candidate) {
            workingSum+=num;
        }
    }
    return next_candidate;
}

bool goal_function(my_set subset, int sum){
    int subsetSum=0;
    for (int num:subset) {
        subsetSum+=num;
    }
    if(abs(subsetSum-sum)==0){
        return true;
    } else{
        return false;
    }
}
```

### Lab4
```
$ ./a.out -f example1.txt output.txt 
$ cat output.txt 
( 2 11 ) - 0
( 3 10 ) - 0
( 4 9 ) - 0
( 5 8 ) - 0
( 6 7 ) - 0
( 3 4 6 ) - 0

```
### Lab5 & Lab6
```$ ./a.out
1.Hill, 2.Tabu, 3.Genetic
1
n, size, sum
100 25 55
q, r
100 100
# count: 1039757456; dt:  0.182823
result 0
```
### Lab7
```
$ $ python run_tests.py 
Hill
rozmiar         wynik_sredni      czas
5               0.15              0.13
6               0.03              0.13
7               0.03              0.13
8               0.00              0.13
9               0.00              0.13
[...]
67               0.03              0.14
68               0.03              0.14
69               0.05              0.14
70               0.08              0.14
71               0.03              0.15
72               0.03              0.14
73               0.03              0.14
74               0.05              0.15
75               0.03              0.15
76               0.05              0.15
77               0.13              0.15
78               0.03              0.15
79               0.08              0.15
80               0.03              0.15
81               0.05              0.15
82               0.08              0.15
83               0.03              0.15
84               0.05              0.15
85               0.03              0.15
86               0.03              0.15
87               0.08              0.15
88               0.03              0.15
89               0.10              0.15
90               0.05              0.15
91               0.08              0.15
92               0.03              0.15
93               0.08              0.15
94               0.05              0.15
95               0.10              0.15
96               0.05              0.15
97               0.03              0.15
98               0.08              0.15
99               0.03              0.15
Tabu
rozmiar         wynik_sredni      czas
5               1.13              0.14
6               1.03              0.14
7               0.54              0.14
8               0.08              0.15
9               0.05              0.15
10               0.10              0.15
11               0.00              0.16
12               0.05              0.16
13               0.00              0.17
14               0.00              0.17
15               0.00              0.18
16               0.00              0.18
17               0.00              0.18
[...]
95               0.18              0.17
96               0.05              0.17
97               0.15              0.17
98               0.18              0.17
99               0.10              0.17
```
### Lab 8 & 9
```
$ ./a.out 
1.Hill, 2.Tabu, 3.Genetic 4.Annealing
3
n, size, sum
20 20 24
pop_size, chromosome_size, iterations
10 10 13
[0] 18:1010110111 16:0101001111 25:1010111111 11:1101110110 13:1000000001 23:1101011111 4:0101011010 4:1101110001 13:0110010000 18:0111010111
[1] 5:1101011010 22:0101011111 2:1001110001 20:1110110111 4:0101011010 4:0101011010 13:0110010000 4:0101011010 4:1101110001 4:1101110001
[2] 3:0101110001 3:1001011010 2:0101010001 8:1001111010 5:1101011010 5:1101011010 3:0101110001 12:1110010000 4:1101110001 2:1001110001
[3] 3:0101110001 2:0101010001 3:0101110001 4:1101110001 2:0101010001 2:1001110001 6:1101011001 3:0101010010 6:1101011001 1:1001110010
[4] 8:1001110000 11:1001110011 4:1101110001 6:1101011001 2:0101010001 2:0101010001 3:0101110001 4:1001010010 1:1101010001 0:0001110010
[5] 2:0101010001 0:0001110010 8:1001110000 8:1001110000 1:1101010001 4:1101110001 0:0001110010 4:1001010010 2:0101010001 2:0101010001
[6] 1:0001110001 3:0101010010 1:1101010001 5:0001010010 0:0001110010 0:0001110010 0:0001110010 4:1001010010 1:0001110001 3:0101010010
[7] 0:0001110010 0:0001110010 0:0001110010 1:0001110001 3:1001010001 2:1101010010 7:0101010011 11:1101010000 2:1101010010 1:0001110001
[8] 2:1101010010 2:1101010010 1:1101010001 0:0001110010 0:0001110010 0:0001110010 0:0001110010 0:0001110010 1:0001110001 0:0001110010
[9] 1:0001110001 1:0001110001 0:0001110010 0:0001110010 0:0001110010 0:0001110010 10:0001110011 11:1101010000 0:0001110010 0:0001110010
[10] 0:0001110010 0:0001110010 0:0001110010 0:0001110010 1:0001110001 0:0001110010 0:0001110010 0:0001110010 0:0001110010 0:0001110010
[11] 0:0001110010 0:0001110010 0:0001110010 0:0001110010 0:0001110010 0:0001110010 0:0001110010 0:0001110010 0:0001110010 0:0001110010
[12] 0:0001110010 0:0001110010 0:0001110010 0:0001110010 0:0001110010 0:0001110010 0:0001110010 0:0001110010 0:0001110010 0:0001110010
```
### Lab12
```
$ ./a.out 
1.Hill, 2.Tabu, 3.Genetic 4.Annealing
4
n, size, sum
20 20 24
init_temp, temp, cooling_ratio, final_temp
1500 500 0.1 0.001
[0]
Neighbours
( 14 15 18 ), ( 9 15 18 ), ( 9 14 18 ), ( 9 14 15 ), ( 9 14 15 18 1 ), ( 9 14 15 18 2 ), ( 9 14 15 18 3 ), ( 9 14 15 18 4 ), ( 9 14 15 18 5 ), ( 9 14 15 18 6 ), ( 9 14 15 18 7 ), ( 9 14 15 18 8 ), ( 9 14 15 18 10 ), ( 9 14 15 18 11 ), ( 9 14 15 18 12 ), ( 9 14 15 18 13 ), ( 9 14 15 18 16 ), ( 9 14 15 18 17 ), ( 9 14 15 18 19 ), ( 9 14 15 18 20 ), 
Temperature: 150
Solution: ( 9 14 15 ): 38 - 14
Best Solution: ( 9 14 15 ): 38 - 14
[1]
Neighbours
( 14 15 ), ( 9 15 ), ( 9 14 ), ( 9 14 15 1 ), ( 9 14 15 2 ), ( 9 14 15 3 ), ( 9 14 15 4 ), ( 9 14 15 5 ), ( 9 14 15 6 ), ( 9 14 15 7 ), ( 9 14 15 8 ), ( 9 14 15 10 ), ( 9 14 15 11 ), ( 9 14 15 12 ), ( 9 14 15 13 ), ( 9 14 15 16 ), ( 9 14 15 17 ), ( 9 14 15 18 ), ( 9 14 15 19 ), ( 9 14 15 20 ), 
Temperature: 15
Solution: ( 9 15 ): 24 - 0
Best Solution: ( 9 15 ): 24 - 0
[2]
Neighbours
( 15 ), ( 9 ), ( 9 15 1 ), ( 9 15 2 ), ( 9 15 3 ), ( 9 15 4 ), ( 9 15 5 ), ( 9 15 6 ), ( 9 15 7 ), ( 9 15 8 ), ( 9 15 10 ), ( 9 15 11 ), ( 9 15 12 ), ( 9 15 13 ), ( 9 15 14 ), ( 9 15 16 ), ( 9 15 17 ), ( 9 15 18 ), ( 9 15 19 ), ( 9 15 20 ), 
exp: 0.201897
Temperature: 1
Solution: ( 9 15 1 ): 25 - 1
Best Solution: ( 9 15 ): 24 - 0
[3]
Neighbours
( 15 1 ), ( 9 1 ), ( 9 15 ), ( 9 15 1 2 ), ( 9 15 1 3 ), ( 9 15 1 4 ), ( 9 15 1 5 ), ( 9 15 1 6 ), ( 9 15 1 7 ), ( 9 15 1 8 ), ( 9 15 1 10 ), ( 9 15 1 11 ), ( 9 15 1 12 ), ( 9 15 1 13 ), ( 9 15 1 14 ), ( 9 15 1 16 ), ( 9 15 1 17 ), ( 9 15 1 18 ), ( 9 15 1 19 ), ( 9 15 1 20 ), 
Temperature: 0
Solution: ( 9 15 ): 24 - 0
Best Solution: ( 9 15 ): 24 - 0
# count: 0; dt:  0.000987429
result 0

```

```
annealing_test.py
rozmiar         wynik_sredni      czas
0.1               0.24              0.00
0.01               0.32              0.00
0.001               0.24              0.00
0.0001               0.52              0.00
rozmiar         wynik_sredni      czas
0.1               0.28              0.00
0.01               0.76              0.00
0.001               0.68              0.00
0.0001               0.40              0.00
rozmiar         wynik_sredni      czas
0.1               0.52              0.00
0.01               0.24              0.00
0.001               0.56              0.00
0.0001               0.24              0.00
rozmiar         wynik_sredni      czas
0.1               0.52              0.00
0.01               0.36              0.00
0.001               0.60              0.00
0.0001               0.32              0.00
rozmiar         wynik_sredni      czas
0.1               0.28              0.00
0.01               0.52              0.00
0.001               0.20              0.00
0.0001               0.52              0.00
rozmiar         wynik_sredni      czas
0.1               0.28              0.00
0.01               0.36              0.00
0.001               0.44              0.00
0.0001               0.20              0.00
rozmiar         wynik_sredni      czas
0.1               0.32              0.00
0.01               0.44              0.00
0.001               0.20              0.00
0.0001               0.24              0.00
rozmiar         wynik_sredni      czas
0.1               0.52              0.00
0.01               0.52              0.00
0.001               0.56              0.00
0.0001               0.60              0.00
``
