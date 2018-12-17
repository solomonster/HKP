#pragma once
#include "Node.h"

/*!
  \brief Класс, описывающий узел-переменную
*/
class Variable : public Node
{
	public:
	Variable(void);
	~Variable(void);

	private:
	string Type; /*!< Тип переменной */ 

	public:
	/*!
	  \brief Конструктор

	  \param[in] type - тип переменной
	  \param[in] name - имя переменной
	  \return - объект класса Variable
	*/
	Variable (string type, string name); 


	/*!
	  \brief Получить тип переменной

	  \return - тип переменной
	*/
	string GetType ();

	/*!
	  \brief Установить тип переменной

	  \param[in] type - тип переменной
	*/
	void SetType(string type);

	/*!
	  \brief Проверка корректности типа переменной

	  \param[in] type - тип переменной
	  \return - результат проверки (\e true - тип корректен, \e false - тип не корректен)
	*/
	bool IsTypeValid (string type);

	/*!
	  \brief Проверка корректности имени переменной

	  \param[in] name - имя переменной
	  \return - результат проверки (\e true - имя корректно, \e false - имя не корректно)
	*/
	bool IsNameValid (string name);


};

