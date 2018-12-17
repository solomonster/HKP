#pragma once
#include "Node.h"

/*!
  \brief Класс, описывающий узел-операцию
*/
class Operation : public Node
{
	public:
	Operation(void);
	~Operation(void);

	private:
	Node* LeftOperand; /*!< Левый операнд */
	Node* RightOperand; /*!< Правый операнд */
	
	public:
	/*!
	  \brief Конструктор

	  \param[in] left - левый операнд
	  \param[in] right - правый операнд
	  \return - объект класса Operation
	*/
	Operation (Node* left, Node* right); 

	/*!
	  \brief Установить левый операнд

	  \param[in] left - левый операнд
	*/
	void SetLeftOperand (Node* left);

	/*!
	  \brief Установить правый операнд

	  \param[in] right - правый операнд
	*/
	void SetRightOperand (Node* right); 

	/*!
	  \brief Получить левый операнд

	  \return - левый операнд
	*/
	Node* GetLeftOperand ();

	/*!
	  \brief Получить правый операнд

	  \return - правый операнд
	*/
	Node* GetRightOperand ();

};

