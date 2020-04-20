#include "memory_database.h"
#include <vector>
#include <map>




// database create_database(){
//     return mem_db;
// }
MemoryDatabase::MemoryDatabase(){

    }

void MemoryDatabase::add_newsgroup(const Newsgroup &newsgroup) {
    newsgroups.insert ( std::pair<unsigned int, Newsgroup>(newsgroup.id,newsgroup) );
}


void MemoryDatabase::delete_newsgroup(unsigned int id) {
    newsgroups.erase(id);
}




//Adds article
void MemoryDatabase::add_article(unsigned int id, const Article &article) {
    newsgroups.at(id).articles.insert(std::pair<unsigned int, Article>(article.id, article));
}




//Delete articles in newsgroup
void MemoryDatabase::delete_article(unsigned int news_id, unsigned int art_id) {
    newsgroups.at(news_id).articles.erase(art_id);
}



//Read articles in newsgroup
Article MemoryDatabase::read_article(unsigned int news_id, unsigned int art_id) {
    std::cout << newsgroups.at(news_id).articles.at(art_id).text << std::endl;
    return newsgroups.at(news_id).articles.at(art_id);
}






//List newsgroups
std::vector<Newsgroup> MemoryDatabase::list_newsgroups(){
    std::vector<Newsgroup> result;
    for (auto &key : newsgroups){
        result.push_back(key.second);
        std::cout << key.second.id << "     " << key.second.name << std::endl;
    }
    return result;
}




//List articles
std::vector<Article> MemoryDatabase::list_articles(unsigned int news_id) {
    std::vector<Article> result;
    for (auto &key : newsgroups.at(news_id).articles){
        result.push_back(key.second);
        std::cout << key.second.id << "     " << key.second.title << std::endl;
    }
    return result;


}

std::ostream& operator<<(std::ostream& os, const MemoryDatabase &mem_db) {
    os << "\nMemory Database Summation\n" << std::endl;
    for (auto &key : mem_db.newsgroups){
        os << "Newsgroup: " << key.second.name << std::endl;
        os << "     Articles: " << std::endl;
        for (auto &it : key.second.articles){
            os << it.second.id << "     " << it.second.title << std::endl;

        }
        os << '\n';

    }
    return os;
}
//Print out entire database
// std::ostream& operator<<(std::ostream& os, const MemoryDatabase &mem_db){
//     os << "\nMemory Database Summation\n" << std::endl;
//     for(std::map<Newsgroup>::size_type i = 0; i != mem_db.newsgroups.size(); i++) {
//         os << "Newsgroup: " << mem_db.newsgroups[i].name << std::endl;
//         os << "     Articles:" << std::endl;
//         for (std::vector<Article>::size_type j = 0; j != mem_db.newsgroups[i].articles.size(); j++) {
//             os << j + 1 << "         " << mem_db.newsgroups[i].articles[j].title << std::endl;
//         }
//         os << '\n';
// }
//     return os;
// }

