#ifndef MEMORY_DATABASE_H
#define MEMORY_DATABASE_H
#include "database.h"
#include <iostream>
#include <map>
#include <vector>

class MemoryDatabase : Database {
public:

    MemoryDatabase();

    void add_newsgroup(const Newsgroup &newsgroup) override;

    void delete_newsgroup(unsigned int) override;


    void add_article(unsigned int, const Article &article) override;

    void delete_article(unsigned int, unsigned int) override;

    Article read_article(unsigned int, unsigned int) override;

    //List newsgroups
    std::vector<Newsgroup> list_newsgroups() override; 

    std::vector<Article> list_articles(unsigned int) override;


    friend std::ostream &operator<<(std::ostream& os, const MemoryDatabase &mem_db);


private:
    std::map<unsigned int, Newsgroup> newsgroups;

    
};

#endif