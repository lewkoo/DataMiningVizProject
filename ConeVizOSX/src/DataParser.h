//
//  DataParser.h
//  ConeVizOSX
//
//  Created by Levko Ivanchuk on 2014-05-31.
//
//

#ifndef __ConeVizOSX__DataParser__
#define __ConeVizOSX__DataParser__

#include <iostream>
#include <string>
#include "ofMain.h"

using namespace std;

class DataParser{
public:
    static DataParser* Instance();
    
    bool analizeFile();                         //displays information about the current file.
    bool setCurrentFile(string newFile);        //set the current file, but do not load it yet.
    bool setAndLoadCurrentFile(string newFile); //
    bool unloadFile();
    
private:
    DataParser(){};  // Private so that it can  not be called
    DataParser(DataParser const&){};             // copy constructor is private
    DataParser& operator=(DataParser const&){};  // assignment operator is private
    static DataParser* m_pInstance;
    
    static string currentFileName;
    
};


bool DataParser::analizeFile()
{
    
}





#endif /* defined(__ConeVizOSX__DataParser__) */
