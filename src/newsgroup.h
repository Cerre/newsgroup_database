#ifndef NEWSGROUP_H
#define NEWSGROUP_H

#include <string>
#include <vector>
#include "article.h"

/* 
 * The newsgroup class should contain:
 * 	- A UNIQUE name of the newsgroup
 * 	- A UNIQUE identification number > 0
 * 	- A list of articles
 *
 * */

class Newsgroup {
	public:
		Newsgroup(unsigned int id);	
		Newsgroup(unsigned int id, std::string name);

	// private:
		unsigned int id;
		std::string name;
		std::vector<Article> articles{};

};

#endif

