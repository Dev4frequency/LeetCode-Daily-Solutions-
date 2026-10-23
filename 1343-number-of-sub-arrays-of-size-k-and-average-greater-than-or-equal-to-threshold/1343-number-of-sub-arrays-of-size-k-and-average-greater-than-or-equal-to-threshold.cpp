class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) 
    {int count = 0;
        int size = arr.size();
        int sum = 0;
        int i = 0;
        
        for(int j = 0; j < k; j++)
        {
            sum += arr[j];
        }

        if((sum / k) >= threshold)
                count++;

        for(int j = k; j < size; j++)
        {
           sum -= arr[i];
           i++;
           sum += arr[j];

           if((sum / k) >= threshold)
                count++;
        }   

        return count;
    }
};