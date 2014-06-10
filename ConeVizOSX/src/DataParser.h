//
//  TestClass.h
//  ConeVizOSX
//
//  Created by Levko Ivanchuk on 2014-06-03.
//
//

#ifndef __ConeVizOSX__DataParser__
#define __ConeVizOSX__DataParser__

#include <iostream>

#include <iostream>
#include <string>
#include "ofMain.h"

using namespace std;

class DataParser{
    
private:
    //some standart stuff for a singleton
    static bool instanceFlag;
    static DataParser *single;
    DataParser()
    {
        //private constructor
    }
    
    static string currentFileName;
    static ofFile file;
    static ofBuffer fileBuffer;
    
public:
    //some standart stuff for a singleton
    static DataParser* getInstance();
    ~DataParser()
    {
        instanceFlag = false;
    }
    
    bool analizeFile();                         //displays information about the current file.
    bool setCurrentFile(string newFile);        //set the current file, but do not load it yet.
    bool setAndLoadCurrentFile(string newFile); //
    bool loadFile();
    bool unloadFile();
    
    
};

#endif /* defined(__ConeVizOSX__DataParser__) */