#include <string>
#include <vector>
#include <map>
using namespace std;

#include "Variable.h"
#include "Operation.h"

/*!
	\brief ��������� ������ � �������� �����

	\param[in] inputFile - ��� �����, ���������� ������� ������ 
	\param[in|out] nodes - ��������� ����� ������ 
	\param[in|out] elementsOfExpressions - ��������� ��������� ���������
	\param[in|out] variables  - ��������� �����-����������
*/
void getDataFromInputFile (char* inputFile, map <string, Node*> & nodes, vector < vector <string> >& elementsOfExpressions, vector <Variable*> &variables,vector <string> & vec);

/*!
	\brief ����� ������ ���������� ���������� �� � ���, �������� � �������� ��������

	\param[in] declaration  - ������, ���������� ���������� ���������� 
	\param[in|out] type - ������, ���������� �������� ���� ���������� 
	\param[in|out] name - ������, ���������� �������� ����������
*/
void cutDeclaration( string declaration, string & type, string & name);

/*!
	\brief ����� ��������� �� �����: ����������, ��������� � ��������

	\param[in] expression - ������, ���������� ��������� � ���� �������� �������� ������
	\param[in|out] elementsOfExpression - ���������, ���������� �������� ��������� 
*/
void cutExpression (string expression, vector <string> & elementsOfExpression);

/*!
	\brief ��������� ������ ������� ���������

	\param[in] elementsOfExpression - ���������, ���������� �������� ���������
	\param[in] variables  - ��������� ���������� 
	\return - ��������� �������� (\e true - �������� ��������� ���������, \e false - ���� �� ���� ������� �����������)
*/
bool IsElementsValid (vector <string> elementsOfExpression, vector <Variable*> variables);

/*!
	\brief ���������� ��� ��������

	\param[in] element - ������, ���������� ����������� ����������� ��������
	\return - ��� �������� �� ������������ OperationTypes
*/
OperationTypes getOperationType (string element);

/*!
	\brief ������ ������ ���������� �� ������ ������ �������

	\param[in] elementsOfExpression - ���������, ���������� �������� ��������� ���������
	\param[in] nodes - ��������� ����� ������
	\return - ������ ������ ����������
*/
void isExpressionValid (vector <string> elementsOfExpression, map <string, Node*> nodes);


/*!
	\brief ���������, ���� �� ��� ������ ������

	\param[in] element - ������� ��������� (����������, ���������, ��������)
	\return - ��������� ���������
*/
void determineVariableType(vector <Variable*> variables,map <string, vector<string>> & outputToFile,vector < vector <string> > elementsOfExpressions);

/*!
	\brief ��������� ��������� ��������

	\param[in] operation - ��� ��������
	\param[in] leftResult - �������� ������ ��������
	\param[in] rightResult - �������� ������� ��������
	\return - ��������� ��������
*/
long double calculateOperation (OperationTypes operation, long double leftResult, long double rightResult);

/*!
	\brief ��������� ��������� ��������

	\param[in] outputFile - ��� �����, ���� ����� ������������ �������� ������
	\param[in] datasets - ��������� ������� �������� ����������, ��� ������� ��������� �� ������������
	\param[in] variables - ��������� ����������
*/
void outputResults (char* outputFile,map<string, vector<string>> outputToFile );