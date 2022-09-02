class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

		auto calc_dist = [&](const vector<int> &point) {
			return point[0] * point[0] + point[1] * point[1];
		};

		auto comp = [&](const vector<int> &v1, const vector<int> &v2) {
			return calc_dist(v1) < calc_dist(v2); // MAX HEAP
		};

		priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);

		for (int i = 0; i < k; i++) {
			pq.push(points[i]);
		}

		for (int i = k; i < points.size(); i++) {
			auto point = pq.top();
			int max_dist = calc_dist(point);
			int cur_dist = calc_dist(points[i]);

			if (cur_dist < max_dist) {
				pq.pop();
				pq.push(points[i]);
			}
		}

		vector<vector<int>> ans;
		while (!pq.empty()) {
			ans.push_back(pq.top());
			pq.pop();
		}

		return ans;
	}
};
