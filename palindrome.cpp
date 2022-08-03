#include <iostream>
#include <cstring>
using namespace std;

class Stack
{
public:
    Stack(int size = 50);         // constructor
    ~Stack() { delete[] values; } // destructor
    bool IsEmpty() { return top == -1; }
    bool IsFull() { return top == maxTop; }
    double Top(); // examine, without popping
    void Push(const char x);
    double Pop();
    void DisplayStack();

private:
    int maxTop;     // max stack size = size - 1
    int top;        // current top of stack
    char *values; // element array
};
Stack::Stack(int size /*= 10*/)
{
    values = new char[size];
    top = -1;
    maxTop = size - 1;
}
void Stack::Push(const char x)
{
    if (IsFull()) // if stack is full, print error
        cout << "Error: the stack is full." << endl;
    else
        values[++top] = x;
}
double Stack::Pop()
{
    if (IsEmpty())
    { // if stack is empty, print error
        cout << "Error: the stack is empty." << endl;
        return -1;
    }
    else
    {
        return values[top--];
    }
}
double Stack::Top()
{
    if (IsEmpty())
    {
        cout << "Error: the stack is empty." << endl;
        return -1;
    }
    else
        return values[top];
}

class Queue
{
public:
	Queue(int size = 50);		  // constructor
	~Queue() { delete[] values; } // destructor
	bool IsEmpty(void);
	bool IsFull(void);
	bool Enqueue(char x);
	char Dequeue();
	void DisplayQueue(void);

private:
	int front;		// front index
	int rear;		// rear index
	int counter;	// number of elements
	int maxSize;	// size of array queue
	char *values; // element array
};
Queue::Queue(int size /* = 10 */)
{
	values = new char[size];
	maxSize = size;
	front = 0;
	rear = -1;
	counter = 0;
}
bool Queue::IsEmpty()
{
	if (counter)
		return false;
	else
		return true;
}
bool Queue::IsFull()
{
	if (counter < maxSize)
		return false;
	else
		return true;
}
bool Queue::Enqueue(char x)
{
	if (IsFull())
	{
		cout << "Error: the queue is full." << endl;
		return false;
	}
	else
	{
		// calculate the new rear position (circular)
		rear = (rear + 1) % maxSize;
		// insert new item
		values[rear] = x;
		// update counter
		counter++;
		return true;
	}
}
char Queue::Dequeue()
{
	if (IsEmpty())
	{
		cout << "Error: the queue is empty." << endl;
		return false;
	}
	else
	{
		// retrieve the front item
		char x = values[front];
		// move front
		front = (front + 1) % maxSize;
		// update counter
		counter--;
		return x;
	}
}

int main(void)
{
    string str;
	cout << "Please enter the word:" << endl;
	cin >> str;

	//Create the stack and queue object
    Stack stack = Stack();
    Queue que = Queue();

    //Push and enqueue all character
    int leng = str.size();
    for (int i = 0; i < leng ; i++) 
    {
        stack.Push(str[i]);
        que.Enqueue(str[i]);

    }

    for (int i = 0; i < leng ; i++) 
    {
        char stackch = stack.Pop();
        char qch = que.Dequeue();
        
        
            if (stackch != qch)
        {
            cout << "No, it's not a palindrome";
            return (0);
        }
    }
        cout << "Yes, it's a palindrome";
}
