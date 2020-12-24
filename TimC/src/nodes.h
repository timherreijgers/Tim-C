#pragma once

#include <iostream>
#include <string>

#define DELETE_IF_NOT_NULL_PTR(x) if(x != nullptr) delete x

namespace TimC
{
	enum NodeType
	{
		EXPRESSION_NODE,
		BINARY_OP_NODE,
		NUMBER_NODE
	};

	class ExpressionNode
	{
	public:
		virtual ~ExpressionNode() {}

		virtual std::string string() const { return ""; }
		virtual NodeType type() { return NodeType::EXPRESSION_NODE; }

	protected:
		ExpressionNode() {}
	};

	class BinaryOpNode : public ExpressionNode
	{
	public:
		BinaryOpNode() : _left(nullptr), _op(0x00), _right(nullptr) {}
		BinaryOpNode(ExpressionNode* left, char op, ExpressionNode* right) : _left(left), _op(op), _right(right) {}
		~BinaryOpNode()
		{
			DELETE_IF_NOT_NULL_PTR(_left);
			DELETE_IF_NOT_NULL_PTR(_right);
		}
		virtual NodeType type() override { return NodeType::BINARY_OP_NODE; }
		std::string string() const override;

		ExpressionNode *_left;
		ExpressionNode *_right;
		char _op;
	};

	class NumberNode : public ExpressionNode
	{
	public:
		NumberNode(float value): _value(value) {}
		~NumberNode() {}
		virtual NodeType type() override { return NodeType::NUMBER_NODE; }
		std::string string() const override;

		float _value;
	};

}
