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
	void parse_v2(ConstStr& input_str);
	~BaseParser();
private:
	StrContainer sock_token_container;
	StrContainer sender_token_conatiner;
	StrContainer encript_buffer_container;
	StrContainer crypto_servis_token_container;
	StrContainer random_buffer_token_container;
	std::unique_ptr<RAIbTree> mainTree;
	std::vector<BtreePtr> bTrees;
	StrContainer base_parse(ConstStr& regular_expr, ConstStr& input_str) const;
	StrContainer base_parse(ConstStr& regular_expr, ConstStr& input_str, ConstStr& sock_token) const;
	StrContainer findeNA(ConstStr& rngToken, ConstStr& input_str) const;
	void finde_sock_tokens(ConstStr& str);
	void finde_sender_tokens(ConstStr& str,ConstStr& sock_token);
	void finde_encript_tokens(ConstStr& str, ConstStr& sender_token);
	void finde_cryptoprovider_v2(ConstStr& str);
	StrContainer finde_random_buffer_container(ConstStr& rngToken,ConstStr& str) const;
};


