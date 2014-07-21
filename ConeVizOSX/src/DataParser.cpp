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

vector<string> DataParser::getDataFiles()
{
    return files;
}

string DataParser::getNextLine()
{
    return fileBuffer.getNextLine();
}

string DataParser::getAllData()
{
    return fileBuffer.getText();
}

Itemset* DataParser::getNextItemset()
{
    
    //0 - Get the line to parse from a file
    string lineToParse = fileBuffer.getNextLine();
    
    if (lineToParse.empty())
        return NULL;
    
    //1 - Instanciate a temporary list of itemsets
    Itemset *itemset = new Itemset();
    
    //2 - Split the line by space, if begins with ( - it is a frequency, else it is an itemset
    std::istringstream buf(lineToParse);
    std::istream_iterator<std::string> beg(buf), end;
    std::vector<std::string> tokens(beg, end); // string is tokenized, parse it
    
    //3 - Construct an itemset
    for (int i = 0; i < tokens.size(); i+=2)
    {
        //i - itemset name
        //i+1 - itemset frequency
        
        itemset->addSingletonToItemset(tokens[i]);
        
        //process the frequency string as it constains brackets -> (xxxx)
        string frequency_string = tokens[i+1];
        frequency_string.erase(frequency_string.begin());
        frequency_string.erase(frequency_string.end()-1);
        
        istringstream buffer(frequency_string);
        int itemsetFrequency;
        
        buffer >> itemsetFrequency;
        
        itemset->setFrequency(itemsetFrequency);
        
    }
    
    return itemset;
    
    
}

