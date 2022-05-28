#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n, tmp, packWeight; cin >> n >> packWeight;
    vector<int> weights(n);
    vector<int> values(n);

    for (int i = 0; i < n; i++){
        cin >> tmp; weights[i] = tmp;
        cin >> tmp; values[i] = tmp;
    }

    vector<vector<int>> dp(2, vector<int>(packWeight + 1, 0));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < packWeight + 1; j++){
            if (j - weights[i] >= 0) {
                dp[1][j] = max(dp[0][j], dp[0][j - weights[i]] + values[i]);
            }
            else{
                dp[1][j] = dp[0][j];
            }
        }

        for (int j = 0; j < packWeight + 1; j++) {
            dp[0][j] = dp[1][j];
        }
    }

    cout << dp[0][packWeight - 1] << endl;
}