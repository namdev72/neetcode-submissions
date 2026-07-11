class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = position.size();

        // {position, time_to_reach_target}
        vector<pair<int, double>> car(n);

        for (int i = 0; i < n; i++) {
            car[i] = {
                position[i],
                (double)(target - position[i]) / speed[i]
            };
        }

        // Sort cars according to position
        sort(car.begin(), car.end());

        stack<double> st;

        // Traverse from the car closest to the target
        for (int i = n - 1; i >= 0; i--) {

            // New fleet only if current car takes more time
            if (st.empty() || car[i].second > st.top()) {
                st.push(car[i].second);
            }
            // Else: current car catches the fleet ahead,
            // so don't push anything.
        }

        return st.size();
    }
};