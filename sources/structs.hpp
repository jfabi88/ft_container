#ifndef STRUCTS_HPP
#define STRUCTS_HPP

namespace ft
{
	template <bool Cond, class T = void>
	struct enable_if {};

	template <class T>
	struct enable_if<true, T> {typedef T type;};


   //******ITERATOR_TRAITS********//
	//La struttura iterator_traits può essere costruita in due modi.
	//Nel primo modo la struttura non avrà nessun dato definito.
	//Nel secondo modo la struttura avrà definita tutti i 5 dati che rendono tale un iteratore.
	//La struttura verrà creata nel secondo modo nel caso in cui la classe templete T passata
	//come argomento abbia i tipi di dato propri di un iteratore definiti. Se uno di questi
	//non è definito, in atto di compilazione, non è possibile creare la classe void_t in quanto si
	//manifesta un errore nel ricavare dalla classe template T tale tipo. Allora per la SFINAE 
	//il compilatore utilizza il primo costrutture per costruire la struttura.

	template <class = void, class = void, class = void, class = void, class = void>
	struct void_t {typedef void value;};

/* 	template <class T, class = void>
	struct iterator_traits {};

	template <class T>
	struct iterator_traits<T, typename void_t<
							typename T::value_type,
							typename T::difference_type,
							typename T::iterator_category,
							typename T::pointer,
							typename T::reference>::value
						> {
		typedef typename T::value_type            value_type;
		typedef typename T::difference_type       difference_type;
		typedef typename T::iterator_category     iterator_category;
		typedef typename T::pointer               pointer;
		typedef typename T::reference             reference;
	}; */

	//***********IS_ITERATOR**********/
	//E' passata come argomento una classe template T. Il compilatore
	//prova ad instanziare is_iterator<T, enable_if<bool, ...>::value>.
	//enable_if<bool, ...>::value è definito solo nel caso in cui bool==true.
	//  Condizione has_iterator_traits
	//      La condizione che viene richesta è has_iterator_traist<Q>::value in
	//      cui Q=<iterator_traits<T>>.
	//      TRUE:   has_iterator::value è true nel caso in cui iterator_traits<T>
	//              abbia definito value_type, e quindi tutti i tipi di dati propri
	//              di un iteratore.
	//              In questo caso enable_if richiama il costruttore enable_if<true, ...>
	//              che definisce un type.
	//              Il costruttore utilizzato per is_iterator è is_iterator<T, typename ...>
	//              con value=true
	//      FALSE: Nel caso in cui non sia stato definito value_type il compilatore
	//              riscontra un errore di sostituzione per has_iterator_traits<Q>,
	//              quindi utilizza il costruttore has_iterator_traits con value=false.
	//              In questo caso enable_if richiama il costruttore enable_if<false, ...>
	//              che NON definisce un type.
	//              Di consequenza is_iterator incorre in un errore di sostituzione
	//              is_iterator<T, typename <...>::type>.
	//              Il costruttore utilizzato sarà quindi is_iterator, con value=false.

/* 	

	template<typename T, typename = void>
	struct is_iterator
	{
		const static bool value = false;
	};

	template<typename T>
	struct is_iterator<T, typename ft::enable_if<has_iterator_traits<typename ft::iterator_traits<T> >::value, void>::type>
	{
		const static bool value = false;
	}; */


	template<class T, T v>
	struct integral_constant {
		static const T value = v;
		typedef T value_type;
		typedef integral_constant type;
		operator value_type() const { return value; }
	};

	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;

	template <class T>
	struct is_integral : public false_type{};

	template <>
	struct is_integral<bool> : public true_type{};

	template <>
	struct is_integral<char> : public true_type{};

	template <>
	struct is_integral<signed char> : public true_type{};

	template <>
	struct is_integral<unsigned char> : public true_type{};

	template <>
	struct is_integral<wchar_t> : public true_type{};

	template <>
	struct is_integral<short> : public true_type{};

	template <>
	struct is_integral<int> : public true_type{};

	template <>
	struct is_integral<long> : public true_type{};

	template <>
	struct is_integral<long long> : public true_type{};

	template <>
	struct is_integral<unsigned short> : public true_type{};

	template <>
	struct is_integral<unsigned int> : public true_type{};

	template <>
	struct is_integral<unsigned long> : public true_type{};

	template <>
	struct is_integral<unsigned long long> : public true_type{};
}

#endif