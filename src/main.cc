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
	Newsgroup n2(2, "Aftonbladet");
	Newsgroup n3(3, "Helsingborgs Dagblad");

	Article a("head", "author", "text body", 1);
	Article b("head2", "author2", "text body2", 2);
	Article c("head3", "author3", "text body3", 3);

	mem_db.add_newsgroup(n);
	mem_db.add_newsgroup(n2);
	mem_db.add_newsgroup(n3);
	mem_db.add_article(n.id, a);
	mem_db.add_article(n.id, b);
	mem_db.add_article(n.id, c);

	bool test = 0;
	if (test){
		// std::cout << mem_db << std::endl;
		// std::cout << "\nLists newsgroups\n";
		std::cout << "\nLists articles in n\n";
		mem_db.list_articles(n.id);
		std::cout << "\nLists articles in n after remove a\n";
		mem_db.delete_article(n.id,a.id);
		mem_db.list_articles(n.id);
		mem_db.read_article(n.id,a.id);
	}

	bool running = true;
	int k = 10;
	while (running) {
		k++;
		// Read input
		std::cout << "What do you want to do? " << std::endl;
		std::cout << "1: Print database" << std::endl;
		std::cout << "2: Add newsgroup" << std::endl;
		std::cout << "3: Add article" << std::endl;
		std::cout << "4: delete newsgroup" << std::endl;
		std::cout << "5: delete article" << std::endl;
		std::cout << "6: read article" << std::endl;

		int line;
		std::cin >> line;
		switch(line) {
			case 1  :
				std::cout << mem_db << std::endl;
				break; //optional
			case 2  :
			{
				std::cout << "Enter newsgroup name" << std::endl;
				std::string news;
				std::cin.ignore();
				std::getline(std::cin, news);
				mem_db.add_newsgroup(Newsgroup(k,news));
				std::cout << news << " was added as a newsgroup." << std::endl;
				break; //optional
			}
			case 3  :
			{
				std::string title;
				std::string author;
				std::string text;
				int newsgroup_number;

				std::cout << "Which newsgroup will the article be added to?" << std::endl;
				mem_db.list_newsgroups();

				std::cout << "Enter number" << std::endl;
				std::cin >> newsgroup_number;

				std::cout << "Enter title" << std::endl;
				std::cin.ignore();
				std::getline(std::cin, title);

				std::cout << "Enter author" << std::endl;
				std::cin.ignore();
				std::getline(std::cin, author);

				std::cout << "Enter text" << std::endl;
				std::cin.ignore();
				std::getline(std::cin, text);

				mem_db.add_article(newsgroup_number, Article(title, author, text, k));
				break; //optional
			}
			case 4  :
			{
				std::cout << "Which newsgroup do you want to delete?" << std::endl;
				mem_db.list_newsgroups();
				std::cout << "Enter number" << std::endl;
				int newsgroup_number;
				std::cin >> newsgroup_number;
				mem_db.delete_newsgroup(newsgroup_number);
				break; //optional
			}
			case 5 :
			{
				mem_db.list_newsgroups();
				std::cout << "Enter newsgroup number" << std::endl;
				int newsgroup_number;
				std::cin >> newsgroup_number;
				mem_db.list_articles(newsgroup_number);
				std::cout << "Enter article number" << std::endl;
				int art_number;
				std::cin >> art_number;
				mem_db.delete_article(newsgroup_number, art_number);
				std::cout << "Article was deleted" << std::endl;
				
			}
			case 6 :
			{
				mem_db.list_newsgroups();
				std::cout << "Enter newsgroup number" << std::endl;
				int newsgroup_number;
				std::cin >> newsgroup_number;
				mem_db.list_articles(newsgroup_number);
				std::cout << "Enter article number" << std::endl;
				int art_number;
				std::cin >> art_number;
				mem_db.read_article(newsgroup_number,art_number);
				

			}
			default : //Optional
				std::cout << "Enter a correct alternative\n" << std::endl;;
			k++;
}

		/* Handle input 
		 * ------------
		 *
		 *  Commands:
		 *  	- list
		 *
		 *
		 * */

		// if (line == "exit" || line == "q" || line == "exit()") {
		// 	std::cout << "Exiting.." << std::endl;
		// 	running = false;
		// 	break;
		// }
        // std::cout << line << std::endl;
	}

    return 0; 
}

