#include <iostream>
#include <random>

struct DBHandle
{
    std::string uri;
};

DBHandle * openConnection(const std::string & uri)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 1000); // distribution in range [1, 1000]

    if (dist(rng) == 1000) {
        return nullptr;
    }

    std::cout << "Open connection success\n";

    return new DBHandle{uri};
}


void closeConnection(DBHandle * handle)
{
    if (handle) {
        std::cout << "Close connection success\n";
        delete handle;
    }
}

int main()
{
    auto handle = openConnection("foobar");

    std::cout << "uri = " << handle->uri << std::endl;

    closeConnection(handle);

    return 0;
}
