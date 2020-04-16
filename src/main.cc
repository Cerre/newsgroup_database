#include <iostream>
#include <string>
#include "newsgroup.h"
#include "article.h"
#include "memory_database.h"


using std::string;
using std::cin;


/* Command line interface pattern
 *
 * 	If the arguments to the program are valid then
 *   	Do necessary pre-processing
 *   	For every line in the input
 *       	Do necessary input processing
 *   	Do necessary post-processing
 *	Otherwise
 *   	Show the user a friendly usage message
 */ 


int main() {
    std::cout << "Starting Newsgroup Database"  << std::endl;
	MemoryDatabase mem_db;

	Newsgroup n(1, "Expressen");
	Article a("head", "author", "text body", 1);

	Newsgroup n2(2, "Aftonbladet");
	Article b("head2", "author2", "text body2", 2);
	Article c("head3", "author3", "text body3", 3);

	mem_db.add_newsgroup(n);
	mem_db.add_newsgroup(n2);
	mem_db.add_article(n2, a);
	mem_db.add_article(n2, b);
	bool test = 1;
	if (test){
		std::cout << mem_db << std::endl;
		std::cout << "\nLists newsgroups\n";
		std::vector<Newsgroup> newsgroups = mem_db.list_newsgroups();
		std::cout << "\nLists articles in n2\n";
		std::vector<Article> articles = mem_db.list_articles(n2);
	}
	// mem_db.add_article(n2, c);
	// mem_db.add_article(n, b);

	bool running = true;
	while (running) {
		// Read input
		std::cout << "news > ";
		std::string line;
		std::getline(std::cin, line);

		/* Handle input 
		 * ------------
		 *
		 *  Commands:
		 *  	- list
		 *
		 *
		 * */

		if (line == "exit" || line == "q" || line == "exit()") {
			std::cout << "Exiting.." << std::endl;
			running = false;
			break;
		}
        std::cout << line << std::endl;
	}

    return 0; 
}

