cmake_minimum_required(VERSION 3.0)

# Set project name
project(news_db)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src include)
add_executable(main.out src/main.cc src/newsgroup.cc src/article.cc include/database.h include/memory_database.h src/memory_database.cc)

