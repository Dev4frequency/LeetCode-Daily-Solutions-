
class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size(); 
        int A = capacityA;
        int B = capacityB;
        int i=0;
        int j=n-1;
        int refill = 0;
        while(i<j){
            if(plants[i]<=capacityA){
            capacityA = capacityA - plants[i];
            i++;
            }
            else{
                refill++;
                capacityA = A;
                capacityA = capacityA - plants[i];
                i++;
            }

            if(plants[j]<=capacityB){
            capacityB = capacityB - plants[j];
            j--;
            }
            else{
                refill++;
                capacityB = B;
                capacityB = capacityB - plants[j];
                j--;
            }
  
        }

        if(i==j){
            if(capacityA == capacityB){
                if(capacityA >= plants[i]){
                capacityA = capacityA - plants[i];
                return refill ;}
                else{
                    refill++;
                    return refill ;
                }


                if(capacityB >= plants[i]){
                capacityB = capacityB - plants[i];
                return refill ;}
                else{
                    refill++;
                    return refill ;
                }
            }


            else{
                if(capacityA < plants[i] && capacityB < plants[i] ){
                    refill++;
                    return refill;
                }
                
            }
            
        }

        return refill;
    }
};
