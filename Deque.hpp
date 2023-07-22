#ifndef DEQUE_H
#define DEQUE_H

#include <stdexcept>
#include <string>

class Deque
{
public:


Deque();

~Deque();


int size() const;


bool empty() const;


const std::string front();


const std::string back();


void insertFront(const std::string x);


void insertBack(const std::string x);


void removeFront();


void removeBack();

private:


struct deqnode
{
std::string line; 

deqnode* prev;
deqnode* next;
};

int n = 0;
deqnode* head;
deqnode* tail;
};

#endif
