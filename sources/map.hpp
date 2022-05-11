#pragma once
#include <iostream>
#include "pair.hpp"

namespace ft
{   
	template < class Key,                                    	 // map::key_type
		class T,                                       			// map::mapped_type
		class Compare = std::less<Key>,                     	// map::key_compare
		class Alloc = std::allocator< pair< const Key, T > >    // map::allocator_type
	>
	class map
	{
		public:
			typedef pair<const Key, T>   value_type;
		private:
	};
}

ft::map<std::string, int> m;