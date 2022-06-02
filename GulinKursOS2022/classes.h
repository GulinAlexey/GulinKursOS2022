#pragma once
#include <string>
#include <sstream>
#include <iostream>

//�������� ������ ��������� ��������
#define GENERAT 0 //����������
#define READY 1//����������
#define EXECUT 2//���������� 
#define WAIT 3//�������� (����������)
#define DEL 4 //�������� �������� (����������)

#define ERRNO -1 //������������ ��� ������� ��������� ��������� �� ������ �������

using namespace std;

//���������� ���������� � �������
extern class Set_of_processes procs;
extern class Set_of_msg_queues msgqs;

extern int last_id_proc; //��������� ��������������� ���������� id ��������
extern int last_id_msg; //��������� ��������������� ���������� id ���������

class Msg; //c��������
class Msq_queue; //������� ���������
class Set_of_msg_queues; //������������ �������� ���������
class Process; //�������
class Set_of_processes; //������������ ���������

class Msg //c��������
{
private:
	int id; //���������� ������������� ���������
	int type; //���� ���� ���������
	string data; //���������� ��������� (������, ���� ���������)
	int id_sender; //������������� �������� - �����������
public:
	Msg(int id_input, int type_input, string data_input, int id_sender_input) //�����������
	{
		id = id_input;
		type = type_input;
		data = data_input;
		id_sender = id_sender_input;
	}
	Msg()
	{
		id = ERRNO;
		type = ERRNO;
		data = "";
		id_sender = ERRNO;
	}
	void init(int id_input, int type_input, string data_input, int id_sender_input)
	{
		id = id_input;
		type = type_input;
		data = data_input;
		id_sender = id_sender_input;
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
	Msg_queue(int id_input, int id_owner_input) //�����������
	{
		id = id_input;
		id_owner = id_owner_input;
		msgs = NULL;
		qty_msgs = 0;
	}
	Msg_queue()
	{
		id = 0;
		id_owner = 0;
		msgs = NULL;
		qty_msgs = 0;
	}


	void init(int id_input, int id_owner_input)
	{
		id = id_input;
		id_owner = id_owner_input;
		delete[] msgs;
		msgs = NULL;
		qty_msgs = 0;
	}

	void push(int type_input, string data_input, int id_sender_input) //��������� ��������� � ����� �������
	{
		Msg* msgs_new = new Msg[qty_msgs + 1];
		for (int i = 0; i < qty_msgs; i++)
		{
			msgs_new[i] = msgs[i];
		}
		msgs_new[qty_msgs].init(++last_id_msg, type_input, data_input, id_sender_input);
		qty_msgs++;

		delete[] msgs;
		msgs = msgs_new;
	}

	Msg pop() //������� ��������� �� �������. ����������� ����� ������� ��������� �� �������, ��������� �� �� 
	{
		Msg pop_msg;
		if (qty_msgs > 0)
		{
			pop_msg = msgs[0];

			qty_msgs--;

			Msg* msgs_new = NULL;
			if (qty_msgs > 0)
			{
				msgs_new = new Msg[qty_msgs];
				for (int i = 0, j = 1; j < qty_msgs + 1; i++, j++)
				{
					msgs_new[i] = msgs[j];
				}
			}
			delete[] msgs;
			msgs = msgs_new;
		}
		else
		{
			pop_msg.init(ERRNO, ERRNO, "empty queue", ERRNO);
		}
		return pop_msg;
	}

	void clear() //�������� ������� 
	{
		delete[] msgs;
		qty_msgs = 0;
	}

	Msg pop_type(int type_output) //������� ��������� ���������� ���� �� �������. ����������� ����� ������� ��������� ������� ���� �� �������, ��������� �� �� 
	{
		Msg pop_msg;
		if (qty_msgs > 0)
		{
			int search_i = -1; //������ �������� ��������� � ��������� �����
			for (int i = 0; i < qty_msgs; i++)
			{
				if (msgs[i].get_type() == type_output)
				{
					search_i = i;
					break;
				}
			}
			if (search_i != -1)
			{
				pop_msg = msgs[search_i];

				qty_msgs--;

				Msg* msgs_new = NULL;
				if (qty_msgs > 0)
				{
					msgs_new = new Msg[qty_msgs];
					for (int i = 0, j = 0; i < qty_msgs + 1; i++)
					{
						if (i != search_i)
						{
							msgs_new[j] = msgs[i];
							j++;
						}
					}
				}
				delete[] msgs;
				msgs = msgs_new;
			}
			else
			{
				pop_msg.init(ERRNO, ERRNO, "", ERRNO);
			}
		}
		else
		{
			pop_msg.init(ERRNO, ERRNO, "", ERRNO);
		}
		return pop_msg;
	}

	Msg* output(int number) //�������� ��������� �� ��������� � ��������� �������� (������������ ��� ������ ���� ��������� �� ����� � ���������, �������������� ������ ��������� ��������������� ��������������)
	{
		return &msgs[number];
	}

	int get_qty() //�������� ���-�� ���������
	{
		return qty_msgs;
	}

	bool msgctl(int id_new_owner, int id_caller) //�������� ������������� �������� � ��������� ������� �� ����� (����� ���������, ������ ���� ���������� ������� �������� ���������� �������)
	{
		if (id_caller == id_owner)
		{
			id_owner = id_new_owner;
			return true;
		}
		else
			return false;
	}

	bool is_this_type_exists(int type_find) //��������, ���� �� � ������ ������� ��������� ���������� ����
	{
		if (type_find = -1 && qty_msgs > 0)
			return true;

		bool f = false;
		for (int i = 0; i < qty_msgs; i++)
		{
			if (msgs[i].get_type() == type_find)
			{
				f = true;
				break;
			}
		}
		return f;
	}

	//������ get
	int get_id()
	{
		return id;
	}

	int get_id_owner()
	{
		return id_owner;
	}
};

class Set_of_msg_queues //������������ �������� ��������� 
{
private:
	Msg_queue* queues; //������� ���������
	int qty_queues; //���-�� �������� ���������
public:
	Set_of_msg_queues() //�����������
	{
		qty_queues = 0;
		queues = NULL;
	}

	Msg_queue* msgget(int id_queue, int id_caller) //�������� ������� ��������� � ��������� ��������������� (��������� � �������� �����). ���� ����� ������� �� ����������, �� ��� ��������)
	{
		Msg_queue* getted_queue = NULL;
		for (int i = 0; i < qty_queues; i++)
		{
			if (queues[i].get_id() == id_queue)
			{
				getted_queue = &queues[i];
				break;
			}
		}
		if (getted_queue == NULL)
		{
			qty_queues++;
			Msg_queue* queues_new = new Msg_queue[qty_queues];

			if (qty_queues > 1)
			{
				for (int i = 0; i < qty_queues - 1; i++)
				{
					queues_new[i] = queues[i];
				}
			}

			queues_new[qty_queues - 1].init(id_queue, id_caller);

			delete[] queues;
			queues = queues_new;

			getted_queue = &queues[qty_queues - 1];
		}

		return getted_queue;
	}

	bool queue_delete(int id_queue, int id_caller) //������� ������� ��������� � ��������� ��������������� (����� �������, ������ ���� ���������� ������� �������� ���������� �������)
	{
		int i_deleted_queue = -1;
		for (int i = 0; i < qty_queues; i++)
		{
			if (queues[i].get_id() == id_queue && queues[i].get_id_owner() == id_caller)
			{
				i_deleted_queue = i;
				break;
			}
		}
		if (i_deleted_queue == -1)
		{
			return false;
		}
		else
		{
			qty_queues--;
			Msg_queue* queues_new = NULL;
			if (qty_queues > 0)
			{
				queues_new = new Msg_queue[qty_queues];

				for (int i = 0, j = 0; j < qty_queues + 1; j++)
				{
					if (j != i_deleted_queue)
					{
						queues_new[i] = queues[j];
						i++;
					}
				}
			}

			delete[] queues;
			queues = queues_new;
			return true;
		}
	}

	Msg_queue* output(int number) //�������� ��������� �� ������� � ��������� ��������
	{
		return &queues[number];
	}

	bool is_queue_exists(int id_queue_find) //���������, ���� �� ������� � ������ id
	{
		bool f_finded = false;
		for (int i = 0; i < qty_queues; i++)
		{
			if (queues[i].get_id() == id_queue_find)
			{
				f_finded = true;
				break;
			}
		}

		return f_finded;
	}

	int get_qty() //�������� ���-�� ��������
	{
		return qty_queues;
	}
};


class Process //�������
{
private:
	int id; //���������� ������������� ��������
	string name; //��� ��������
	string owner_name; //��� ��������� �������� (�����-�� ������������ ��� �������)
	int f_condition; //���� ��������� �������� (���������� ��������, ����������, ����������, ��������, �������� ��������)
	string* queue_tasks; //������� �������
	string current_task; //������� ����������� �������
	int qty_tasks; //���-�� ������� (����� ��������)

	Msg last_msg; //��������� ���������� ���������, ������������ ��� ������ �������� (���� �������� �� �������)

public:
	Process(int id_input, int name_input, string owner_name_input, int f_condition_input) //�����������
	{
		id = id_input;
		name = name_input;
		owner_name = owner_name_input;
		f_condition = f_condition_input;
		queue_tasks = NULL;
		current_task = "";
		qty_tasks = 0;
	}
	Process()
	{
		id = 0;
		name = "empty process";
		owner_name = "";
		f_condition = 0;
		queue_tasks = NULL;
		current_task = "";
		qty_tasks = 0;
	}

	void init(int id_input, string name_input, string owner_name_input, int f_condition_input)
	{
		id = id_input;
		name = name_input;
		owner_name = owner_name_input;
		f_condition = f_condition_input;
		queue_tasks = NULL;
		current_task = "";
		qty_tasks = 0;
	}

	void add_task(string input) //�������� ������� � ����� �������
	{
		string* tasks_new = new string[qty_tasks + 1];
		for (int i = 0; i < qty_tasks; i++)
		{
			tasks_new[i] = queue_tasks[i];
		}
		tasks_new[qty_tasks] = input;
		qty_tasks++;

		delete[] queue_tasks;
		queue_tasks = tasks_new;
	}

	void add_task_to_top(string input) //�������� ������� � ������ ������� (�����, ���� ������ ������� ����� ���������� ������� ���������) 
	{
		string* tasks_new = new string[qty_tasks + 1];
		for (int i = 1, j = 0; j < qty_tasks; i++, j++)
		{
			tasks_new[i] = queue_tasks[j];
		}
		tasks_new[0] = input;
		qty_tasks++;

		delete[] queue_tasks;
		queue_tasks = tasks_new;
	}

	bool to_next_task() //������� � ���������� ������� (��������� ������� �� ������ ������� � ���������� � ������� ��������)
	{
		if (qty_tasks == 0)
		{
			current_task = "";
			return false;
		}
		else
		{
			current_task = queue_tasks[0];
			delete_task(0+1);
			return true;
		}
	}

	bool delete_task(int number) //������� ������� � ��������� �������� �� �������, ��������� �� 1
	{
		if (number > 0 && number <= qty_tasks)
		{
			qty_tasks--;
			string* tasks_new = NULL;
			if (qty_tasks > 0)
			{
				tasks_new = new string[qty_tasks];

				for (int i = 0, j = 0; j < qty_tasks + 1; j++)
				{
					if (j != number - 1)
					{
						tasks_new[i] = queue_tasks[j];
						i++;
					}
				}
			}

			delete[] queue_tasks;
			queue_tasks = tasks_new;
			return true;
		}
		else
			return false;
	}

	System::String^ exec() //���������� � ����������� �� ��������� (������������ ���� � ���������� ����������)
	{
		string command; //������ � �������� �� �������� �������
		stringstream  task_stream; //����� ��� ������� �������� �������
		bool f_success; //��� �������� ��������� ��������� � ������� � ������ ��������

		switch (f_condition)
		{
		case GENERAT: //����������
			f_condition = READY;
			return "������� \"" + gcnew System::String(name.c_str()) + "\" � id = " + System::Convert::ToString(id) + " ������� � ��������� ����������.";
			break;

		case READY: //����������
			if (qty_tasks > 0)
			{
				to_next_task();
				f_condition = EXECUT;
				return "������� \"" + gcnew System::String(name.c_str()) + "\" � id = " + System::Convert::ToString(id) + " ������� ������� \"" + gcnew System::String(current_task.c_str()) + "\" �� ������� ������� � ������� � ��������� ����������.";
			}
			else
			{
				current_task = "";
				return "������� \"" + gcnew System::String(name.c_str()) + "\" � id = " + System::Convert::ToString(id) + " �� ����� ������� � ������� � ������� � ��������� ����������.";
			}
			break;

		case EXECUT: //����������
			task_stream << current_task; //������� ����� �� ������ �������� �������
			task_stream >> command; //�������� ������� �� �������

			//���������� � ����������� �� ������� ������������� �����
			if (command == "snd") //��������� ���������
			{
				int id_queue_of_msg; //id �������, ���� ���� ��������� ���������
				task_stream >> id_queue_of_msg; //�������� �� �������

				int type_of_msg; //��� ������������� ���������
				task_stream >> type_of_msg; //�������� �� �������


				string msg_text = current_task; //�������� ����� �������
				msg_text.assign(msg_text, msg_text.find("\"") + 1, msg_text.rfind("\"") - msg_text.find("\"") - 1); //�������� ����� ��������� �� �������

				//msg_text = std::to_string(msg_text.find("\"")) + " " + std::to_string(msg_text.rfind("\""));

				msgqs.msgget(id_queue_of_msg, id)->push(type_of_msg, msg_text, id); //��������� ��������� � �������

				f_condition = READY;
				current_task = "";
				return "������� \"" + gcnew System::String(name.c_str()) + "\" � id = " + System::Convert::ToString(id) + " �������� ��������� \"" + gcnew System::String(msg_text.c_str()) + "\" ���� " + System::Convert::ToString(type_of_msg) + " � ������� " + System::Convert::ToString(id_queue_of_msg) + " � ������� � ��������� ����������.";
			}
			else if (command == "rsv") //�������� ���������
			{
				int id_queue_of_msg; //id �������, ������ ���� �������� ���������
				task_stream >> id_queue_of_msg; //�������� �� �������

				int type_of_msg; //��� ����������� ��������� (-1, ���� �����)
				task_stream >> type_of_msg; //�������� �� �������

				if (msgqs.is_queue_exists(id_queue_of_msg) == true)
				{
					if (type_of_msg != -1)
					{
						last_msg = msgqs.msgget(id_queue_of_msg, id)->pop_type(type_of_msg);
					}
					else
					{
						last_msg = msgqs.msgget(id_queue_of_msg, id)->pop();
					}
					if (last_msg.get_id() == ERRNO)
					{
						if (type_of_msg != -1)
						{
							return "������� \"" + gcnew System::String(name.c_str()) + "\" � id = " + System::Convert::ToString(id) + " �� ����� � ������� ��������� � id = " + System::Convert::ToString(id_queue_of_msg) + " ��������� ���� " + System::Convert::ToString(type_of_msg) + " � ������� � ��������� �������� ��������� ���������.";
						}
						else
						{
							return "������� \"" + gcnew System::String(name.c_str()) + "\" � id = " + System::Convert::ToString(id) + " �� ����� � ������� ��������� � id = " + System::Convert::ToString(id_queue_of_msg) + " ��������� ����� ����� � ������� � ��������� �������� ��������� ���������.";
						}
					}
					else
					{
						f_condition = READY;
						current_task = "";
						if (type_of_msg != -1)
						{
							return "������� \"" + gcnew System::String(name.c_str()) + "\" � id = " + System::Convert::ToString(id) + " ������� �� ������� ��������� � id = " + System::Convert::ToString(id_queue_of_msg) + " ��������� ���� " + System::Convert::ToString(type_of_msg) + " � ������� � ��������� ����������.";
						}
						else
						{
							return "������� \"" + gcnew System::String(name.c_str()) + "\" � id = " + System::Convert::ToString(id) + " ������� �� ������� ��������� � id = " + System::Convert::ToString(id_queue_of_msg) + " ��������� ������ ���� � ������� � ��������� ����������.";
						}
					}
				}
				else
				{
					f_condition = WAIT;
					return "������� \"" + gcnew System::String(name.c_str()) + "\" � id = " + System::Convert::ToString(id) + " �� ����� ������� ��������� � id = " + System::Convert::ToString(id_queue_of_msg) + " � ������� � ��������� �������� ��������� �������.";
				}
			}
			else if (command == "finish") //��������� ������ ��������
			{
				f_condition = DEL;
				current_task = "";
				return "��� ���������� �������� \"" + gcnew System::String(name.c_str()) + "\" � id = " + System::Convert::ToString(id) + " ������� � ��������� �������� (����������).";
			}
			else if (command == "nop")
			{
				f_condition = READY;
				current_task = "";
				return "������� \"" + gcnew System::String(name.c_str()) + "\" � id = " + System::Convert::ToString(id) + " �������� ������ ������� � ������� � ��������� ����������.";
			}
			else
			{
				f_condition = READY;
				current_task = "";
				return "��� ���������� �������� \"" + gcnew System::String(name.c_str()) + "\" � id = " + System::Convert::ToString(id) + " ���������� ����������� ������� \"" + gcnew System::String(command.c_str()) + "\". ������� � ������ �������� ���������. ������� ������� � ��������� ����������.";
			}
			break;

		case WAIT: //�������� (����������)
			int id_queue; //id �������, ������ ���� �������� ���������
			int type_queue_find; //��� ���������, ������� ���� ��������

			task_stream << current_task; //������� ����� �� ������ �������� �������
			task_stream >> command; //�������� ������� �� �������
			task_stream >> id_queue;
			task_stream >> type_queue_find;

			f_success = false;
			if (msgqs.is_queue_exists(id_queue) == true)
			{
				if (msgqs.msgget(id_queue, id)->is_this_type_exists(type_queue_find) == true)
				{
					f_success = true;
				}
			}
			if (f_success == true)
			{
				f_condition = EXECUT;

				if (type_queue_find != -1)
				{
					return "������� \"" + gcnew System::String(name.c_str()) + "\" � id = " + System::Convert::ToString(id) + " ����� � ������� ��������� � id = " + System::Convert::ToString(id_queue) + " ��������� ���� " + System::Convert::ToString(type_queue_find) + " � ������� � ��������� ����������.";
				}
				else
				{
					return "������� \"" + gcnew System::String(name.c_str()) + "\" � id = " + System::Convert::ToString(id) + " ����� � ������� ��������� � id = " + System::Convert::ToString(id_queue) + " ��������� ������ ���� � ������� � ��������� ����������.";
				}
			}
			else
			{
				if (type_queue_find != -1)
				{
					return "������� \"" + gcnew System::String(name.c_str()) + "\" � id = " + System::Convert::ToString(id) + " �� ����� ������� ��������� � id = " + System::Convert::ToString(id_queue) + " ���/� ��������� ���� " + System::Convert::ToString(type_queue_find) + " � ��� � ������� � ��������� �������� ��������� ���������.";
				}
				else
				{
					return "������� \"" + gcnew System::String(name.c_str()) + "\" � id = " + System::Convert::ToString(id) + " �� ����� ������� ��������� � id = " + System::Convert::ToString(id_queue) + " ���/� ��������� ����� ����� � ��� � ������� � ��������� �������� ��������� ���������.";
				}
			}
			break;
			
		case DEL:
			return "";
			break;
		}
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

	void set_name(string input)
	{
		name = input;
	}

	string get_name()
	{
		return name;
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
	
	int get_qty_tasks()
	{
		return qty_tasks;
	}

	string get_task(int number)
	{
		return queue_tasks[number];
	}

	string get_current_task()
	{
		return current_task;
	}

	string get_last_msg_data()
	{
		return last_msg.get_data();
	}
};

class Set_of_processes //������������ ���������
{
private:
	Process* processes; //��������
	int qty_processes; //���-�� ���������
public:
	Set_of_processes() //�����������
	{
		qty_processes = 0;
		processes = NULL;
	}

	void add(string name_input, string owner_name_input) //������� ������� (��������� �������� � �����������, ������� ������� ������, ���-�� ������� ����� ����)
	{
		Process* processes_new = new Process[qty_processes + 1];
		for (int i = 0; i < qty_processes; i++)
		{
			processes_new[i] = processes[i];
		}
		processes_new[qty_processes].init(++last_id_proc, name_input, owner_name_input, GENERAT);
		qty_processes++;

		delete[] processes;
		processes = processes_new;
	}

	bool del(int id_del) //������� ������� � ��������� ���������������
	{
		int i_deleted_proc = -1;
		for (int i = 0; i < qty_processes; i++)
		{
			if (processes[i].get_id() == id_del)
			{
				i_deleted_proc = i;
				break;
			}
		}
		if (i_deleted_proc == -1)
		{
			return false;
		}
		else
		{
			qty_processes--;
			Process* processes_new = NULL;
			if (qty_processes > 0)
			{
				processes_new = new Process[qty_processes];

				for (int i = 0, j = 0; j < qty_processes + 1; j++)
				{
					if (j != i_deleted_proc)
					{
						processes_new[i] = processes[j];
						i++;
					}
				}
			}

			delete[] processes;
			processes = processes_new;
			return true;
		}
	}

	Process* get_process(int id_proc) //�������� ��������� �� ������� � ��������� ���������������
	{
		Process* getted_proc = NULL;
		for (int i = 0; i < qty_processes; i++)
		{
			if (processes[i].get_id() == id_proc)
			{
				getted_proc = &processes[i];
				break;
			}
		}
		return getted_proc;
	}

	Process* output(int number) //�������� ��������� �� ������� � ��������� ��������
	{
		return &processes[number];
	}

	int get_qty() //�������� ���-�� ���������
	{
		return qty_processes;
	}
};