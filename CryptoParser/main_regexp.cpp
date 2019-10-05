#include"BaseParser.hpp"
#include<iostream>
#include"BinaryTree.hpp"
#define DEBUG
using std::vector;
using std::string;
constexpr auto Expr_1_parser = "\\Socket\\s([a-zA-Z0-9_-]{1,})";
constexpr auto Expr_2_parser = ".Send\\((.*?)\\)";

int main()
{

	string cs_text_impl_sock{ "Socket socA = new Socket(ipAddress.AddressFamily,SocketType.Stream, ProtocolType.Tcp);  socA.Send(M1enc);" };
	string cs_text_test{ "Socket socA = new Socket(ipAddress.AddressFamily,	SocketType.Stream, ProtocolType.Tcp);socA.Connect(remoteEP);RNGCryptoServiceProvider rng = new RNGCryptoServiceProvider();byte[] A = new byte[]{ 132, 114 };byte[] B = new byte[]{ 15, 245 };byte[] Na = new byte[64];rng.GetBytes(Na);byte[] M1 = new byte[2 + 64];Array.Copy(A, 0, M1, 0, A.Length);Array.Copy(Na, 0, M1, 2, Na.Length);//1byte[] M1enc;using (RSACryptoServiceProvider RSA = new RSACryptoServiceProvider()){RSA.ImportParameters(rsaPB.ExportParameters(false));M1enc = RSA.Encrypt(M1, true);}socA.Send(M1enc);//2byte[] MGet2Encr = new byte[256];socA.Receive(MGet2Encr);byte[] MGet2;using (RSACryptoServiceProvider RSA = new RSACryptoServiceProvider()){" };

	BaseParser Parse;
	//Parse.parse(cs_text_impl_sock);
	Parse.parse(cs_text_test);

	return 0;
	
}



