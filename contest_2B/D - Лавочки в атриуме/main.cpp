#include <iostream>
#include <vector>

using namespace std;

int main() {
    int L, K;
    vector<int> blocks;
    cin >> L >> K;

    for (int i = 0; i < K; ++i) {
        int coordinate;
        cin >> coordinate;
        blocks.push_back(coordinate);
    }

    int rightBlockIndex = 0;
    int leftBlockIndex = blocks.size() - 1;

    if (L % 2 == 1) {
        while(blocks[rightBlockIndex] < L/2) {
            ++rightBlockIndex;
        }
        while(blocks[leftBlockIndex] > L/2) {
            --leftBlockIndex;
        }
    } else {
        while(blocks[rightBlockIndex] < L/2) {
            ++rightBlockIndex;
        }
        while(blocks[leftBlockIndex] >= L/2) {
            --leftBlockIndex;
        }
    }

    if(leftBlockIndex == rightBlockIndex) {
        cout << blocks[leftBlockIndex];
    } else
    {
        cout << blocks[leftBlockIndex] << " " << blocks[rightBlockIndex];
    }

    return 0;
}