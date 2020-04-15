#ifndef ARTICLE_H
#define ARTICLE_H

#include <string>

/* The Article class should contain
 *  - A title
 *  - A Author
 *  - An article text
 *  - Identification number, unique within newsgroup
 *
 * */

struct Article {
		Article(std::string title, std::string author, std::string text, unsigned int id);
		Article(const Article &article); //Copy constructor

		bool operator==(const Article &article);

		std::string text;
		unsigned int id;				
		std::string title;
		std::string author;
};


#endif

