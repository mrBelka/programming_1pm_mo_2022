#include <stdio.h>
#include <stdlib.h>
#include <sqlite3/sqlite3.h> 
#include <iostream>

static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char* argv[]) {
    sqlite3* db;
    char* zErrMsg = 0;
    int rc;

    /* Open database */
    rc = sqlite3_open("data.db", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    }
    else {
        fprintf(stderr, "Opened database successfully\n");
    }

    for (int i = 0; i < 1; i++)
    {
        std::string name, surname;
        std::cin >> name >> surname;
        /* Create SQL statement */
        std::string sql = "INSERT INTO students (name,surname) " \
            "VALUES ('" + name + "','" + surname + "');";

        std::cout << sql << std::endl;

        /* Execute SQL statement */
        rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
        else {
            fprintf(stdout, "Records created successfully\n");
        }
    }
    sqlite3_close(db);
    return 0;
}

/*#include <stdio.h>
#include <stdlib.h>
#include <sqlite3/sqlite3.h> 
#include <Windows.h>
#include <string>
#include <iostream>

class SQLite
{
private:
    std::string m_db_name;
    sqlite3* m_db;
    bool m_isOpen = false;

    static int callback(void* data, int argc, char** argv, char** azColName) {
        int i;
        fprintf(stderr, "%s: ", (const char*)data);

        for (i = 0; i < argc; i++) {
            printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        }

        printf("\n");
        return 0;
    }

public:
    SQLite(const std::string& db_name) : m_db_name(db_name)
    {

    }

    ~SQLite()
    {
        if(!m_isOpen)
            sqlite3_close(m_db);
    }

    void Open()
    {
        try
        {
            int rc = sqlite3_open("data.db", &m_db);

            if (rc) {
                fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(m_db));
            }
            else {
                m_isOpen = true;
                fprintf(stderr, "Opened database successfully\n");
            }
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    void Exec(const std::string& sql)
    {
        char* zErrMsg = 0;
        int rc = sqlite3_exec(m_db, sql.c_str(), callback, "111", &zErrMsg);

        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
        else {
            fprintf(stdout, "Operation done successfully\n");
        }
    }
};

int main(int argc, char* argv[]) {

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    SQLite s("data.db");
    
    s.Open();
    s.Exec("SELECT * FROM students");

    return 0;
}*/