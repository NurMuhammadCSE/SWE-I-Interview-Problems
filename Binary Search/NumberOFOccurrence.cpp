#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // প্রথম অবস্থান খুঁজতে Binary Search
    int findFirstPosition(vector<int> &arr, int target)
    {
        int low = 0, high = arr.size() - 1, first = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target)
            {
                first = mid;    // সম্ভাব্য প্রথম অবস্থান
                high = mid - 1; // বাঁদিকে আরো খুঁজবো
            }
            else if (arr[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return first;
    }

    // শেষ অবস্থান খুঁজতে Binary Search
    int findLastPosition(vector<int> &arr, int target)
    {
        int low = 0, high = arr.size() - 1, last = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target)
            {
                last = mid;    // সম্ভাব্য শেষ অবস্থান
                low = mid + 1; // ডানদিকে আরো খুঁজবো
            }
            else if (arr[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return last;
    }

    // প্রধান ফাংশন যা সংখ্যার মোট উপস্থিতি গণনা করবে
    int countFreq(vector<int> &arr, int target)
    {
        int first = findFirstPosition(arr, target);
        if (first == -1)
            return 0; // Target নেই

        int last = findLastPosition(arr, target);
        return (last - first + 1);
    }
};

int main()
{
    Solution solution;
    vector<int> arr = {5, 7, 7, 8, 8, 10};
    int target = 8;
    cout << solution.countFreq(arr, target) << endl;
    return 0;
}