#include "Utilities.h"

int Utilities::Y_RASING_FACTOR = 20;

Utilities::Utilities(void)
{
}


Utilities::~Utilities(void)
{
}

void Utilities::loadItemsets(ofFile fileToOpen, std::vector<Itemset*>* itemsets, std::vector<Level*>* levels)
{
	//1 - Clear the itemsets and levels
	//delete levels;
	//levels->clear();
	//levels = new std::vector<Level*>();

	////delete itemsets;
	//itemsets->clear();
	//itemsets = new std::vector<Itemset*>();

	//2 - Open the file
	ofBuffer fileBuffer = ofBufferFromFile("datasets/" + fileToOpen.getFileName());

	//3 - Parse all the lines
	while(fileBuffer.isLastLine() == false)
	{
		string lineToParse = fileBuffer.getNextLine();

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

			//process the frequency string as it constains (xxxx)
			string frequency_string = tokens[i+1];
			frequency_string.erase(frequency_string.begin());
			frequency_string.erase(frequency_string.end()-1);


			itemset->setFrequency(std::stoi(frequency_string));

		}

		//4 - Add itemset to itemsets collection
		itemsets->push_back(itemset);

		//5 - Add it to a level or create a new level if does not exist

		Level *level;

		try{
			level = levels->at(itemset->getLevel()-1);
			level->addItemset(itemset);
		}catch(std::exception& e)
		{
			cout << "WARNING: No level " << itemset->getLevel()  << " exists. Creating.";

			level = new Level(itemset->getLevel());
			level->addItemset(itemset);

			levels->push_back(level);

		}
	}

}

//finds the max frequency in the dataset
int Utilities::findMaxFreq(std::vector<Level*> *levels)
{
	int maxFrequency = 0;
	int i;
	for(i = 0; i < levels->size(); i++)
	{
		if(maxFrequency < levels->at(i)->getMaxFrequency() )
		{
			maxFrequency = levels->at(i)->getMaxFrequency();
		}
	}

	return maxFrequency;
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

		//for(int i = 0; i < levels->size(); i++)
		//{
		//	int newY = abs((int)((i+1)-levels->size())) * Y_RASING_FACTOR;
		//	levels->at(i)->setYCoordinate(newY);
		//}
		
		for(int i = 0; i < levels->size(); i++)
		{
			int level_id = abs( (int)(levels->size() - i) );

			int newY = level_id * Y_RASING_FACTOR;
			levels->at(i)->setYCoordinate(newY);
		}

		break;

	}

}

void Utilities::setConnections(Level top, Level bottom, ofMesh mesh)
{
	std::vector<VizElement*> top_itemsets = top.getVizElements();
	std::vector<VizElement*> bottom_itemsets = bottom.getVizElements();

	for(int i = 0; i < top_itemsets.size(); i++)
	{
		for(int j = 0; j < bottom_itemsets.size(); j++)
		{
			const char top_itemset_string = *top_itemsets[i]->getName().data();
			string bottom_itemset_name = bottom_itemsets[j]->getName();

			string::size_type return_value = bottom_itemset_name.find(top_itemset_string);

			if(return_value != string::npos)
			{
				//mesh.addIndex(top_itemsets[i]->getId());
				//mesh.addIndex(bottom_itemsets[j]->getId());
				//ofLine(top_itemsets[i]->getLocation(), bottom_itemsets[j]->getLocation());
			}
		}
	}
}

int Utilities::getYRasingFactor()
{
	return Y_RASING_FACTOR;
}

void Utilities::setYRasingFactor(int newY)
{
	Y_RASING_FACTOR = newY;

}