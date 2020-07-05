#include <iostream>
using namespace std;

void towerOfHanoi(int n, char fromRod, char toRod, char auxRod)
{
    if (n == 1)
    {
        cout << "Moving disk 1 from " << fromRod << " to " << toRod << "\n";
        return;
    }

    // n - 1 to aux array using the destination array
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);

    cout << "Moving disk " << n << " from " << fromRod << " to " << toRod << "\n";

    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}

int main()
{
    int n = 3;                      // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    return 0;
}