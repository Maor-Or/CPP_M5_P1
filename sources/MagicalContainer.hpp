#pragma once

namespace ariel
{

    class MagicalContainer
    {
    private:
 // private classe to implement:
        class Iterator
        {
        private:
        public:
            // Ctors & Dtors:
            Iterator(MagicalContainer container);
            ~Iterator();

            // functions to implement:
            Iterator begin();
            Iterator end();
            Iterator &operator++();
            int operator*();
            bool operator!=(const Iterator &other) const;
            bool operator==(const Iterator &other) const;
            bool operator>(const Iterator &other) const;
            bool operator<(const Iterator &other) const;
        };

    public:
        // Ctors & Dtors:
        MagicalContainer(/* args */);
        ~MagicalContainer();

        // functions to implement:
        void addElement(int number);
        int size();
        void removeElement(int number);

       
        // classes to implement:

        class AscendingIterator : public Iterator
        {
        private:
        public:
            // Ctors & Dtors:
            AscendingIterator(MagicalContainer container);
            ~AscendingIterator();
        };

        class SideCrossIterator : public Iterator
        {
        private:
        public:
            // Ctors & Dtors:
            SideCrossIterator(MagicalContainer container);
            ~SideCrossIterator();
        };

        class PrimeIterator : public Iterator
        {
        private:
        public:
            // Ctors & Dtors:
            PrimeIterator(MagicalContainer container);
            ~PrimeIterator();
        };
    };

};
