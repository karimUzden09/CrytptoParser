
//#include"BaseParser.hpp"
#include"tests.hpp"
#include<fstream>
#include<fmt/printf.h>

std::string readFile(const std::string& fileName) {
	std::ifstream f(fileName);
	f.seekg(0, std::ios::end);
	size_t size = f.tellg();
	std::string s(size, ' ');
	f.seekg(0);
	f.read(&s[0], size); 
	return s;
}
int main()
{
	string cs_text_test{ "Socket socA = new Socket(ipAddress.AddressFamily,	SocketType.Stream, ProtocolType.Tcp);socA.Connect(remoteEP);RNGCryptoServiceProvider rng = new RNGCryptoServiceProvider();byte[] A = new byte[]{ 132, 114 };byte[] B = new byte[]{ 15, 245 };byte[] Na = new byte[64];rng.GetBytes(Na);byte[] M1 = new byte[2 + 64];Array.Copy(A, 0, M1, 0, A.Length);Array.Copy(Na, 0, M1, 2, Na.Length);//1byte[] M1enc;using (RSACryptoServiceProvider RSA = new RSACryptoServiceProvider()){RSA.ImportParameters(rsaPB.ExportParameters(false));M1enc = RSA.Encrypt(M1, true);}socA.Send(M1enc);//2byte[] MGet2Encr = new byte[256];socA.Receive(MGet2Encr);byte[] MGet2;using (RSACryptoServiceProvider RSA = new RSACryptoServiceProvider()){" };
	string cs_text_test2 = readFile("test.cs");
	//BaseParser Parse_v2;
	//Parse_v2.parse_v2(cs_text_test);
	//std::getline(file, cs_text_test2);
	
	//fmt::print("{}\n", cs_text_test2);
	
	Test_parser test;
	test.parse(cs_text_test2);
	return 0;
	
}
