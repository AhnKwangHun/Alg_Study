#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int H, W, input;
vector<int> height;

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> H >> W; // ����, ����
	for (int i = 0; i < W; i++) {
		cin >> input;
		height.push_back(input);
	}
	int result = 0;
	
	// �� ������ �¿츦 ���캼 �ʿ䰡 ����
	for (int i = 1; i < W - 1; i++) {
		// ����, ������ ���캸��
		int left = 0, right = 0;
		for (int L = i-1; L >= 0; L--) 
			left = max(left, height[L]);
		for (int R = i + 1; R < W; R++) 
			right = max(right, height[R]);

		int target = min(left, right); // ���� �� ����
		int current = height[i]; // ���� ����
		result = result + max(0, target - current);
	}

	cout << result;

	return 0;
}