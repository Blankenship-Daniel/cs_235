#ifndef QS_H_
#define QS_H_

#include <sstream>
#include "QSInterface.h"

class QS : public QSInterface
{
    public:
        QS();
        ~QS();

        void sortAll();
        int medianOfThree(int left, int right);
        int partition(int left, int right, int pivotIndex);
        string getArray();
        int getSize();
        void addToArray(int value);
        bool createArray(int size);
        void clear();

    private:
        int *arr;
        int numItems;
        int size;

        void swap(int a, int b);
        void quickSort(int left, int right);
};

#endif

