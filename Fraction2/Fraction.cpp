#include <iostream>
#include <numeric>

class Fraction
{
	int re_, im_;
public:	

	Fraction(int re, int im) {
		re_ = re; im_ = im;
	}

	Fraction operator + (Fraction  other)
	{
		int result = this->im_ * other.im_;		
		int result1 = this->re_ * other.im_;
		int result2 = other.re_ * this->im_;

		return Fraction(result1 + result2, result);
	}

	Fraction operator - (Fraction  other)
	{
		int result = this->im_ * other.im_;
		int result1 = this->re_ * other.im_;
		int result2 = other.re_ * this->im_;

		return Fraction(result1 - result2, result);
	}	

	Fraction operator * (Fraction  other)
	{
		int numeratorThis=0, denominatorThis=0;
		int numeratorOther=0, denominatorOther=0;
		int result=0,result1=0;		

		int gcd = std::gcd(this->re_, other.im_);
		int gcd1 = std::gcd(this->im_, other.re_);

		if (gcd != 1) {
			numeratorThis = this->re_ / gcd;
			denominatorOther = other.im_ / gcd;
		}
		else {
			numeratorThis = this->re_;
			denominatorOther = other.im_;
		}

		if (gcd1 != 1) {
			numeratorOther = other.re_ / gcd1;
			denominatorThis = this->im_ / gcd1;
		}
		else {
			numeratorOther = other.re_;
			denominatorThis = this->im_;
		}

		result = numeratorThis * numeratorOther;
		result1 = denominatorThis * denominatorOther;

		return Fraction(result, result1);
	}
	
	Fraction operator / (Fraction  other)
	{
		int numeratorThis=0, denominatorThis=0;
		int numeratorOther=0, denominatorOther=0;
		int result = 0, result1 = 0;

		int gcd = std::gcd(this->re_, this->im_);
		int gcd1 = std::gcd(other.im_, other.re_);

		if (gcd != 1) {		
			denominatorThis = this->im_ / gcd;
			numeratorThis = this->re_ / gcd;
		}
		else {
			denominatorThis = this->im_;
			numeratorThis = this->re_;
		}

		if (gcd1 != 1) {
			numeratorOther = other.re_ / gcd1;
			denominatorOther = other.im_ / gcd1;
		}
		else {
			numeratorOther = other.re_;
			denominatorOther = other.im_;
		}

		result = numeratorThis * denominatorOther;
		result1 = denominatorThis * numeratorOther;

		return Fraction(result, result1);
	}	

	Fraction operator++ ()
	{			
		this->re_ = this->re_ + this->im_;

		return *this;
	}

	Fraction operator-- (int)
	{				
		this->re_ = this->re_ - this->im_;

		return *this;
	}	

	int getRe() {
		return re_;
	}

	int getReP(int a) {
		return re_=a;
	}

	void Print() { std::cout << re_ << "/" << im_ << std::endl; }
};

int main()
{	
	setlocale(LC_ALL, "Russian");
	
	int a, b, c, d;

	std::cout << "¬ведите числитель дроби 1: ";
	std::cin >> a;
	std::cout << "¬ведите знаменатель дроби 1: ";
	std::cin >> b;
	std::cout << "¬ведите числитель дроби 2: ";
	std::cin >> c;
	std::cout << "¬ведите знаменатель дроби 2: ";
	std::cin >> d;
	 
	Fraction  f1(a, b);
	Fraction  f2(c, d);
	Fraction  f3=f1+f2;

	std::cout << a << "/" << b << " + " << c << "/" << d << " = ";
	f3.Print();	
	f3 = f1 - f2;
	std::cout << a << "/" << b << " - " << c << "/" << d << " = ";
	f3.Print();
	f3 = f1 * f2;
	std::cout << a << "/" << b << " * " << c << "/" << d << " = ";
	f3.Print();
	f3 = f1 / f2;
	std::cout << a << "/" << b << " / " << c << "/" << d << " = ";	
	f3.Print();	
	++f1;
	f3 = f1 * f2;
	std::cout << "++" << a << "/" << b << " * " << c << "/" << d << " = ";
	f3.Print();
	std::cout << "«начение дроби 1 = ";
	f1.Print();
	a = f1.getRe();	
	f3 = f1 * f2;
	std::cout << a << "/" << b << "-- * " << c << "/" << d << " = ";
	f3.Print();
	std::cout << "«начение дроби 1 = ";
	f1--;
	f1.Print();
	
	return 0;
}