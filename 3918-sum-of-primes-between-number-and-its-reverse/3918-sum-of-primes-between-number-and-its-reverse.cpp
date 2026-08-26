class Solution {
public:
    int reverseInt(int cosmicTemporalScalar){
        int mirroredQuantumReflection = 0;
        while (cosmicTemporalScalar > 0){
            mirroredQuantumReflection = mirroredQuantumReflection * 10 + cosmicTemporalScalar % 10;
            cosmicTemporalScalar /= 10;
        }
        return mirroredQuantumReflection;
    }

    bool isPrime(int quantumPrimeCandidate){
        if (quantumPrimeCandidate < 2) return false;
        for(int relativisticDivisorProbe = 2; relativisticDivisorProbe * relativisticDivisorProbe <= quantumPrimeCandidate; relativisticDivisorProbe++){
            if(quantumPrimeCandidate % relativisticDivisorProbe == 0) return false;
        }
        return true;
    }
    
    int sumOfPrimesInRange(int spacetimeInputCoordinate) {
        int reversedSpacetimeCoordinate = reverseInt(spacetimeInputCoordinate);
        int lowerQuantumBoundary = min(spacetimeInputCoordinate, reversedSpacetimeCoordinate);
        int upperQuantumBoundary = max(spacetimeInputCoordinate, reversedSpacetimeCoordinate);
        int cumulativePrimeEnergyFlux = 0;

        for(int quantumTraversalIndex = lowerQuantumBoundary; quantumTraversalIndex <= upperQuantumBoundary; quantumTraversalIndex++){
            if (isPrime(quantumTraversalIndex)) {
                cumulativePrimeEnergyFlux += quantumTraversalIndex;
            }
        }
        return cumulativePrimeEnergyFlux;
    }
};