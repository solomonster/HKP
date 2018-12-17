#pragma once
#include "Node.h"

/*!
  \brief �����, ����������� ����-��������
*/
class Operation : public Node
{
	public:
	Operation(void);
	~Operation(void);

	private:
	Node* LeftOperand; /*!< ����� ������� */
	Node* RightOperand; /*!< ������ ������� */
	
	public:
	/*!
	  \brief �����������

	  \param[in] left - ����� �������
	  \param[in] right - ������ �������
	  \return - ������ ������ Operation
	*/
	Operation (Node* left, Node* right); 

	/*!
	  \brief ���������� ����� �������

	  \param[in] left - ����� �������
	*/
	void SetLeftOperand (Node* left);

	/*!
	  \brief ���������� ������ �������

	  \param[in] right - ������ �������
	*/
	void SetRightOperand (Node* right); 

	/*!
	  \brief �������� ����� �������

	  \return - ����� �������
	*/
	Node* GetLeftOperand ();

	/*!
	  \brief �������� ������ �������

	  \return - ������ �������
	*/
	Node* GetRightOperand ();

};

