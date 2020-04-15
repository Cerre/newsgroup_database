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

	Newsgroup n(1);
	Article a("head", "author", "text body", 1);
	n.add_article(a);

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

