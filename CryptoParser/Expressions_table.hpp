#include<vector>
#include<string>
#pragma once
namespace RegularExpressions
{
	using string = std::string;
	using StringContainer = std::vector<string>;
	constexpr auto SOCK_PARSE_EXPRESSION_1 = "\\Socket\\s([a-zA-Z0-9_-]{1,})";

	constexpr auto SENDER_PARSE_EXPRESSION_1 = ".Send\\((.*?)\\)";

	constexpr auto ENCRYPT_BUFFER_EXPRESSION_1 = ".=.RSA.Encrypt\\((.*?)\\)";
	constexpr auto ENCRYPT_BUFFER_EXPRESSION_2 = ".=.RSA.Encrypt\\((.*?)\\,";
	constexpr auto ENCRYPT_BUFFER_EXPRESSION_3 = ".=.AES.Encrypt\\((.*?)\\,";

	constexpr auto CRYPTO_SERVIS_EXPRESSION_1 = "\\SRNGCryptoServiceProvider\\s([a-zA-Z0-9_-]{1,})";

	constexpr auto RUNDOM_BUFFER_EXPRESSION_1 = "\\.GetBytes\\((.*?)\\)";

	constexpr auto COPY_BUFFERS_EXPRESSION_1 = ".Array\\.Copy\\((.*?)\\)";
	constexpr auto BUFFERS_INFORMATION_EXPRESSION_1 = ".=";


	enum class RegularExprOptions
	{
		SOCKET_REGEXP,
		SENDER_REGEXP,
		ENCRIPT_REGEXP,
		RUNDOM_GENERATOR_OBJ_REGEXP,
		COPY_BUFFERS_REGEXP,
		BUFF_INFO_REGEXP
	};
	
	class RegularExpressions
	{
	public:
		const StringContainer SOCK_regexp_container{ SOCK_PARSE_EXPRESSION_1 };
		const StringContainer SENDER_regexp_container{ SENDER_PARSE_EXPRESSION_1 };
		const StringContainer Encrypt_buffer_expression_containers{ ENCRYPT_BUFFER_EXPRESSION_2,ENCRYPT_BUFFER_EXPRESSION_3 };
		const StringContainer Copy_buffer_expr_container{ COPY_BUFFERS_EXPRESSION_1 };
		const StringContainer Buff_info_expr_container{ BUFFERS_INFORMATION_EXPRESSION_1 };
		const StringContainer Crypto_srevice_provider_container{ CRYPTO_SERVIS_EXPRESSION_1 };
	private:

	};
}