// wsltst.cpp : 애플리케이션의 진입점을 정의합니다.
//

#include "wsltst.h"
#include <boost/asio.hpp>

using namespace std;

int main()
{
	boost::asio::io_service io_service;
	boost::asio::ip::tcp::socket socket(io_service);
	boost::asio::ip::tcp::resolver resolver(io_service);
	boost::asio::ip::tcp::resolver::query query("httpbin.org", "http");
	boost::asio::ip::tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
	boost::asio::connect(socket, endpoint_iterator);
	boost::asio::write(socket, boost::asio::buffer("GET /get HTTP/1.0\r\n\r\n"));

	boost::asio::streambuf response;
	boost::asio::read_until(socket, response, "\r\n");

	std::string http_version;
	std::istream response_stream(&response);
	response_stream >> http_version;
	unsigned int status_code;
	response_stream >> status_code;
	std::string status_message;
	std::getline(response_stream, status_message);

	if (!response_stream.eof())
	{
		boost::asio::read_until(socket, response, "\r\n\r\n");
	}

	std::string response_data = boost::asio::buffer_cast<const char*>(response.data());
	std::cout << response_data << std::endl;
	return 0;
}
