class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int x=-initialEnergy;
        for (int i=0;i<energy.size();i++){x+=energy[i];}
        if (x<0){x=0;}
        else {x++;}
        int o=0;
        for (int i=0;i<experience.size();i++){
            while (initialExperience<=experience[i]){
                initialExperience++;o++;
            }
            initialExperience+=experience[i];
        }
        return x+o;
    }
};