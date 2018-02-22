cmake_minimum_required(VERSION 3.9)
project(polidb)

set(CMAKE_CXX_STANDARD 11)

add_executable(polidb
        db/client.cpp
        db/db.cpp
        db/node.cpp
        db/node.h
        db/trie.cpp
        db/trie.h
        includes/db.h
        db/trie_iterator.h
        db/trie_iterator.cpp)
