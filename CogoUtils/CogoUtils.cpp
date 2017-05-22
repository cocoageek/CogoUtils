// CogoUtils.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <boost/chrono.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/regex.hpp>
#include <boost/format.hpp>
#include <iostream>
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>

using namespace boost::chrono;
using namespace boost::algorithm;

namespace bg = boost::geometry;
namespace bc = boost::chrono;

int main()
{
	std::cout << bc::system_clock::now() << "\n";
	std::string s = "--Boost C++ Libraries--";
	std::cout << trim_left_copy_if(s, is_any_of("-")) << '\n';
	std::cout << trim_right_copy_if(s, is_any_of("-")) << '\n';
	std::cout << trim_copy_if(s, is_any_of("-")) << '\n';
	s = "Boost C++ Libraries";
	std::cout.setf(std::ios::boolalpha);
	std::cout << starts_with(s, "Boost") << '\n';
	std::cout << ends_with(s, "Libraries") << '\n';
	std::cout << contains(s, "C++") << '\n';
	std::cout << lexicographical_compare(s, "Boost") << '\n';
	s = "Boost C++ Libraries";
	std::vector<std::string> v;
	split(v, s, is_space());
	std::cout << v.size() << '\n';
	s = "Boost C++ Libraries";
	boost::iterator_range<std::string::iterator> r =
		find_regex(s, boost::regex{ "\\w\\+\\+" });
	std::cout << r << '\n';

	std::cout << boost::format{ "%2%/%1%/%3%" } % 12 % 5 % 2014 << '\n';

	std::stringstream ss;

	int year = 2011;
	auto month = 3;
	int day = 11;
	int hour = 12;
	int minute = 1;
	auto seconds = 23.35;
	double epoch = 1231234567890.35;

	// Fill with whitespace, right align
	std::cout << boost::format("#1.0 %4i %4i %4in") % year % month % day << '\n';
	// Output: #1.0 2011    3   11

	// Fill with whitespace, left align
	std::cout << boost::format("#1.1 %-4i %-4i %-4in") % year % month % day << '\n';
	// Output: #1.1 2011 3    11

	// Fill with zero (pad)
	std::cout << boost::format("#2.0 %04i %04i %04in") % year % month % day << '\n';
	// Output: #2.0 2011 0003 0011

	// Floating point precision
	std::cout << boost::format("#3.0 %11.2fn") % seconds << '\n';
	// Output: #3.0       23.35

	// Floating point precision with zero-fill (zero pad)
	std::cout << boost::format("#4.0 %011.2fn") % seconds << '\n';
	// Output: #4.0 00000023.35

	bg::model::d2::point_xy<double> point1;
	bg::model::d2::point_xy<double> point2(100.0, 200.0);

	bg::set<0>(point1, 350.0);
	point1.y(250.0);

	bg::model::d2::point_xy<double> point3(200.0, 200.0);
	double x = bg::get<0>(point1);
	double y = point1.y();

	std::cout << x << ", " << y << std::endl;
	std::cout << point2.x() << ", " << point2.y() << std::endl;
}

