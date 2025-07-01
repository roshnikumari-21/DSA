// using dijkstra's algorithm
// every node will be between 0 to 9999

// use min-heap  {steps,number}, array
// here a simplle queue will also work , coz we are going in incressing nature

//tc=O(1e5 * N) 
//but we cant geneatate all the number so tc will be lesser than this

#include <vector>
#include <queue>
#include <utility>
#include <limits.h>

using namespace std;

class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        queue<pair<int, int>> q; // {current number, steps taken}
        q.push({start, 0});

        vector<int> dist(100000, INT_MAX);
        dist[start] = 0;
        int mod = 100000; // To limit the number size

        while (!q.empty())
        {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();

            for (auto it : arr)
            {
                int num = (it * node) % mod; // Perform multiplication and take modulo
                if (steps + 1 < dist[num])
                {
                    dist[num] = steps + 1;
                    if (num == end)
                        return dist[num]; // Found the end
                    q.push({num, dist[num]});
                }
            }
        }

        return -1; // If no path found
    }
};