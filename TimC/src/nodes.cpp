#include "Nodes.h"
#include <sstream>

namespace TimC
{
	std::string BinaryOpNode::string() const
	{
		std::stringstream ss;
		ss << "(" << _left->string() << "[" << _op << "]" << _right->string() << ")";
		return ss.str();
	}

	std::string NumberNode::string() const
	{
		std::stringstream ss;
		ss << _value;
		return ss.str();
	}
}
