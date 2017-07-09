// Prüfung C, Sommer 2013, A.Voss@FH-Aachen.de

// todo: matse_name:   Nachname
// todo: matse_matrnr: 123456

#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <functional>
#include <thread>

using namespace std;

// todo:
class stringset {
	private:
	class MyIterator
	{
		private:
			const stringset & qu;
			int index;
		public:
			MyIterator(const stringset & aQueue, int aIndex) : qu(aQueue), index(aIndex) {};
			
			bool operator != (const MyIterator & rhs)
			{
				return (&qu == &rhs.qu) && (index != rhs.index);
			}
			
			const MyIterator & operator ++()
			{
				index++;
				return *this;
			}
			
			string operator *() const 
			{
				return qu[index];
			}	
	};


	public:
		vector<string> v;
		
		stringset() {}
		
		stringset(const initializer_list<string>& liste)
		{
			for (string x: liste)
				add(x);
		}

		stringset(const stringset & set)
		{
			for(unsigned int i = 0; i < set.v.size(); i++)
			{
				add(set.v[i]);
			}
		}
		
		void add(const string &s)
		{
			for(string mys : v)
			{
				if (mys == s)
					return;
			}
			v.push_back(string(s));
		}
		
	    stringset& operator+=(const string &s)
		{
			add(s);
			return *(this);
		}
		
		stringset& operator=(const stringset& tmp_obj)
		{
			for(unsigned int i = 0; i < tmp_obj.v.size(); i++)
			{
				add(tmp_obj.v[i]);
			}
			return *this;
		}
		
		friend stringset & operator+(stringset& lobj, stringset robj)
		{
			for(unsigned int i = 0; i < robj.v.size(); i++)
			{
				lobj.add(robj.v[i]);
			}
			
			return lobj;
		}
		
		string operator[](unsigned int pos) const 
		{
			string value = v[pos];
			return value;
		}
		
		friend ostream& operator<<(ostream& os, const stringset& obj)
		{
			
			os << "{ ";
			
			for(unsigned int i = 0; i < obj.v.size(); i++) 
			{
				os << "'" << obj.v[i] << "' ";
			}
			
			os << "}";

			return os;
		}
		MyIterator begin() const
		{
			return MyIterator(*this,0);
		}
		
		MyIterator end() const 
		{
			return MyIterator(*this,v.size());
		}
};



template <typename T>
class Tset
{
	public:
		vector<T> v;
		
		
		void add(const T &s)
		{
			for(auto mys : v)
			{
				if (mys == s)
					return;
			}
			v.push_back(s);
		}
		
	    Tset& operator+=(const T &s)
		{
			add(s);
			return *(this);
		}
		
		
		
		
};
