#include "./loja.hpp"
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; 
    cin >> n;

    while(n--)
    {
        int r; 
        vector<int> v; // vetor de armazenamento dos rolos 
        cin >> r;

        for (int j = 0; j < r; j++)
        {
            int p; 
            cin >> p;
            v.insert(v.begin(), 1, p); 
            v.push_back(p); 
        }


        int ans = lds(v); 
        cout << ans << endl;
    }

    return (0);
}