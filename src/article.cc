#include "article.h"


Article::Article(std::string title, std::string author, std::string text, unsigned int id) 
		: title(title), author(author), text(text), id(id) {}


//Copy constructor, disable? Since ID is unique.
Article::Article(const Article &article) {title = article.title; author = article.author;
text = article.text; id = article.id;
}

bool Article::operator==(const Article &article) {
	return this->id == article.id;
}
