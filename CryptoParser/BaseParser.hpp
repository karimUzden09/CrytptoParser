#pragma once
#include<string>
#include<vector>
#include"BinaryTree.hpp"
#include"Expressions_table.hpp"
using std::vector;
using std::string;

class BaseParser
{
public:
	BaseParser();
	vector<string> base_parse(const string& regular_expr, const string& input_str) const;
	vector<string> base_parse(const string& regular_expr, const string& input_str, const string& sock_token);
	void parse(const string& input_str);
	~BaseParser();
private:
	vector<string> sock_token_container;
	vector<string> sender_token_conatiner;
	vector<string> encript_buffer_container;
};

enum class ParseErrors
{
	SockNotFound = 1
};
