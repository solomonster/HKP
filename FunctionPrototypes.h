#include <string>
#include <vector>
#include <map>
using namespace std;

#include "Variable.h"
#include "Operation.h"

/*!
	\brief Считывает данные с входного файла

	\param[in] inputFile - имя файла, содержащий входные данные 
	\param[in|out] nodes - контейнер узлов дерева 
	\param[in|out] elementsOfExpressions - контейнер элементов выражений
	\param[in|out] variables  - контейнер узлов-переменных
*/
void getDataFromInputFile (char* inputFile, map <string, Node*> & nodes, vector < vector <string> >& elementsOfExpressions, vector <Variable*> &variables,vector <string> & vec);

/*!
	\brief Делит строку объявления переменной на её тип, название и диапазон значений

	\param[in] declaration  - строка, содержащая объявление переменной 
	\param[in|out] type - строка, содержащая название типа переменной 
	\param[in|out] name - строка, содержащая название переменной
*/
void cutDeclaration( string declaration, string & type, string & name);

/*!
	\brief Делит выражение на части: переменные, константы и операции

	\param[in] expression - строка, содержащее выражение в виде обратной польской записи
	\param[in|out] elementsOfExpression - контейнер, содержащий элементы выражения 
*/
void cutExpression (string expression, vector <string> & elementsOfExpression);

/*!
	\brief Проверяет каждый элемент выражения

	\param[in] elementsOfExpression - контейнер, содержащий элементы выражения
	\param[in] variables  - контейнер переменных 
	\return - результат проверки (\e true - элементы выражения корректны, \e false - хотя бы один элемент некорректен)
*/
bool IsElementsValid (vector <string> elementsOfExpression, vector <Variable*> variables);

/*!
	\brief Определяет тип операции

	\param[in] element - строка, содержащая графическое обозначение операции
	\return - тип операции из перечисления OperationTypes
*/
OperationTypes getOperationType (string element);

/*!
	\brief Создаёт дерево вычислений на основе дерева разбора

	\param[in] elementsOfExpression - контейнер, содержащий названия элементов выражения
	\param[in] nodes - контейнер узлов дерева
	\return - корень дерева вычислений
*/
void isExpressionValid (vector <string> elementsOfExpression, map <string, Node*> nodes);


/*!
	\brief Проверяет, есть ли ещё наборы данных

	\param[in] element - элемент выражения (переменная, константа, операция)
	\return - результат выражения
*/
void determineVariableType(vector <Variable*> variables,map <string, vector<string>> & outputToFile,vector < vector <string> > elementsOfExpressions);

/*!
	\brief Вычисляет результат операции

	\param[in] operation - тип операции
	\param[in] leftResult - значение левого операнда
	\param[in] rightResult - значение правого операнда
	\return - результат операции
*/
long double calculateOperation (OperationTypes operation, long double leftResult, long double rightResult);

/*!
	\brief Вычисляет результат операции

	\param[in] outputFile - имя файла, куда будут записываться выходные данные
	\param[in] datasets - контейнер наборов значений переменных, при которых выражения не эквивалентны
	\param[in] variables - контейнер переменных
*/
void outputResults (char* outputFile,map<string, vector<string>> outputToFile );