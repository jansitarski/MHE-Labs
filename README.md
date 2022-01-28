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

