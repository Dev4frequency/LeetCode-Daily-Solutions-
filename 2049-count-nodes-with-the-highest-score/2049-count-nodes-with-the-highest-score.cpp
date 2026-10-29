class Solution {
public:
    struct Node {
        int left = -1;
        int right = -1;
    };

    int countHighestScoreNodes(vector<int>& parents) {
        vector<Node> tree(parents.size());
        for (int i = 1; i < parents.size(); i++) {
            if (tree[parents[i]].left < 0)
                tree[parents[i]].left = i;
            else tree[parents[i]].right = i;
        }

        long long maxScore = 0; int count = 0;
        traverse(tree, 0, maxScore, count);
        return count;
    }

    int traverse(vector<Node>& tree, int root, long long& maxScore, int& count) {
        if (root == -1)
            return 0;
        int left = traverse(tree, tree[root].left, maxScore, count);
        int right = traverse(tree, tree[root].right, maxScore, count);
        int parent = tree.size() - 1 - left - right;
        long long score = (long long)(max(right, 1)) *
                          (long long)(max(left, 1)) *
                          (long long)(max(parent, 1));
        if (score > maxScore) {
            maxScore = score;
            count = 1;
        } else count += maxScore == score;
        return left + right + 1;
    }

};