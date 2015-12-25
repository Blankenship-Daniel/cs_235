#include "Station.h"

Station::Station()
{
    curr_car = -1;
}

// Part 1
bool Station::addToStation(int car)
{
    if ( station_stack.car_exists(car) || 
         station_queue.car_exists(car) ||
         station_deque.car_exists(car) || 
         car < 0                       || 
         curr_car >= 0 )
    {
        return false;
    }

    curr_car = car;

    return true;
}

int Station::showCurrentCar()
{
    return curr_car;
}

bool Station::removeFromStation()
{
    if (curr_car >= 0)
    {
        curr_car = -1;
        return true;
    }
    return false;
}

// Part 2
bool Station::addToStack()
{
    bool full = station_stack.isFull();

    if (curr_car >= 0 && !full)
    {
        station_stack.push(curr_car);
        curr_car = -1;
        return true;
    }
    return false;
}

bool Station::removeFromStack()
{
    bool empty = station_stack.isEmpty();
    
    if (!empty && curr_car == -1)
    {
        curr_car = station_stack.get_top();
        station_stack.pop();
        return true;
    }
    return false;
}

int Station::showTopOfStack()
{
    bool empty = station_stack.isEmpty();
    if (!empty)
    {
        return station_stack.get_top();
    }
    return -1;
}

int Station::showSizeOfStack()
{
    return station_stack.size();
}

// Part 3
bool Station::addToQueue()
{
    bool full = station_queue.isFull();

    if (curr_car >= 0 && !full)
    {
        station_queue.push(curr_car);
        curr_car = -1;
        return true;
    }
    return false;
}

bool Station::removeFromQueue()
{
    bool empty = station_queue.isEmpty();

    if (!empty && curr_car == -1)
    {
        curr_car = station_queue.get_front();
        station_queue.pop();
        return true;
    }
    return false;
}

int Station::showTopOfQueue()
{
    bool empty = station_queue.isEmpty();

    if (!empty)
    {
        return station_queue.get_front();
    }
    return -1;
}

int Station::showSizeOfQueue()
{
    return station_queue.size();
}

// Part 4
bool Station::addToDequeLeft()
{
    bool full = station_deque.isFull();

    if (curr_car >= 0 && !full)
    {
        station_deque.push_left(curr_car);
        curr_car = -1;
        return true;
    }
    return false;
}

bool Station::addToDequeRight()
{
    bool full = station_deque.isFull();

    if (curr_car >= 0 && !full)
    {
        station_deque.push_right(curr_car);
        curr_car = -1;
        return true;
    }
    return false;
}

bool Station::removeFromDequeLeft()
{
    bool empty = station_deque.isEmpty();

    if (!empty && curr_car == -1)
    {
        curr_car = station_deque.get_left();
        station_deque.pop_left();
        return true;
    }
    return false;
}

bool Station::removeFromDequeRight()
{
    bool empty = station_deque.isEmpty();

    if (!empty && curr_car == -1)
    {
        curr_car = station_deque.get_right();
        station_deque.pop_right();
        return true;
    }
    return false;
}

int Station::showTopOfDequeLeft()
{
    bool empty = station_deque.isEmpty();

    if (!empty)
        return station_deque.get_left();

    return -1;
}

int Station::showTopOfDequeRight()
{
    bool empty = station_deque.isEmpty();

    if (!empty)
        return station_deque.get_right();

    return -1;
}

int Station::showSizeOfDeque()
{
    return station_deque.size();
}



