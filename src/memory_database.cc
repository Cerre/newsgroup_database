#include "memory_database.h"
#include <vector>
#include <map>




// database create_database(){
//     return mem_db;
// }
MemoryDatabase::MemoryDatabase(){

    }

void MemoryDatabase::add_newsgroup(Newsgroup newsgroup) {
    newsgroups.push_back(newsgroup);
}


void MemoryDatabase::delete_newsgroup(Newsgroup newsgroup) {

}




//Adds article
void MemoryDatabase::add_article(const Newsgroup &newsgroup, const Article &article) {
    auto it = std::find_if(newsgroups.begin(), newsgroups.end(), 
					[newsgroup] (Newsgroup n) -> bool {
						return newsgroup.id == n.id;
					});
    if (it == newsgroups.end()){
        std::cout << "Newsgroup doesn't exist, code should never reach here" << std::endl;
    }
    else{
        it->articles.push_back(article);
    }


}




//Delete articles in newsgroup
void MemoryDatabase::delete_article(const Newsgroup &newsgroup, const Article &article) {
    // auto it = find_article(newsgroup, article);


}



//Read articles in newsgroup
void MemoryDatabase::read_article(const Newsgroup &newsgroup, const Article &article) {
    auto it = find_newsgroup(newsgroup);
    // auto it2 = find_article(*it, article);

    // std::cout << it2->text << std::endl;


}



//Help function. Maybe we should convert to map to reduce searching?
std::vector<Newsgroup>::iterator MemoryDatabase::find_newsgroup(const Newsgroup &newsgroup){
    auto it = std::find_if(newsgroups.begin(), newsgroups.end(), 
                        [newsgroup] (Newsgroup n) -> bool {
                            return n.id == newsgroup.id;
                        });
    return it;
}

// std::vector<Article>::iterator MemoryDatabase::find_article(constNewsgroup &newsgroup, const Article &article){
//     auto it = std::find_if(newsgroup.articles.begin(), newsgroup.articles.end(),
//                 [article] (Article a) -> bool {
//                     return a.id == article.id;
//                 });
//     return it;

// }


//List newsgroups
std::vector<Newsgroup> MemoryDatabase::list_newsgroups(){
    for(std::vector<Newsgroup>::size_type i = 0; i != newsgroups.size(); i++) {
        std::cout << newsgroups[i].name << std::endl;
    }
    return newsgroups;
}




//List articles
std::vector<Article> MemoryDatabase::list_articles(const Newsgroup &newsgroup) {
    auto it = find_newsgroup(newsgroup);
        if (it == newsgroups.end()){
            //Throw exception
            std::cout << "No such group exists" << std::endl;
        }
        else{
            std::cout << "Articles in newsgroup " << it->name << ":\n";
            for(std::vector<Article>::size_type i = 0; i != it->articles.size(); i++) {
                std::cout << i + 1  << "     " << it->articles[i].title << std::endl;
            }
            return it->articles;
        }

}


//Print out entire database
std::ostream& operator<<(std::ostream& os, const MemoryDatabase &mem_db){
    os << "\nMemory Database Summation\n" << std::endl;
    for(std::vector<Newsgroup>::size_type i = 0; i != mem_db.newsgroups.size(); i++) {
        os << "Newsgroup: " << mem_db.newsgroups[i].name << std::endl;
        os << "     Articles:" << std::endl;
        for (std::vector<Article>::size_type j = 0; j != mem_db.newsgroups[i].articles.size(); j++) {
            os << j + 1 << "         " << mem_db.newsgroups[i].articles[j].title << std::endl;
        }
        os << '\n';
}
    return os;
}