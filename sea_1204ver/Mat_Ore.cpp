#include "Material.cpp"

class Mat_Ore : public Material{
	private:
		int Exp;
	public:
		Mat_Ore(int exp) : Exp(exp){
			
		}
		void SetExp(int exp){
			this->Exp = exp;
		}
		int GetExp(){
			return this->Exp;
		}
};

Mat_Ore* EnhanmentOre = new Mat_Ore(600);
Mat_Ore* FineEnhanmentOre = new Mat_Ore(1000);
Mat_Ore* MysticEnhanmentOre = new Mat_Ore(5000);
