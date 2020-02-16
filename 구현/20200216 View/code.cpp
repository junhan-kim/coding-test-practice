#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	T = 10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
    int len;
    cin>>len; 
    vector<int> v(len);
    for(int i = 0; i < len; i++)
    {
        int num;
        cin >> num;
        v[i] = num;
    }
    int sum = 0;
    for(int i = 0; i < len; i++){
        vector<int> comp(4);
        int priv;
        if(i>=2) comp.push_back(v[i-2]);
        if(i>=1) comp.push_back(v[i-1]);
        if(i < len - 1) comp.push_back(v[i+1]);
        if(i < len - 2) comp.push_back(v[i+2]);
        int max = *max_element(comp.begin(), comp.end());
        priv = v[i] - max;
        if(priv < 0) priv = 0;
        sum += priv;
    }
    cout << '#' << test_case << ' ' << sum << endl;
	}
	return 0;
}