#include "utils.hpp"

int main()
{
	try {
/***********************************INSERT***************************************************/

/* 	std::vector<int> ins;
	ft::vector<int>  ftins;
	ft::vector<int>  e;

	ins.push_back(1); ins.push_back(2); ins.push_back(3); ins.push_back(4);ins.push_back(8); ins.push_back(9); ins.push_back(10);
	ftins.push_back(1); ftins.push_back(2); ftins.push_back(3); ftins.push_back(4);ftins.push_back(8); ftins.push_back(9); ftins.push_back(10);

	//e.insert(e.begin(), 3, -1);
	print_vector("Evector", e);
	e.clear();
	e.insert(e.begin(), 3, -1);
	print_vector("Evector2", e);

	print_vector("1)beginning", ins);

	ins.insert(ins.begin() + 4, 3, -1);
	ftins.insert(ftins.begin() + 4, 3, -1);
	print_vector("2)insert(ins.begin() + 4, 3, -1)", ins);
	print_vector("", ftins);

	ins.insert(ins.begin(), 1, 0);
	ftins.insert(ftins.begin(), 1, 0);
	print_vector("3)insert(ins.begin(), 1, 0)", ins);
	print_vector("", ftins);

	ins.insert(ins.begin() + 6, 0, 6);
	ftins.insert(ftins.begin() + 6, 0,6);
	print_vector("4)insert(ins.begin() + 6, 0, 6)", ins);
	print_vector("", ftins);

	ins.insert(ins.end(), 2, 555);
	ftins.insert(ftins.end(), 2, 555);
	print_vector("5)insert(ins.end(), 2, 555)", ins);
	print_vector("", ftins);

	std::cout << "********************************************************************\n";

	ins.clear();
	ftins.clear();
	print_vector("6)ins.clear()", ins);
	print_vector("", ftins);
	std::cout << "begin = " << *(ins.begin()) << "\n";
	std::cout << "begin = " << *(ftins.begin()) << "\n";

	std::cout << "********************************************************************\n";

	ins.push_back(1); ins.push_back(2); ins.push_back(3);
	ftins.push_back(1); ftins.push_back(2); ftins.push_back(3);

	std::vector<int>::const_iterator sit = ins.begin();

	std::vector<int> vf;
	ft::vector<int>  gc;

	vf.insert(ins.begin(),ins.begin(),ins.end());
	print_vector("1)beginning", vf); */

/**************************************************************************************/

/* 	std::vector<int>::iterator ivf;
	ft::vector<int>::iterator igc;

	vf.push_back(1); vf.push_back(2); vf.push_back(3); vf.push_back(4);vf.push_back(8); vf.push_back(9); vf.push_back(10);

	gc.push_back(1); gc.push_back(2); gc.push_back(3); gc.push_back(4);gc.push_back(8); gc.push_back(9); gc.push_back(10);

	print_vector("\nbeginning INSERT single element", vf, 1);
	ivf = vf.insert(vf.begin()+4, 55);
	igc = gc.insert(gc.begin()+4, 55);
	print_vector("10)insert(vf.begin()+4, 5)", vf);
	print_vector("", gc);
	std::cout << *ivf << "," << *igc << "\n";

	ivf = vf.insert(vf.begin()+1, 66);
	igc = gc.insert(gc.begin()+1, 66);
	print_vector("11)insert(vf.begin()+1, 66)", vf, 3);
	print_vector("", gc, 3);
	std::cout << *ivf << "," << *igc << "\n";

	ivf = vf.insert(vf.begin()-3, 433);
	igc = gc.insert(gc.begin()-3, 433);
	print_vector("12)insert(vf.begin()-3, 433)", vf, 5);
	print_vector("", gc, 5);
	std::cout << *ivf << "," << *igc << "\n";

	vf.insert(vf.begin()-2, 2, 45);
	gc.insert(gc.begin()-2, 2, 45);
	print_vector("13)insert(vf.begin()-2, 2, 45)", vf, 4);
	print_vector("", gc, 4);
	return (0);
 */

/***********************************CLEAR***************************************************/

/* 	std::vector<int> cl;
	ft::vector<int>  ftcl;

	cl.push_back(1); cl.push_back(2); cl.push_back(3); cl.push_back(4); cl.push_back(8); cl.push_back(9); cl.push_back(10);
	print_vector("std= ", cl);
	ftcl.push_back(1); ftcl.push_back(2); ftcl.push_back(3); ftcl.push_back(4); ftcl.push_back(8); ftcl.push_back(9); ftcl.push_back(10);
	print_vector("ft= ", ftcl);
	cl.clear();
	ftcl.clear();
	std::cout << cl.size() << std::endl;
	std::cout << ftcl.size() << std::endl;
	print_vector("after clear\n std= ", cl);
	print_vector("ft= ", ftcl); */

	ft::vector<int>  a;
	ft::vector<int>  b;
	ft::vector<int>::iterator it;
	ft::vector<int>::iterator it2;
	for(int i=0; i < 8 ; i++)
		a.push_back(i);

	print_vector("a= ", a, 0 ,true);
	a.insert(a.begin() + 3, 3, 9);
	print_vector("a.insert(a.begin() + 3, 3, 9)", a, 0 ,true);
	a.insert(a.begin() + 2, 11);
	print_vector("a.insert(a.begin() + 2, 9) ", a, 0 ,true);

	a.insert(a.begin() + 4, 3, 11);
	print_vector("a.insert(a.begin() + 4, 3, 11)", a, 0 ,true);
	
	
	it = b.begin();
	b.insert(b.begin(), a.begin()+ 3, a.begin() + 6);
	print_vector("range ", b, 0 ,true);

	}catch (const std::exception& e) {
		// Code that executes when an exception of type
		// networkIOException is thrown in the try block
		// ...
		// Log error message in the exception object
		std::cout << "ERROR: " << e.what();
	}
}
