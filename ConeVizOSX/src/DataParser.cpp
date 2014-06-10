//
//  TestClass.cpp
//  ConeVizOSX
//
//  Created by Levko Ivanchuk on 2014-06-03.
//
//

#include "DataParser.h"

bool DataParser::instanceFlag = false;
string DataParser::currentFileName;
ofFile DataParser::file;
ofBuffer DataParser::fileBuffer;

DataParser* DataParser::single = NULL;


DataParser* DataParser::getInstance()
{
    if(! instanceFlag)
    {
        single = new DataParser();
        instanceFlag = true;
        return single;
    }
    else
    {
        return single;
    }
}

bool DataParser::setCurrentFile(string newFile)
{
    currentFileName = newFile;
}

bool DataParser::analizeFile()
{
    
    //0.5 - Test if the currentFileName has been set
    if(currentFileName.empty())
        return false;
    
    //1 - Attempt to open the file
    file.open(ofToDataPath(currentFileName), ofFile::ReadOnly, false);
    ofLog() << "Opening: " << currentFileName;
    
    //2 - Test is the file can be opened and read
    ofLog() << "Can be read: " << bool(file.isFile());
    
    //3 - Get the filesize
    long file_size = file.getSize();
    ofLog() << "File size: " << ofToString(file_size);
    
    //4 - Attempt to allocate a buffer
    fileBuffer.allocate(file_size);
    
    fileBuffer = file.readToBuffer();
    
    return true; //file analized successfully.
    
}

//Load the file, create a datastructure

bool DataParser::loadFile()
{

}

bool DataParser::unloadFile()
{
    //1 - Clear the current file name string
    currentFileName.clear();
    
    //2 - Clear the file container
    file.close();
    
    //3 - Clear the file buffer
    fileBuffer.clear();
    
    return true;
}