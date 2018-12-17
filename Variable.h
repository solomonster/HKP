#pragma once
#include "Node.h"

/*!
  \brief �����, ����������� ����-����������
*/
class Variable : public Node
{
	public:
	Variable(void);
	~Variable(void);

	private:
	string Type; /*!< ��� ���������� */ 

	public:
	/*!
	  \brief �����������

	  \param[in] type - ��� ����������
	  \param[in] name - ��� ����������
	  \return - ������ ������ Variable
	*/
	Variable (string type, string name); 


	/*!
	  \brief �������� ��� ����������

	  \return - ��� ����������
	*/
	string GetType ();

	/*!
	  \brief ���������� ��� ����������

	  \param[in] type - ��� ����������
	*/
	void SetType(string type);

	/*!
	  \brief �������� ������������ ���� ����������

	  \param[in] type - ��� ����������
	  \return - ��������� �������� (\e true - ��� ���������, \e false - ��� �� ���������)
	*/
	bool IsTypeValid (string type);

	/*!
	  \brief �������� ������������ ����� ����������

	  \param[in] name - ��� ����������
	  \return - ��������� �������� (\e true - ��� ���������, \e false - ��� �� ���������)
	*/
	bool IsNameValid (string name);


};

