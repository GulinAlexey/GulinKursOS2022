#pragma once
#include <string>
#include "classes.h"

using namespace std;

class Process; //�������
class Msg; //c��������
class Msq_queue; //������� ���������
class Set_of_processes; //������������ ���������
class Set_of_msg_queues; //������������ �������� ���������

class Process //�������
{
private:
	int id; //���������� ������������� ��������
	int type; //���� ���� ��������
	string owner_name; //��� ��������� �������� (�����-�� ������������ ��� �������)
	int f_condition; //���� ��������� �������� (���������� ��������, ����������, ����������, ��������, �������� ��������)
	string* queue_tasks; //������� �������
	string* current_task; //������� ����������� �������
	int qty_tasks; //���-�� �������
public:
	void add_task(string input) //�������� ������� � ����� �������
	{

	}

	void add_task_to_top(string input) //�������� ������� � ������ ������� (�����, ���� ������ ������� ����� ���������� ������� ���������) 
	{

	}

	void exec() //���������� � ����������� �� ���������
	{

	}

	//������ set, get �����
	void set_id(int input) 
	{
		id = input;
	}

	int get_id()
	{
		return id;
	}

	void set_type(int input)
	{
		type = input;
	}

	int get_type()
	{
		return type;
	}

	void set_owner_name(string input)
	{
		owner_name = input;
	}

	string get_owner_name()
	{
		return owner_name;
	}

	void set_f_condition(int input)
	{
		f_condition = input;
	}

	int get_f_condition()
	{
		return f_condition;
	}
};

class Msg //c��������
{
private:
	int id; //���������� ������������� ���������
	int type; //���� ���� ���������
	string data; //���������� ��������� (������, ���� ���������)
	int id_sender; //������������� �������� - �����������
public:
	//������ set, get ����� 
	void set_id(int input)
	{
		id = input;
	}

	int get_id()
	{
		return id;
	}

	void set_type(int input)
	{
		type = input;
	}

	int get_type()
	{
		return type;
	}

	void set_data(string input)
	{
		data = input;
	}

	string get_data()
	{
		return data;
	}

	void set_id_sender(int input)
	{
		id_sender = input;
	}

	int get_id_sender()
	{
		return id_sender;
	}
};

class Msg_queue //������� ���������
{
private:
	int id; //���������� ������������� ������� (�� �� �������� ������ �������)
	int id_owner; //������������� �������� - ��������� ������� (������� ����� ������� �������)
	Msg* msgs; //������� ���������
	int qty_msgs; //���-�� ���������
public:
	void push(int type_input, string data_input, int id_sender_input) //��������� ��������� � ����� �������
	{

	}

	Msg* pop() //������� ��������� �� �������. ����������� ����� ������� ��������� �� �������, ��������� �� �� 
	{

	}

	void clear() //�������� ������� 
	{

	}

	Msg* pop_type(int type_output) //������� ��������� ���������� ���� �� �������. ����������� ����� ������� ��������� ������� ���� �� �������, ��������� �� �� 
	{

	}

	Msg* output(int number) //�������� ��������� �� ��������� � ��������� �������� (������������ ��� ������ ���� ��������� �� ����� � ���������, �������������� ������ ��������� ��������������� ��������������)
	{
		return &msgs[number];
	}

	int get_qty() //�������� ���-�� ���������
	{
		return qty_msgs;
	}

	void msgctl(int id_new_owner, int id_caller) //�������� ������������� �������� � ��������� ������� �� ����� (����� ���������, ������ ���� ���������� ������� �������� ���������� �������)
	{

	}
};

class Set_of_processes //������������ ���������
{
private:
	Process* processes; //��������
	int qty_processes; //���-�� ���������
public:
	void add(int id_input, int type_input, string owner_name_input) //������� ������� (��������� �������� � �����������, ������� ������� ������, ���-�� ������� ����� ����)
	{

	}

	void del(int id_del) //������� ������� � ��������� ���������������
	{

	}

	void exec_processes() //��������� ��������� �������� ���������������� ���������
	{

	}

	Process* get_process(int id_proc) //�������� ��������� �� ������� � ��������� ���������������
	{

	}

	Process* output(int number) //�������� ��������� �� ������� � ��������� ��������
	{

	}

	int get_qty() //�������� ���-�� ���������
	{

	}
};

class Set_of_msg_queues //������������ �������� ��������� 
{
private:
	Msg_queue* queues; //������� ���������
	int qty_queues; //���-�� �������� ���������
public:
	Msg_queue* msgget(int id_queue, int id_caller) //�������� ������� ��������� � ��������� ��������������� (��������� � �������� �����). ���� ����� ������� �� ����������, �� ��� ��������)
	{
	
	}

	void queue_delete(int id_queue, int id_caller) //������� ������� ��������� � ��������� ��������������� (����� �������, ������ ���� ���������� ������� �������� ���������� �������)
	{

	}

	Msg_queue* output(int number) //�������� ��������� �� ������� � ��������� ��������
	{

	}

	int get_qty() //�������� ���-�� ��������
	{

	}
};
