#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

struct Compare
{

    bool Operator()(pair<int, string> const &a, pair<int, string> const &b)
    {

        if (a.first == b.first)
        {
            return a.second < b.second;
        }

        return a.first > b.first;
    }
};

void kFrequentWords(vector<string> str, int k)
{
    map<string, int> freq;

    for (auto word : str)
        freq[word]++;

    vector<pair<int, string>> sorted_freq;

    for (auto x : freq)
    {
        sorted_freq.push_back(make_pair(x.second, x.first));
    }

    sort(sorted_freq.begin(), sorted_freq.end(), Compare); // Now we have sorted the vector in  decreasing order of frequency

    vector<string> ans;

    for (int i = 0; i < k; i++)
        // ans.push_back(sorted_freq[i]);
        cout << sorted_freq[i].second << " ";
    // return ans;
}

int main()
{

    vector<string> str = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;
    vector<string> ans;
    kFrequentWords(str, k);
    // Output: ["i", "love"]
    return 0;
}
