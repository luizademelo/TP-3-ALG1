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
                int size = v.size()-1; 
                if(p > v[0]) 
                {
                    //printf("p: %d, v[size]: %d, i: %d\n", p, v[size], i); 
                    v.insert(v.begin(), 1, p); 
                }
                else if(p < v[size] && p < v[0]) v.push_back(p); 
                else 
                {
                    int diff_sup = abs(p - v[0]); 
                    int diff_inf = abs(p - v[size]); 
                    if(diff_sup < v[size]) v.insert(v.begin(), 1, p); 
                    else v.push_back(p); 
                }
            }
        }
        for(int i = 0; i < r; i++) cout << v[i] << " "; 
        cout << endl; 
        int max = lis(v, r); 
        cout << max << endl; 
    }
}

int _lis(vector<int> arr, int n, int* max_ref)
{
    /* Base case */
    if (n == 1)
        return 1;
 
    // 'max_ending_here' is length of LIS
    // ending with arr[n-1]
    int res, max_ending_here = 1;
 
    /* Recursively get all LIS ending with arr[0],
    arr[1] ... arr[n-2]. If arr[i-1] is smaller
    than arr[n-1], and max ending with arr[n-1]
    needs to be updated, then update it */
    for (int i = 1; i < n; i++) {
        res = _lis(arr, i, max_ref);
        if (arr[i - 1] > arr[n - 1]
            && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }
 
    // Compare max_ending_here with the overall
    // max. And update the overall max if needed
    if (*max_ref < max_ending_here)
        *max_ref = max_ending_here;
 
    // Return length of LIS ending with arr[n-1]
    return max_ending_here;
}
 
// The wrapper function for _lis()
int lis(vector<int> arr, int n)
{
    // The max variable holds the result
    int max = 1;
 
    // The function _lis() stores its result in max
    _lis(arr, n, &max);
 
    // returns max
    return max;
}
 
