//Alfonzo Avila	aavila28@cnm.edu
// File : Functions.h

void WriteHeader();
void fillvectors(vector<string> &vShowerType, vector<int> &vminGal, vector<int> &vmaxGal);
void askFishShower(vector<string> &vShowerType, int *pindex);
void calcPond(int *gal);
bool validateFishShower(int index, int gal, vector<int> &vminGal, vector<int> &vmaxGal, vector<int> &vrecommendation);
void WriteInfo(vector<string> &vshowertype, int gal, int index);
void WriteInfo(string showertype, vector<string> &vShowerType, vector<int> &vrecommendation, int gal);
