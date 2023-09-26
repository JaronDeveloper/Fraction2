#include <iostream>

class Fraction
{
	int re_, im_;
public:	
	Fraction(int re, int im) { re_ = re; im_ = im; }
	Fraction  operator+(Fraction  other)
	{
		return Fraction(re_ + other.re_, im_ + other.im_);
	}
	Fraction  operator+(int other) { return Fraction(re_ + other, im_); }
	Fraction  operator-(Fraction  other)
	{
		return Fraction(re_ - other.re_, im_ - other.im_);
	}
	Fraction  operator-(int other) { return Fraction(re_ - other, im_); }

	Fraction  operator*(Fraction  other)
	{
		return Fraction(re_ * other.re_, im_ * other.im_);
	}
	Fraction  operator*(int other) { return Fraction(re_ * other, im_); }

	Fraction  operator /(Fraction  other)
	{
		return Fraction(re_ / other.re_, im_ / other.im_);
	}
	Fraction  operator/(int other) { return Fraction(re_ / other, im_); }

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
	Fraction  f3 = f1 + f2;

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
	++a;
	f3 = f1 * f2;
	std::cout << "++" << a << "/" << b << " * " << c << "/" << d << " = ";
	f3.Print();
	std::cout << "«начение дроби 1 = ";
	f3.Print();
	b--;
	f3 = f1 * f2;
	std::cout << a << "/" << b << "-- * " << c << "/" << d << " = ";
	f3.Print();
	std::cout << "«начение дроби 1 = ";
	f3.Print();
	
	return 0;
}