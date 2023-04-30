#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	string s;
	getline(cin, s);
	stack<long long> st;
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			st.push((int)(s[i] - '0'));
		}
		else if (s[i] != ' ')
		{
			long long a = st.top();
			st.pop();
			long long b = st.top();
			st.pop();
			if (s[i] == '*')
				b *= a;
			else if (s[i] == '+')
				b += a;
			else if (s[i] == '-')
				b -= a;
			st.push(b);
		}
	}
	cout << st.top() << "\n";
	return 0;
}