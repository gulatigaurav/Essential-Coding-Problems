#include <iostream>
#include <vector>
using namespace std;

int calculateProductOf3(vector<int> arr)
{

    int lowest = max(arr[1], arr[0]);
    int highest = max(arr[0], arr[1]);

    int highestProduct2 = arr[1] * arr[0];
    int lowestProduct2 = arr[1] * arr[0];

    int highestProduct3 = arr[2] * arr[1] * arr[0];

    for (int i = 2; i < arr.size(); i++)
    {
        int currentElement = arr[i];

        highest = max(currentElement, highest);
        lowest = max(currentElement, lowest);

        highestProduct3 = max(max(highestProduct3, currentElement * highestProduct2), currentElement * lowestProduct2);

        highestProduct2 = max(max(highestProduct2, currentElement * highest), currentElement * lowest);

        highest = max(currentElement, highest);
        lowest = min(currentElement, lowest);
    }

    return highestProduct3;
}

int main()
{
    vector<int> arr = {10, -5, 1, 1, -100};
    int sum = calculateProductOf3(arr);
    cout << sum << endl;
}