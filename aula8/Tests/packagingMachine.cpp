#include "packagingMachine.h"
#include <sstream>
#include <list>

PackagingMachine::PackagingMachine(int boxCap): boxCapacity(boxCap)
{}

unsigned PackagingMachine::numberOfBoxes() {
	return boxes.size();
}

unsigned PackagingMachine::addBox(Box& b1) {
	boxes.push(b1);
	return boxes.size();
}

HeapObj PackagingMachine::getObjects() const {
	return this->objects;
}

HeapBox PackagingMachine::getBoxes() const {
	return this->boxes;
}

// ---------------------------------------------

// TODO
unsigned PackagingMachine::loadObjects(vector<Object> &objs) {
    int counter = 0;

    for (auto itr = objs.begin(); itr != objs.end(); itr++) {
        if (itr->getWeight() <= boxCapacity) {
            objects.push(*itr);
            itr = objs.erase(itr);
            itr--;
            counter++;
        }
    }
	return counter;
}


// TODO
Box PackagingMachine::searchBox(Object& obj) {
    list<Box> notGoodBoxes;
    Box aBox;

    return Box(boxCapacity);
}


// TODO
unsigned PackagingMachine::packObjects() {
    Box boxToUse;
    vector<Box> boxesUsed;



	return boxesUsed.size();
}

// TODO
stack<Object> PackagingMachine::boxWithMoreObjects() const {
    stack<Object> res;

	return res;
}



