// Prüfung C, Sommer 2013, A.Voss@FH-Aachen.de

// todo: matse_name:   Haidl
// todo: matse_matrnr: 864333

#include <thread>
#include <mutex>
void SumFactors(unsigned int aMax, unsigned int aIndex);



// todo:
unsigned int sum_factors_serial(unsigned int n)
{
	unsigned int sum = 0;
	
	for(unsigned int i = 1; i < n; i++)
	{
		if((n % i) == 0)
			sum += i;
	}
    return sum;
}

// todo:
mutex mute;
unsigned int summe = 0;

unsigned int sum_factors_parallel(unsigned int n)
{

	summe = 0;
	thread t1(SumFactors, n, 1);
	thread t2(SumFactors, n, 2);
	
	t1.join();
	t2.join();
    return summe;
}

void SumFactors(unsigned int aMax, unsigned int aIndex)
{

	for(unsigned int i = aIndex; i < aMax; i+=2)
	{
		mute.lock();
		
		if((aMax % i) == 0)
			summe += i;
			
		mute.unlock();		
	}
}
