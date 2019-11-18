#pragma once
#include"BaseParser.hpp"
#include<optional>
#include<map>

enum class Var_typese
{
	Socket,
	Buffers,
	Senders
};


using buff_types = string;

class Test_parser
{
public:
	Test_parser();

	StrContainer base_parse(ConstStr& regular_expr, ConstStr& input_str);
	StrContainer base_parse(ConstStr& regular_expr, ConstStr& input_str, ConstStr& sock_token);
	std::optional<StrContainer> modern_parser(const RegularExpressions::RegularExpressions& regex,
		RegularExpressions::RegularExprOptions option, ConstStr& input_str);
	void parse(const std::string& text);
	StrContainer modern_base_parser(const StrContainer& regex_container,

		ConstStr& input_str);

	StrContainer modern_base_parser(const StrContainer& regex_container,
		ConstStr& input_str, ConstStr& sock_token);
	vector< StrContainer > copy_spit(const StrContainer& vec);

	std::optional<std::vector< std::map<size_t, std::string> > > make_buff_tree
	(const std::vector<std::vector<std::string>>& copy_tokens);

	

	~Test_parser();

private:
	std::multimap< buff_types, string > make_buff_types(const std::vector< std::map<size_t, std::string> >& buff_tree, const string& input_str);
	void finde_cryptoprovider_v2(ConstStr& str);

	StrContainer crypto_servis_token_container;
	StrContainer sock_token_conteiner;
	StrContainer sender_token_conteiner;
	StrContainer encripter_token_container;
	StrContainer copy_buffers_container;
	std::vector<StrContainer> Tokens;
};

template<class T>
size_t types_caster(T var);
template<class T>
inline size_t types_caster(T var)
{
	return static_cast<size_t>(var);
}
