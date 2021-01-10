
#ifndef CHAIN_H
#define CHAIN_H
#include <Chain_Of_Responsibility\Request.h>

class Request;

class Chain {

protected:
	Chain *chain;
	virtual void request(Request *request);

public:
	Chain(Chain *chain = nullptr);
	~Chain();

};

#endif // CHAIN_H