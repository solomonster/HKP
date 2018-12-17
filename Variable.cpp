#include "StdAfx.h"
#include "Variable.h"

Variable::Variable(void)
{
}


Variable::~Variable(void)
{
}

Variable::Variable(string type, string name)
{
	SetType(type);
	SetName(name);
	OperationType=value;
}


string Variable::GetType()
{
	return Type;
}

void Variable::SetType(string type)
{
	Type=type;
}



bool Variable::IsTypeValid (string type)
{
	bool isOk=false;
	string arr[]=
	{ 
		"short",
		"short int", 
		"signed short", 
		"signed short int", 
		"unsigned short",
		"unsigned short int",
		"int",
		"signed",
		"signed int",
		"unsigned",
		"unsigned int",
		"float",
		"double",
		"string"
	};
	vector <string> types (arr,arr+14);

	for (int i=0; i<types.size() && isOk==false; i++)
	{
		if (types[i]==type)
		{
			isOk=true;
		}
	}
	
	if (isOk==false)
	{
		string msg="Тип переменной ";
		msg+=GetName();
		msg+=" неверно задан или не поддерживается программой. Измените его";
		throw msg;
	}

	return isOk;
}

bool Variable::IsNameValid (string name)
{
	bool isOk=true;
	if (name.size()>20)
	{
		string msg="Имя переменной ";
		msg+=name;
		msg+=" должно быть не длиннее 20 символов. Сократите имя до 20 символов или измените его";
		throw msg;
		isOk=false;
	}
	else if (name[0]<'a' || name[0]>'z')
	{
		string msg="Имя переменной ";
		msg+=name;
		msg+=" должно начинаться с маленькой латинской буквы. Измените его";
		throw msg;
		isOk=false;
	}
	
	for (int i=1; i<name.size() && isOk==true; i++)
	{
		if ( !( (name[i]>='a' && name[i]<='z') || (name[i]>='A' && name[i]<='Z') || (name[i]>='0' && name[i]<='9') || name[i]=='_') )
		{
			string msg="Имя переменной ";
			msg+=name;
			msg+=" должно включать только символы латиницы, цифры, символ подчёркивания '_'. Измените его";
			throw msg;
			isOk=false;
		}
	}

	return isOk;
}


