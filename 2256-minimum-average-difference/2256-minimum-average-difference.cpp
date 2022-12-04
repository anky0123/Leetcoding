class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long index = 0;
        unsigned long long total_sum = 0;
        long n = nums.size();
        for(int i=0;i<nums.size();i++)
        {
            total_sum +=nums[i];
        }
        unsigned long long  first_sum = 0;
        vector<long long> average;
        for(long long i=0;i<nums.size();i++)
        {
           first_sum +=nums[i]; 
            total_sum -=nums[i];
            if((n-1-i)!=0)
            {
            average.push_back(first_sum/(i+1) - total_sum/(n-1-i));
                if(average[i]<0 ) average[i]*=(-1);
            }
            else
                            average.push_back(first_sum/(i+1));

                
            
        }
        int element  = average[0];
        for(int i=0;i<average.size();i++)
                              {
                                  if(average[i] < element) 
                                  {
                                      element = average[i] ;
                                   index = i;
                                  }
                              }
                              
        return index;      
    }
};