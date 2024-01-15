#include <iostream>
#include "SQLiteCpp/Database.h"

int main() {
    try
    {

        // Open a database file
        SQLite::Database    db("LibCat.sqlite");
        SQLite::Statement query {db, "SELECT 1"};

        while (query.executeStep())
        {
            // Demonstrate how to get some typed column value
            int         result      = query.getColumn(0);

            std::cout << "row: " << result << std::endl;
        }
    }
    catch (std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
    }
    return 0;
}
