//
// connection.cpp
// ~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2017 Gavin Hurlbut (gjhurlbu@gmail.com)
//

#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main()
{
    try
    {
        boost::asio::io_service io_service;

        tcp::endpoint endpoint(tcp::v4(), 7001);
        tcp::acceptor acceptor(io_service, endpoint);

        for (;;)
        {
            tcp::iostream stream;
            boost::system::error_code ec;
            acceptor.accept(*stream.rdbuf(), ec);
            if (!ec)
            {
                stream << "Output";
            }
        }
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}