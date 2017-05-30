#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "tree.h"

using namespace std;

AVLTree::AVLTree() {
	this->root = NULL;
	this->size = 0;
}
AVLTree::~AVLTree() {
//	if (root != NULL) {
//		Node* temp1 = root->left;
//		Node* temp2 = root->right;
//		while(root != NULL) {
//			delete root;
//			delete
//		}
//	}
	size--;
}

Node* AVLTree::rightRotate(Node* y) {
	Node* x  = y->left;
	Node* T1 = x->left;
	Node* T2 = x->right;
	Node* T3 = y->right;
	
	// Perform rotation
	x->right = y;
	y->left  = T2;
	
	// Update heights
	y->height = max(T2->getHeight(), T3->getHeight()) + 1;
	x->height = max(T1->getHeight(), y->getHeight()) + 1;
	
	// Return new root
	return x;
}

Node* AVLTree::leftRotate(Node* x) {
	Node* y  = x->right;
	Node* T1 = x->left;
	Node* T2 = y->left;
	Node* T3 = y->right;
	
	// Perform rotation
	y->left  = x;
	x->right = T2;
	
	// Update heights
	x->height = max(T1->getHeight(), T2->getHeight()) + 1;
	y->height = max(x->getHeight(), T3->getHeight()) + 1;
	
	// Return new root
	return y;
}

int AVLTree::getBalanceFactor(Node* node) {
	if (node == NULL) return 0;
	return node->left->getHeight() - node->right->getHeight();
}

void AVLTree::insert(string word, string meaning) {
	//transform(word.begin(), word.end(), word.begin(), ::tolower);
	this->root = insertWord(this->root, word, meaning);
	this->size++;
	//cout << "Word inserted!" << endl;
}

Node* AVLTree::insertWord(Node* node, string word, string meaning) {
	// 1. Perform the normal BST insertion
	if (node == NULL) {
		Node* newNode = new Node(word, meaning);
		return newNode;
	}
	
	if (word < node->word) {
		node->left = insertWord(node->left, word, meaning);
	}
	else if (word > node->word) {
		node->right = insertWord(node->right, word, meaning);
	}
	else return node;
	
	// 2. Update height
	//cout << "Step 2" << endl;
	
	node->height = 1 + max(node->left->getHeight(), node->right->getHeight());
	//cout << node->height << endl;
	// 3. Check unbalanced or not
	//cout << "Step 3" << endl;
	int balanceFactor = getBalanceFactor(node);
	
	// If unbalanced then make it balance
	// There are 4 cases
	
	//Left left case
	if (balanceFactor > 1 && word < node->left->word) {
		//cout << "Left left case" << endl;
		return rightRotate(node);
	}
	// Right right case
	if (balanceFactor < -1 && word > node->right->word) {
		//cout << "Right right case" << endl;
		return leftRotate(node);
	}
	//Left right case
	if (balanceFactor > 1 && word > node->left->word) {
		//cout << "Left right case" << endl;
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	//Right left case
	if (balanceFactor < - 1 && word < node->right->word) {
		//cout << "Right left case" << endl;
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	
	return node;
}

void AVLTree::show() const {
	preOrderShow(this->root);
}
void AVLTree::showWord(Node* node) const {
	cout << node->word << "-->" << node->meaning << endl;
}
void AVLTree::preOrderShow(Node* r) const {
	if (r != NULL) {
		preOrderShow(r->left);
		showWord(r);
		preOrderShow(r->right);
	}
}
void AVLTree::search(string word) const {
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	Node* result = searchWord(this->root, word);
	if (result == NULL)
		cout << "Not found!";
	else 
		cout << result->word << "-->" << result->meaning;
	cout << endl;
}
Node* AVLTree::searchWord(Node* node, string word) const {
	if (node == NULL) {
		return NULL;
	}
	if (word < node->word) {
		return searchWord(node->left, word);
	}
	if (word > node->word) {
		return searchWord(node->right, word);
	}
	return node;
}
Node* AVLTree::minValueNode(Node* node) {
	Node* current = node;
	// Loop down to find the leftmost leaf
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}
void AVLTree::del(string word) {
	//cout << "Del function" << endl;
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	if (searchWord(this->root, word)) {
		this->root = deleteWord(this->root, word);
		this->size--;
		cout << "Word deleted!" << endl;
	}
	else
		cout << "Can't find this word!";
}
Node* AVLTree::deleteWord(Node* node, string word) {
	//cout << "deleteWord function" << endl;
	// 1. Perform the normal BST delete
	if (node == NULL) {
		return node;
	}
	if (word < node->word) {
		node->left = deleteWord(node->left, word);
	}
	else if (word > node->word) {
		node->right = deleteWord(node->right, word);
	}
	else {
		// node with only one child or no child
        if((node->left == NULL) || (node->right == NULL)) {
            Node* temp;
			if (node->left != NULL)
				temp = node->left;
 			else 
 				temp = node->right;
            // No child case
            if (temp == NULL) {
                temp = node;
                node = NULL;
            }
            else // One child case
            	*node = *temp; 	// Copy the contents of
                            	// the non-empty child
            delete temp;
        }
        else {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            Node* temp = minValueNode(node->right);
 
            // Copy the inorder successor's data to this node
            node->word = temp->word;
            node->meaning = temp->meaning;
 
            // Delete the inorder successor
            node->right = deleteWord(node->right, temp->word);
        }
        return node;
    }
    // 2. Update height
	//cout << "Step 2" << endl;
	node->height = 1 + max(node->left->getHeight(), node->right->getHeight());
	//cout << node->height << endl;
	// 3. Check unbalanced or not
	//cout << "Step 3" << endl;
	int balanceFactor = getBalanceFactor(node);
	// If unbalanced then make it balance
	// There are 4 cases
	
	//Left left case
	if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0) {
		//cout << "Left left case" << endl;
		return rightRotate(node);
	}
	// Right right case
	if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0) {
		//cout << "Right right case" << endl;
		return leftRotate(node);
	}
	//Left right case
	if (balanceFactor > 1 && getBalanceFactor(node->left) < 0) {
		//cout << "Left right case" << endl;
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	//Right left case
	if (balanceFactor < - 1 && getBalanceFactor(node->right) > 0) {
		//cout << "Right left case" << endl;
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}
void AVLTree::saveWord(Node* node, fstream& f){	
	f << node->word << "\n" << node->meaning << endl;
}
void AVLTree::preOrderSave(Node* r, fstream& f){
	if (r != NULL) {
		preOrderSave(r->left, f);
		saveWord(r, f);
		preOrderSave(r->right, f);
	}
}
void AVLTree::saveDictData(char* path){
	fstream f;
	f.open(path, ios::out);
	f << this->size << endl;
	preOrderSave(root, f);
	f.close();
}
void AVLTree::loadDictData(char* path){
	//this->~AVLTree();
	
	string word, mean;
	fstream f;
	f.open(path, ios::in);
	
	int numOfWord = 0;
	f >> numOfWord;
	f.seekg(3);
	 
	while(!f.eof()){
		getline(f, word);
		getline(f, mean);
		insert(word, mean);
		if(--numOfWord  == 0)	break;
	}
	f.close();	
}
void AVLTree::checkDocumentByDict(char* path){
	fstream f;
	f.open(path, ios::in);
	string word;
	char c;
	while(!f.eof()){
		word.clear();
		while(isLetter(c)){
			word += c;
			c = f.get();			
		}
		if(!word.empty()){
			if(isExist(word)){
				cout << word << " ";
			}
		}
	}
}
void AVLTree::viewDocument(char* path){
	fstream f;
	f.open(path, ios::in);
	string doc;
	while(!f.eof()){
		getline(f, doc);
		cout << doc << endl;
	}
	f.close();	
}

bool AVLTree::isLetter(char c){
	return ((c>='a' && c<='z') || (c>='A' && c<='Z'));
}
bool AVLTree::isExist(string word){
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	Node* foo = searchWord(this->root, word);
	return (foo != NULL);
}
