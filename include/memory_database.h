#ifndef MEMORY_DATABASE_H
#define MEMORY_DATABASE_H
#include "database.h"
#include <iostream>
#include <map>
#include <vector>

class MemoryDatabase : Database {
public:

    MemoryDatabase();

    void add_newsgroup(Newsgroup newsgroup) override;

    void delete_newsgroup(Newsgroup newsgroup) override;


    void add_article(const Newsgroup &newsgroup, const Article &article) override;

    void delete_article(const Newsgroup &newsgroup, const Article &article) override;

    void read_article(const Newsgroup &newsgroup, const Article &article) override;

    //List newsgroups
    std::vector<Newsgroup> list_newsgroups() override; 

    std::vector<Article> list_articles(const Newsgroup &newsgroup) override;

    friend std::ostream &operator<<(std::ostream& os, const MemoryDatabase &mem_db);

    std::vector<Newsgroup>::iterator find_newsgroup(const Newsgroup &newsgroup);

    std::vector<Article>::iterator find_article(Newsgroup &newsgroup, const Article &article);





// private:
    std::vector<Newsgroup> newsgroups;

    
};

#endif