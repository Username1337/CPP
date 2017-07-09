// Prüfung C, Sommer 2013, A.Voss@FH-Aachen.de

// todo: matse_name:   Haidl	
// todo: matse_matrnr: 864333

#include <iostream>
#include <functional>

using namespace std;

// todo:
class PRNG_Base {
	public:
		virtual unsigned int next() = 0;
		virtual unsigned int* generate_seq(unsigned int aCount)=0;
		virtual ~PRNG_Base() {};
};

// todo: 
// class LKG 
class LKG : public PRNG_Base {
	private:
		unsigned int a;
		unsigned int b;
		unsigned int m;
		unsigned int x0;
		unsigned int xn;
		unsigned int* seq;
	public:
		LKG(unsigned int aA, unsigned int aB, unsigned int aM, unsigned int aX0) : a(aA), b(aB), m(aM), x0(aX0), xn(aX0) {} 
		unsigned int next() override
		{
			xn = (a*xn + b) % m;
			return xn;
		}

		unsigned int* generate_seq(unsigned int aCount) override
		{
			seq = new unsigned int[aCount];
			for(unsigned int i = 0; i< aCount; i++)
			{
				seq[i] = next();
			}
			return seq;
		}
};

// todo: 
// class PRNG
class PRNG : public PRNG_Base {
	private:
		unsigned int x0;
		unsigned int xn;
		function<unsigned int(unsigned int)> f;
		unsigned int* seq;
	public:
	
	PRNG(unsigned int aX0, function<unsigned int(unsigned int)> aFunc) : x0(aX0), xn(aX0), f(aFunc) {}

	unsigned int next() override
	{
		xn = f(xn);
		return xn;
	}

	unsigned int* generate_seq(unsigned int aCount) override
	{
		seq = new unsigned int[aCount];
		for(unsigned int i = 0; i< aCount; i++)
		{
			seq[i] = next();
		}
		return seq;
	}


};

