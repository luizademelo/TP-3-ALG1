#include "./loja.hpp"
using namespace std;

int main()
{
    int N, R, P;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        Loja minha_loja;

        cin >> R;

        for (int j = 0; j < R; j++)
        {
            cin >> P;

            minha_loja.set_Rolos(P);
        }

        int resp = minha_loja.lds();
        cout << resp << endl;

        minha_loja.rolos.clear();
    }

    return (0);
}