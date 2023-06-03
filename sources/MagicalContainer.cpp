#include "MagicalContainer.hpp"

namespace ariel
{

    // Ctors & Dtors:
    MagicalContainer::MagicalContainer(/* args */)
    {
    }

    MagicalContainer::~MagicalContainer()
    {
    }

    // functions to implement:
    void MagicalContainer::addElement(int number) {}
    int MagicalContainer::size() { return 0; }
    void MagicalContainer::removeElement(int number) {}

    // classes to implement:

    // class MagicalContainer::Iterator:

    // Ctors & Dtors:
    MagicalContainer::Iterator::Iterator(MagicalContainer& con):container(con) {}
    MagicalContainer::Iterator::~Iterator() {}

    // functions to implement:
    MagicalContainer::Iterator MagicalContainer::Iterator::begin() { return *this; }
    MagicalContainer::Iterator MagicalContainer::Iterator::end() { return *this; }
    MagicalContainer::Iterator &MagicalContainer::Iterator::operator++() { return *this; } // prefix
    bool MagicalContainer::Iterator::operator>(const Iterator &other) const { return false; }
    bool MagicalContainer::Iterator::operator<(const Iterator &other) const { return false; }
    MagicalContainer::Iterator & MagicalContainer::Iterator::operator=(const Iterator &other) 
    {
        return *this;
    }
    bool MagicalContainer::Iterator::operator==(
        const MagicalContainer::Iterator &other) const { return true; }
    bool MagicalContainer::Iterator::operator!=(
        const MagicalContainer::Iterator &other) const { return !(*this == other); }

    int MagicalContainer::Iterator::operator*()
    {
        return 1;
    }

    // class MagicalContainer::AscendingIterator:

    // Ctors & Dtors:
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer container) : Iterator(container) {}
    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    // // class MagicalContainer::SideCrossIterator;

    // Ctors & Dtors:
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer container) : Iterator(container) {}
    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

    // // functions to implement:
    // MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() { return *this; }
    // MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end(){ return *this; }

    // MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    // {

    //     return *this;
    // } // prefix

    // bool MagicalContainer::SideCrossIterator::operator!=(
    //     const MagicalContainer::SideCrossIterator &other)
    // {
    //     return false;
    // }

    // int MagicalContainer::SideCrossIterator::operator*()
    // {
    //     return 1;
    // }

    // // class MagicalContainer::PrimeIterator;

    // Ctors & Dtors:
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer container) : Iterator(container) {}
    MagicalContainer::PrimeIterator::~PrimeIterator() {}

    // // functions to implement:
    // MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() { return *this; }
    // MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end(){ return *this; }

    // MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    // {

    //     return *this;
    // } // prefix

    // bool MagicalContainer::PrimeIterator::operator!=(
    //     const MagicalContainer::PrimeIterator &other)
    // {
    //     return !(*this == other);
    // }
    // bool MagicalContainer::PrimeIterator::operator==(
    //     const MagicalContainer::PrimeIterator &other) const
    // {
    //     return true;
    // }

    // int MagicalContainer::PrimeIterator::operator*()
    // {
    //     return 1;
    // }

} // namespace ariel
