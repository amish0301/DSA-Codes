class Solution
{
    public:
    long long int numberOfSquares(long long int base)
    {
        if(base >= 2) base -= 2;
        long long int h = base / 2;
        long long int ans = h*(h+1) / 2;
        return ans;
    }
};

// T.C = O(1) , S.C = O(1)

// Here q. wants to tell you that we are given the base of isoceleos triangle and we have to return that, how many 2X2 grid is possible to form.
// so we know for 2X2 grid, for the left most side of base we can't able to make the grid bcoz that is Angle part and square not be form. so we will decreament the base value by 2 so (base = base - 2).
// after that base/2 squares Can Form.
// Upside of base (base/2 - 1) squares can form and it's decreament by 1. so Eq. is --> n * (n+1) / 2.
