#include "HeapInt.h"

HeapInt::HeapInt(const HeapInt& copy)
{
    heapValue = new int{ *copy.heapValue };
}

// rvalue for move
HeapInt::HeapInt(HeapInt&& other)
{
    heapValue = other.heapValue;
    other.heapValue = nullptr;
}

void HeapInt::operator=(const HeapInt& operand)
{
    if (this == &operand) {
        return;
    }

    delete heapValue;

    heapValue = new int{ *operand.heapValue };
}

void HeapInt::operator=(HeapInt&& operand)
{
    if (this == &operand) {
        return;
    }

    delete heapValue;

    heapValue = operand.heapValue;

    operand.heapValue = nullptr;
}