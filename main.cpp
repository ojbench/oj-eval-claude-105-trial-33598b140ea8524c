#include <iostream>
#include <iomanip>

using namespace std;

double dp[25][25];

// Calculate expected days to go from 'from' apples to 'to' apples
double solve(int from, int to) {
    // Base case: already at target
    if (from == to) {
        return 0.0;
    }

    // If already calculated, return cached result
    if (dp[from][to] >= 0) {
        return dp[from][to];
    }

    double sum = 0.0;
    // When we have 'from' apples, we can eat k apples with probability 1/from
    // We can eat k = 1, 2, ..., from apples
    // After eating k apples, we have from-k apples left
    // We only consider cases where from-k >= to (we don't overshoot)
    for (int k = 1; k <= from - to; k++) {
        sum += solve(from - k, to);
    }

    // Expected days = 1 (current day) + (1/from) * sum of expected days from next states
    dp[from][to] = 1.0 + sum / from;

    return dp[from][to];
}

int main() {
    int n, m;
    cin >> n >> m;

    // Initialize dp array with -1 (not calculated)
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = -1.0;
        }
    }

    // We want to go from n apples to (n-m) apples (eating m apples)
    double result = solve(n, n - m);

    // Output with 2 decimal places
    cout << fixed << setprecision(2) << result << endl;

    return 0;
}
