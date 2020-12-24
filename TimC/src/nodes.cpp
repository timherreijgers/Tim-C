#include "Nodes.h"
#include <sstream>

namespace TimC
{
	std::string BinaryOpNode::string() const
	{
		std::stringstream ss;
		ss << "(" << _left->string();
		if (_op != 0x00 && _right != nullptr)
			ss << "[" << _op << "]" << _right->string();
		ss << ")";
		return ss.str();
	}

	std::string NumberNode::string() const
	{
		std::stringstream ss;
		ss << _value;
		return ss.str();
	}
}
