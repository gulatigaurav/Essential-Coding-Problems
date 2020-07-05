#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

typedef pair<int, string> t;

int main()
{
    string dict[] =
        {
            "code", "coder", "coding", "codable", "codec", "codecs", "coded",
            "codeless", "codec", "codecs", "codependence", "codex", "codify",
            "codependents", "codes", "code", "coder", "codesign", "codec",
            "codeveloper", "codrive", "codec", "codecs", "codiscovered"};

    int k = 4;
    map<string, int> freq;
    for (string i : dict)
    {
        freq[i] += 1;
    }

    priority_queue<t, vector<t>, greater<t>> pq;

    for (auto i : freq)
    {
        pq.push(make_pair(i.second, i.first));
        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    while (!pq.empty())
    {
        cout << pq.top().second << " " << pq.top().first << "\n";
        pq.pop();
    }
}