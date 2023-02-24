#include <array>
#include <iostream>
#include <memory>
#include <regex>
#include <unistd.h>

void clear() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// https://stackoverflow.com/a/64889432
std::string execute_command(std::string cmd) {
    std::array<char, 128> buffer;
    std::string result;

#if defined(_WIN32)
#define POPEN  _popen
#define PCLOSE _pclose
#elif defined(unix) || defined(__unix__) || defined(__unix)
#define POPEN  popen
#define PCLOSE pclose
#endif

    std::unique_ptr<FILE, decltype(&PCLOSE)>
        pipe(POPEN(cmd.c_str(), "r"), PCLOSE);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get())
            != nullptr) {
        result += buffer.data();
    }
    return result;
}

std::string getUserName() {
#if defined(_WIN32)
// whoami works on windows as well but it returns the name
// in the format of `computer_name\user_name` so instead
// we use %USERNAME% which gives us the exact username.
#define USERNAME_QUERY "echo %USERNAME%"
#elif defined(unix) || defined(__unix__) || defined(__unix)
#define USERNAME_QUERY "whoami"
#endif
    auto username = execute_command(USERNAME_QUERY);
    // this line removes the white spaces (such as newline, etc)
    // from the username.
    username = std::regex_replace(username, std::regex("\\s"), "");
    return username;
}
