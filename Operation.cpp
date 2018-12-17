#include "StdAfx.h"
#include "Operation.h"


Operation::Operation(void)
{
}


Operation::~Operation(void)
{
}

Operation::Operation (Node* left, Node* right)
{
	SetLeftOperand(left);
	SetRightOperand(right);
}

void Operation::SetLeftOperand (Node* left)
{
	LeftOperand=left;
}

void Operation::SetRightOperand (Node* right)
{
	RightOperand=right;
}

Node* Operation::GetLeftOperand()
{
	return LeftOperand;
}

Node* Operation::GetRightOperand()
{
	return RightOperand;
}