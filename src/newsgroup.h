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

struct Newsgroup {
		Newsgroup(unsigned int id);	
		void add_article(Article article);
		void remove_article(Article article);
		Article read_article(Article article);
		std::vector<Article> list_articles();



		unsigned int id;
		std::string name;
		std::vector<Article> articles{};
		

};

#endif

