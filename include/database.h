#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include "newsgroup.h"
#include <vector>

class Database{
public:
    virtual void add_newsgroup(Newsgroup newsgroup);

    virtual void delete_newsgroup(Newsgroup newsgroup);

    virtual void add_article(Article article);

    virtual void delete_article(Article article);

    virtual void read_article(Newsgroup newsgroup, Article article);

    //Perhaps use something like this since they are unique?
    // virtual void read_article(unsigned int, unsigned int);


    // List newsgroups
    // virtual std::vector<Newsgroup> list_newsgroups(); 

    // virtual std::vector<Article> list_articles(Newsgroup newsgroup);

    // Perhaps use something like this since they are unique?
    // virtual std::vector<Article> list_articles(unsigned int);


    };

#endif




