#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>
using namespace std;

class Coppia{
	private:
		int x,y;
		Coppia(){};
		
	public:
		Coppia(int x, int y) {
			this->x = x;
			this->y = y;
		}
		void setX(int x) { this->x = x;}
		void sety(int y) { this->y = y;}
		int getX() const {return x;}
		int getY() const {return y;}
};

ostream &operator<<(ostream& out, const Coppia& c) {
	out << "(" << c.getX() << ", " << c.getY() << ") ";
	return out;
}

bool operator>(const Coppia& c, const Coppia& d) {
	if(c.getX() > d.getX()) return true;
	else if(c.getX()==d.getX() && c.getY() > d.getY()) return true;
	return false;
}

bool operator==(const Coppia& c, const Coppia& d) {
	if(c.getX() == d.getX() && c.getY() == d.getY()) return true;
	return false;
}

bool operator<(const Coppia& c, const Coppia& d) {
	if(c.getX() < d.getX()) return true;
	else if(c.getX()==d.getX() && c.getY() < d.getY()) return true;
	return false;
}


