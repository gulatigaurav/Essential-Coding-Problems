#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int getHash(vector<char> v2)
{

    long long total = 0;
    for (int i = v2.size() - 1; i >= 0; i--)
    {

        total = total + (int)v2[i] * pow(10, v2.size() - i);
        cout << (int)v2[i] << " " << pow(10, v2.size() - i) << " " << total << endl;
        // total *= ;
    }
    return total;
}

bool RKP(vector<char> &s, int hash, int n)
{

    int i = 0;

    vector<char> temp_arr;
    for (int i = 0; i < n; i++)
    {
        temp_arr.push_back(s[i]);
    }
    int get = getHash(temp_arr);

    if (get == hash)
    {
        check
    }
}

int main()
{
    string s = "abcxabcdabcdabcy";
    string subString = "abcd";
    vector<char> v(s.begin(), s.end());
    vector<char> v2(subString.begin(), subString.end());

    long long ans = getHash(v2);

    cout << ans << " ";
    //     createTemporaryArray(v2);
    // bool result = RKP(v, v2);
    // cout << result << endl;
}