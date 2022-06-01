#include <iostream>
#include <map>
#include "../../sources/map.hpp"
#include "mUtils.hpp"

int main(){

	std::cout << "DAJE_1\n";
	ft::map<int, std::string> map;
	std::cout << "DAJE_2\n";
	std::map<int, std::string> smap;

	ft::map<int, std::string>::iterator it;
	std::map<int, std::string>::iterator sit;
	std::map<int, std::string>::iterator sit2(sit);
	std::map<int, std::string>::iterator sit3;
	sit3 = sit2;

	smap.insert(std::make_pair(0, "zero"));
	map.insert(ft::make_pair(0, "zero"));

	sit = smap.begin();
	std::cout << sit->first << "/" << (*sit).second << std::endl;

	it = map.begin();
	std::cout << it->first << "/" << (*it).second << std::endl;

	std::cout << "STD:\n";
	sit = smap.insert(sit , std::make_pair(1, "uno"));
	std::cout << sit->first << "/" << (*sit).second << std::endl;
	sit = smap.insert(sit, std::make_pair(2, "due"));
	std::cout << sit->first << "/" << (*sit).second << std::endl;
	sit = smap.begin();
	std::cout << "begin = " << sit->first << "/" << (*sit).second << std::endl;
	sit++;
	std::cout << sit->first << "/" << (*sit).second << std::endl;

	std::cout << "FT:\n";
	it = map.insert(it , ft::make_pair(1, "uno"));
	std::cout << it->first << "/" << (*it).second << std::endl;
	it = map.insert(it, ft::make_pair(2, "due"));
	std::cout << it->first << "/" << (*it).second << std::endl;
	it = map.begin();
	std::cout << "begin = " << it->first << "/" << (*it).second << std::endl;
	it++;
	std::cout << it->first << "/" << (*it).second << std::endl;



	sit = smap.insert(smap.begin(), std::make_pair(9, "nove"));
	smap.insert(sit, std::make_pair(8, "8"));
	it = map.insert(map.begin(), ft::make_pair(9, "nove"));
	map.insert(it, ft::make_pair(8, "8"));


	ft::map<int, std::string> map2;
	std::map<int, std::string> smap2;

	std::cout << "\nInsert Range\n";
	smap2.insert(smap.begin(), sit);
	for (sit = smap2.begin(); sit != smap2.end(); sit++){
		std::cout << sit->first << "/" << (*sit).second << std::endl;
	}

	std::cout << "\nInsert Range(FT)\n";
	map2.insert(map.begin(), it);
	for (it = map2.begin(); it != map2.end(); it++){
		std::cout << it->first << "/" << (*it).second << std::endl;
	}

	prinTree(map2._tree);

/* 	std::cout << "STD=) " <<  (smap2.begin() == smap.begin()) << "/"
					   << ( *(smap2.begin()) == *(smap.begin()) ) << std::endl;

	std::cout << "FT=) " <<  (map2.begin() == map.begin()) << "/"
					   << ( *(map2.begin()) == *(map.begin()) ) << std::endl; */

	std::cout << "STD=) " <<  (smap2 == smap) << std::endl;
	std::cout << "FT=) " <<  (map2 == map) << std::endl;

	std::cout << "STD<) " <<  (smap2 < smap) << std::endl;
	std::cout << "FT<) " <<  (map2 < map) << std::endl;

	std::cout << "STD>) " <<  (smap2 > smap) << std::endl;
	std::cout << "FT>) " <<  (map2 > map) << std::endl;
/*     std::map<int, std::string> roma;
	std::map<int, std::string>::iterator a;
	std::map<int, std::string>::const_iterator b;
	std::map<int, std::string>::iterator::pointer c;
	std::map<int, std::string>::const_iterator::pointer d;
	std::map<int, std::string>::iterator::value_type e; */

	ft::map<int, int > mp;
	ft::map<int, int, std::plus<int> > mp2;

	std::map<int, int > smp;
	std::map<int, int, std::plus<int> > smp2;

	mp.insert(ft::make_pair(16, 3));

    smp2.insert(std::make_pair(16, 3));
    smp2.insert(std::make_pair(8, 3));
    smp2.insert(std::make_pair(23, 3));
    smp2.insert(std::make_pair(7, 3));
    smp2.insert(std::make_pair(19, 3));
    smp2.insert(std::make_pair(29, 3));
    smp2.insert(std::make_pair(41, 3));
    smp2.insert(std::make_pair(4, 3));
    smp2.insert(std::make_pair(11, 3));

    mp2.insert(ft::make_pair(16, 3));
    mp2.insert(ft::make_pair(8, 3));
    mp2.insert(ft::make_pair(23, 3));
    mp2.insert(ft::make_pair(7, 3));
    mp2.insert(ft::make_pair(19, 3));
    mp2.insert(ft::make_pair(29, 3));
    mp2.insert(ft::make_pair(41, 3));
    mp2.insert(ft::make_pair(4, 3));
    mp2.insert(ft::make_pair(11, 3));

	std::map<int, int >::iterator smpi = smp2.begin();
	//ft::map<int, int >::iterator mpix = mp.begin();
	//ft::map<int, int, std::plus<int> >::iterator mpi = mp2.begin();
	ft::map<int, int>::iterator mpi = mp2.begin();
	std::cout << "hey = " << mpi->first << std::endl;

	//map with plus commpare
	std::cout << "STD MAP with plus commpare :" << std::endl;
	for (smpi = smp2.begin(); smpi != smp2.end(); smpi++){
		std::cout << smpi->first << "/" << (*smpi).second << std::endl;
	}

	//prinTree(mp2._tree);
	ft::debugxx();
	//map with plus commpare
	std::cout << "FT MAP with plus commpare :" << std::endl;
	for (mpi = mp2.begin(); mpi != mp2.end(); mpi++){
		std::cout << mpi->first << "/" << (*mpi).second << std::endl;
		//exit(0);
	}


	ft::map<int, char>::iterator pippo;
	ft::map<const int, char>::iterator pluto;

	pippo = pluto;
}