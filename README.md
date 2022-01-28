# MHE-Labs
## Subset sum problem
### Lab2
```
$ ./a.out -f example1.txt
      |   0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20
      |   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -
   0  |    1   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
   1  |    1   1   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
   2  |    1   1   1   1   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
   3  |    1   1   1   1   1   1   1   0   0   0   0   0   0   0   0   0   0   0   0   0   0
   4  |    1   1   1   1   1   1   1   1   1   1   1   0   0   0   0   0   0   0   0   0   0
   5  |    1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   0   0   0   0   0
   6  |    1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1
  78  |    1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1
7   20
1
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

std::istream &operator>>(std::istream &stream, my_set mySet) {
    std::copy(std::istream_iterator<int>(stream), std::istream_iterator<int>(),
              std::back_inserter(mySet));
    return stream;
}
```

### Lab4
```
$ ./a.out -f example1.txt output.txt 20

$ cat output.txt 
      |   0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20
      |   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -
   0  |    1   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
   1  |    1   1   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
   2  |    1   1   1   1   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
   3  |    1   1   1   1   1   1   1   0   0   0   0   0   0   0   0   0   0   0   0   0   0
   4  |    1   1   1   1   1   1   1   1   1   1   1   0   0   0   0   0   0   0   0   0   0
   5  |    1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   0   0   0   0   0
   6  |    1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1
  78  |    1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1
7   20
1
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
$ python run_tests.py 
Hill
rozmiar         wynik_sredni      czas
5               0.11              0.13
6               0.00              0.13
7               0.00              0.13
8               0.00              0.13
9               0.00              0.13
10               0.00              0.13
11               0.00              0.13
12               0.00              0.14
13               0.00              0.13
14               0.00              0.14
15               0.00              0.13
16               0.00              0.14
17               0.00              0.13
18               0.00              0.14
19               0.00              0.14
20               0.00              0.14
21               0.00              0.14
22               0.00              0.14
23               0.00              0.14
24               0.00              0.14
25               0.00              0.14
26               0.00              0.14
27               0.00              0.14
28               0.00              0.14
29               0.00              0.14
Tabu
rozmiar         wynik_sredni      czas
5               0.11              0.14
6               0.00              0.15
7               0.00              0.16
8               0.00              0.17
9               0.00              0.17
10               0.00              0.17
11               0.00              0.17
12               0.00              0.17
13               0.00              0.17
14               0.00              0.17
15               0.00              0.17
16               0.00              0.17
17               0.00              0.17
18               0.00              0.17
19               0.00              0.17
20               0.00              0.17
21               0.00              0.17
22               0.00              0.17
23               0.00              0.17
24               0.00              0.17
25               0.00              0.17
26               0.00              0.17
27               0.00              0.17
28               0.00              0.17
29               0.00              0.17
```
