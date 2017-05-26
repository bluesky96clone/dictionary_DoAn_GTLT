#include <iostream>
#include <windows.h>
#include "tree.h"
#include "node.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	AVLTree* dict = new AVLTree();
	cout << "Insert 'art'" << endl;
	dict->insert("art", "nghe thuat");
	cout << "Insert 'love'" << endl;
	dict->insert("love", "tinh yeu");
	cout << "Insert 'cute'" << endl;
	dict->insert("cute", "de thuong");
	cout << "Insert 'cool'" << endl;
	dict->insert("cool", "ngau");
	cout << "Insert 'fun'" << endl;
	dict->insert("fun", "vui");
	cout << "Insert 'happy'" << endl;
	dict->insert("happy", "hanh phuc");
	cout << "Insert 'world'" << endl;
	dict->insert("world", "the gioi");
	cout << "Insert 'youth'" << endl;
	dict->insert("youth", "tuoi tre");
	dict->del("youth");
	dict->show();
	//dict->search("love");
	system("pause");
	return 0;
}
