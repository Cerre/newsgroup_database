#ifndef MEMORY_DATABASE_H
#define MEMORY_DATABASE_H
#include "database.h"

class MemoryDatabase : Database {
public:
    void add_newsgroup(Newsgroup newsgroup) override;

    void delete_newsgroup(Newsgroup newsgroup) override;


    void add_article(Article article) override;

    void delete_article(Article article) override;

    void read_article(Newsgroup newsgroup, Article article) override;

    //List newsgroups
    // std::vector<Newsgroup> list_newsgroups() override; 

    // std::vector<Article> list_articles(Newsgroup newsgroup) override;


};

#endif