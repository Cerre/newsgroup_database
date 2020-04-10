#include "newsgroup.h"

Newsgroup::Newsgroup(unsigned int id) : id(id) {}

void Newsgroup::add_article(Article article) {
	articles.push_back(article);
}

