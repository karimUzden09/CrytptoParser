//#include<boost/spirit/include/qi.hpp>
//#include<string>
//#include<iostream>
//#include"interpritator.hpp"
////using namespace boost::spirit;
//
//template<class Iterator>
//struct calculator_simple:qi::grammar<Iterator>
//{
//	calculator_simple()
//		:calculator_simple::base_type(expression)
//	{
//		expression = term >> *('+' >> term | '-' >> term);
//
//		term = factor >> *('*' >> factor | '/' >> factor);
//		
//		factor = qi::uint_| '(' >> expression >> ')'| '+' >> factor| '-' >> factor;
//	}
//	qi::rule<Iterator> expression, term, factor;
//};
////
////template<class Iterator>
////struct simple_grammer : qi::grammar<Iterator>
////{
////	simple_grammer() :simple_grammer::base_type(expr)
////	{
////		expr = term >>'+'>> exp | term;
////		//expr = num;
////		term = factor >> '*' >> term | factor;
////		factor = '(' >> expr >> ')' | num;
////		num = qi::int_;
////	}
////	qi::rule<Iterator> expr, num,factor ,term;
////};
//
//int main()
//{
//	/*std::cout << "Welcome to the expression parser!\n\n";
//	std::cout << "Type an expression or [q or Q] to quit\n\n";
//
//	typedef std::string     str_t;
//	typedef str_t::iterator str_t_it;
//
//	str_t expression;
//
//	calculator_simple<str_t_it> calc;
//
//	while (true)
//	{
//		std::getline(std::cin, expression);
//		if (expression == "q" || expression == "Q") break;
//		str_t_it begin = expression.begin(), end = expression.end();
//
//		bool success = qi::parse(begin, end, calc);
//
//		std::cout << "---------------------\n";
//		if (success && begin == end)
//			std::cout << "Parsing succeeded\n";
//		else
//			std::cout << "Parsing failed\nstopped at: """
//			<< str_t(begin, end) << "\"\n";
//		std::cout << "---------------------\n";
//	}*/
//	std::cout << "//////////////////////////////////////////////\n\n";
//	std::cout << "Expression parser...\n";
//	std::cout << "//////////////////////////////////////////////\n\n";
//	std::cout << "Type an expression... or [q or Q] to quit\n\n";
//
//	std::string expression;
//
//	calculator_interpreter<std::string::iterator> calc;
//
//	while (true)
//	{
//		std::getline(std::cin, expression);
//		if (expression == "q" || expression == "Q") break;
//		std::string::iterator  begin = expression.begin()
//			, end = expression.end();
//
//		int result;
//		bool success = qi::phrase_parse(begin
//			, end
//			, calc
//			, qi::space
//			, result);
//
//		std::cout << "-----------------------\n";
//		if (success && begin == end)
//		{
//			std::cout << "Parsing succeeded\n";
//			std::cout << "result = " << result << "\n";
//		}
//		else
//		{
//			std::cout << "Parsing failed\nstopped at: \""
//				<< std::string(begin, end) << "\"\n";
//		}
//		std::cout << "-----------------------\n";
//	}
//}