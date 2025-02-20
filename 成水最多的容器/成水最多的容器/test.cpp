#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int a = 0;
        int b = height.size() - 1;
        int area = 0;
        int max_area = (b - a) * (min(height[a], height[b]));
        if (max_area >= area)
        {
            while (a < b)
            {
                if (height[a] <= height[b])
                {
                    a += 1;
                    area = (b - a) * (min(height[a], height[b]));
                }
                else
                {
                    b -= 1;
                    area = (b - a) * (min(height[a], height[b]));
                }
                max_area = max(max_area, area);
            }

        }

        return max_area;

    }

};
int main()
{
    return 0;
}