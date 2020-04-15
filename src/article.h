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

class Article {
	public:
		Article(std::string title, std::string author, std::string text, unsigned int id);

	private:
		unsigned int id;				
		std::string title;
		std::string author;
		std::string text;
};


#endif

