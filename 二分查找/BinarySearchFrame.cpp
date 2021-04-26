

int binarySearch(vector<int> nums, int target)
{
    int left = 0;
    // int right = ...;

    // while (...)
    {
        //防止溢出
        int mid = left + (right - left) / 2;
        if(nums[mid] == target)
        {
            // ...
        }
        else if (nums[mid] < target)
        {
            // left = ...;
        }
        else if (nums[mid] > target)
        {
            // right = ...;
        }
    }

    // return ...
}