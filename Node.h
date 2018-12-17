#pragma once
#include <string>
#include <vector>
using namespace std;

/*!
  \brief ������������, ����������� ��� ��������� ���� ��������
*/
enum OperationTypes
{
	value, /*!< ������� �������� */
	add, /*!< �������� */
	sub, /*!< ��������� */
	mul, /*!< ��������� */
	Div /*!< ������� */
	
	

	
}; 

/*!
  \brief �����, ����������� ���� ������ �������
*/
class Node
{
	public:
	Node(void);
	~Node(void);

	long double Value; /*!< �������� ���� */
	string Name; /*!< �������� ���� */ 
	OperationTypes OperationType; /*!< ��� �������� */

	/*!
	  \brief �����������

	  \param[in] name - �������� ����
	  \param[in] value - �������� ����
	  \return - ������ ������ Node
	*/
	Node (string name, string value);

	/*!
	  \brief ���������� ��� ����

	  \param[in] name - �������� ����
	*/
	void SetName (string name);

	/*!
	  \brief �������� ��� ����

	  \return - �������� ����
	*/
	string GetName ();

	/*!
	  \brief ���������� �������� ����

	  \param[in] value - �������� ����
	*/
	void SetValue (long double value);

	/*!
	  \brief �������� �������� ����

	  \return - �������� ����
	*/
	long double GetValue ();

	/*!
	  \brief ���������� ��� ��������

	  \param[in] type - ��� ��������
	*/
	void SetOperationType (OperationTypes type);

};
