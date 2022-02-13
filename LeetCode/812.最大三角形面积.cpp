/*
 * @lc app=leetcode.cn id=812 lang=cpp
 *
 * [812] 最大三角形面积
 */

// @lc code=start
class Solution {
public:
    double det(double x1, double y1, double x2, double y2) {
        return x1 * y2 - x2 * y1;
    }
    double getArea(vector<int>&p1, vector<int>&p2, vector<int>&p3) {
        return 0.5 * fabs(det(p2[0]-p1[0], p2[1]-p1[1], p3[0]-p1[0], p3[1]-p1[1]));
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ret = 0.0, area;
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                for (int k=j+1; k<n; ++k) {
                    area = getArea(points[i], points[j], points[k]);
                    ret = max(ret, area);
                }
            }
        }
        return ret;
    }
};
// @lc code=end

