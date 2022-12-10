#include "./loja.hpp"
using namespace std;

int main()
{
    int n; 
    cin >> n;

    while(n--)
    {
        int r; 
        vector<int> v; 
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