#include"BaseParser.hpp"
int main()
{
	string cs_text_test{ "Socket socA = new Socket(ipAddress.AddressFamily,	SocketType.Stream, ProtocolType.Tcp);socA.Connect(remoteEP);RNGCryptoServiceProvider rng = new RNGCryptoServiceProvider();byte[] A = new byte[]{ 132, 114 };byte[] B = new byte[]{ 15, 245 };byte[] Na = new byte[64];rng.GetBytes(Na);byte[] M1 = new byte[2 + 64];Array.Copy(A, 0, M1, 0, A.Length);Array.Copy(Na, 0, M1, 2, Na.Length);//1byte[] M1enc;using (RSACryptoServiceProvider RSA = new RSACryptoServiceProvider()){RSA.ImportParameters(rsaPB.ExportParameters(false));M1enc = RSA.Encrypt(M1, true);}socA.Send(M1enc);//2byte[] MGet2Encr = new byte[256];socA.Receive(MGet2Encr);byte[] MGet2;using (RSACryptoServiceProvider RSA = new RSACryptoServiceProvider()){" };
	BaseParser Parse_v2;
	Parse_v2.parse_v2(cs_text_test);

	return 0;
	
}



