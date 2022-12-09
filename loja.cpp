#include "loja.hpp"

using namespace std;

void test()
{

    int n;
    cin >> n;
    while (n--)
    {
        int r;
        cin >> r;
        vector<int> v1(r);
        vector<int> v;
        for (int i = 0; i < r; i++)
            cin >> v1[i];
        for (int i = 0; i < r; i++)
        {
            int p = v1[i];
            if (i == 0)
            {
                v.push_back(p);
            }
            else
            {
                vector<int> aux_front = v;
                vector<int> aux_back = v;
                aux_front.insert(aux_front.begin(), 1, p);
                aux_back.push_back(p);
                vector<int> max_front = constructPrintLIS(aux_front, aux_front.size());  
                vector<int> max_back = constructPrintLIS(aux_back, aux_back.size());  
                if (max_front.size() > max_back.size())
                {
                    v.insert(v.begin(), 1, p);
                }else if(max_front.size() == max_back.size())
                {
                    vector<int> max = constructPrintLIS(v, v.size()); 
                    int maiores(0), menores(0); 
                    for(int j = 0; j < max.size(); j++)
                    {
                        if(p < max[j]) maiores++; 
                        else menores++; 
                    }
                    if(maiores >= menores) v.push_back(p); 
                    else v.insert(v.begin(), 1, p); 
                }
                else
                    v.push_back(p);
            }
        }
        int max = constructPrintLIS(v, v.size()).size();
        for (int x : v)
            cout << x << " ";
        cout << endl;
        cout << max << endl;
    }
}

vector<int> constructPrintLIS(vector<int> arr, int n)
{
    // L[i] - The longest increasing sub-sequence
    // ends with arr[i]
    vector<vector<int>> L(n);

    // L[0] is equal to arr[0]
    L[0].push_back(arr[0]);

    // start from index 1
    for (int i = 1; i < n; i++)
    {
        // do for every j less than i
        for (int j = 0; j < i; j++)
        {
            /* L[i] = {Max(L[j])} + arr[i]
            where j < i and arr[j] < arr[i] */
            if ((arr[i] < arr[j]) &&
                (L[i].size() < L[j].size() + 1))
                L[i] = L[j];
        }

        // L[i] ends with arr[i]
        L[i].push_back(arr[i]);
    }

    // L[i] now stores increasing sub-sequence of
    // arr[0..i] that ends with arr[i]
    vector<int> max = L[0];

    // LIS will be max of all increasing sub-
    // sequences of arr
    for (vector<int> x : L)
        if (x.size() > max.size())
            max = x;
    // for (int x : max)
    //     cout << x << " ";
    // cout << endl;

    // max will contain LIS
    // printLIS(max);
    return max;
}
