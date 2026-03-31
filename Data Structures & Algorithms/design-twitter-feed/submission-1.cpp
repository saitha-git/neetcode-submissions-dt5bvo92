class Twitter {
    // userID: tweetIDs
    unordered_map<int, vector<vector<int>> >        tweetMap;
    unordered_map<int, set<int>>                    followMap;
    int timestamp;
public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({timestamp++, tweetId});
    }
    
    struct Compare{
        bool operator()(vector<int>& a, vector<int>& b)
        {
            return a[0] < b[0]; 
        }
    };

    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        followMap[userId].insert(userId);
        priority_queue<vector<int>, vector<vector<int>>, Compare> maxHeap;
        for(auto& followeeId: followMap[userId])
        {
            if (tweetMap.count(followeeId))
            {
                auto& tweets = tweetMap[followeeId];
                int lastIndex = tweets.size()-1;
                // tweets[0] --> timestamp
                maxHeap.push({tweets[lastIndex][0], tweets[lastIndex][1], followeeId, lastIndex});
            }
        }

        while (!maxHeap.empty() && res.size() < 10)
        {
            vector<int> top = maxHeap.top();
            maxHeap.pop();
            int lastIndex = top[3];
            res.push_back(top[1]);          
            if (lastIndex-1 >= 0)
            {
                auto& tweets = tweetMap[top[2]];
                maxHeap.push({tweets[lastIndex-1][0],tweets[lastIndex-1][1],top[2],lastIndex-1});
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};



