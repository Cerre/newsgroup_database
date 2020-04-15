#include "newsgroup.h"
#include <iostream>

Newsgroup::Newsgroup(unsigned int id) : id(id) {}

void Newsgroup::add_article(Article article) {
	articles.push_back(article);
}

void Newsgroup::remove_article(Article article) {
	auto it = std::find(articles.begin(), articles.end(), article);
	if (*it == *articles.end()){
		std::cout << "Article not in newsgroup" << std::endl;
		//Throw Exception?
	}
	else{
		articles.erase(it);
	}
}

Article Newsgroup::read_article(Article article) {
	auto it = std::find(articles.begin(), articles.end(), article);
	if (*it == *articles.end()){
		std::cout << "Article not in newsgroup" << std::endl;
		//Throw exception?
	}
	else{
		std::cout << it->text << std::endl;
		return *it;
	}
}


std::vector<Article> Newsgroup::list_articles(){
	for (auto it : articles){
		std::cout << it.title << std::endl;
	}
	return articles;
}
