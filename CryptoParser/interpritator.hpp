//#pragma once
//#include <boost/spirit/include/qi.hpp>
//#include<boost/spirit/include/phoenix_operator.hpp>
//
//
//namespace qi = boost::spirit::qi;
//namespace spirit = boost::spirit;
//
//template <typename Iterator>
//struct calculator_interpreter
//	: qi::grammar<Iterator, int(), qi::space_type>
//{
//	calculator_interpreter()
//		: calculator_interpreter::base_type(expr)
//	{
//		expr =
//			term[qi::_val = qi::_1]
//			>> *('+' >> term[qi::_val += qi::_1]
//				| '-' >> term[qi::_val -= qi::_1]
//				)
//			;
//
//		term =
//			factor[qi::_val = qi::_1]
//			>> *('*' >> factor[qi::_val *= qi::_1]
//				| '/' >> factor[qi::_val /= qi::_1]
//				)
//			;
//
//		factor =
//			qi::uint_[qi::_val = qi::_1]
//			| '(' >> expr[qi::_val = qi::_1] >> ')'
//			| '-' >> factor[qi::_val = -qi::_1]
//			| '+' >> factor[qi::_val = qi::_1]
//			;
//
//	}
//
//	qi::rule<Iterator, int(), qi::space_type>
//		expr, term, factor;
//};