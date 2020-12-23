#pragma once

#include <iostream>
#include <string>

#define DELETE_IF_NOT_NULL_PTR(x) if(x != nullptr) delete x

namespace TimC
{
	class ExpressionNode
	{
	public:
		virtual ~ExpressionNode() {}

		virtual std::string string() const { return ""; }
	protected:
		ExpressionNode() {}
	};

	class BinaryOpNode : public ExpressionNode
	{
	public:
		BinaryOpNode(ExpressionNode* left, char op, ExpressionNode* right) : _left(left), _op(op), _right(right) {}
		~BinaryOpNode()
		{
			DELETE_IF_NOT_NULL_PTR(_left);
			DELETE_IF_NOT_NULL_PTR(_right);
		}

		std::string string() const override;
	private:
		ExpressionNode *_left;
		ExpressionNode *_right;
		char _op;
	};

	class NumberNode : public ExpressionNode
	{
	public:
		NumberNode(int value): _value(value) {}
		~NumberNode() {}

		std::string string() const override;
	private:
		int _value;
	};

	std::ostream& operator<<(std::ostream& os, const BinaryOpNode& nodes);
	std::ostream& operator<<(std::ostream& os, const NumberNode& node);

}
