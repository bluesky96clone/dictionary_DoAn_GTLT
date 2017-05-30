#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <string>
#include "node.h"

class AVLTree {
	private:
		// Data members
		Node* root;
		int size;
		
		//Methods
		Node* insertWord(Node* node, string word, string meaning);
		Node* searchWord(Node* node, string word) const;
		Node* deleteWord(Node* node, string word);
		Node* minValueNode(Node* node);
		void preOrderShow(Node* r) const;
		void preOrderSave(Node* r, fstream& f);
		
		//cac phuong thuc can bang cay
		Node* rightRotate(Node* y);
		Node* leftRotate(Node* x);
		int getBalanceFactor(Node* node);
		
		//cac phuong thuc kiem tra tu
		bool isLetter(char c);
		bool isExist(string word);
		
		void saveWord(Node* node, fstream& f);
	public:
		friend class Node;
		
		//constructor and destructor
		AVLTree();
		~AVLTree();
		
		//cac phuong thuc thao tac voi tu dien
		int getSize(){
			return size;
		}
		void insert(string word, string meaning);
		void search(string word) const;
		void del(string word);
		void show() const;
		void showWord(Node* node) const;
		
		//cac phuong thuc thao tac voi file
		void saveDictData(char* path);
		void loadDictData(char* path);
		void checkDocumentByDict(char* path);
		void viewDocument(char* path);	
};

#endif
