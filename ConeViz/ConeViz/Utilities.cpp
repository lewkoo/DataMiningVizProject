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

void Utilities::loadItemsets(ofFile fileToOpen, std::vector<Itemset*>* itemsets, std::vector<Level*>* levels)
{
	//1 - Open the file
	ofBuffer fileBuffer = ofBufferFromFile("datasets/" + fileToOpen.getFileName());

	//2 - Parse all the lines
	while(fileBuffer.isLastLine() == false)
	{
		Utilities::parseLine(fileBuffer.getNextLine(), itemsets, levels);	
	}

}

void Utilities::parseLine(std::string lineToParse, std::vector<Itemset*>* itemsets, std::vector<Level*>* levels)
{
	/**Observations: format is as follows: 
		itemsetID (frequency) itemset (frequency) itemset (frequency) 

		the number of these compinations corresponds to the Level ID

		a way to do it: create a temp list of itemsets, go over the entire line and parse the itemsets data
		the length of that temporary list will determine the level, the smallest frequency value will represent the frequency of that itemset

	*/

	//1 - Instanciate a temporary list of itemsets
	vector <Itemset*> itemsetsToAdd = vector <Itemset*>();

	//2 - Split the line by space, if begins with ( - it is a frequency, else it is an itemset
    std::istringstream buf(lineToParse);
    std::istream_iterator<std::string> beg(buf), end;
	std::vector<std::string> tokens(beg, end); // string is tokenized, parse it

	



	//171 (68)
	//parse this: 180 (105) 730 (22) 783 (21) 



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
		
		for(int i = 0; i < levels->size(); i++)
		{
			int level_id = abs( (int)(levels->at(i)->getLevelId()-levels->size()) );

			int newY = level_id * Y_RASING_FACTOR;
			levels->at(i)->setYCoordinate(newY);
		}

		break;

	}

}

void Utilities::drawConnections(Level top, Level bottom)
{
	std::vector<Itemset*> top_itemsets = top.getItemsets();
	std::vector<Itemset*> bottom_itemsets = bottom.getItemsets();

	for(int i = 0; i < top_itemsets.size(); i++)
	{
		for(int j = 0; j < bottom_itemsets.size(); j++)
		{
			const char top_itemset_string = *top_itemsets[i]->getName().data();
			string bottom_itemset_name = bottom_itemsets[j]->getName();

			string::size_type return_value = bottom_itemset_name.find(top_itemset_string);

			if(return_value != string::npos)
			{
				ofLine(top_itemsets[i]->getLocation(), bottom_itemsets[j]->getLocation());
			}
		}
	}
}