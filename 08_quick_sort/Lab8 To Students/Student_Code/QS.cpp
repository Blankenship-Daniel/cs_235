#include "QS.h"

QS::QS()
{
    numItems = 0;
    size = 0;
    arr = NULL;
}

QS::~QS()
{
    clear();
}

void QS::sortAll()
{
    quickSort(0, numItems - 1); 
}

void QS::quickSort(int left, int right)
{
    int pivotElement; 
    if (left < right)
    {
        pivotElement = partition(left, right, medianOfThree(left, right));
        quickSort(left, pivotElement - 1);
        quickSort(pivotElement + 1, right);
    }
}

void QS::swap(int a, int b)
{
    int tempA = arr[a];
    arr[a] = arr[b];
    arr[b] = tempA;
}

int QS::medianOfThree(int left, int right) 
{
    int middle = (left + right) / 2;
    
    if (numItems > 0 && left  >= 0 && left  < size
                     && right >= 0 && right < size && left < right) 
    {
        if (arr[middle] < arr[left])
            swap(left, middle);
        if (arr[right] < arr[middle])
            swap(middle, right);
        if (arr[middle] < arr[left])
            swap(left, middle);
        return middle;
    }
    return -1;
}

int QS::partition(int left, int right, int pivotIndex)
{
    if (pivotIndex >= 0 && pivotIndex <= right && numItems > 0 && left  >= 0 && left  < size
                                                               && right >= 0 && right < size && left < right)
    {
        swap(pivotIndex, left);
        int up   = left + 1;
        int down = right;
        do
        {
            while ((up != right) && !(arr[left] < arr[up]))
                ++up;
            while (arr[left] < arr[down])
                --down;
            if (up < down)
                swap(up, down);
        } while (up < down);
        swap(left, down);
        return down;
    }
    return -1;
}

string QS::getArray()
{
    stringstream ss;
    for (int i = 0; i < numItems; i++)
    {
        if (i == numItems - 1)
            ss << arr[i];
        else
            ss << arr[i] << ",";
    }
    return ss.str();
}

int QS::getSize()
{
    return size;
}

void QS::addToArray(int value)
{
    if (numItems < size)
    {
        arr[numItems] = value;
        numItems++;
    }
    else
    {
        cout << "Error: Array has reached max capacity\n";
    }
}

bool QS::createArray(int size)
{
    if (size > 0)
    {
        numItems = 0;
        this->size = size;
        
        arr = new int[this->size];
        
        return true;
    }
    return false;
}

void QS::clear()
{
    delete [] arr;
    size = numItems = 0;
}
