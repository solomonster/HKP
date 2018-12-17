// fFndVariableTypeCplusplus.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <math.h>
#include <cmath>
#include <ctype.h>
#include<fstream>
#include <cstdio>
#include <locale.h>

#include "Node.h"
#include "FunctionPrototypes.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	
	setlocale(LC_CTYPE,"Russian");

	string declaration, expression, type, name;
	vector < vector <string> > elementsOfExpressions;
	elementsOfExpressions.resize(2);
	map <string, Node*> nodes;
	vector <Variable*> variables;
	vector <string> vec;
	map<string, vector<string>> outputToFile;

	try
	{
		if (argc < 3)
		{
			throw "������������� ���������� ���������� (���������� ������� �/��� �������� ���� )";
		}
		else if (argc > 3)
		{
			throw "�������� ���������� ����������";
		}


		char* inputFile = "input.txt";
		char* outputFile = "output.txt"; 

		// ������� ������� ������
		getDataFromInputFile (inputFile, nodes, elementsOfExpressions, variables,vec);
		//void isExpressionValid (vector <string> elementsOfExpression, map <string, Node*> nodes)

		 // Find the types for the variables which have not been defined
		determineVariableType(variables,outputToFile,elementsOfExpressions);

	
		// �������� � �������� ���� ���������� ��������� ���������
		outputResults (outputFile,outputToFile );
	}

	catch (char* msg)
	{
		cin.clear();
		freopen("CONOUT$", "r+", stdout);
		
		cout<<endl<<msg<<endl;

		freopen("error.txt", "w",stdout);
		
		cout<<endl<<msg<<endl;
	}

	catch (string msg)
	{
		cin.clear();
		freopen("CONOUT$", "r+", stdout);
		
		cout<<endl<<msg<<endl;

		freopen("error.txt", "w",stdout);
		
		cout<<endl<<msg<<endl;
	}
	
	
	return 0;
}

void determineVariableType(vector <Variable*> variables,map <string, vector<string>> & outputToFile,vector < vector <string> > elementsOfExpressions)
{
	bool t;
    string ty;
	vector<string> v;
	vector<string> undefinedVariables;

	for(int i=0; i<elementsOfExpressions.size(); i++)
	{
		for(int k=0; k<elementsOfExpressions[i].size(); k++)
		 {
			 t=false;
		 
			 for(int j=0; j < variables.size(); j++)
			 {
				 if(elementsOfExpressions[i][k]==(variables[j]->GetName())){
					 t=true;
					 v.push_back(variables[j]->GetType());
					 
					  
				 }
			 }

			

			// To get the undefined variables and excluding operators as  undefined variables
			if(t==false)
			{
				if(!elementsOfExpressions[i][k].compare("*"))
				{
				}
				else
				{
					if(!elementsOfExpressions[i][k].compare("+"))
					{
					}
					else
					{
						if(!elementsOfExpressions[i][k].compare("-"))
						{
						}
						else
						{
							if (!elementsOfExpressions[i][k].compare("/"))
							{
							}
							else
							{
								undefinedVariables.push_back(elementsOfExpressions[i][k]);
							}
							
						}
						
					}
					
				}
				

			}



			 
			 
		 }

		// Remove duplicate variable type from our vector of types
		sort( v.begin(), v.end() );
		v.erase( unique( v.begin(), v.end() ), v.end() );

		// Store our undefined variable types with new given types in a map
		for(int h=0; h<undefinedVariables.size(); h++)
		{
			 outputToFile.insert(std::make_pair(undefinedVariables[h],v));
			
	
		}

		v.clear();

	}

}

// ����� ������ ���������� ���������� �� � ���, �������� .
void cutDeclaration (string declaration, string & type, string & name)
{ 

	// �������� �������� ����������
	name = declaration.substr(declaration.find_first_of(":") + 1);
	name.erase(name.find(";"));
	// ������� �������� ���������� �� ��������� ������
	declaration.erase(declaration.find_first_of(":"),declaration.size() - 1);
	// cout<<name<<endl;
	// ��������� ��� ���������� � ������ ������
	type = declaration;

	if (type.empty())
	{
		string msg = "� ���������� ";
		msg += name;
		msg += " ����������� ���. �������� ���";
		throw msg;
	}


}

// ����� ��������� �� �����: ����������, ��������� � ��������.
void cutExpression (string expression, vector <string> & elementsOfExpression)
{
	// ��������� ��������� �� �������� (����������, ��������� � ��������) � �� ������
	while (expression.size()!=0)
	{
		// ��� ��������� ��������������� ����������, ���������, ��������

		// �����
		string buf;

		// ��������� � ����� ������� ���������
		buf = expression.substr(0,expression.find(' '));

		// ��������� ������ ������ � ���������, ��� ����� ��������� �������� ���������
		elementsOfExpression.push_back(buf);

		// �������� ��������, ������� ���������, �� ���������
		expression.erase(0, buf.size() + 1);
	}
}

// ��������� ������ ������� ��������� �� ������������
bool IsElementsValid (vector <string> elementsOfExpression, vector <Variable*> variables,vector<string>& vec)
{
	string arr[]=
	{ 
		"+",
		"-", 
		"*", 
		"/",
		"."
		
	};
	vector <string> operationSymbols (arr, arr + 5);
	
	bool isOk=false;

	// ��� ���� ��������� ���������
	for (int i=0; i<elementsOfExpression.size(); i++)
	{
		bool isOk = false;


		// ��� ���� ����������
		for (int j = 0; j<variables.size() && isOk == false; j++)
		{
			if (elementsOfExpression[i] == variables[j]->GetName())
			{
				isOk = true;
			}
		}

		// ��� ���� ����� ��������
		for (int j = 0; j < operationSymbols.size() && isOk == false; j++)
		{
			if (elementsOfExpression[i] == operationSymbols[j])
			{
				isOk = true;
			}
		}

		if (isOk == false)
		{
			vec.push_back(elementsOfExpression[i]);
		}
	}

	return isOk;
}

void getDataFromInputFile (char* inputFile, map <string, Node*> & nodes, vector < vector <string> > & elementsOfExpressions, vector <Variable*> & variables,vector <string> & vec)
{

	FILE* file = freopen(inputFile,"r",stdin);

	if (file == NULL)
	{
		string msg="�� ������� ������� ���� ";
		msg+=inputFile;
		throw msg;
	}

	int countVariables;
	string abc;

	cin>>countVariables;
	
	if (countVariables < 1)
	{
		throw "��� ������ � ���������� ����������� ����������. �������� ����� � ������ �����";
	}

	getline(cin,abc);

	// ��������� ���������� ���������� � �� �� ������ ������ ����-����������
	for (int i=0; i<countVariables; i++)
	{
		string declaration, type, name;
		getline(cin,declaration);

		if (declaration.empty())
		{
			throw "��� ������ � ����������. �������� �������� ������ ��� ����������";
		}
		
		else if (declaration.rfind(';') == -1)
		{
			string msg = "� ���������� ���������� �� ������ ";
			msg += std::to_string((long double)i+2);
			msg += " ����������� ���� ';'. �������� ��� � ����� ������";
			throw msg;
		}

		// ������� ���������� ���������� �� � ���, ��� 
		cutDeclaration(declaration, type, name);
		if (name.empty())
		{
			string msg = "� ����������, ����������� �� ������ ";
			msg += std::to_string( (long double)i + 2);
			msg += " ����������� ���. �������� ���";
			throw msg;
		}

		Variable *variable = new Variable (type, name);

		// ���� ��� � ��� ���������, �� �������� ������ ����������
		if (variable->IsNameValid(name) && variable->IsTypeValid(type) )
		{
			// ���� ���������� ��� ���� ���������
			if (nodes.count(name) != 0)
			{
				string msg = "�������� ���������� �� ������� ";
				msg += std::to_string((long double)i + 2);
				msg += ", ";

				// ��� ���� ����������
				for (int j=0; j<variables.size(); j++)
				{
					
					if (name == variables[j]->GetName())
					{
						msg += std::to_string( (long double)j + 2);
						msg += ", ";
					}
				}

				msg += "���������. �������� �������� ����������, ����� �� ���� ����������";
				throw msg;
			}
			
			nodes[name] = variable;
			variables.push_back(variable);
		}
	}
	int countExpressions;
	//string abc;

	cin>>countExpressions;
	
	if (countExpressions < 1)
	{
		throw "��� ������ � ���������� ���������. �������� ����� ����� ���������� ����������";
	}

	getline(cin,abc);
	//vector <string> & vec;
	//// C�������� ��������� �� ����� � ����� �� �� ��������
	for (int i = 0; i < countExpressions; i++)
	{
		string expression;
		getline(cin, expression);
		
		if (expression.empty())
		{
			throw "����������� ���������. �������� ���";
		}

		cutExpression(expression, elementsOfExpressions[i]);
		IsElementsValid(elementsOfExpressions[i], variables,vec);
		
	}
	
	fclose(stdin);
}

// ���������� ��� ��������
OperationTypes getOperationType (string element)
{
	OperationTypes operationType;

	if (element == "+")
	{
		operationType = add;
	}
	else if (element == "-")
	{
		 operationType = sub;

	}
	else if (element == "*")
	{
		operationType = mul;
	}
	else if (element == "/")
	{
		operationType = Div;
	}
	
	

	return operationType;
}

// ������ ������ ���������� �� ������ ������ �������
void isExpressionValid (vector <string> elementsOfExpression, map <string, Node*> nodes)
{
	vector <string> stack;
	Operation *root=NULL;
	string element;
	
	// ��� ������� �������� ���������
	for (int i = 0; i < elementsOfExpression.size(); i++)
	{
		element = elementsOfExpression[i];

		// ���� ������� ��������� �� ����������
		if (nodes.count(element) == 0)
		{
			// ���� ��� ���������
			if (isdigit(element[0]))
			{
				Node *constant = new Node (element, element);
				nodes[element] = constant;
				stack.push_back(element);
			}
			else // ����� ��� ��������
			{
				string binaryOperations="+-*/";
				string name;
				OperationTypes type;
				Node *left = NULL, *right;
				int index = stack.size() - 1;

				if (stack.empty())
				{
					string msg = "� ��������� ����������� �������� ��� �������� ";
					msg += element;
					msg += " �� ������� ";
					msg += std::to_string(( long double)i + 1);
					msg += ". �������� ���������";
					//throw msg;
				}

				name = element + stack[index];
				right = nodes[stack[index]];
				stack.pop_back();
				type=getOperationType(element);
				
				// ���� �������� ��������, �� �������� ����� �������
				if (binaryOperations.find(element) != -1)	
				{
					if (stack.empty())
					{
						string msg = "� ��������� ����������� �������� ��� �������� ";
						msg += element;
						msg += " �� ������� ";
						msg += std::to_string( (long double)i + 1);
						msg += ". �������� ���������";
						//throw msg;
					}
					
					left = nodes[stack[index-1]];
					name.insert(0, stack[index-1]);
					stack.pop_back();
				}
					
				Operation *operation = new Operation(left,right);
				operation->SetName(name);
				operation->SetOperationType(type);
				stack.push_back(name);
				nodes[name] = operation;
				root = operation;
			}

		}
		else
		{
			stack.push_back(element);
		}
	}

	// ���� � ����� �������� ����, ����� �����
	if (stack.size() > 1)
	{
		string msg = "� ��������� ����������� �������� ��� ��������� ";

		for (int i = 0; i < stack.size(); i++)
		{
			msg += stack[i];
			msg += ", ";
		}

		msg += "�������� ���������";
		//throw msg;
	}

	
}





// ���������� ���������� � �������� ����
void outputResults (char* outputFile,map<string, vector<string> > outputToFile )
{
	freopen(outputFile,"w",stdout);

	if (outputToFile.size()==0)
	{
		cout<<"All variables have been defined earlier";
	}
	else
	{
		cout<<"The undefined variables and their possible given types"<<endl;
		cout<<endl;

		// Write to our output file
		for(auto ii=outputToFile.begin(); ii!=outputToFile.end(); ++ii){
		   cout << (*ii).first << ": ";
		   vector <string> inVect = (*ii).second;
		   for (unsigned j=0; j<inVect.size(); j++){
			   cout << inVect[j] << "; ";
		   }
			cout << endl;
		}

	}
	fclose(stdout);
}

