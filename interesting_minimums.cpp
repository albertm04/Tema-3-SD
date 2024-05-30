#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll total = 0;

int main() {
    int count;
    cin >> count;
    vector<int> nums(count), left(count), right(count);
    for (int i = 0; i < count; i++) {
        cin >> nums[i];
    }
    vector<int> stack;
    for (int i = 0; i < count; i++) {
        while (!stack.empty() && nums[i] <= nums[stack.back()]) {
            stack.pop_back();
        }
        left[i] = stack.empty() ? 0 : stack.back() + 1;
        stack.push_back(i);
    }
    stack.clear();
    for (int i = count - 1; i >= 0; i--) {
        while (!stack.empty() && nums[i] < nums[stack.back()]) {
            stack.pop_back();
        }
        right[i] = stack.empty() ? count - 1 : stack.back() - 1;
        stack.push_back(i);
    }
    for (int i = 0; i < count; i++) {
        for (int j = left[i]; j <= i; j++) {
            total += max(0, min(right[i], 2 * i - j - 1) - i + 1);
        }
    }
    cout << total << "\n";
    return 0;
}

