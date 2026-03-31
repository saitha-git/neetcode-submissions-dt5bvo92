class Compare {
public:
    bool operator()(vector<int> a, vector<int> b)
    {
        double distA = sqrt( a[0]*a[0] + a[1]*a[1] );
        double distB = sqrt( b[0]*b[0] + b[1]*b[1]  );
        
        cout << "a[0]:"<<a[0] << "a[1]:"<<a[1] << endl;
        cout << "b[0]:"<<b[0] << "b[1]:"<<b[1] << endl;
        cout << "distA:" << distA << "distB:" << distB << endl; 
        return distA < distB;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue< vector<int>, vector<vector<int>>, Compare > pq;
        vector<vector<int>> res;
        
        for(auto& point: points)
        {
            pq.push(point);

            while (pq.size() > k)
            {
                pq.pop();
            }
        }

        while (!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};
