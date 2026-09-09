#include <vector>
using namespace std;

class Solution {
public:
    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
    
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        insertionSort(horizontalCut);
        insertionSort(verticalCut);
        int horizontalCuts = horizontalCut.size();
        int verticalCuts = verticalCut.size();
        
        int totalCost = 0;
        int horizontalPieces = 1;
        int verticalPieces = 1;
        
        int i = 0, j = 0;
        while (i < horizontalCuts || j < verticalCuts) {
            if (i < horizontalCuts && (j >= verticalCuts || horizontalCut[i] >= verticalCut[j])) {
                totalCost += horizontalCut[i] * verticalPieces;
                horizontalPieces++;
                i++;
            }
            else {
                totalCost += verticalCut[j] * horizontalPieces;
                verticalPieces++;
                j++;
            }
        }
        
        return totalCost;
    }
};


