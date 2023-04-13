#pragma once
#include "Akun.h"

Akun* Satu = new Akun();

Akun::Akun(){
	
}
void Akun::SetLMD(int lmd){
	this->LMD = lmd;
}
void Akun::TambahLMD(int lmd){
	this->LMD += lmd;
}
void Akun::KurangLMD(int lmd){
	this->LMD -= lmd;
}
int Akun::GetLMD(){
	return this->LMD;
}
