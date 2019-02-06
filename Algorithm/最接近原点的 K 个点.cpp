#include<vector>

using namespace std;

class Solution {
public:

	int dist(vector<vector<int>>& points, int i) {
		return points[i][0] * points[i][0] + points[i][1] * points[i][1];
	}

	void swap(vector<vector<int>>& points, int i, int j) {
		int temp1 = points[i][0];
		int temp2 = points[i][1];
		points[i][0] = points[j][0];
		points[i][1] = points[j][1];
		points[j][0] = temp1;
		points[j][1] = temp2;
	}

	void findK(int i, int j, int K, vector<vector<int>>& points) {
		if (i >= j) return;
		int pivot = dist(points, (i + j) / 2);
		int oi = i;
		int oj = j;

		while (i < j) {
			while (i < j && dist(points, i) < pivot)  i++;
			while (i<j && dist(points, j)>pivot)  j--;
			swap(points, i, j);
		}

		if (K <= i - oi + 1) {
			findK(oi, i, K, points);
		}
		else {
			findK(i + 1, oj, K - (i - oi + 1), points);
		}

	}

	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		vector<vector<int>> result;
		findK(0, points.size() - 1, K, points);
		for (int i = 0; i < K; i++) {
			result.push_back(points[i]);
		}

		return result;
	}



};