#include "node.h"

Node::Node() {
	this->left 	 = NULL;
	this->right  = NULL;
	this->height = 0;
}
Node::Node(string word, string meaning) : word(word), meaning(meaning) {
	this->left = NULL;
	this->right = NULL;
	this->height = 1;
}

Node::~Node() {
}
int Node::getHeight() const {
	if (this == NULL) {
		return 0;
	}
	return this->height;
} 
