#include "StdAfx.h"
#include "Node.h"
#include <string>


Node::Node(void)
{
}


Node::~Node(void)
{
}

Node::Node (string name, string Value)
{
	SetName(name);
	SetValue(std::stold(Value));
	OperationType=value;
}

void Node::SetName(string name)
{
	Name=name;
}

string Node::GetName()
{
	return Name;
}

void Node::SetValue(long double value)
{
	Value=value;
}

long double Node::GetValue()
{
	return Value;
}

void Node::SetOperationType (OperationTypes type)
{
	OperationType=type;
}