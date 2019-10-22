#include<iostream>
#include<regex>
#include<memory>
#include"EroorsTable.hpp"
#include "BaseParser.hpp"
using std::regex;
using std::smatch;
namespace re = runtime;

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

vector<string> BaseParser::base_parse(const string& regular_expr, const string& input_str, const string& sock_token) const
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
}


vector<string> BaseParser::findeNA(const string& rngToken, const string& input_str) const
{
	regex expr("." + rngToken + "\\.GetBytes\\((.*?)\\)");
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

void BaseParser::parse(const string& input_str)
{
	sock_token_container = base_parse(RegularExpressions::SOCK_PARSE_EXPRESSION_1,input_str);
	Tree::Brunch* maintree = nullptr;
	if (!sock_token_container.empty())
	{
		for (const auto& sock_token : sock_token_container) {
			Tree::add(sock_token, maintree);
			sender_token_conatiner = base_parse(RegularExpressions::SENDER_PARSE_EXPRESSION_1, input_str, sock_token);
			if (!sender_token_conatiner.empty())
			{
				for (const auto& sender_token : sender_token_conatiner)
				{
					Tree::add(sender_token, maintree);
					encript_buffer_container = base_parse(RegularExpressions::ENCRYPT_BUFFER_EXPRESSION_1, input_str, sender_token);
					if (!encript_buffer_container.empty())
					{
						//Tree::add(encript_buffer_container[0], maintree);
						for (const auto& buffer_token : encript_buffer_container)
						{
							Tree::add(buffer_token, maintree);
							auto crypto_provider = find_crypto_provider(input_str);
							if (crypto_provider!= std::nullopt)
							{
								NaContainer =  findeNA(crypto_provider.value(), input_str);
								Tree::add(NaContainer[0], maintree);
							}

						}
					}
				}
				
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

void BaseParser::parse_v2(const string& input_str)
{
	if (!input_str.empty())
	{
		finde_sock_tokens(input_str);
		mainTree.get()->print_tree();
	}
	else
	{
		printer::_println(re::STR_IS_EMTY, re::STR_EMTY);
	}
}

BaseParser::~BaseParser()
{
}

std::optional<string> BaseParser::find_crypto_provider(const string& input_str)
{
	crypto_servis_token_container = base_parse(RegularExpressions::CRYPTO_SERVIS_EXPRESSION_1, input_str);
	if (!crypto_servis_token_container.empty())
	{
		return crypto_servis_token_container[0];
	}
	return std::nullopt;
}

inline void BaseParser::verefication(const std::string& token, const const string& input_str)
{
	sender_token_conatiner = base_parse(RegularExpressions::SENDER_PARSE_EXPRESSION_1, input_str,token);
	if (!sender_token_conatiner.empty())
	{
		
	}
	else
	{
		printer::_println(re::SENDER_NOT_FOUND, re::SENDER_EMTY);
	}

}

void BaseParser::finde_sock_tokens(ConstStr& str)
{
	sock_token_container = base_parse(RegularExpressions::SOCK_PARSE_EXPRESSION_1, str);
	if (!sock_token_container.empty())
	{
		mainTree = std::make_unique<RAIbTree>();
		for (const auto& sock_token : sock_token_container)
		{
			mainTree.get()->add_data(sock_token);
			finde_sender_tokens(str, sock_token);
		}
	}
	else
	{
		printer::_println(re::SOC_NOT_FOUNT, re::SOC_EMTY);
	}
}

void BaseParser::finde_sender_tokens(ConstStr& str,ConstStr& sock_token)
{
	sender_token_conatiner = base_parse(RegularExpressions::SENDER_PARSE_EXPRESSION_1, str, sock_token);
	if (!sender_token_conatiner.empty())
	{
		for (const auto sender_token : sender_token_conatiner)
		{
			mainTree.get()->add_data(sender_token);
			finde_encript_tokens(str, sender_token);
		}
	}
	else
	{
		printer::_println(re::SOC_NOT_FOUNT, re::SOC_EMTY);
	}
}

void BaseParser::finde_encript_tokens(ConstStr& str, ConstStr& sender_token)
{
	encript_buffer_container = base_parse(RegularExpressions::ENCRYPT_BUFFER_EXPRESSION_1, str, sender_token);
	if (!encript_buffer_container.empty())
	{
		for (const auto& encript_token : encript_buffer_container)
		{
			mainTree.get()->add_data(encript_token);
		}
		finde_cryptoprovider_v2(str);
	}
	else
	{
		printer::_println(re::ENCRIPT_PROVAIDER_NOT_FOUND, re::EN_PR_NOT_FOUND);
	}
}

void BaseParser::finde_cryptoprovider_v2(ConstStr& str)
{
	crypto_servis_token_container = base_parse(RegularExpressions::CRYPTO_SERVIS_EXPRESSION_1, str);
	if (!crypto_servis_token_container.empty())
	{
		for (const auto& crypto_toke : crypto_servis_token_container)
		{
			random_buffer_token_container = finde_random_buffer_container(crypto_toke, str);
			for (const auto& r_buf_token : crypto_servis_token_container) {
				mainTree.get()->add_data(r_buf_token);
			}
		}
	}
	else
	{
		printer::_println(re::CRYPTO_SERVIS_NOT_FOUND, re::CR_SER_NOT_FOUND);
	}
}

StrContainer BaseParser::finde_random_buffer_container(ConstStr& rngToken, ConstStr& str) const
{
	regex expr("." + rngToken + RegularExpressions::RUNDOM_BUFFER_EXPRESSION_1);
	smatch match;
	vector<string> resault;
	auto beg = str.cbegin();

	while (std::regex_search(beg, str.cend(), match, expr))
	{
		resault.push_back(match.str(1));
		beg = match.suffix().first;
	}
	return resault;
}
