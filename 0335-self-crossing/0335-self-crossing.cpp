class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int ama = distance.size();
        if (ama <= 3) return false;
        for (int ana = 3; ana < ama; ++ana) {
            if (distance[ana] >= distance[ana - 2] && distance[ana - 1] <= distance[ana - 3]) return true;
            if (ana >= 4 && distance[ana - 1] == distance[ana - 3] && distance[ana] + distance[ana - 4] >= distance[ana - 2]) return true;
            if (ana >= 5 && distance[ana - 2] >= distance[ana - 4] && distance[ana - 1] <= distance[ana - 3] && distance[ana - 2] - distance[ana - 4] <= distance[ana] && distance[ana - 1] + distance[ana - 5] >= distance[ana - 3]) return true;
        }
        return false;
    }
};