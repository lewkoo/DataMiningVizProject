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
ofDirectory DataParser::currentFileStore = ofDirectory("");
vector<string> DataParser::files;


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

bool DataParser::setFileStoreDirectory(string newDirectory) // takes absolute path
{
    //1 - Change the current directory
    currentFileStore = ofDirectory(newDirectory);
    //2 - Automatically rebuild the File Store
    buildFileStore();
    //3 - Print the current path
    ofLog() << "Current path being scanned: " << currentFileStore.path();
}

bool DataParser::analizeFile()
{
    
    //0.5 - Test if the currentFileName has been set
    if(currentFileName.empty())
        return false;
    
    //1 - Attempt to open the file

    file.open(ofToDataPath(currentFileName), ofFile::ReadOnly, false);
    ofLog() << "Opening: " << currentFileName;

    //1.1 - Check if the file has been opened and located
    
    if(file.isFile() == 0)
    {
        ofLog() << "File can not be opened or does not exist" << endl;
        return false;
    }

    //2 - Test is the file can be opened and read
    ofLog() << "Can be read: " << bool(file.isFile());
    
    //3 - Get the filesize
    long file_size = file.getSize();
    ofLog() << "File size: " << ofToString(file_size);
    
    //3.1 - TODO: Get the number of lines in the file
    
    
    //4 - Attempt to allocate a buffer
    fileBuffer.allocate(file_size);
    
    fileBuffer = file.readToBuffer();
    
    return true; //file analized successfully.
    
}

//Load the file

bool DataParser::loadFile()
{
    analizeFile();
    
    //do ther stuff...
    
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

bool DataParser::buildFileStore()
{
    //1 - Only show txt files
    currentFileStore.allowExt("txt");
    //2 - Populate the directory object
    currentFileStore.listDir();
    
    //3 - go through and print out all the paths
    for(int i = 0; i < currentFileStore.numFiles(); i++){
        ofLogNotice(currentFileStore.getPath(i));
        files.push_back(currentFileStore.getPath(i));
    }
}