/*** Name: Ahmed Ghoneim
 *   This is a Program that used a Double Ended Deque to convert between three different notation into arithmetic from the Deque class
***/



#include "NotationConverter.hpp"

std::string NotationConverter::postfixToInfix(std::string inStr)
{

unsigned int i;


for (i = 0; i < inStr.length(); i++)
{

if (inStr[i] == '[' || inStr[i] == ']' ||inStr[i] == '^' ||inStr[i] == '\\')
{
throw std::invalid_argument("invalid character");
}
}

Deque newDeque;


for (i = 0; i < inStr.length(); i++)
{


if ((inStr[i] >= 'A' && inStr[i] <= 'Z') || (inStr[i] >= 'a' && inStr[i] <= 'z'))
{

std::string s(1, inStr[i]); 
newDeque.insertFront(s); 
}


else if(inStr[i] == ' ')
{
continue;
}


else
{

std::string secondOperand = newDeque.front();
newDeque.removeFront();

std::string firstOperand = newDeque.front();
newDeque.removeFront();

newDeque.insertFront("(" + firstOperand + " " + inStr[i] + " " + secondOperand + ")");
}
}

return newDeque.front();
}


std::string NotationConverter::postfixToPrefix(std::string inStr)
{

unsigned int i;


for (i = 0; i < inStr.length(); i++)
{

if (inStr[i] == '[' || inStr[i] == ']' ||inStr[i] == '^' ||inStr[i] == '\\')
{
throw std::invalid_argument("invalid character");
}
}

NotationConverter postToInfix;
NotationConverter inToPrefix;
std::string tempString;

tempString = postToInfix.postfixToInfix(inStr); 
tempString = inToPrefix.infixToPrefix(tempString);

return tempString;
}


std::string NotationConverter::infixToPostfix(std::string inStr)
{

unsigned int i;



for (i = 0; i < inStr.length(); i++)
{

if (inStr[i] == '[' || inStr[i] == ']' ||inStr[i] == '^' ||inStr[i] == '\\')
{
throw std::invalid_argument("invalid character");
}
}

Deque newDeque;
std::string tempString;

newDeque.insertFront("bottomOfStack"); 

for (i = 0; i < inStr.length(); i++)
{

if(inStr[i] == ' ')
{
continue;
}


if ((inStr[i] >= 'A' && inStr[i] <= 'Z') || (inStr[i] >= 'a' && inStr[i] <= 'z'))
{

std::string s(1, inStr[i]); 
tempString = tempString + s + " ";
}
else if (inStr[i] == '(')
{

std::string s(1, inStr[i]); 
newDeque.insertFront(s);

}


else if (inStr[i] == ')')
{

while ((newDeque.front() != "("))
{

tempString = tempString + newDeque.front() + " ";
newDeque.removeFront();
}
if (newDeque.front() == "(")
{
newDeque.removeFront(); 
}
}


else if ((inStr[i] == '*') || (inStr[i] == '/'))
{

if ((newDeque.front() != "*" && newDeque.front() != "/") || newDeque.empty())
{

std::string s(1, inStr[i]);
newDeque.insertFront(s);
}
else
{
while ((newDeque.front() == "*" || newDeque.front() == "/") && newDeque.front() != "bottomOfStack")
{

tempString = tempString + newDeque.front() + " ";
newDeque.removeFront();
}

std::string s(1, inStr[i]);
newDeque.insertFront(s);
}
}


else if ((inStr[i] == '+') || (inStr[i] == '-'))
{

if ((newDeque.front() != "*" && newDeque.front() != "/" && newDeque.front() != "+" && newDeque.front() != "-") || newDeque.empty()) {

std::string s(1, inStr[i]); 
newDeque.insertFront(s);
}
else
{
while ((newDeque.front() == "*" || newDeque.front() == "/" || newDeque.front() == "+" || newDeque.front() == "-") && newDeque.front() != "bottomOfStack") {

tempString = tempString + newDeque.front() + " ";
newDeque.removeFront();
}

std::string s(1, inStr[i]);
newDeque.insertFront(s);
}
}
}



while(newDeque.front() != "bottomOfStack")
{

tempString = tempString + newDeque.front() + " ";
newDeque.removeFront();
}
return tempString;
}


std::string NotationConverter::infixToPrefix(std::string inStr)
{

unsigned int i;


for (i = 0; i < inStr.length(); i++)
{

if (inStr[i] == '[' || inStr[i] == ']' ||inStr[i] == '^' ||inStr[i] == '\\')
{
throw std::invalid_argument("invalid character");
}
}

Deque newDeque;
NotationConverter infixToPost;
std::string tempString;

std::reverse(inStr.begin(), inStr.end());


for (i = 0; i < inStr.length(); i++)
{

if (inStr[i] == '(')
{
inStr[i] = ')';
}
else if (inStr[i] == ')')
{
inStr[i] = '(';
}
}

tempString = infixToPost.infixToPostfix(inStr);

std::reverse(tempString.begin(), tempString.end()); 

return tempString;
}


std::string NotationConverter::prefixToInfix(std::string inStr)
{

unsigned int i;


for (i = 0; i < inStr.length(); i++)
{

if (inStr[i] == '[' || inStr[i] == ']' ||inStr[i] == '^' ||inStr[i] == '\\')
{
throw std::invalid_argument("invalid character");
}
}

NotationConverter preToPost;
NotationConverter postToInfix;
std::string tempString;

tempString = preToPost.prefixToPostfix(inStr);

tempString = postToInfix.postfixToInfix(tempString); 

return tempString;
}


std::string NotationConverter::prefixToPostfix(std::string inStr)
{

unsigned int i;


for (i = 0; i < inStr.length(); i++)
{

if (inStr[i] == '[' || inStr[i] == ']' ||inStr[i] == '^' ||inStr[i] == '\\')
{
throw std::invalid_argument("invalid character");
}
}

Deque newDeque;
std::string tempString;

std::reverse(inStr.begin(), inStr.end());

for (i = 0; i < inStr.length(); i++)
{

if (inStr[i] == ' ')
{
continue;
}


if ((inStr[i] >= 'A' && inStr[i] <= 'Z') || (inStr[i] >= 'a' && inStr[i] <= 'z'))
{

std::string s(1, inStr[i]); 
newDeque.insertFront(s);
}


else
{
std::string firstOperand = newDeque.front();
newDeque.removeFront();

std::string secondOperand = newDeque.front();
newDeque.removeFront();

newDeque.insertFront(firstOperand + " " + secondOperand + " " + inStr[i]);
}
}

return newDeque.front();
}
