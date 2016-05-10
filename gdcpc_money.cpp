//
// Created by wb on 16/5/10.
//

#include <iostream>
#include <vector>

using namespace std;

bool cmp(double a, double b) {
    return a > b;
}

int main() {
    int t;
    int n;
    int i, j;
    double left, right;
    double f, tmp, sum, ave;
    vector<double> money;

    cin >> t;
    while (t--) {
        cin >> n >> f;
        sum = 0;
        money.clear();
        for (i = 0; i < n; ++i) {
            cin >> tmp;
            sum += tmp;
            money.push_back(tmp);
        }
        sort(money.begin(), money.end(), cmp);
        i = 0;
        j = n / 2;
        while (true) {
            left = 0;
            for (int k = i; k < j; ++k) {
                left += money[k];
            }
            right = sum - left;
            ave = (left + right - left * f) / (n - f * j);

            if (money[j] <= ave && money[j - 1] >= ave) {
                cout << ave << endl;
                break;
            }
            else if (money[j - 1] < ave) {
                j = j / 2;
            } else if (money[j] > ave) {
                j += (n - j) / 2;
            }
        }
    }
    return 0;
}