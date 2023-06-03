#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <stdexcept>

using namespace ariel;
using namespace std;


TEST_CASE("checking the functions of MagicalContainer")
{

    SUBCASE("checking addElement() and size()")
    {

        // upon initialization, size() should return 0:
        MagicalContainer container;
        CHECK(container.size() == 0);

        // after adding a single element:
        container.addElement(1);
        CHECK(container.size() == 1);

        // adding multiple elements at once:
        container.addElement(2);
        container.addElement(3);
        container.addElement(4);
        container.addElement(5);
        container.addElement(6);
        container.addElement(7);

        CHECK(container.size() == 7);

        container.addElement(8);
        container.addElement(9);
        container.addElement(10);

        CHECK(container.size() == 10);
    }

    SUBCASE("checking removeElement()")
    {

        MagicalContainer container;
        container.addElement(10);
        container.addElement(11);

        // removing the first inserted element into the container:
        CHECK(container.size() == 2);
        CHECK_NOTHROW(container.removeElement(10));
        CHECK(container.size() == 1);

        container.addElement(12);
        container.addElement(13);
        container.addElement(14);
        container.addElement(15);

        // removing the last inserted element into the container:
        CHECK(container.size() == 5);
        CHECK_NOTHROW(container.removeElement(15));
        CHECK(container.size() == 4);

        // removing some element that was at some point inserted into the container:
        CHECK(container.size() == 4);
        CHECK_NOTHROW(container.removeElement(13));
        CHECK(container.size() == 3);

        // removing an already removed element:
        CHECK_THROWS_AS(container.removeElement(13), runtime_error);
        CHECK(container.size() == 3);

        // removing an element that is not in the container:
        CHECK_THROWS_AS(container.removeElement(9), runtime_error);
        CHECK(container.size() == 3);
    }
}

TEST_CASE("Iterating through different containers using different Iterators")
{

    SUBCASE("Iterating with AscendingIterator")
    {
        MagicalContainer container;
        container.addElement(2);
        container.addElement(3);
        container.addElement(4);
        container.addElement(5);
        container.addElement(6);
        container.addElement(7);

        MagicalContainer::AscendingIterator ait(container);
        CHECK(*ait == 2);
        ++ait;
        CHECK(*ait == 3);
        ++ait;
        CHECK(*ait == 4);
        ++ait;
        CHECK(*ait == 5);
        ++ait;
        CHECK(*ait == 6);
        ++ait;
        CHECK(*ait == 7);
        ++ait;

        CHECK(ait == ait.end());

        SUBCASE("Iterating with AscendingIterator with begin(), end(), '!=' ")
        {
            MagicalContainer::AscendingIterator ait2(container);
            int i = 2;
            for (auto it = ait2.begin(); it != ait2.end(); ++it)
            {
                CHECK(*it == i++);
            }
            CHECK(ait2 == ait2.end());
        }
    }

    SUBCASE("Iterating with PrimeIterator")
    {
        MagicalContainer container;
        container.addElement(2);
        container.addElement(3);
        container.addElement(4);
        container.addElement(5);
        container.addElement(6);
        container.addElement(7);

        MagicalContainer::PrimeIterator pit(container);
        CHECK(*pit == 2);
        ++pit;
        CHECK(*pit == 3);
        ++pit;
        CHECK(*pit == 5);
        ++pit;
        CHECK(*pit == 7);
        ++pit;

        CHECK(pit == pit.end());
    }

    SUBCASE("Iterating with SideCrossIterator")
    {
        MagicalContainer container;
        container.addElement(2);
        container.addElement(3);
        container.addElement(4);
        container.addElement(5);
        container.addElement(6);
        container.addElement(7);

        MagicalContainer::SideCrossIterator scit(container);
        CHECK(*scit == 2);
        ++scit;
        CHECK(*scit == 7);
        ++scit;
        CHECK(*scit == 3);
        ++scit;
        CHECK(*scit == 6);
        ++scit;
        CHECK(*scit == 4);
        ++scit;
        CHECK(*scit == 5);
        ++scit;
        CHECK(scit == scit.end());
    }
}

TEST_CASE("Iterating through the same container using different Iterators")
{
    MagicalContainer container;
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    container.addElement(6);
    container.addElement(7);
    container.addElement(8);
    container.addElement(9);
    container.addElement(10);
    container.addElement(11);
    container.addElement(12);
    container.addElement(13);

    SUBCASE("Iterating with the AscendingIterator")
    {
        MagicalContainer::AscendingIterator ait(container);
        CHECK(*ait == 2);
        ++ait;
        CHECK(*ait == 3);
        ++ait;
        CHECK(*ait == 4);
        ++ait;
        CHECK(*ait == 5);
        ++ait;
        CHECK(*ait == 6);
        ++ait;
        CHECK(*ait == 7);
        ++ait;
        CHECK(*ait == 8);
        ++ait;
        CHECK(*ait == 9);
        ++ait;
        CHECK(*ait == 10);
        ++ait;
        CHECK(*ait == 11);
        ++ait;
        CHECK(*ait == 12);
        ++ait;
        CHECK(*ait == 13);
        ++ait;

        CHECK(ait == ait.end());
    }
    SUBCASE("Iterating with the PrimeIterator")
    {
        MagicalContainer::PrimeIterator pit(container);
        CHECK(*pit == 2);
        ++pit;
        CHECK(*pit == 3);
        ++pit;
        CHECK(*pit == 5);
        ++pit;
        CHECK(*pit == 7);
        ++pit;
        CHECK(*pit == 11);
        ++pit;
        CHECK(*pit == 13);
        ++pit;

        CHECK(pit == pit.end());
    }

    SUBCASE("Iterating with the SideCrossIterator")
    {
        MagicalContainer::SideCrossIterator scit(container);
        CHECK(*scit == 2);
        ++scit;
        CHECK(*scit == 13);
        ++scit;
        CHECK(*scit == 3);
        ++scit;
        CHECK(*scit == 12);
        ++scit;
        CHECK(*scit == 4);
        ++scit;
        CHECK(*scit == 11);
        ++scit;
        CHECK(*scit == 5);
        ++scit;
        CHECK(*scit == 10);
        ++scit;
        CHECK(*scit == 6);
        ++scit;
        CHECK(*scit == 9);
        ++scit;
        CHECK(*scit == 7);
        ++scit;
        CHECK(*scit == 8);
        ++scit;

        CHECK(scit == scit.end());
    }

    SUBCASE("Iterating over an empty container/container with no primes")
    {
        MagicalContainer emptyContainer;
        MagicalContainer::AscendingIterator ait(emptyContainer);
        MagicalContainer::SideCrossIterator scit(emptyContainer);
        MagicalContainer::SideCrossIterator pit(emptyContainer);

        CHECK(ait == ait.end());
        CHECK(scit == scit.end());
        CHECK(pit == pit.end());

        MagicalContainer noPrimesContainer;

        noPrimesContainer.addElement(1);
        noPrimesContainer.addElement(4);
        noPrimesContainer.addElement(6);

        CHECK(*ait == 1);
        CHECK(*scit == 1);

        CHECK(pit == pit.end());
        // trying to de-reference end
        CHECK_THROWS_AS(*pit, std::runtime_error);
    }
}

TEST_CASE("Comparing between Iterators")
{
    SUBCASE("AscendingIterator")
    {

        MagicalContainer container;
        for (int i = 1; i <= 10; ++i)
        {
            container.addElement(i);
        }

        MagicalContainer::AscendingIterator ait1(container);
        MagicalContainer::AscendingIterator ait2(container);

        CHECK(ait1 == ait2);
        CHECK(*ait1 == *ait2);
        CHECK(!(ait1 != ait2));
        CHECK(!(ait1 < ait2));
        CHECK(!(ait1 > ait2));

        ++ait2;
        // ait2 is now one step ahead:
        CHECK(ait1 != ait2);
        CHECK(!(ait1 == ait2));
        CHECK(ait1 < ait2);
        CHECK(!(ait1 > ait2));

        ++ait1;
        // ait1 and ait2 are now in the same spot:
        CHECK(*ait1 == *ait2);
        CHECK(ait1 == ait2);
        CHECK(!(ait1 != ait2));
        CHECK(!(ait1 < ait2));
        CHECK(!(ait1 > ait2));

        ++ait1;
        // ait1 is now one step ahead:
        CHECK(ait1 != ait2);
        CHECK(!(ait1 == ait2));
        CHECK(!(ait1 < ait2));
        CHECK(ait1 > ait2);
    }

    SUBCASE("SideCrossIterator")
    {
        MagicalContainer container;
        for (int i = 1; i <= 10; ++i)
        {
            container.addElement(i);
        }

        MagicalContainer::SideCrossIterator sct1(container);
        MagicalContainer::SideCrossIterator sct2(container);

        CHECK(sct1 == sct2);
        CHECK(*sct1 == *sct2);
        CHECK(!(sct1 != sct2));
        CHECK(!(sct1 < sct2));
        CHECK(!(sct1 > sct2));

        ++sct2;
        // sct2 is now one step ahead:
        CHECK(sct1 != sct2);
        CHECK(!(sct1 == sct2));
        CHECK(sct1 < sct2);
        CHECK(!(sct1 > sct2));

        ++sct1;
        // sct1 and sct2 are now in the same spot:
        CHECK(*sct1 == *sct2);
        CHECK(sct1 == sct2);
        CHECK(!(sct1 != sct2));
        CHECK(!(sct1 < sct2));
        CHECK(!(sct1 > sct2));

        ++sct1;
        // sct1 is now one step ahead:
        CHECK(sct1 != sct2);
        CHECK(!(sct1 == sct2));
        CHECK(!(sct1 < sct2));
        CHECK(sct1 > sct2);
    }

    SUBCASE("PrimeIterator")
    {
        MagicalContainer container;
        for (int i = 1; i <= 10; ++i)
        {
            container.addElement(i);
        }

        MagicalContainer::PrimeIterator pit1(container);
        MagicalContainer::PrimeIterator pit2(container);

        CHECK(pit1 == pit2);
        CHECK(*pit1 == *pit2);
        CHECK(!(pit1 != pit2));
        CHECK(!(pit1 < pit2));
        CHECK(!(pit1 > pit2));

        ++pit2;
        // pit2 is now one step ahead:
        CHECK(pit1 != pit2);
        CHECK(!(pit1 == pit2));
        CHECK(pit1 < pit2);
        CHECK(!(pit1 > pit2));

        ++pit1;
        // pit1 and pit2 are now in the same spot:
        CHECK(*pit1 == *pit2);
        CHECK(pit1 == pit2);
        CHECK(!(pit1 != pit2));
        CHECK(!(pit1 < pit2));
        CHECK(!(pit1 > pit2));

        ++pit1;
        // pit1 is now one step ahead:
        CHECK(pit1 != pit2);
        CHECK(!(pit1 == pit2));
        CHECK(!(pit1 < pit2));
        CHECK(pit1 > pit2);
    }
}

TEST_CASE("Using operators on iterators of different type or different containers should throw an exception")
{
    MagicalContainer container1;
    container1.addElement(1);
    container1.addElement(2);

    MagicalContainer container2;
    container2.addElement(3);
    container2.addElement(4);

    SUBCASE("AscendingIterator")
    {
        MagicalContainer::AscendingIterator it1(container1);
        MagicalContainer::AscendingIterator it2(container2);

        CHECK_THROWS_AS(bool res = (it1 > it2), std::runtime_error);
        CHECK_THROWS_AS(bool res = (it1 < it2), std::runtime_error);
        CHECK_THROWS_AS(bool res = (it1 != it2), std::runtime_error);
        CHECK_THROWS_AS(bool res = (it1 == it2), std::runtime_error);
        CHECK_THROWS_AS((it1 = it2), std::runtime_error);
    }

    SUBCASE("SideCrossIterator")
    {
        MagicalContainer::SideCrossIterator it1(container1);
        MagicalContainer::SideCrossIterator it2(container2);

        CHECK_THROWS_AS(bool res = (it1 > it2), std::runtime_error);
        CHECK_THROWS_AS(bool res = (it1 < it2), std::runtime_error);
        CHECK_THROWS_AS(bool res = (it1 != it2), std::runtime_error);
        CHECK_THROWS_AS(bool res = (it1 == it2), std::runtime_error);
        CHECK_THROWS_AS((it1 = it2), std::runtime_error);
    }

    SUBCASE("PrimeIterator")
    {
        MagicalContainer::PrimeIterator it1(container1);
        MagicalContainer::PrimeIterator it2(container2);

        CHECK_THROWS_AS(bool res = (it1 > it2), std::runtime_error);
        CHECK_THROWS_AS(bool res = (it1 < it2), std::runtime_error);
        CHECK_THROWS_AS(bool res = (it1 != it2), std::runtime_error);
        CHECK_THROWS_AS(bool res = (it1 == it2), std::runtime_error);
        CHECK_THROWS_AS((it1 = it2), std::runtime_error);
    }

    SUBCASE("different types")
    {
        MagicalContainer::AscendingIterator ait(container1);
        MagicalContainer::SideCrossIterator scit(container1);
        MagicalContainer::PrimeIterator pit(container1);

        // iter > iter:
        CHECK_THROWS_AS(bool res = (ait > scit), std::runtime_error);
        CHECK_THROWS_AS(bool res = (ait > pit), std::runtime_error);

        CHECK_THROWS_AS(bool res = (scit > ait), std::runtime_error);
        CHECK_THROWS_AS(bool res = (scit > pit), std::runtime_error);

        CHECK_THROWS_AS(bool res = (pit > ait), std::runtime_error);
        CHECK_THROWS_AS(bool res = (pit > scit), std::runtime_error);

        // iter < iter:
        CHECK_THROWS_AS(bool res = (ait < scit), std::runtime_error);
        CHECK_THROWS_AS(bool res = (ait < pit), std::runtime_error);

        CHECK_THROWS_AS(bool res = (scit < ait), std::runtime_error);
        CHECK_THROWS_AS(bool res = (scit < pit), std::runtime_error);

        CHECK_THROWS_AS(bool res = (pit < ait), std::runtime_error);
        CHECK_THROWS_AS(bool res = (pit < scit), std::runtime_error);

        // iter != iter:
        CHECK_THROWS_AS(bool res = (ait != scit), std::runtime_error);
        CHECK_THROWS_AS(bool res = (ait != pit), std::runtime_error);

        CHECK_THROWS_AS(bool res = (scit != ait), std::runtime_error);
        CHECK_THROWS_AS(bool res = (scit != pit), std::runtime_error);

        CHECK_THROWS_AS(bool res = (pit != ait), std::runtime_error);
        CHECK_THROWS_AS(bool res = (pit != scit), std::runtime_error);

        // iter == iter:
        CHECK_THROWS_AS(bool res = (ait == scit), std::runtime_error);
        CHECK_THROWS_AS(bool res = (ait == pit), std::runtime_error);

        CHECK_THROWS_AS(bool res = (scit == ait), std::runtime_error);
        CHECK_THROWS_AS(bool res = (scit == pit), std::runtime_error);

        CHECK_THROWS_AS(bool res = (pit == ait), std::runtime_error);
        CHECK_THROWS_AS(bool res = (pit == scit), std::runtime_error);

    }
}
