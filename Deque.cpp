#include "Deque.hpp"

Deque::Deque()
{


head = new deqnode;
tail = new deqnode;


head->next = tail;
tail->prev = head;
}

Deque::~Deque()
{

deqnode* curr = head; 
deqnode* temp; 


while (curr != tail)
{

temp = curr->next;
delete curr;
curr = temp;
}

delete tail;
}

int Deque::size() const
{

return n;
}

bool Deque::empty() const
{

return n == 0;
}

const std::string Deque::front()
{

if (empty()) throw std::invalid_argument("empty");

deqnode* temp = head->next;
return temp->line;
}

const std::string Deque::back()
{

if (empty()) throw std::invalid_argument("empty");

deqnode* temp = tail->prev;
return temp->line;
}

void Deque::insertFront(const std::string x)
{

deqnode* newNode = new deqnode;
deqnode* temp;

newNode->line = x;

temp = head->next; 
head->next = newNode; 
newNode->prev = head; 

if (empty())
{

newNode->next = tail; 
tail->prev = newNode; 

}
else
{
newNode->next = temp; 
}

n++; 
}

void Deque::insertBack(const std::string x)
{

deqnode* newNode = new deqnode;
deqnode* temp;

newNode->line = x;

temp = tail->prev; 
newNode->next = tail; 
tail->prev = newNode; 

if (empty())
{

newNode->prev = head; 
head->next = newNode; 

}
else
{
newNode->prev = temp; 
}

n++; 
}

void Deque::removeFront()
{

if (empty()) throw std::invalid_argument("empty");

deqnode* removenode; 
deqnode* next_node; 

removenode = head->next; 
next_node = head->next->next; 


head->next = next_node;
next_node->prev = head;

n--;

delete removenode;
}

void Deque::removeBack()
{

if (empty()) throw std::invalid_argument("empty");

deqnode* removenode; 
deqnode* prev_node; 

removenode = tail->prev; 
prev_node = tail->next->next; 


tail->prev = prev_node;
prev_node->next = tail;

n--;

delete removenode;
}