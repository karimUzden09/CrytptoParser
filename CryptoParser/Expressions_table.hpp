#pragma once
namespace RegularExpressions
{
	constexpr auto SOCK_PARSE_EXPRESSION_1 = "\\Socket\\s([a-zA-Z0-9_-]{1,})";
	constexpr auto SENDER_PARSE_EXPRESSION_1 = ".Send\\((.*?)\\)";
	constexpr auto ENCRYPT_BUFFER_EXPRESSION_1 = ".=.RSA.Encrypt\\((.*?)\\)";
}