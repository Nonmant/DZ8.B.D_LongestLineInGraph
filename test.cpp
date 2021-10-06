#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp"

TEST_CASE("Catch operability", "[simple]"){
    REQUIRE(1+1 == 2);
}

#include "funcs.h"

TEST_CASE("test 1, file", "[simple]"){
    std::ofstream inputPrepare;
    inputPrepare.open ("input.txt", std::ofstream::trunc);
    inputPrepare<<"2\n"
                  "1 2";
    inputPrepare.close();

    std::ifstream input( "input.txt", std::ofstream::in);
    std::ofstream output("output.txt", std::ofstream::trunc);
    parseFile(input,output);
    input.close();
    output.close();
    
    std::ifstream outputCheck("output.txt", std::ofstream::in);
    std::stringstream buffer;
    buffer<<outputCheck.rdbuf();
    outputCheck.close();
    REQUIRE(buffer.str() == "2\n");
}

TEST_CASE("test 2, astrix", ""){
    std::stringstream input(
                            "5\n"
                            "2 1\n"
                            "2 3\n"
                            "2 4\n"
                            "2 5");
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() == "3\n");
}

TEST_CASE("test 3, line", ""){
    std::stringstream input(
            "10\n"
            "1 2\n"
            "2 3\n"
            "3 4 \n"
            "4 5\n"
            "1 6\n"
            "6 10\n"
            "10 9\n"
            "9 8\n"
            "8 7");
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() == "10\n");
}

TEST_CASE("T-shape", ""){
    std::stringstream input(
            "6\n"
            "3 1\n"
            "2 1\n"
            "2 6\n"
            "4 6\n"
            "2 5\n"
            );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() == "5\n");
}

TEST_CASE("Long branchy shape", ""){
    std::stringstream input(
            "19\n"
            "8 5\n"
            "1 2\n"
            "2 3\n"
            "4 5\n"
            "5 6\n"
            "6 7\n"
            "3 11\n"
            "5 13\n"
            "9 10\n"
            "10 11\n"
            "11 12\n"
            "12 19\n"
            "19 13\n"
            "13 14\n"
            "14 15\n"
            "10 16\n"
            "12 17\n"
            "14 18\n"
            );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() == "10\n");
}

TEST_CASE("2 separate figures", ""){
    std::stringstream input(
            "9\n"
            "2 1\n"
            "2 3\n"
            "2 4\n"
            "2 5\n"
            "6 7\n"
            "7 8\n"
            "8 9\n"
            );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() == "4\n");
}
