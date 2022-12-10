#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
using namespace std;

void test();

// create a class loja
class Loja
{
public:
    int N, R, P;
    vector<int> rolos;
    int soma;
    int media;
    int menor;

    Loja();

    void set_Rolos(int P); // Insere os rolos no vector de rolos

    void print_Rolos();  // Imprime os rolos
    void print_N(int N); // Imprime o valor de N
    void print_R(int R); // Imprime o valor de R
    void print_P(int P); // Imprime o valor de P

    void lis(); // Longest Increasing Subsequence
    int lds();  // Longest Increasing Subsequence
    int test(int n);
    int test2(int n);
};