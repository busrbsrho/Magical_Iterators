#include "doctest.h"

#include "sources/MagicalContainer.hpp"


using namespace std;
using namespace ariel;

TEST_CASE("removing and adding elements in a magical container") {
	MagicalContainer magic;
	CHECK_EQ(magic.size(), 0);

	magic.addElement(4);
	CHECK_EQ(magic.size(), 1);

	CHECK_NOTHROW(magic.addElement(10));
	CHECK_NOTHROW(magic.addElement(15));
    CHECK_NOTHROW(magic.addElement(12));

	CHECK_EQ(magic.size(), 4);

	CHECK_NOTHROW(magic.removeElement(4));
	CHECK_EQ(magic.size(), 3);

	magic.removeElement(10);
	CHECK_NOTHROW(magic.removeElement(15));
    CHECK_NOTHROW(magic.removeElement(12));
    CHECK_THROWS(magic.removeElement(2));
	CHECK_EQ(magic.size(), 0);
    CHECK_THROWS(magic.removeElement(2));

}

TEST_CASE(" Iterator SideCross ") {
	MagicalContainer magic;
	magic.addElement(10);
	magic.addElement(15);
	magic.addElement(12);
    MagicalContainer::SideCrossIterator cross(magic);

	CHECK_EQ(*cross, 10);
	++cross;
	CHECK_EQ(*cross, 15);
	++cross;
	CHECK_EQ(*cross, 12);
	++cross;
	CHECK_EQ(cross, cross.end());
    CHECK_THROWS(++cross);


}


TEST_CASE("Iterator Sorted")
{
    MagicalContainer magic;
    magic.addElement(10);
    magic.addElement(15);
	magic.addElement(12);

	MagicalContainer::AscendingIterator iter(magic);

	CHECK_EQ(*iter, 10);
	++iter;
	CHECK_EQ(*iter, 12);
	++iter;
	CHECK_EQ(*iter, 15);
	++iter;
	CHECK_EQ(iter, iter.end());
    CHECK_THROWS(++iter);

}

TEST_CASE("Test 4 - Iterator Prime") {
	MagicalContainer magic;
	magic.addElement(11);
	magic.addElement(2);
	magic.addElement(19);

	MagicalContainer::PrimeIterator prime(magic);

	CHECK_EQ(*prime, 2);
	++prime;
	CHECK_EQ(*prime, 11);
	++prime;
    CHECK_EQ(*prime, 19);
    ++prime;
	CHECK_EQ(prime, prime.end());
    CHECK_THROWS(++prime);

}

TEST_CASE("Test 5 - Check iterators comparison") {
	MagicalContainer magic;
	magic.addElement(13);
	magic.addElement(15);
	magic.addElement(12);

	
	MagicalContainer::SideCrossIterator crossIter1(magic);

	MagicalContainer::SideCrossIterator crossIter2(magic);

	MagicalContainer::PrimeIterator primesIter1(magic);

	MagicalContainer::PrimeIterator primesIter2(magic);

    MagicalContainer::AscendingIterator ascIter1(magic);

	MagicalContainer::AscendingIterator ascIter2(magic);

	
	CHECK_EQ(crossIter1, crossIter2);
    CHECK_EQ(ascIter1, ascIter2);
	CHECK_EQ(primesIter1, primesIter2);

}

