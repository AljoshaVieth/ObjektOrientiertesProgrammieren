//
// Created by Aljosha on 01.06.2021.
//
#include <string>
#include <iostream>
#include <cassert>
#include <map>
#include <fstream>
#include <bits/unique_ptr.h>


namespace hfu {


    /**
     * This function should return the nth index of an occurrence in a text. If nothing is found, -1 is returned
     * @param text the given text to investigate
     * @param search_param the text to find
     * @param n the soMany appearance of search-param in text
     * @return the index of the nth occurrence of search_param in text
     */
    int find_nth_index(const std::string &text, const std::string &search_param, const int &n) {
        if (n <= 0) {
            throw std::invalid_argument("n has to be more than 0");
        }
        int pos = 0;
        int iterations = 0;
        //TODO check if n < 0
        while (iterations < n) {
            pos = text.find(search_param, pos + 1);
            // if nothing is found (pos=-1) return -1 to prevent unnecessary operations.
            if (pos == -1) {
                return -1;
            }
            iterations++;
        }
        return pos;
    }

    void find_nth_index_test() {
        std::string text = "hello-hfu-how-are-you";
        std::string search_param = "-";
        assert(find_nth_index(text, search_param, 1) == 5);
        assert(find_nth_index(text, search_param, 2) == 9);
        assert(find_nth_index(text, search_param, 15) == -1);
        search_param = "-h";
        assert(find_nth_index(text, search_param, 2) == 9);
        assert(find_nth_index(text, search_param, 3) == -1);
        search_param = "xyz";
        assert(find_nth_index(text, search_param, 1) == -1);
        try {
            assert(find_nth_index(text, search_param, 0) == 5);
            assert(false);
        }
        catch (...) {
        }
    }

    std::string extract_airline(const std::string &text) {
        int column_of_airline_in_data = 9;
        std::string separator_in_data = ",";
        int index_of_airline_in_text = find_nth_index(text, separator_in_data, column_of_airline_in_data);
        return text.substr(index_of_airline_in_text + 2, 2);
    }

    void extract_airline_test() {
        // clang-tidy recommends a raw-string
        std::string test_data = R"(2013,1,1,542,540,2,923,850,33,"AA",1141,"N619AA","JFK","MIA",160,1089,5,40,2013-01-01 05:00:00)";
        assert(extract_airline(test_data) == "AA");
        test_data = R"(2013,1,1,517,515,2,830,819,11,"UA",1545,"N14228","EWR","IAH",227,1400,5,15,2013-01-01 05:00:00)";
        assert(extract_airline(test_data) == "UA");
        test_data = R"(2013,1,1,848,1835,853,1001,1950,851,"MQ",3944,"N942MQ","JFK","BWI",41,184,18,35,2013-01-01 18:00:00)";
        assert(extract_airline(test_data) == "MQ");
    }


    std::unique_ptr<std::map<std::string, int>> create_frequencies(const std::string &filename) {
       auto frequencies = std::make_unique< std::map<std::string, int> >();
        //std::map<std::string, int> frequencies;
        std::ifstream in(filename);
        assert(in.is_open());
        std::string line;
        in >> line; // skip first line;
        while (in >> line) {
            if (line.length() > 40) { // filter corrupted lines (somehow, in sees space as a new line)
                (*frequencies)[extract_airline(line)] += 1;
            }
        }
        in.close();
        return frequencies;
    }

    void create_frequencies_test() {
        std::string filename = "D:/Programming/HFU/MIB 6/OOP/09/flights.csv";
        auto airlines = create_frequencies(filename);
         assert(airlines->find("AA")->second ==32729);
        int size = airlines->size();
        std::cout << size << std::endl;
    }


}

int main() {

    std::cout << "starting" << std::endl;
    hfu::find_nth_index_test();
    std::cout << "find_nth_index_test passed" << std::endl;
    hfu::extract_airline_test();
    std::cout << "find_airline_test passed" << std::endl;
    hfu::create_frequencies_test();
    std::cout << "create_frequencies_test passed" << std::endl;
    std::cout << "terminating" << std::endl;
    return 0;
}

