#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class NumMatrix {
public:
	NumMatrix(vector<vector<int>> matrix)
	{
		this->matrix = matrix;
	}

	int sumRegion(int row1, int col1, int row2, int col2)
	{
		int ret = 0;
		for (int i = row1; i <= row2; ++i)
		{
			for (int j = col1; j <= col2; ++j)
			{
				ret += matrix[i][j];
			}
		}
		return ret;
	}
private:
	vector<vector<int>> matrix;
};
