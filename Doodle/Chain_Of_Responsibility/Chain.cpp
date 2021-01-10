
#include <Chain_Of_Responsibility/Chain.h>


Chain::Chain(Chain *chain)
	:chain(chain) {


}

Chain::~Chain() {


}

void Chain::request(Request *request) {

	if (this->chain != nullptr) {
		this->chain->request(request);

	}
}