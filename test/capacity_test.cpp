#include <iostream>
#include <vector>
#include <memory>
#include "utils.hpp"

int main()
{

/*MAX SIZE */
/*     std::vector<std::string> vect2(4, "ciao");
	ft::vector<std::string> vect(4, "ciao");

	std::vector<int> vect3(4, 11);
	ft::vector<int> vect4(4, 11);

	std::vector<bool> vect5(4, true);
	ft::vector<bool> vect6(4, true);

	std::vector<float> vect7(4, 2.5f);
	ft::vector<float> vect8(4, 2.5f);

	std::vector<char> vect9(4, 'n');
	ft::vector<char> vect10(4, 'n');

	std::cout << "STRING" << std::endl;
	std::cout << "ft::vector: " << vect.max_size() << std::endl;
	std::cout << "sd::vector: " << vect2.max_size() << std::endl;
	std::cout << "INT" << std::endl;
	std::cout << "ft::vector: " << vect4.max_size() << std::endl;
	std::cout << "sd::vector: " << vect3.max_size() << std::endl;
	std::cout << "BOOL" << std::endl;
	std::cout << "ft::vector: " << vect6.max_size() << std::endl;
	std::cout << "sd::vector: " << vect5.max_size() << std::endl;
	std::cout << "FLOAT" << std::endl;
	std::cout << "ft::vector: " << vect8.max_size() << std::endl;
	std::cout << "sd::vector: " << vect7.max_size() << std::endl;
	std::cout << "CHAR" << std::endl;
	std::cout << "ft::vector: " << vect10.max_size() << std::endl;
	std::cout << "sd::vector: " << vect9.max_size() << std::endl; */


/* RESIZE & RESERVE*/

    std::vector<int> rvect_st(5, 11); 
	ft::vector<int> rvect(5, 11);

	std::cout << "0) at Beginning" << std::endl;
	print_vector("FT::VECTOR", rvect, 0, true);
	print_vector("SD::VECTOR", rvect_st, 0, true);

	std::cout << std::endl << "1) reserve(9);" << std::endl;
	rvect.reserve(9);
	rvect_st.reserve(9);	
	print_vector("FT::VECTOR", rvect, 0, true);
	print_vector("SD::VECTOR", rvect_st, 0, true);

	std::cout << std::endl << "2)resize(2, 8);" << std::endl;
	rvect.resize(2, 8);
	rvect_st.resize(2, 8);
	print_vector("FT::VECTOR", rvect, 0, true);
	print_vector("SD::VECTOR", rvect_st, 0, true);

	std::cout << std::endl << "3)resize(7,1);" << std::endl;
	rvect.resize(7,1);
	rvect_st.resize(7,1);
	print_vector("FT::VECTOR", rvect, 0, true);
	print_vector("SD::VECTOR", rvect_st, 0, true);

	std::cout << std::endl << "4)resize(10);" << std::endl;
	rvect.resize(10);
	rvect_st.resize(10);
	print_vector("FT::VECTOR", rvect, 0, true);
	print_vector("SD::VECTOR", rvect_st, 0, true);

	std::cout << std::endl << "5)reserve(12);" << std::endl;
	rvect.reserve(12);
	rvect_st.reserve(12);
	print_vector("FT::VECTOR", rvect, 0, true);
	print_vector("SD::VECTOR", rvect_st, 0, true);

	std::cout << std::endl << "6)resize(37, 5);" << std::endl;
	rvect.resize(37, 5);
	rvect_st.resize(37, 5);
	print_vector("FT::VECTOR", rvect, 0, true);
	print_vector("SD::VECTOR", rvect_st, 0, true);

/* RESIZE & RESERVE*/

/*     std::cout << "CIAO" << std::endl;
	std::vector<std::string> rsvect_st(5, "Sole");
	ft::vector<std::string> rsvect(5, "Sole");
	std::cout << "Come state" << std::endl;
	rsvect.reserve(8);
	std::cout << "Come state" << std::endl;
	rsvect_st.reserve(8);
	std::cout << "Come state" << std::endl;
	rsvect.resize(3, "Luna");
	rsvect_st.resize(3, "Luna");

	std::cout << "TEST RESIZE RESERVE (std::string)" << std::endl;
	std::cout << "Size e capacity di ft::vector : " << rsvect.size() << " " << rsvect.capacity() << std::endl;
	std::cout << "Size e capacity di sd::vector: " << rsvect_st.size() << " " << rsvect_st.capacity() << std::endl;
	print_vector("FT::VECTOR", rsvect);
	print_vector("SD::VECTOR", rsvect_st);
	rsvect.resize(5, "Marte");
	rsvect_st.resize(5, "Marte");
	std::cout << "Size e capacity di ft::vector : " << rsvect.size() << " " << rsvect.capacity() << std::endl;
	std::cout << "Size e capacity di sd::vector: " << rsvect_st.size() << " " << rsvect_st.capacity() << std::endl;
	print_vector("FT::VECTOR", rsvect);
	print_vector("SD::VECTOR", rsvect_st);
	rsvect.resize(7);
	rsvect_st.resize(7);
	std::cout << "Size e capacity di ft::vector : " << rsvect.size() << " " << rsvect.capacity() << std::endl;
	std::cout << "Size e capacity di sd::vector: " << rsvect_st.size() << " " << rsvect_st.capacity() << std::endl;
	print_vector("FT::VECTOR", rsvect);
	print_vector("SD::VECTOR", rsvect_st);
	rsvect.resize(10);
	rsvect_st.resize(10);
	std::cout << "Size e capacity di ft::vector : " << rsvect.size() << " " << rsvect.capacity() << std::endl;
	std::cout << "Size e capacity di sd::vector: " << rsvect_st.size() << " " << rsvect_st.capacity() << std::endl;
	print_vector("FT::VECTOR", rsvect);
	print_vector("SD::VECTOR", rsvect_st);
	rsvect.resize(14, "Venere");
	rsvect_st.resize(14, "Venere");
	std::cout << "Size e capacity di ft::vector : " << rsvect.size() << " " << rsvect.capacity() << std::endl;
	std::cout << "Size e capacity di sd::vector: " << rsvect_st.size() << " " << rsvect_st.capacity() << std::endl;
	print_vector("FT::VECTOR", rsvect);
	print_vector("SD::VECTOR", rsvect_st); */


/* PUSH_BACK & RESERVE*/

/*     std::vector<int>::size_type sz;
	ft::vector<int>::size_type cz;
	std::vector<int> foo;
	ft::vector<int> cfoo;

	sz = foo.capacity();
	std::cout << "making foo grow from: " << sz << "\n";
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
		if (sz!=foo.capacity()) {
		sz = foo.capacity();
		std::cout << "capacity changed: " << sz << '\n';
		}
	}

	std::cout << "\n****************************************************\n";
	cz = cfoo.capacity();
	std::cout << "making foo grow from: " << cz << "\n";
	std::cout << "MAX SIZE: " << cfoo.max_size() << "\n";
	for (int i=0; i<100; ++i) {
	   cfoo.push_back(i);
		if (cz!=cfoo.capacity()) {
			cz = cfoo.capacity();
			std::cout << i << ")capacity changed: " << cz;
			print_vector(" vECTOR", cfoo);
			std::cout << '\n';
			//std::cout << " value: " << cfoo.at(i) << '\n';
		}
	}

	std::cout << "\n****************************************************\n";

	std::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
		sz = bar.capacity();
		std::cout << "capacity changed: " << sz << '\n';
		}
	}

	 ft::vector<int> cbar;
	cz = cbar.capacity();
	cbar.reserve(100);   // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		cbar.push_back(i);
		if (cz!=cbar.capacity()) {
		cz = cbar.capacity();
		std::cout << "capacity changed: " << cz << '\n';
		}
	} */



	/* RESIZE*/
	std::vector<int> myvector;
	std::vector<int> cmyvector;

	// set some initial content:
	for (int i=1;i<10;i++) {
		myvector.push_back(i);
		cmyvector.push_back(i);
	}
	// 1 2 3 4 5 6 7 8 9

	myvector.resize(5);
	// 1 2 3 4 5 0 0 0 0
	myvector.resize(8,100);
	// 1 2 3 4 5 100 100 100 0
	myvector.resize(12);
	// 1 2 3 4 5 100 100 100 0 0 0 0 0


	cmyvector.resize(5);
	cmyvector.resize(8,100);
	cmyvector.resize(12);

	std::cout << "myvector contains:";
	for (int i=0;i<myvector.size();i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	std::cout << "Cmyvector contains:";
	for (int i=0;i<cmyvector.size();i++)
		std::cout << ' ' << cmyvector[i];
	std::cout << '\n';
}