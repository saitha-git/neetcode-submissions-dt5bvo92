typedef pair<int, int> pi;
class Solution {
public:
    
    // Comparison function defined for the priority queue
    struct compare {
        bool operator()(pair<int, int> p1, pair<int, int> p2)
        {
            // If frequencies of two elements are same
            // then the larger number should come first
            if (p1.first == p2.first)
                return p1.second > p2.second;

            // Insert elements in the priority queue on the
            // basis of decreasing order of frequencies
            return p1.first > p2.first;
        }
    };


    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> freq;

        for (auto elem: nums)
        {
            freq[elem]++;
        }

        for (auto elem: freq)
        {
            cout << elem.second <<" " << elem.first <<endl;
        }
        priority_queue<pi, vector<pi>, compare> pq; 

        for (auto elem: freq)
        {
            pq.push(make_pair(elem.second,elem.first));
            cout << pq.top().second <<" " << pq.top().first <<" " <<pq.size()<<endl;
            if(pq.size()>k)
            {
                pq.pop();
            }
        
        }

        while (!pq.empty())
        {
            cout << pq.top().first <<" " << pq.top().second <<endl;
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};

