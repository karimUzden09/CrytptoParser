#include"BaseParser.hpp"
#include<map>
#include<iostream>
#include"BinaryTree.hpp"
#define DEBUG
using std::vector;
using std::string;
//using std::regex;
//using std::smatch;
//using std::map;
using std::multimap;
constexpr auto Expr_1_parser = "\\Socket\\s([a-zA-Z0-9_-]{1,})";
constexpr auto Expr_2_parser = ".Send\\((.*?)\\)";

//void insert_parse(std::string str) {
//	auto expr_1 =  parse_1(str);
//	for (auto&& var : expr_1) {
//		if (var.second.length()> 0) {
//			Tree::Brunch* main_tree = nullptr;
//			Tree::add(var.second, main_tree);
//			std::cout << "sock is founded" << std::endl;
//			auto test_2expresion = parse_2(var.second,str);
//			for (auto&& var : test_2expresion) {
//				if (var.second.length() > 0){
//					Tree::add(var.second,main_tree);
//				}
//			}
//#ifdef DEBUG
//			//print_map(test_2expresion);
//
//#endif // DEBUG
//
//			Tree::print(main_tree);
//			Tree::FreeTree(main_tree);
//		}
//		else
//		{
//			std::cout << "str is null" << std::endl;
//			return;
//		}
//	}
//	
//}
int main()
{

	string cs_text_impl_sock{ "Socket socA = new Socket(ipAddress.AddressFamily,SocketType.Stream, ProtocolType.Tcp);  socA.Send(M1enc);" };
	string cs_text_test{ "Socket socA = new Socket(ipAddress.AddressFamily,	SocketType.Stream, ProtocolType.Tcp);socA.Connect(remoteEP);RNGCryptoServiceProvider rng = new RNGCryptoServiceProvider();byte[] A = new byte[]{ 132, 114 };byte[] B = new byte[]{ 15, 245 };byte[] Na = new byte[64];rng.GetBytes(Na);byte[] M1 = new byte[2 + 64];Array.Copy(A, 0, M1, 0, A.Length);Array.Copy(Na, 0, M1, 2, Na.Length);//1byte[] M1enc;using (RSACryptoServiceProvider RSA = new RSACryptoServiceProvider()){RSA.ImportParameters(rsaPB.ExportParameters(false));M1enc = RSA.Encrypt(M1, true);}socA.Send(M1enc);//2byte[] MGet2Encr = new byte[256];socA.Receive(MGet2Encr);byte[] MGet2;using (RSACryptoServiceProvider RSA = new RSACryptoServiceProvider()){" };

	BaseParser Parse;
	//Parse.parse(cs_text_impl_sock);
	Parse.parse(cs_text_test);
	//insert_parse(cs_text_impl_sock);
	/*auto var = parse_1(cs_text_impl_sock);
	for (auto&& varible : var)
	{
		std::cout << varible.first << " : " << varible.second << std::endl;
	}

	Tree::Brunch* tree = nullptr;
	Tree::add(sometext, tree);
	Tree::print(tree);
	Tree::FreeTree(tree);*/


	//printer::print_map(res);

	//printer::pause();

	return 0;
	
}



