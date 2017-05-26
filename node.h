#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string.h>
using namespace std;

class Node {
	private:
		string word;
		string meaning;
		Node* left;
		Node* right;
		int height;
	public:
		friend class AVLTree;
		Node();
		Node(string word, string meaning);
		~Node();
		int getHeight() const;
		
//		string getWord() const;
//		void setWord(string word);
//		
//		string getMeaning() const;
//		void setMeaning(string meaning);
//		
//		int getHeight() const;
//		void setHeight(int height);
//		
//		void setLeft(Node* left);
//		void setRight(Node* right)
};

#endif
