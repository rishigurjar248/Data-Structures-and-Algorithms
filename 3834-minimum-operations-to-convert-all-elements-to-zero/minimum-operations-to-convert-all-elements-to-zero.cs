public class Solution {
    private void GroupIdx(List<List<int>> groups, int[] vals) {
        int pos = 0;
        int n = vals.Length;
        while (pos < n) {
            if (vals[pos] > 0) {
                groups[vals[pos]].Add(pos);
            }
            pos++;
        }
    }

    private int CountOperations(List<int> positions, FenwickTree tracker) {
        int ops = 0;
        int lastPos = -2;
        int it = 0;
        int m = positions.Count;
        while (it < m) {
            int curr = positions[it];
            if (lastPos == -2 || tracker.RangeCount(lastPos + 1, curr - 1) > 0) {
                ops++;
            }
            lastPos = curr;
            it++;
        }
        int j = 0;
        while (j < m) {
            tracker.Mark(positions[j], 1);
            j++;
        }
        return ops;
    }

    public int MinOperations(int[] nums) {
        int n = nums.Length;
        int peak = 0, idx = 0;
        while (idx < n) {
            if (nums[idx] > peak) {
                peak = nums[idx];
            }
            idx++;
        }

        List<List<int>> groups = new List<List<int>>();
        for (int i = 0; i <= peak + 5; i++) {
            groups.Add(new List<int>());
        }
        GroupIdx(groups, nums);

        FenwickTree zeroTracker = new FenwickTree(n);
        int k = 0;
        while (k < n) {
            if (nums[k] == 0) {
                zeroTracker.Mark(k, 1);
            }
            k++;
        }

        int res = 0;
        int val = 1;
        while (val <= peak) {
            if (groups[val].Count > 0) {
                res += CountOperations(groups[val], zeroTracker);
            }
            val++;
        }

        return res;
    }
}

public class FenwickTree {
    private int[] BIT;
    private int len;

    public FenwickTree(int size) {
        len = size;
        BIT = new int[size + 2];
    }

    public void Mark(int idx, int val) {
        idx++;
        while (idx <= len) {
            BIT[idx] += val;
            idx += (idx & -idx);
        }
    }

    public int Sum(int idx) {
        idx++;
        int res = 0;
        while (idx > 0) {
            res += BIT[idx];
            idx -= (idx & -idx);
        }
        return res;
    }

    public int RangeCount(int l, int r) {
        if (l > r) return 0;
        return Sum(r) - Sum(l - 1);
    }
}
