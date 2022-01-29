# MHE-Labs
## Subset sum problem
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
