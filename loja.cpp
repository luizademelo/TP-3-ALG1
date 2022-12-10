#include "loja.hpp"
#include <bits/stdc++.h>

using namespace std; 

int lds(vector<int> &v)
{
    int n = v.size();
    int lds[n];

    lds[0] = 1;

    for (int i = 1; i < n; i++)
    {
        lds[i] = 1;

        for (int j = 0; j < i; j++)
        {
            if (v[i] < v[j] && lds[i] < lds[j] + 1)
            {
                lds[i] = lds[j] + 1;
            }
        }
    }
    int maior = lds[0];
    for (int i = 1; i < n; i++)
    {
        if (maior < lds[i])
        {
            maior = lds[i];
        }
    }

    return maior;
}
