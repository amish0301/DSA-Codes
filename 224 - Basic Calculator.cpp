// ***************************************** ONE OF THE BEST Q. ON STACK ***********************************************

class Solution
{
public:
    int calculate(string s)
    {
        int sum = 0;
        int sign = 1;

        stack<int> st;

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            if (isdigit(ch))
            {

                // first fetch the value
                int val = 0;
                while (i < s.length() && isdigit(s[i]))
                {

                    val = val * 10 + (s[i] - '0');
                    i++;
                }
                val *= sign;
                sum += val;
                sign = 1;
                i--;          // because for loop is also get increament 1 step ahead
            }
            else if (ch == '-')
            {
                sign *= -1;
            }
            else if (ch == '(')
            {
                st.push(sum);
                st.push(sign);

                // make suma nd sign to default
                sum = 0;
                sign = 1;
            }
            else if (ch == ')')
            {
                sum *= st.top();      // top consist sign which is present before the '(' so we just add the sign 
                st.pop();

                sum += st.top();
                st.pop();
            }
        }
        return sum;
    }
};

// #LeetCode Hard Way
// T.C = O(n) , auxilliary S.C = (Worst case O(n) , bestcase O(1)) 
