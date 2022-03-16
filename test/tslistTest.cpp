#include <rcds/tslist.h>

class Element : public rco::Intrusive_queue {
	public:
		Element(int i)
		: data(i){

		}
		int data;
};

int main(int argc, char** argv) {

	Element* head = nullptr;
	Element* tail = nullptr;
	Element* cur = head;
	for(int i = 0; i < 10; ++i) {
		cur = new Element(i);
		tail = cur;
		cur = (Element*)cur->next;
	}

	rco::TSList<Element> list(head, tail, 10);

	list.clear();
	return 0;
}
