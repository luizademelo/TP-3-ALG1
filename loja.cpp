#include "loja.hpp"
#include <bits/stdc++.h>

using namespace std; 

int lds(vector<int> &v)
{
    int tam = v.size();
    int lds[tam];

    lds[0] = 1;

    for (int i = 1; i < tam; i++)
    {
        lds[i] = 1;

        for (int j = 0; j < i; j++)
        {
            if (v[i] < v[j]) // se acharmos um elemento que possamos incluir na sequência
            {
                if(lds[i] < (lds[j]+1)) // se esse elemento aumentar a maior subsequência conhecida 
                {
                    lds[i] = lds[j] + 1;
                }
            }
        }
    }
    int maior = -1;
    for (int i = 0; i < tam; i++)
        maior = max(lds[i], maior);

    return maior;
}
