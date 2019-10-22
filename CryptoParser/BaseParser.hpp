#pragma once
#include<string>
#include<vector>
#include"BinaryTree.hpp"
#include"Expressions_table.hpp"
#include<optional>
#include<print_v.001/print_min_lib.hpp>
#include<memory>
using std::vector;
using std::string;
using RAIbTree = TreeV2::Btree;
using BtreePtr = std::unique_ptr<RAIbTree>;
using ConstStr = const std::string;
using StrContainer = std::vector<std::string>;
class BaseParser
{
public:
	BaseParser();
	void parse(const string& input_str);
	void parse_v2(const string& input_str);
	~BaseParser();
private:
	vector<string> sock_token_container;
	vector<string> sender_token_conatiner;
	vector<string> encript_buffer_container;
	vector<string> crypto_servis_token_container;
	vector<string> NaContainer;
	StrContainer random_buffer_token_container;
	std::optional<string> find_crypto_provider(const string& input_str);
	inline void verefication(const std::string& token,const const string& input_str);
	std::unique_ptr<RAIbTree> mainTree;
	std::vector<BtreePtr> bTrees;
	vector<string> base_parse(const string& regular_expr, const string& input_str) const;
	vector<string> base_parse(const string& regular_expr, const string& input_str, const string& sock_token) const;
	vector<string> findeNA(const string& rngToken, const string& input_str) const;
	void finde_sock_tokens(ConstStr& str);
	void finde_sender_tokens(ConstStr& str,ConstStr& sock_token);
	void finde_encript_tokens(ConstStr& str, ConstStr& sender_token);
	void finde_cryptoprovider_v2(ConstStr& str);
	StrContainer finde_random_buffer_container(ConstStr& rngToken,ConstStr& str) const;
};

enum class ParseErrors
{
	SockNotFound = 1
};


