#include <iostream>

#include <vector>

using namespace std;

class Solution
{
public:
    /// 二分查找
    // https://leetcode.cn/problems/binary-search/
    // 704.二分查找
    // 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid;
            }
            else
            {
                return mid;
            }
        }

        return -1;
    }

    // https://leetcode.cn/problems/search-insert-position/
    // 35.搜索插入位置
    // 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
    int serarchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (target < nums[mid])
            {
                right = mid;
            }
            else if (target > nums[mid])
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }

        return right;
    }

    /// 移除元素
    // https://leetcode.cn/problems/remove-element/
    // 27.移除元素
    // 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
    int removeElement(vector<int> &nums, int val)
    {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
        {
            if (val != nums[fastIndex])
            {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }

    // https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/
    // 26.删除排序数组中的重复项
    // 给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。
    int removeDuplicates(vector<int> &nums)
    {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
        {
            if (nums[slowIndex] != nums[fastIndex])
            {
                nums[++slowIndex] = nums[fastIndex];
            }
        }
        return slowIndex + 1;
    }

    /// 有序数组的平方
    // https://leetcode.cn/problems/squares-of-a-sorted-array/
    // 977.有序数组的平方
    // 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
    vector<int> sortedSquares(vector<int> &A)
    {
        int k = A.size() - 1;
        vector<int> result(A.size(), 0);
        for (int l = 0, int r = A.size() - 1; l <= r;)
        {
            if (A[l] * A[l] > A[r] * A[r])
            {
                result[k--] = A[l] * A[l];
                l++;
            }
            else
            {
                result[k--] = A[r] * A[r];
                r--;
            }
        }
        return result;
    }

    /// 长度最小的子数组
    // https://leetcode.cn/problems/minimum-size-subarray-sum/
    // 209.长度最小的子数组
    // 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int result = INT32_MAX;
        int sum = 0;
        int l = 0;
        int subLength = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            while (sum >= s)
            {
                subLength = j - l + 1;
                result = result < subLength ? result : subLength;
                l++;
            }
        }

        return result == INT32_MAX ? 0 : result;
    }

    // 水果成篮
    // https://leetcode.cn/problems/fruit-into-baskets/description/
    // 你正在探访一家农场，农场从左到右种植了一排果树。这些树用一个整数数组 fruits 表示，其中 fruits[i] 是第 i 棵树上的水果 种类 。
    // 你想要尽可能多地收集水果。然而，农场的主人设定了一些严格的规矩，你必须按照要求采摘水果：
    // 你只有 两个 篮子，并且每个篮子只能装 单一类型 的水果。每个篮子能够装的水果总量没有限制。
    // 你可以选择任意一棵树开始采摘，你必须从 每棵 树（包括开始采摘的树）上 恰好摘一个水果 。采摘的水果应当符合篮子中的水果类型。每采摘一次，你将会向右移动到下一棵树，并继续采摘。
    // 一旦你走到某棵树前，但水果不符合篮子的水果类型，那么就必须停止采摘。
    // 给你一个整数数组 fruits ，返回你可以收集的水果的 最大 数目。
    int totalFruit(vector<int> &fruits)
    {
        int result = 0;
        int l = 0;
        for (int j = 0; j < fruits.size(); j++)
        {
            result++;
        }
    }
};

int main(int argc, char **argv)
{
    Solution solution;
    // vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> nums = {1, 1, 2};
    solution.removeDuplicates(nums);

    return 0;
}
