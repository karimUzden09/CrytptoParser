#pragma once
namespace runtime {
	auto constexpr STR_IS_EMTY = "Input string is emty Erore code ";
	auto constexpr SOC_NOT_FOUNT = "Socket no found Error code ";
	auto constexpr SENDER_NOT_FOUND = "Sender not found Error code ";
	auto constexpr ENCRIPT_PROVAIDER_NOT_FOUND = "Encript provider is not found Error code ";
	auto constexpr CRYPTO_SERVIS_NOT_FOUND = "Crypto servis is not found Eroor code ";



	enum Erros_Code {
		STR_EMTY,
		SOC_EMTY,
		SENDER_EMTY,
		EN_PR_NOT_FOUND,
		CR_SER_NOT_FOUND
	};
}