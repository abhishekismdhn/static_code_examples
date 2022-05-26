/*
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

*/
#include <string>
#include <map>
#include <iostream>
#include <cstring>

struct AsxOrder
{
    char orderOrigin[4];
    char orderCapacity;
    char reserved;
    short reserved2;
};

void accessOrder()
{
    unsigned char buf[8];
    memset(buf, 0, sizeof(buf));
    buf[0] = 'F';
    buf[1] = 'F';
    buf[2] = 'F';
    buf[3] = 'F';
    buf[4] = 'P';
    const AsxOrder* asxOrder = reinterpret_cast<AsxOrder*>(buf);

    std::map<std::string, std::string> m;
    m["order_origin"] = asxOrder->orderOrigin;
    m["order_capacity"] = std::string(asxOrder->orderCapacity, sizeof(asxOrder->orderCapacity));

    std::cout << "origin: " << m.at("order_origin") << std::endl;
    std::cout << "capacity: " << m.at("order_capacity") << std::endl;
}

int main()
{
    accessOrder();
    return 0;
}
