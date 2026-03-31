
class Solution {
public:

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<double,double>> posSpdPr;
        int fleetCnt = 0;

        for(int i=0; i< position.size(); ++i)
        {
            posSpdPr.push_back({position[i],speed[i]});
        }
        
        sort( posSpdPr.begin(),posSpdPr.end());//,comparePairs);

        #if 1
        for(int i=0; i< position.size(); ++i)
        {
            cout<<posSpdPr[i].first<<","<<posSpdPr[i].second<<endl;
        }
        #endif

        int fleetH = position.size()-1;
        fleetCnt++;
        double time; 
        time = (target - posSpdPr[fleetH].first) / posSpdPr[fleetH].second;
        cout << "timeH:" << time << endl;
        for(int i=position.size()-2; i>=0 ; --i)
        {
            cout << "time:" << ((target - posSpdPr[i].first)/posSpdPr[i].second) << endl;
            if ( (posSpdPr[i].first+ (time*posSpdPr[i].second)) >= target )
            {
                
            }
            else
            {
                fleetH = i;
                
                time = (target - posSpdPr[fleetH].first)/posSpdPr[fleetH].second;
                cout << "timeH:" << time << endl;
                fleetCnt++;
            }
        }
        
        return fleetCnt;
    }

private:
    static bool comparePairs(const pair<int,int>& a,const pair<int,int>& b)
    {
        return a.first < b.first;
    }
};



