// GFG LINK: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
class Solution 
{
    public:
    static bool cmp(Job a , Job b)
    {
        return a.profit > b.profit;
        
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        
        // Sort the Job array by its profit in decendong order
        sort(arr , arr+n , cmp);
        
        //  find the maximum deadline among all the deadlines
        int max_dead = INT_MIN;
        for(int i = 0; i < n ; i++)
        {
            max_dead = max(max_dead , arr[i].dead);
        }
        
        vector<int> vacant(max_dead+1 , 0);
        int cntJobs =0, prof =0 ;
        for(int i= 0 ; i < n ; i++)
        {   
             //  start from the current deadline and move backward to find the
            // vacant space to complete this job, if possible.
            for(int j = arr[i].dead ; j>=1 ; j--)
            {
                
                if(!vacant[j])
                {
                
                vacant[j] = 1;
                prof+= arr[i].profit;
                cntJobs++;
                break;
                }
                
            }
        }
        
        return {cntJobs , prof};
        
    } 
};