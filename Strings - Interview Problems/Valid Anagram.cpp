// This solution contains 3 approaches with time complexities
// O(Nlogn), O(N), O(N) respectively

class Solution
{
public:
    bool isAnagram(string s, string t)
    {

        //         APPROACH 1

        //         sort(s.begin(), s.end());
        //         sort(t.begin(), t.end());

        //         // cout << s << " ";

        //         return s == t;

        //         APPROACH 2

        //         map<char, int> freq;

        //         for(auto word: s) {
        //             freq[word]++;
        //         }

        //         for(auto word: t) {
        //             freq[word]--;
        //         }

        //         for(auto it: freq) {
        //             if(it.second != 0) {
        //                 return false;
        //             }
        //         }

        int arr[256] = {};
        for (auto letter : s)
        {
            arr[letter - 'A']++;
        }

        for (auto letter : t)
        {
            arr[letter - 'A']--;
        }

        for (int i = 0; i < 256; i++)
        {
            if (arr[i] != 0)
            {
                return false;
            }
        }

        return true;
    }
};