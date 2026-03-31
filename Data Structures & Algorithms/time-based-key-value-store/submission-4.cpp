class TimeMap {
public:
    unordered_map< string, vector<pair<int,string>> > timemap;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timemap[key].push_back({timestamp,value});
    }
    
    string findT(vector<pair<int,string>> myVec,int timestamp)
    {
        int n = myVec.size();
        int l = 0;
        int r = n-1;
        int mid;

        while(l<=r)
        {
            mid = l+(r-l)/2;

            if(myVec[mid].first == timestamp)
            {
                return myVec[mid].second;
            }
            else if(timestamp < myVec[mid].first)
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }

        if(myVec[mid].first < timestamp)
        {
            return myVec[mid].second;
        }
        else if(timestamp < myVec[mid].first)
        {
            if( mid-1 >= 0)
                return myVec[mid-1].second;
            else
                return "";
        }
        else
        {
            return "";
        }

    }

    string get(string key, int timestamp) {
        vector<pair<int,string>> myVec;

        if(timemap.find(key) != timemap.end())
        {
            myVec = timemap[key];   
        }
        else
        {
            return "";
        }

        return findT(myVec,timestamp);
    }
};

