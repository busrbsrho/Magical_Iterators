
#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;



MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& _container): container(_container), index(0) {}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& _container, size_t _index): container(_container), index(_index) {}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other): container(other.container), index(other.index) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& _container): container(_container), index(0) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& _container, size_t _index): container(_container), index(_index) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other): container(other.container), index(other.index) {}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& _container): container(_container), index(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& _container, size_t _index): container(_container), index(_index) {}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other): container(other.container), index(other.index) {}