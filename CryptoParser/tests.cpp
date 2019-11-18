
#include "tests.hpp"
#include<regex>
#include<array>
#include<boost/algorithm/string.hpp>
#include<fmt/printf.h>
#include<algorithm>
#include<boost/lexical_cast.hpp>
#define MAKE_BUFF_TREES_FUNC_DEBUG
#define PRINT_BUFFER_TYPES
//#define USE_RANGES_V3

#ifdef USE_RANGES_V3
#include<range/v3/all.hpp>
#endif // USE_RANGES_V3

StrContainer Test_parser::base_parse(ConstStr& regular_expr, ConstStr& input_str)
{
	using namespace std;
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

StrContainer Test_parser::base_parse(ConstStr& regular_expr, ConstStr& input_str, ConstStr& sock_token)
{
	using namespace std;
	regex expr(sock_token + regular_expr);
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

std::optional<StrContainer>Test_parser::modern_parser(const RegularExpressions::RegularExpressions& regex,
	RegularExpressions::RegularExprOptions option, ConstStr& input_str)
{
	using namespace std;
	using Regular_Exp_opt = RegularExpressions::RegularExprOptions;

	if (option == Regular_Exp_opt::SOCKET_REGEXP)
	{
		sock_token_conteiner = modern_base_parser(regex.SOCK_regexp_container, input_str);
		if (!sock_token_conteiner.empty())
		{

			return (sock_token_conteiner);
		}
		else
		{
			printer::_println("Socckets is not found");
			return (std::nullopt);
		}
	}
	else if (option == Regular_Exp_opt::SENDER_REGEXP)
	{
		for (const auto& sock_token : sock_token_conteiner)
		{
			sender_token_conteiner = modern_base_parser(regex.SENDER_regexp_container, input_str, sock_token);
		}
		if (!sender_token_conteiner.empty())
		{
			return(sender_token_conteiner);
		}
		else
		{
			printer::_println("Sender is not found");
			return (std::nullopt);
		}
		
		
	}
	else if (option == Regular_Exp_opt::ENCRIPT_REGEXP)
	{
		for (const auto& sender_token : sender_token_conteiner)
		{
			encripter_token_container = modern_base_parser(regex.Encrypt_buffer_expression_containers, input_str, sender_token);
		}
		if (!encripter_token_container.empty())
		{
			return(encripter_token_container);
		}
		else
		{
			printer::_println("Encriter buffer is not found");
			return (std::nullopt);
		}
	}

	else if (option == Regular_Exp_opt::COPY_BUFFERS_REGEXP)
	{
		copy_buffers_container = modern_base_parser(regex.Copy_buffer_expr_container, input_str);
		if (!copy_buffers_container.empty())
		{
			return copy_buffers_container;
		}
		else
		{
			printer::_println("Copy buffers is not found");
			return (std::nullopt);
		}
	}

	else
	{
		printer::_println("Option is not found");
		return(std::nullopt);
	}
}

void Test_parser::parse(const std::string& text)
{
	RegularExpressions::RegularExpressions reg;
	auto sockets_tokens = modern_parser(reg, RegularExpressions::RegularExprOptions::SOCKET_REGEXP, text);
	if (sockets_tokens!=std::nullopt)
	{
		printer::print_range_v3(sockets_tokens.value());
	}
	else
	{
		printer::_println("sock tokens not found");
	}

	auto sender_tokens = modern_parser(reg, RegularExpressions::RegularExprOptions::SENDER_REGEXP, text);
	if (sender_tokens != std::nullopt)
	{
		printer::print_range_v3(sender_tokens.value());
	}
	else
	{
		printer::_println("senders is not found");
	}
	auto encrypter_tokens = modern_parser(reg, RegularExpressions::RegularExprOptions::ENCRIPT_REGEXP, text);
	if (encrypter_tokens != std::nullopt)
	{
		printer::print_range_v3(encrypter_tokens.value());
	}
	else
	{
		printer::_println("Ecrypt tokens is not found");
	}
	auto copy_tokens = modern_parser(reg,RegularExpressions::RegularExprOptions::COPY_BUFFERS_REGEXP, text);
	if (copy_tokens != std::nullopt)
	{
		
		auto test_split = copy_spit(copy_tokens.value());
		auto test_buffers_tree = make_buff_tree(test_split);
		if (test_buffers_tree != std::nullopt)
		{
			auto buffer_tree = test_buffers_tree.value();

			auto buffer_types = make_buff_types(buffer_tree, text);


#ifdef PRINT_BUFFER_TYPES
			auto print_map = [](std::pair<string, string> p) {
				fmt::print("{} : {}\n", p.first, p.second);
			};

#ifdef USE_RANGES_V3
			fmt::print("Buffer types\n");
			ranges::for_each(buffer_types, print_map);
			fmt::print("Buffer tree is end size of Buffer types: {}\n", buffer_types.size());
#endif // USE_RANGES_V3


				//fmt::print("Buffer types\n");
				std::for_each(buffer_types.cbegin(), buffer_types.cend(), print_map);
				//fmt::print("Buffer tree is end size of Buffer types: {}\n", buffer_types.size());

#endif // PRINT_BUFFER_TYPES


		}
	}
	else
	{
		printer::_println("copy tokens is not found");
	}

}

void finde_all_varibles(const std::string& text)
{
}

StrContainer Test_parser::modern_base_parser(const StrContainer & regex_container, ConstStr& input_str)
{
	using namespace std;
	vector<string> resault;
	for (const auto& var : regex_container) {
		std::regex expr(var);
		smatch match;
		auto beg = input_str.cbegin();

		while (std::regex_search(beg, input_str.cend(), match, expr))
		{
			resault.push_back(match.str(1));
			beg = match.suffix().first;
		}
	}

	return (resault);
}

StrContainer Test_parser::modern_base_parser(const StrContainer& regex_container, ConstStr& input_str, ConstStr& sock_token)
{
	using namespace std;

	vector<string> resault;
	for (const auto& var : regex_container) {
		std::regex expr(sock_token+var);
		smatch match;
		auto beg = input_str.cbegin();

		while (std::regex_search(beg, input_str.cend(), match, expr))
		{
			resault.push_back(match.str(1));
			beg = match.suffix().first;
		}
	}

	return (resault);
}

vector< StrContainer> Test_parser::copy_spit(const StrContainer& vec)
{
	vector<StrContainer> copy_container;
	StrContainer resault; resault.reserve(100);
	string str;
		for (const auto& var : vec) {

			boost::split(resault, var, boost::is_any_of(" "));
			boost::split(resault, var, boost::is_any_of(","));
			copy_container.push_back(resault);
		}
	
	return (copy_container);
}



std::optional<std::vector<std::map<size_t, std::string>>> Test_parser::make_buff_tree(const std::vector<std::vector<std::string>>& copy_tokens)
{
	

	std::vector<std::string> main_tokens;
	main_tokens.reserve(20);
	for (const auto& var : copy_tokens)
	{
		main_tokens.push_back(var[2]);
	}
	main_tokens.erase(std::unique(main_tokens.begin(), main_tokens.end()), main_tokens.end());

	std::map<size_t, std::string> buff_tree;
	std::vector< std::map<size_t, std::string> > buff_trees_vector;
	const auto main_tokens_size = main_tokens.size();
	if (main_tokens_size == 0)
	{
		return (std::nullopt);
	}
	else
	{
		buff_trees_vector.reserve(main_tokens_size);
		size_t count = 0;
		for (size_t i = 0; i < main_tokens_size; i++)
		{
			for (const auto& vec_tokens : copy_tokens)
			{
				if (vec_tokens[2] == main_tokens[i])
				{
					buff_tree.insert(std::make_pair(count, vec_tokens[2]));
					count++;
					buff_tree.insert(std::make_pair(count, vec_tokens[0]));
				}
			}
			buff_trees_vector.push_back(buff_tree);
			count = 0;
			buff_tree.clear();
		}
#ifdef MAKE_BUFF_TREES_FUNC_DEBUG
		auto print_map = [](std::pair<size_t, string> p) {
			fmt::print("{} : {}\n", p.first, p.second);
		};

#ifdef USE_RANGES_V3
		fmt::print("Buffer tree\n");
		for (const auto& var : buff_trees_vector) {
			ranges::for_each(var, print_map);
			fmt::print("____________\n");
		}
		fmt::print("Buffer tree is end size of Buffer tree: {}\n", buff_trees_vector.size());
#endif // USE_RANGES_V3
		//fmt::print("Buffer tree\n");
		for (const auto& var : buff_trees_vector) {
			std::for_each(var.cbegin(),var.cend(), print_map);
			fmt::print("____________\n");
		}
		//fmt::print("Buffer tree is end size of Buffer tree: {}\n", buff_trees_vector.size());
#endif // MAKE_BUFF_TREES_FUNC_DEBUG

		return (buff_trees_vector);
	}
}

Test_parser::~Test_parser()
{
}

std::multimap<buff_types, string> Test_parser::make_buff_types(const std::vector<std::map<size_t, std::string>>& buff_tree, const string& input_str )
{
	using namespace std;
	const string Rand_type = "RANDOM ";
	const string Deafult_var = "Deafult varible ";
	std::multimap<buff_types, string> m_resault;
	vector<string> rund_resault;
	size_t count = 0;
	RegularExpressions::RegularExpressions reg;
	crypto_servis_token_container = modern_base_parser(reg.Crypto_srevice_provider_container, input_str);
	
	for (const auto& var : crypto_servis_token_container)
	{
		
			regex expr("." + var + RegularExpressions::RUNDOM_BUFFER_EXPRESSION_1);
			smatch match;
			auto beg = input_str.cbegin();

			while (std::regex_search(beg, input_str.cend(), match, expr))
			{
				rund_resault.push_back(match.str(1));
				beg = match.suffix().first;
			}
	}

	for (const auto& tokens : buff_tree)
	{
		for (const auto& maps : tokens)
		{
			for (const auto& rund_token:rund_resault)
			{
				if (rund_token == maps.second)
				{
					m_resault.insert(make_pair(Rand_type, maps.second));
				}
				else
				{
					m_resault.insert(make_pair(Deafult_var, maps.second));
				}
			}
		}
		
	}
	

		
	return (m_resault);
	
}

void Test_parser::finde_cryptoprovider_v2(ConstStr& str)
{


}

Test_parser::Test_parser()
{
}
