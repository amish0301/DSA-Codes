#include <bits/stdc++.h>
using namespace std;

int solveIncrease(int a, int b, int tmpa)
{
    while (b != 1)
    {
        b--;
        a++;

        if (a % b == 0) 
            return a-tmpa;
    }
    return 0;
}

int solveDecrease(int a, int b, int tmpb)
{
    while (a > b)
    {
        a--;
        b++;

        if (a % b == 0)
            return b-tmpb;
    }
    return 0;
}

int main()
{
    cout << "enter testcases" << endl;
    int t;
    cin >> t;

    while (t--)
    {

        int a, b;
        cout << "enter 2 values" << endl;
        cin >> a >> b;

        if (a % b == 0)
            cout << 0 << endl;

        int dupa = a, dupb = b;

        if (a < b)
        {
            // as we chef has less marbles compare to his friends
            // so we need to increase the number of marbles of chef until condition not true. 
            while (a % b != 0)
            {
                a++;
                b--;

                if (a % b == 0)
                    cout << dupb - b << endl;
            }
        }
        else
        {
            // now here we chef alredy have the more marbles then his friends
            // so there can be two possibilities where either we increase or decrease the chef marble and pick out the min ans. whichever possible from both options. 
            int increase = solveIncrease(a, b, dupb);
            int decrease = solveDecrease(a, b, dupa);

            cout << min(increase, decrease) << endl;
        }
    }
    return 0;
}
