#pragma once
#include <iostream>
using namespace std;

class ObjetoBase
{
public:
	virtual ~ObjetoBase();
	virtual string toString() const = 0;
};

ostream& operator << (ostream&, const ObjetoBase&);

