#include "Utilities.h"


Utilities::Utilities(void)
{
}


Utilities::~Utilities(void)
{
}

void Utilities::generateRandomItemsets(std::vector<Itemset>* itemsets)
{

}

void Utilities::loadItemsets(char* fileName, std::vector<Itemset>* itemsets, std::vector<Level>* levels)
{
	//1 - Generate the filepath
	char* datasetFile = (char*) malloc(200 * sizeof(char));
    _getcwd(datasetFile, 200);
    strcat(datasetFile, "\\..\\Data\\");
	strcat(datasetFile, fileName);
    printf("%s \n", datasetFile);

	
	//2 - Open the file
    FILE* stream = fopen(datasetFile, "r");
    if(stream == NULL){
            perror("File open error");
            exit(EXIT_FAILURE);
    }


    //3 - Populate the dataset
    int counter = 0;
    char current_line[200]; //to store the retreived line from the file
    char* line_tokenized; //to store the tokenized line

    //4 - Read all the lines
    while (fgets(current_line, 200, stream)) //loops while there is data in the file
    {
		
		Itemset newItemset = Itemset(current_line);
	
		itemsets->push_back(newItemset);


    }


}

