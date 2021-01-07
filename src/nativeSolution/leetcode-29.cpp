#include <vector>
#include <iostream>
using namespace std;
 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }

        int rows = matrix.size(), columns = matrix[0].size();
        vector<int> order;
        int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
        while (left <= right && top <= bottom) {
            for (int column = left; column <= right; column++) {
                order.push_back(matrix[top][column]);
            }
            for (int row = top + 1; row <= bottom; row++) {
                order.push_back(matrix[row][right]);
            }
            if (left < right && top < bottom) {
                for (int column = right - 1; column > left; column--) {
                    order.push_back(matrix[bottom][column]);
                }
                for (int row = bottom; row > top; row--) {
                    order.push_back(matrix[row][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return order;
    }
};
int main(){
    Solution solution1;
    vector<vector<int>> matrix;
    matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> result;
    result = solution1.spiralOrder(matrix);
    for (auto lin: result){
        cout << lin;
    }
    cout << "\n";
    return 0;
}
// g++ leetcode-29.cpp -o a.out&&./a.out&&rm a.out