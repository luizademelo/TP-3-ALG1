#include "loja.hpp"

using namespace std; 

void test(){

    int n; cin >> n; 
    while(n--)
    {
        int r; cin >> r; 
        vector<int> v; 
        for(int i = 0; i < r; i++)
        {
            int p; cin >> p; 
            if(i == 0) 
            {
                v.push_back(p); 
            }else
            {
                if(p > v[0]) 
                {
                    //printf("p: %d, v[size]: %d, i: %d\n", p, v[size], i); 
                    v.insert(v.begin(), 1, p); 
                }
                else if(p < v[v.size()-1]) v.push_back(p); 
                else
                {
                    int menores = 0; 
                    for(int j = 0; j < v.size(); j++)
                    {
                        if(v[j] < p) menores++; 
                    }
                    if(menores < lis(v, v.size()))
                        v.push_back(p); 
                    else v.insert(v.begin(), 1,p); 
                }
                // else 
                // {
                //     int diff_sup = abs(p - v[0]); 
                //     int diff_inf = abs(p - v[size]); 
                //     if(diff_sup < v[size]) v.insert(v.begin(), 1, p); 
                //     else v.push_back(p); 
                // }
            }
        }
        for(int i = 0; i < v.size(); i++) cout << v[i] << " "; 
        cout << endl; 
        int max = lis(v, v.size()); 
        cout << max << endl; 
    }
}

int lis(vector<int> arr, int n)
{
    int lis[n];
 
    lis[0] = 1;
 
    /* Compute optimized LIS values in
       bottom up manner */
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] < arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }
 
    return *max_element(lis, lis + n);
}