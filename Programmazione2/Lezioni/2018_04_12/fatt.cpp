#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

class FattoriNutrizionali {
	private:
		const int porzioni;
		const int peso;
		int calorie;
		int grassi;
		int sodio;
		int carboidrati;
		
		FattoriNutrizionali(int x, int y, int calorie, int grassi, int sodio, int carboidrati) : 
			porzioni(x), peso(y) {
			this->calorie = calorie;
			this->grassi = grassi;
			this->sodio = sodio;
			this->carboidrati = carboidrati;
		}	
		FattoriNutrizionali() : porzioni(0), peso(0) {} 
		FattoriNutrizionali(int x, int y) : porzioni(x), peso(y) {}	

	public:
		class Builder {
			//elementi obbligatori
			int porzioni;
			int peso;
			//elementi opzionali
			int calorie;
			int grassi;
			int sodio;
			int carboidrati;
			
			public:
				Builder(int porzioni, int peso) {
					this->porzioni = porzioni;
					this->peso = peso;
					//elementi opzionali
					this->calorie = 0;
					this->grassi = 0;
					this->sodio = 0;
					this->carboidrati = 0;
				}
				Builder setCalorie(int calorie) { 
					this->calorie = calorie; 
					return *this;
				}
				Builder setGrassi(int grassi) { 
					this->grassi = grassi; 
					return *this;
				}
				Builder setSodio(int sodio) { 
					this->sodio = sodio; 
					return *this;
				}
				Builder setCarboidrati(int carboidrati) { 
					this->carboidrati = carboidrati; 
					return *this;
				}
				FattoriNutrizionali build() {
					FattoriNutrizionali nf(porzioni, peso); 
					nf.calorie = calorie;
					nf.grassi = grassi;
					nf.sodio = sodio;
					nf.carboidrati = carboidrati;
					return nf;
				}
		};
		
		int getPorzioni() { return porzioni; }
		int getPeso() { return peso; }
		int getCalorie() { return calorie; }
		int getGrassi() { return grassi; }
		int getSodio() { return sodio; }
		int getCarboidrati() { return carboidrati; }

        void print()
        {
            cout <<"{ "<<porzioni<<" , "<<peso<<" , "<<calorie<<endl;
        }
};

int main() {
	//primo metodo di costruzione
	FattoriNutrizionali::Builder PC(1,100);
	PC.setCalorie(350).setGrassi(134).setSodio(35).setCarboidrati(500);
	FattoriNutrizionali PepsiCola = PC.build();

	//secondo metodo di costruzione
	FattoriNutrizionali  CocoCola = FattoriNutrizionali::Builder(1,100).
								setCalorie(350).
								setGrassi(134).
								setSodio(35).
								setCarboidrati(500).
								build();
    
    CocoCola.print();

	return 0;
}
