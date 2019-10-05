#include "BaseParser.hpp"
#include<iostream>
#include<regex>
using std::regex;
using std::smatch;

BaseParser::BaseParser()
{

}

vector<string> BaseParser::base_parse(const string& regular_expr, const string& input_str) const
{
	regex expr(regular_expr);
	smatch match;
	vector<string> resault;
	auto beg = input_str.cbegin();

	while (std::regex_search(beg, input_str.cend(), match, expr))
	{
		resault.push_back(match.str(1));
		beg = match.suffix().first;
	}
	return resault;
}

vector<string> BaseParser::base_parse(const string& regular_expr, const string& input_str, const string& sock_token)
{
	regex expr(sock_token +regular_expr);
	smatch match;
	vector<string> resault;
	auto beg = input_str.cbegin();

	while (std::regex_search(beg, input_str.cend(), match, expr))
	{
		resault.push_back(match.str(1));
		beg = match.suffix().first;
	}
	return resault;
	return vector<string>();
}

void BaseParser::parse(const string& input_str)
{
	sock_token_container = base_parse(RegularExpressions::SOCK_PARSE_EXPRESSION_1,input_str);
	Tree::Brunch* maintree = nullptr;
	if (!sock_token_container.empty())
	{
		for (auto& sock_token : sock_token_container) {
			Tree::add(sock_token, maintree);
			sender_token_conatiner = base_parse(RegularExpressions::SENDER_PARSE_EXPRESSION_1, input_str, sock_token);
			if (!sender_token_conatiner.empty())
			{
				Tree::add(sender_token_conatiner[0], maintree);
				sender_token_conatiner = base_parse(RegularExpressions::ENCRYPT_BUFFER_EXPRESSION_1, input_str, sender_token_conatiner[0]);
				Tree::add(sender_token_conatiner[0],maintree);
			}

			else
			{
				std::cout << "Sender is not found" << std::endl;
			}
		}
	}
	else
	{
		std::cout << "Socked is not found Error " << static_cast<int32_t>(ParseErrors::SockNotFound) <<std::endl;
	}
	Tree::print(maintree);
	Tree::FreeTree(maintree);
}

BaseParser::~BaseParser()
{
}
