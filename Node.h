#pragma once
#include <string>
#include <vector>
using namespace std;

/*!
  \brief Перечисление, описывающее все возможные типы операций
*/
enum OperationTypes
{
	value, /*!< Вернуть значение */
	add, /*!< Сложение */
	sub, /*!< Вычитание */
	mul, /*!< Умножение */
	Div /*!< Деление */
	
	

	
}; 

/*!
  \brief Класс, описывающий узел дерева разбора
*/
class Node
{
	public:
	Node(void);
	~Node(void);

	long double Value; /*!< Значение узла */
	string Name; /*!< Название узла */ 
	OperationTypes OperationType; /*!< Тип операции */

	/*!
	  \brief Конструктор

	  \param[in] name - название узла
	  \param[in] value - значение узла
	  \return - объект класса Node
	*/
	Node (string name, string value);

	/*!
	  \brief Установить имя узла

	  \param[in] name - название узла
	*/
	void SetName (string name);

	/*!
	  \brief Получить имя узла

	  \return - название узла
	*/
	string GetName ();

	/*!
	  \brief Установить значение узла

	  \param[in] value - значение узла
	*/
	void SetValue (long double value);

	/*!
	  \brief Получить значение узла

	  \return - значение узла
	*/
	long double GetValue ();

	/*!
	  \brief Установить тип операции

	  \param[in] type - тип операции
	*/
	void SetOperationType (OperationTypes type);

};
