#include "loja.hpp"

Loja::Loja()
{
}
// Binary search (note boundaries in the caller)
int CeilIndex(std::vector<int> &v, int l, int r, int key)
{
    while (r - l > 1)
    {
        int m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }

    return r;
}

int LongestIncreasingSubsequenceLength(std::vector<int> &v)
{
    if (v.size() == 0)
        return 0;

    std::vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail

    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++)
    {

        // new smallest value
        if (v[i] < tail[0])
            tail[0] = v[i];

        // v[i] extends largest subsequence
        else if (v[i] < tail[length - 1])
            tail[length++] = v[i];

        // v[i] will become end candidate of an existing
        // subsequence or Throw away larger elements in all
        // LIS, to make room for upcoming greater elements
        // than v[i] (and also, v[i] would have already
        // appeared in one of LIS, identify the location
        // and replace it)
        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
    }

    return length;
}
void Loja::set_Rolos(int P)
{
    // 1) coloca-lo na prateleira pelo lado direito e empurra-lo ate encostar nos rolos ja existentes
    // 2) coloca-lo na prateleira pelo lado esquerdo e empurr´a-lo at´e encostar nos rolos j´a existentes,
    // 3) simplesmente n˜ao coloc´a-lo na prateleira.

    if (rolos.size() == 0)
    {
        rolos.push_back(P);
    }
    else
    {
        vector<int> old_rolos = rolos;
        int lds_old = LongestIncreasingSubsequenceLength(old_rolos);

        vector<int> begin_rolos = rolos;
        begin_rolos.insert(begin_rolos.begin(), 1, P);
        int lds_begin = LongestIncreasingSubsequenceLength(begin_rolos);

        vector<int> end_rolos = rolos;
        end_rolos.push_back(P);
        int lds_end = LongestIncreasingSubsequenceLength(end_rolos);

        if (lds_old > lds_begin && lds_old > lds_end)
        {
            rolos.push_back(P);
        }
        else if (lds_begin > lds_old && lds_begin > lds_end)
        {
            rolos.insert(rolos.begin(), 1, P);
        }
        else if (lds_end > lds_old && lds_end > lds_begin)
        {
            rolos.push_back(P);
        }
        else
        {
            rolos.push_back(P);
        }

        int diff_sup = abs(P - rolos[0]);
        int diff_inf = abs(P - rolos[rolos.size()]);

        if (diff_sup < rolos[rolos.size() - 1])
        {
            rolos.insert(rolos.begin(), 1, P);
        }
        else if (diff_inf < rolos[0])
        {
            rolos.push_back(P);
        }
        int maiores(0), menores(0);
        for (int j = 0; j < rolos.size(); j++)
        {
            if (P < rolos[j])
                maiores++;
            else
                menores++;
        }
        if (maiores >= menores)
            rolos.push_back(P);
        else
            rolos.insert(rolos.begin(), 1, P);
    }
}

void Loja::print_Rolos()
{
    for (long unsigned int i = 0; i < rolos.size(); i++)
    {
        std::cout << rolos[i] << " ";
    }
    cout << endl;
}

// longest decreasing subsequence adding in the beginning of the vector
int Loja::lds()
{
    int n = rolos.size();
    int lds[n];

    lds[0] = 1;

    // interate over the vector and find the longest decreasing subsequence
    for (int i = 1; i < n; i++)
    {
        // initialize the lds with 1
        lds[i] = 1;

        // iterate over the vector again
        for (int j = 0; j < i; j++)
        {
            // if the current value is greater than the previous value
            if (rolos[i] < rolos[j] && lds[i] < lds[j] + 1)
            {
                // add 1 to the lds
                lds[i] = lds[j] + 1;
            }
        }
    }
    // find the maximum value of the lds
    int maior = lds[0];
    // iterate over the lds vector
    for (int i = 1; i < n; i++)
    {
        // if the current value is greater than the previous value
        if (maior < lds[i])
        {
            // set the current value as the maximum value
            maior = lds[i];
        }
    }

    return maior;
}

// longest increasing subsequence using binare search