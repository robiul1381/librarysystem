#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Person.h"
#include <vector>
#include <sstream>
#include <fstream>

TEST_CASE("Person Class Tests") {
    Person p1;

    SECTION("Default Constructor") {
        REQUIRE(p1.getName() == "");
        REQUIRE(p1.getAddress() == "");
        REQUIRE(p1.getEmail() == "");
    }

    SECTION("Setters and Getters") {
        p1.setName("Robiul Hasan");
        p1.setAddress("London");
        p1.setEmail("robiul@gmail.com");

        REQUIRE(p1.getName() == "Robiul Hasan");
        REQUIRE(p1.getAddress() == "London");
        REQUIRE(p1.getEmail() == "robiul@gmail.com");
    }
}


TEST_CASE("Member File IO Tests") {
    std::vector<Member> members;
    Person p("Robiul Hasan", "London", "robiul@gmail.com");
    Member m(p);
    members.push_back(m);

    SECTION("Save and Load Members") {
        saveMembersToFile(members);

        std::vector<Member> loadedMembers;
        loadMembersFromFile(loadedMembers);

        REQUIRE(loadedMembers.size() == 1);
        REQUIRE(loadedMembers[0].getPerson().getName() == "Robiul Hasan");
        REQUIRE(loadedMembers[0].getPerson().getAddress() == "London");
        REQUIRE(loadedMembers[0].getPerson().getEmail() == "robiul@gmail.com");
    }
}

TEST_CASE("Display Member Information") {
    std::vector<Member> members;
    Person p("Robiul Hasan", "London", "robiul@gmail.com");
    Member m(p);
    members.push_back(m);

    std::stringstream buffer;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    displayMemberInformation(members);

    std::cout.rdbuf(oldCoutStreamBuf);

    std::string output = buffer.str();
    REQUIRE(output.find("Robiul Hasan") != std::string::npos);
    REQUIRE(output.find("London") != std::string::npos);
    REQUIRE(output.find("robiul@gmail.com") != std::string::npos);
}