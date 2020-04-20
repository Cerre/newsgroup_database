#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include "newsgroup.h"
#include <vector>

class Database{
public:
    virtual void add_newsgroup(const Newsgroup &newsgroup) = 0;

    virtual void delete_newsgroup(unsigned int) = 0;

    virtual void add_article(unsigned int, const Article &article) = 0;

    virtual void delete_article(unsigned int, unsigned int) = 0;

    virtual Article read_article(unsigned int, unsigned int) = 0;

    //Perhaps use something like this since they are unique?
    // virtual void read_article(unsigned int, unsigned int);


    // List newsgroups
    virtual std::vector<Newsgroup> list_newsgroups() = 0; 

    virtual std::vector<Article> list_articles(unsigned int) = 0;

    // Perhaps use something like this since they are unique?
    // virtual std::vector<Article> list_articles(unsigned int);


    };

#endif




