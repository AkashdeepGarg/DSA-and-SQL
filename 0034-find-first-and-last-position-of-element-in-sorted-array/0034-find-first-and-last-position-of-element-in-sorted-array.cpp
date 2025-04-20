class Solution {
public:
    vector<int> searchRange(vector<int>& A, int B) {
        int n = A.size();
    int low = 0, high = n - 1;
    int first = -1, last = -1;

    // Find first occurrence
    while (low <= high) {
        int mid = (low + high) / 2;
        if (A[mid] == B) {
            first = mid;
            high = mid - 1; // keep searching in left part
        } else if (A[mid] < B) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Find last occurrence
    low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (A[mid] == B) {
            last = mid;
            low = mid + 1; // keep searching in right part
        } else if (A[mid] < B) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return {first, last};
    }
};