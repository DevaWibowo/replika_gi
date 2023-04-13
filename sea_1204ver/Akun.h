#pragma once
using namespace std;

class Akun{
	private:
		int LMD;
	public:
		Akun();
		void SetLMD(int lmd);
		void TambahLMD(int lmd);
		void KurangLMD(int lmd);
		int GetLMD();
};
