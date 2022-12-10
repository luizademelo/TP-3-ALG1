#include "loja.hpp"

Loja::Loja()
{
}

void Loja::set_Rolos(int P)
{
    if (rolos.size() == 0)
    {
        rolos.push_back(P);
    }
    else
    {
        vector<int> old_rolos = rolos;
        int lds_old = lds();

        vector<int> begin_rolos = rolos;
        begin_rolos.insert(begin_rolos.begin(), 1, P);
        int lds_begin = lds();

        vector<int> end_rolos = rolos;
        end_rolos.push_back(P);
        int lds_end = lds();

        if (lds_old > lds_begin && lds_old > lds_end)
        {
            rolos.push_back(P);
        }
        else if (lds_begin > lds_old && lds_begin > lds_end)
        {
            rolos.insert(rolos.begin(), 1, P);
        }
        else if (lds_end >= lds_old && lds_end >= lds_begin)
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

int Loja::lds()
{
    int n = rolos.size();
    int lds[n];

    lds[0] = 1;

    for (int i = 1; i < n; i++)
    {
        lds[i] = 1;

        for (int j = 0; j < i; j++)
        {
            if (rolos[i] < rolos[j] && lds[i] < lds[j] + 1)
            {
                lds[i] = lds[j] + 1;
            }
        }
    }
   return *max_element(lds, lds + n);

}


