#include "doctest.h"
#include "Notebook.hpp"
#include "Direction.hpp"
using namespace ariel;
using ariel::Direction;

#include <string>
#include <algorithm>
using namespace std;

TEST_CASE("Good input") {
    	ariel::Notebook notebook;
	string s = "hello world";
	notebook.write(/*page=*/1, /*row=*/100, /*column=*/50, Direction::Horizontal, s);
	CHECK(notebook.read(/*page=*/1, /*row=*/100, /*column=*/50, Direction::Horizontal, /*length=*/s.length()) == (s));
	notebook.erase(/*page=*/1, /*row=*/100, /*column=*/50, Direction::Horizontal, /*length=*/s.length());
	CHECK(notebook.read(/*page=*/1, /*row=*/100, /*column=*/50, Direction::Horizontal, /*length=*/s.length()) == ("~~~~~~~~~~~"));
	notebook.erase(/*page=*/1, /*row=*/100, /*column=*/50, Direction::Horizontal, /*length=*/s.length());
	CHECK(notebook.read(/*page=*/1, /*row=*/100, /*column=*/50, Direction::Horizontal, /*length=*/s.length()) == ("~~~~~~~~~~~"));
	
    s = "HELLO WORLD";
	notebook.write(/*page=*/2, /*row=*/100, /*column=*/50, Direction::Horizontal, s);
	CHECK(notebook.read(/*page=*/2, /*row=*/100, /*column=*/50, Direction::Horizontal, /*length=*/s.length()) == (s));
	notebook.erase(/*page=*/2, /*row=*/100, /*column=*/50, Direction::Horizontal, /*length=*/s.length());
	CHECK(notebook.read(/*page=*/2, /*row=*/100, /*column=*/50, Direction::Horizontal, /*length=*/s.length()) == ("~~~~~~~~~~~"));
	notebook.erase(/*page=*/2, /*row=*/100, /*column=*/50, Direction::Horizontal, /*length=*/s.length());
	CHECK(notebook.read(/*page=*/2, /*row=*/100, /*column=*/50, Direction::Horizontal, /*length=*/s.length()) == ("~~~~~~~~~~~"));
	

    s = "math:1.2+2 = 4";
	notebook.write(/*page=*/3, /*row=*/100, /*column=*/50, Direction::Horizontal, s);
	CHECK(notebook.read(/*page=*/3, /*row=*/100, /*column=*/50, Direction::Horizontal, /*length=*/s.length()) == (s));
	notebook.erase(/*page=*/3, /*row=*/100, /*column=*/50, Direction::Horizontal, /*length=*/s.length());
	CHECK(notebook.read(/*page=*/3, /*row=*/100, /*column=*/50, Direction::Horizontal, /*length=*/s.length()) == ("~~~~~~~~~~~~~~"));
	notebook.erase(/*page=*/3, /*row=*/100, /*column=*/50, Direction::Horizontal, /*length=*/s.length());
	CHECK(notebook.read(/*page=*/3, /*row=*/100, /*column=*/50, Direction::Horizontal, /*length=*/s.length()) == ("~~~~~~~~~~~~~~"));
	
    s = "!@#$%^&*()_+";
	notebook.write(/*page=*/4, /*row=*/100, /*column=*/50, Direction::Horizontal, s);
	CHECK(notebook.read(/*page=*/4, /*row=*/100, /*column=*/50, Direction::Horizontal, /*length=*/s.length()) == (s));
	notebook.erase(/*page=*/4, /*row=*/100, /*column=*/50, Direction::Horizontal, /*length=*/s.length());
	CHECK(notebook.read(/*page=*/4, /*row=*/100, /*column=*/50, Direction::Horizontal, /*length=*/s.length()) == ("~~~~~~~~~~~~"));
	notebook.erase(/*page=*/4, /*row=*/100, /*column=*/50, Direction::Horizontal, /*length=*/s.length());
	CHECK(notebook.read(/*page=*/4, /*row=*/100, /*column=*/50, Direction::Horizontal, /*length=*/s.length()) == ("~~~~~~~~~~~~"));
	

	s = "!@#$%^&*()_+";
	notebook.write(/*page=*/5, /*row=*/100, /*column=*/50, Direction::Vertical, s);
	CHECK(notebook.read(/*page=*/5, /*row=*/100, /*column=*/50, Direction::Vertical, /*length=*/s.length()) == (s));
	notebook.erase(/*page=*/5, /*row=*/100, /*column=*/50, Direction::Vertical, /*length=*/s.length());
	CHECK(notebook.read(/*page=*/5, /*row=*/100, /*column=*/50, Direction::Vertical, /*length=*/s.length()) == ("~~~~~~~~~~~~"));
	notebook.erase(/*page=*/5, /*row=*/100, /*column=*/50, Direction::Vertical, /*length=*/s.length());
	CHECK(notebook.read(/*page=*/5, /*row=*/100, /*column=*/50, Direction::Vertical, /*length=*/s.length()) == ("~~~~~~~~~~~~"));
	
}


TEST_CASE("Bad input-more then 100 char") {
	ariel::Notebook notebook;
    string s = "hello";
    CHECK_THROWS(notebook.write(/*page=*/1, /*row=*/100, /*column=*/101, Direction::Horizontal, s));
	CHECK_THROWS(notebook.write(/*page=*/1, /*row=*/100, /*column=*/96, Direction::Horizontal, s));
	CHECK_THROWS(notebook.erase(/*page=*/4, /*row=*/100, /*column=*/101, Direction::Horizontal, /*length=*/s.length()));
	CHECK_THROWS(notebook.erase(/*page=*/4, /*row=*/100, /*column=*/96, Direction::Horizontal, /*length=*/s.length()));
	CHECK_THROWS(notebook.read(/*page=*/3, /*row=*/100, /*column=*/96, Direction::Horizontal, /*length=*/s.length()));
	CHECK_THROWS(notebook.read(/*page=*/3, /*row=*/100, /*column=*/101, Direction::Horizontal, /*length=*/s.length()));
}

TEST_CASE("Bad input-negtive input") {
	ariel::Notebook notebook;
    string s = "hello";
    CHECK_THROWS(notebook.write(/*page=*/1, /*row=*/-100, /*column=*/1, Direction::Horizontal, s));
	CHECK_THROWS(notebook.erase(/*page=*/-4, /*row=*/100, /*column=*/1, Direction::Horizontal, /*length=*/s.length()));
	CHECK_THROWS(notebook.read(/*page=*/3, /*row=*/100, /*column=*/-90, Direction::Horizontal, /*length=*/s.length()));
}

TEST_CASE("Bad input-earse in a place that is not empty") {
	ariel::Notebook notebook;
    string s = "hello";
    notebook.write(/*page=*/1, /*row=*/1, /*column=*/1, Direction::Horizontal, s);
	notebook.erase(/*page=*/1, /*row=*/1, /*column=*/1, Direction::Horizontal, /*length=*/s.length());
	CHECK_THROWS(notebook.write(/*page=*/1, /*row=*/1, /*column=*/1, Direction::Horizontal, s));

	notebook.write(/*page=*/2, /*row=*/1, /*column=*/1, Direction::Vertical, s);
	notebook.erase(/*page=*/2, /*row=*/1, /*column=*/1, Direction::Vertical, /*length=*/s.length());
	CHECK_THROWS(notebook.write(/*page=*/2, /*row=*/1, /*column=*/1, Direction::Vertical, s));

	
}