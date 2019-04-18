#include"func.h"
#include <iostream>

using namespace std;

template class Point<int, int>;
template class Point<char*, char*>;

template<class T1,class T2>
void Point<T1, T2>::display() const{
	cout << "x=" << m_x << ",y=" << m_y << endl;
}

