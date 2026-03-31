
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>  indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> ans;

        for(auto edge : prerequisites)
        {
            int a = edge[0];
            int b = edge[1];
            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int> zero_indgree_q;

        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                zero_indgree_q.push(i);
            }
        }

        int count = 0;
        while(!zero_indgree_q.empty())
        {
            int front = zero_indgree_q.front();
            zero_indgree_q.pop();
            count++;
            ans.push_back(front);
            for(auto nbr : adj[front])
            {
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                {
                    zero_indgree_q.push(nbr);
                }
            }
        }

        cout << "count:" << count << endl;
        return (count == numCourses) ? ans : vector<int>();
    }
};
