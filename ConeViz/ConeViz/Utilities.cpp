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

void Utilities::loadItemsets(char* fileName, std::vector<Itemset*>* itemsets, std::vector<Level*>* levels)
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
    char current_line[200]; //to store the retreived line from the file
    char* line_tokenized; //to store the tokenized line

	Level* current_level = new Level(0);

    //4 - Read all the lines
    while (fgets(current_line, 200, stream)) //loops while there is data in the file
    {
		
		if((unsigned)strlen(current_line)-1 != current_level->getLevelId())
		{
			//Push the level to the pool
			current_level = new Level(strlen(current_line)-1);
			levels->push_back(current_level);
		}

		Itemset newItemset = Itemset(current_line);
	
		//add the itemset to the level
		current_level->addItemset(newItemset);

		//add to the general pool of itemsets
		itemsets->push_back(&newItemset);

		memset(&current_line, 0, sizeof(char) * 200);


    }


}

void Utilities::setYCoordinates(std::vector<Level*> *levels, SHAPE_TYPES newShape)
{
	switch(newShape)
	{

	case SHAPE_TYPES::FLAT_CONE : 
			
		for(int i = 0; i < levels->size(); i++)
		{
			levels->at(i)->setYCoordinate(0);
		}

		break;

	case SHAPE_TYPES::INVERTED_CONE :

		for(int i = 0; i < levels->size(); i++)
		{
			int newY = levels->at(i)->getLevelId() * Y_RASING_FACTOR;
			levels->at(i)->setYCoordinate(newY);
		}

		break;

	case SHAPE_TYPES::NORMAL_CONE :

		for(int i = 0; i < levels->size(); i++)
		{
			int newY = abs((int)((i+1)-levels->size())) * Y_RASING_FACTOR;
			levels->at(i)->setYCoordinate(newY);
		}
		
		break;

	}

}

void Utilities::drawConnections(Level top, Level bottom)
{
	std::vector<Itemset> top_itemsets = top.getItemsets();
	std::vector<Itemset> bottom_itemsets = bottom.getItemsets();

	for(int i = 0; i < top_itemsets.size(); i++)
	{
		for(int j = 0; j < bottom_itemsets.size(); j++)
		{
			const char top_itemset_string = *top_itemsets[i].getName().data();
			string bottom_itemset_name = bottom_itemsets[j].getName();

			string::size_type return_value = bottom_itemset_name.find(top_itemset_string);

			if(return_value != string::npos)
			{
				ofLine(top_itemsets[i].getLocation(), bottom_itemsets[j].getLocation());
			}
		}
	}
}