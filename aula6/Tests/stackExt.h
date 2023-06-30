# include <iostream>
# include <stack>
using namespace std;

template <class T>
class StackExt {
	stack<T> values;
	stack<T> minimums;
public:
	StackExt() {};
	bool empty() const; 
	T& top();
	void pop();
	void push(const T& val);
	T& findMin();
};

//TODO
template <class T>
bool StackExt<T>::empty() const {
    if (values.empty())
	    return true;
    return false;
}

//TODO
template <class T> 
T& StackExt<T>::top() {
	return values.top();
}

//TODO
template <class T> 
void StackExt<T>::pop() {
    if (!values.empty()) {
        if (!minimums.empty() && values.top() == minimums.top()) {
            minimums.pop();
        }
        values.pop();
    }
}

//TODO
template <class T> 
void StackExt<T>::push(const T& val) {
    values.push(val);
    if (minimums.empty() || minimums.top() >= val)
        minimums.push(val);
}

//TODO
template <class T> 
T& StackExt<T>::findMin() {
    return minimums.top();
}

