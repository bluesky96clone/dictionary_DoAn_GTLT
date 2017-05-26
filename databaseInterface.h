#ifndef DATABASEINTERFACE_H
#define DATABASEINTERFACE_H
#include <iostream>
#include <fstream>
class DataBaseInterface{
	public:
		DataBaseInterface(const char *path){
			f.open(path, ios::in || ios::out);
		};
		virtual ~DataBaseInterface();
			
		virtual void Load(const char *path) = 0;
		virtual void Save(const char *path) = 0;
	protected:
		fstream f;
		char *path;
};
#endif

