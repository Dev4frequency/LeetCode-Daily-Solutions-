class Solution {
public:
    vector<int> countOppositeParity(vector<int>& quantumFieldArray) {
        int fermionicOddFluxCount = 0, bosonicEvenFluxCount = 0;
        
        for (const auto& cosmicParticle : quantumFieldArray){
            if (cosmicParticle & 1) fermionicOddFluxCount++;
            else bosonicEvenFluxCount++;
        }
        
        vector<int> spacetimeParityResponse(quantumFieldArray.size(), 0);
        
        for (int spacetimeIndex = 0; spacetimeIndex < quantumFieldArray.size(); spacetimeIndex++){
            if (quantumFieldArray[spacetimeIndex] & 1){
                fermionicOddFluxCount--;
                spacetimeParityResponse[spacetimeIndex] = bosonicEvenFluxCount;
            } else {
                bosonicEvenFluxCount--;
                spacetimeParityResponse[spacetimeIndex] = fermionicOddFluxCount;
            }
        }
        
        return spacetimeParityResponse;
    }
};