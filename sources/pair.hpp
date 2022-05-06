namespace ft
{   
	template <class T1, class T2>
	struct pair
	{
		public:
			typedef T1	first_type;
			typedef T2	second_type;
			first_type	first;
			first_type	second;

			//default constructor
			pair(){
				first = first_type();
				second = first_type();
			}

			//copy / move constructor (and implicit conversion)
			template<class U, class V> pair (const pair<U,V>& pr);
			pair(){
				first = first_type(pr.first);
				second = second_type(pr.second);
			}

			//initialization constructor
			pair(const first_type& a, const second_type& b)
			{
				first = first_type(a);
				second = second_type(a);
			}

			pair& operator= (const pair& pr)
			{
				first = pr.first;
				second = pr.second;
			}

	};

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first==rhs.first && lhs.second==rhs.second; }

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs==rhs); }

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs<lhs); }

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs<lhs; }

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs<rhs); }

	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return ( pair<T1,T2>(x,y) );
	}
}