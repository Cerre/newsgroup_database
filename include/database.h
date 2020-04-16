#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include "newsgroup.h"
#include <vector>

class Database{
public:
    virtual void add_newsgroup(Newsgroup newsgroup) = 0;

    virtual void delete_newsgroup(Newsgroup newsgroup) = 0;

    virtual void add_article(const Newsgroup &newsgroup, const Article &article) = 0;

    virtual void delete_article(const Newsgroup &newsgroup, const Article &article) = 0;

    virtual void read_article(const Newsgroup &newsgroup, const Article &article) = 0;

    //Perhaps use something like this since they are unique?
    // virtual void read_article(unsigned int, unsigned int);


    // List newsgroups
    virtual std::vector<Newsgroup> list_newsgroups() = 0; 

    virtual std::vector<Article> list_articles(const Newsgroup &newsgroup) = 0;

    // Perhaps use something like this since they are unique?
    // virtual std::vector<Article> list_articles(unsigned int);


    };

#endif




