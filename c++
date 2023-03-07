You are given an array time where time[i] denotes the time taken by the ith bus to complete one trip.

Each bus can make multiple trips successively; that is, the next trip can start immediately after completing the current trip. 

Also, each bus operates independently; that is, the trips of one bus do not influence the trips of any other bus.

You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. 

Return the minimum time required for all buses to complete at least totalTrips trips.

****************************************************************************************************************************************

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long start = 1;
        long long end = 1e14;
        while(start <= end){
            long long trip = 0;
            long long mid = start + (end - start)/2;
            for(int i=0;i<time.size();i++)
                trip += mid / time[i];
            if(trip < totalTrips){
                start = mid + 1;
            }
            else 
                end = mid - 1;
        }
        return start;
    }
};
