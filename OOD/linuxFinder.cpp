#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct File {
public:
	string filename;
    long createtime;
    bool isDir;
    vector<string> subdir;
    long inode;
    int filesize;
    File(string name,long create,bool dir,long node,int filesize) {
    	this->filename = name;
    	this->createtime = create;
    	this->isDir = dir;
    	this->inode = node;
    	this->filesize = filesize;
    }
};
class IFilter {
public:
	virtual bool filter(File* input) = 0;
};

class Larger_than:public IFilter {
private:
	int size;

public:
	Larger_than(int compare) {
        this->size =  compare;
	}
	bool filter(File* input) {
       if(input->filesize > size) {
       	   return true;
       }
       return false;
	}
};

class Less_than:public IFilter {
private:
	int size;
public:
	Less_than(int compare) {
       this->size = compare;
	}
	bool filter(File* input) {
       if(input->filesize < size) {
       	  return true;
       }
       return false;
	}
};

class FileFilter {
private:
	vector<IFilter*> filterlist;
public:
	void appendFilter(IFilter* input) {
		filterlist.push_back(input);
	}
    
    /*
     * use filterlist to check whether pass all the filters
     * param:File object pointer
     * return: true for pass false for fail
    */
	bool pass(File* fp) {
		for(int i=0;i<filterlist.size();i++) {
			bool ret = filterlist[i]->filter(fp);
			if(ret == false) {
				return false;
			}
		}
		return true;
	}

};

int main() {
   IFilter* f1 = new Larger_than(5);
   IFilter* f2 = new Less_than(10);
   FileFilter* filter = new FileFilter();
   filter->appendFilter(f1);
   filter->appendFilter(f2);
   File* file = new File("dev",1234,false,5434,30);
   if( filter->pass(file) ) {
   	   cout<<"satisfied"<<endl;
   }



}