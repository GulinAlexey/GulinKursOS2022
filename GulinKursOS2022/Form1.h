#pragma once
#include <msclr/marshal_cppstd.h>
#include <ctime>
#include "classes.h"

#define TICK_TEXT (L"Прошло тиков : ")
#define PROCS_TEXT (L"Процессы. Кол-во: ")
#define QUEUES_TEXT (L"Очереди сообщений. Кол-во: ")
#define NOT_FIND_PROC_TEXT_1 (L"Процесс с id = ")
#define NOT_FIND_PROC_TEXT_2 (L" не найден. Задание \"")
#define NOT_FIND_PROC_TEXT_3 (L"\" не добавлено.")
#define DEL_PROC_TEXT_1 (L"Процесс с id = ")
#define DEL_PROC_TEXT_2 (L" успешно удалён.")
#define DEL_PROC_TEXT_2_2 (L" не найден. Ничего не удалено.")
#define DEL_TASK_TEXT_1 (L"Задание №")
#define DEL_TASK_TEXT_2 (L" процесса с id = ")
#define DEL_TASK_TEXT_3 (L" успешно удалено.")
#define DEL_TASK_TEXT_3_2 (L" не было найдено. Ничего не удалено.")

int all_ticks = 0; //всего прошло тиков таймера

namespace GulinKursOS2022 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer_exec;
	private: System::Windows::Forms::DataGridView^ t_procs;
	private: System::Windows::Forms::Label^ procs_text;

	private: System::Windows::Forms::DataGridView^ t_queues;
	private: System::Windows::Forms::Label^ queues_text;
















	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id_queue;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id_owner;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ msgs;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ qty_msgs;
	private: System::Windows::Forms::TextBox^ interval_text;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ start;
	private: System::Windows::Forms::Button^ pause;
	private: System::Windows::Forms::Label^ ticks_text;



	private: System::Windows::Forms::TextBox^ log;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DataGridView^ t_procs_new;



	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ add_proc_butt;

	private: System::Windows::Forms::DataGridView^ t_tasks_new;



	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ name_proc_new;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ name_owner_new;


	private: System::Windows::Forms::Button^ add_task_butt;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id_proc_task_new;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ task_text_new;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id_proc;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ owner_name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ condition;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ queue_tasks;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ current_task;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ qty_tasks;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ id_proc_del_text;
	private: System::Windows::Forms::Button^ ok_del_proc;
	private: System::Windows::Forms::Button^ ok_del_task;

	private: System::Windows::Forms::TextBox^ task_del_text;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ task_to_end;
	private: System::Windows::Forms::RadioButton^ task_to_begin;













	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->timer_exec = (gcnew System::Windows::Forms::Timer(this->components));
			this->t_procs = (gcnew System::Windows::Forms::DataGridView());
			this->id_proc = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->owner_name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->condition = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->queue_tasks = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->current_task = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->qty_tasks = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->procs_text = (gcnew System::Windows::Forms::Label());
			this->t_queues = (gcnew System::Windows::Forms::DataGridView());
			this->id_queue = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->id_owner = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->msgs = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->qty_msgs = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->queues_text = (gcnew System::Windows::Forms::Label());
			this->interval_text = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->start = (gcnew System::Windows::Forms::Button());
			this->pause = (gcnew System::Windows::Forms::Button());
			this->ticks_text = (gcnew System::Windows::Forms::Label());
			this->log = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->t_procs_new = (gcnew System::Windows::Forms::DataGridView());
			this->name_proc_new = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->name_owner_new = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->add_proc_butt = (gcnew System::Windows::Forms::Button());
			this->t_tasks_new = (gcnew System::Windows::Forms::DataGridView());
			this->id_proc_task_new = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->task_text_new = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->add_task_butt = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->id_proc_del_text = (gcnew System::Windows::Forms::TextBox());
			this->ok_del_proc = (gcnew System::Windows::Forms::Button());
			this->ok_del_task = (gcnew System::Windows::Forms::Button());
			this->task_del_text = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->task_to_end = (gcnew System::Windows::Forms::RadioButton());
			this->task_to_begin = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->t_procs))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->t_queues))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->t_procs_new))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->t_tasks_new))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer_exec
			// 
			this->timer_exec->Interval = 1000;
			this->timer_exec->Tick += gcnew System::EventHandler(this, &Form1::timer_exec_Tick);
			// 
			// t_procs
			// 
			this->t_procs->AllowUserToAddRows = false;
			this->t_procs->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->t_procs->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->t_procs->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->id_proc, this->name,
					this->owner_name, this->condition, this->queue_tasks, this->current_task, this->qty_tasks
			});
			this->t_procs->Location = System::Drawing::Point(15, 25);
			this->t_procs->Name = L"t_procs";
			this->t_procs->ReadOnly = true;
			this->t_procs->RowHeadersVisible = false;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->t_procs->RowsDefaultCellStyle = dataGridViewCellStyle1;
			this->t_procs->Size = System::Drawing::Size(903, 193);
			this->t_procs->TabIndex = 0;
			// 
			// id_proc
			// 
			this->id_proc->HeaderText = L"ID";
			this->id_proc->Name = L"id_proc";
			this->id_proc->ReadOnly = true;
			// 
			// name
			// 
			this->name->HeaderText = L"Имя процесса";
			this->name->Name = L"name";
			this->name->ReadOnly = true;
			// 
			// owner_name
			// 
			this->owner_name->HeaderText = L"Имя владельца процесса ";
			this->owner_name->Name = L"owner_name";
			this->owner_name->ReadOnly = true;
			// 
			// condition
			// 
			this->condition->HeaderText = L"Состояние";
			this->condition->Name = L"condition";
			this->condition->ReadOnly = true;
			// 
			// queue_tasks
			// 
			this->queue_tasks->HeaderText = L"Очередь заданий";
			this->queue_tasks->Name = L"queue_tasks";
			this->queue_tasks->ReadOnly = true;
			this->queue_tasks->Width = 200;
			// 
			// current_task
			// 
			this->current_task->HeaderText = L"Текущее задание";
			this->current_task->Name = L"current_task";
			this->current_task->ReadOnly = true;
			this->current_task->Width = 200;
			// 
			// qty_tasks
			// 
			this->qty_tasks->HeaderText = L"Кол-во заданий (кроме текущего)";
			this->qty_tasks->Name = L"qty_tasks";
			this->qty_tasks->ReadOnly = true;
			// 
			// procs_text
			// 
			this->procs_text->AutoSize = true;
			this->procs_text->Location = System::Drawing::Point(12, 9);
			this->procs_text->Name = L"procs_text";
			this->procs_text->Size = System::Drawing::Size(111, 13);
			this->procs_text->TabIndex = 1;
			this->procs_text->Text = L"Процессы. Кол-во: 0";
			// 
			// t_queues
			// 
			this->t_queues->AllowUserToAddRows = false;
			this->t_queues->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->t_queues->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->t_queues->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->id_queue, this->id_owner,
					this->msgs, this->qty_msgs
			});
			this->t_queues->Location = System::Drawing::Point(15, 254);
			this->t_queues->Name = L"t_queues";
			this->t_queues->ReadOnly = true;
			this->t_queues->RowHeadersVisible = false;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->t_queues->RowsDefaultCellStyle = dataGridViewCellStyle2;
			this->t_queues->Size = System::Drawing::Size(503, 188);
			this->t_queues->TabIndex = 2;
			// 
			// id_queue
			// 
			this->id_queue->HeaderText = L"ID";
			this->id_queue->Name = L"id_queue";
			this->id_queue->ReadOnly = true;
			// 
			// id_owner
			// 
			this->id_owner->HeaderText = L"ID процесса - владельца очереди";
			this->id_owner->Name = L"id_owner";
			this->id_owner->ReadOnly = true;
			// 
			// msgs
			// 
			this->msgs->HeaderText = L"Очередь сообщений";
			this->msgs->Name = L"msgs";
			this->msgs->ReadOnly = true;
			this->msgs->Width = 200;
			// 
			// qty_msgs
			// 
			this->qty_msgs->HeaderText = L"Кол-во сообщений";
			this->qty_msgs->Name = L"qty_msgs";
			this->qty_msgs->ReadOnly = true;
			// 
			// queues_text
			// 
			this->queues_text->AutoSize = true;
			this->queues_text->Location = System::Drawing::Point(12, 238);
			this->queues_text->Name = L"queues_text";
			this->queues_text->Size = System::Drawing::Size(162, 13);
			this->queues_text->TabIndex = 3;
			this->queues_text->Text = L"Очереди сообщений. Кол-во: 0";
			// 
			// interval_text
			// 
			this->interval_text->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->interval_text->Location = System::Drawing::Point(1010, 52);
			this->interval_text->Name = L"interval_text";
			this->interval_text->Size = System::Drawing::Size(100, 20);
			this->interval_text->TabIndex = 4;
			this->interval_text->Text = L"1000";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label2->Location = System::Drawing::Point(970, 36);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(171, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Интервал тика таймера в мс:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// start
			// 
			this->start->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->start->Location = System::Drawing::Point(973, 78);
			this->start->Name = L"start";
			this->start->Size = System::Drawing::Size(75, 26);
			this->start->TabIndex = 6;
			this->start->Text = L"Старт";
			this->start->UseVisualStyleBackColor = true;
			this->start->Click += gcnew System::EventHandler(this, &Form1::start_Click);
			// 
			// pause
			// 
			this->pause->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pause->Location = System::Drawing::Point(1066, 78);
			this->pause->Name = L"pause";
			this->pause->Size = System::Drawing::Size(75, 26);
			this->pause->TabIndex = 7;
			this->pause->Text = L"Пауза";
			this->pause->UseVisualStyleBackColor = true;
			this->pause->Click += gcnew System::EventHandler(this, &Form1::pause_Click);
			// 
			// ticks_text
			// 
			this->ticks_text->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->ticks_text->AutoSize = true;
			this->ticks_text->Location = System::Drawing::Point(1047, 9);
			this->ticks_text->Name = L"ticks_text";
			this->ticks_text->Size = System::Drawing::Size(94, 13);
			this->ticks_text->TabIndex = 8;
			this->ticks_text->Text = L"Прошло тиков : 0";
			// 
			// log
			// 
			this->log->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->log->BackColor = System::Drawing::SystemColors::MenuText;
			this->log->Font = (gcnew System::Drawing::Font(L"Consolas", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->log->ForeColor = System::Drawing::SystemColors::Info;
			this->log->Location = System::Drawing::Point(539, 254);
			this->log->Multiline = true;
			this->log->Name = L"log";
			this->log->ReadOnly = true;
			this->log->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->log->Size = System::Drawing::Size(379, 373);
			this->log->TabIndex = 9;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(536, 238);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Лог работы";
			// 
			// t_procs_new
			// 
			this->t_procs_new->AllowUserToAddRows = false;
			this->t_procs_new->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->t_procs_new->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->name_proc_new,
					this->name_owner_new
			});
			this->t_procs_new->Location = System::Drawing::Point(15, 466);
			this->t_procs_new->Name = L"t_procs_new";
			this->t_procs_new->RowHeadersVisible = false;
			this->t_procs_new->Size = System::Drawing::Size(204, 71);
			this->t_procs_new->TabIndex = 11;
			// 
			// name_proc_new
			// 
			this->name_proc_new->HeaderText = L"Имя процесса";
			this->name_proc_new->Name = L"name_proc_new";
			// 
			// name_owner_new
			// 
			this->name_owner_new->HeaderText = L"Имя владельца процесса ";
			this->name_owner_new->Name = L"name_owner_new";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 450);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(194, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Добавить процесс. Введите данные:";
			// 
			// add_proc_butt
			// 
			this->add_proc_butt->Location = System::Drawing::Point(225, 514);
			this->add_proc_butt->Name = L"add_proc_butt";
			this->add_proc_butt->Size = System::Drawing::Size(75, 23);
			this->add_proc_butt->TabIndex = 13;
			this->add_proc_butt->Text = L"Добавить";
			this->add_proc_butt->UseVisualStyleBackColor = true;
			this->add_proc_butt->Click += gcnew System::EventHandler(this, &Form1::add_proc_butt_Click);
			// 
			// t_tasks_new
			// 
			this->t_tasks_new->AllowUserToAddRows = false;
			this->t_tasks_new->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->t_tasks_new->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->id_proc_task_new,
					this->task_text_new
			});
			this->t_tasks_new->Location = System::Drawing::Point(15, 579);
			this->t_tasks_new->Name = L"t_tasks_new";
			this->t_tasks_new->RowHeadersVisible = false;
			this->t_tasks_new->Size = System::Drawing::Size(204, 47);
			this->t_tasks_new->TabIndex = 14;
			// 
			// id_proc_task_new
			// 
			this->id_proc_task_new->HeaderText = L"ID процесса";
			this->id_proc_task_new->Name = L"id_proc_task_new";
			// 
			// task_text_new
			// 
			this->task_text_new->HeaderText = L"Задание";
			this->task_text_new->Name = L"task_text_new";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 563);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(194, 13);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Добавить задание. Введите данные:";
			// 
			// add_task_butt
			// 
			this->add_task_butt->Location = System::Drawing::Point(225, 604);
			this->add_task_butt->Name = L"add_task_butt";
			this->add_task_butt->Size = System::Drawing::Size(75, 23);
			this->add_task_butt->TabIndex = 16;
			this->add_task_butt->Text = L"Добавить";
			this->add_task_butt->UseVisualStyleBackColor = true;
			this->add_task_butt->Click += gcnew System::EventHandler(this, &Form1::add_task_butt_Click);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1028, 600);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(119, 13);
			this->label1->TabIndex = 17;
			this->label1->Text = L"Гулин Алексей, ПИ-92";
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(1063, 617);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(84, 13);
			this->label6->TabIndex = 18;
			this->label6->Text = L"АлтГТУ 2022 г.";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(924, 128);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(140, 13);
			this->label7->TabIndex = 19;
			this->label7->Text = L"ID процесса для удаления";
			// 
			// id_proc_del_text
			// 
			this->id_proc_del_text->Location = System::Drawing::Point(940, 144);
			this->id_proc_del_text->Name = L"id_proc_del_text";
			this->id_proc_del_text->Size = System::Drawing::Size(100, 20);
			this->id_proc_del_text->TabIndex = 20;
			this->id_proc_del_text->Text = L"0";
			// 
			// ok_del_proc
			// 
			this->ok_del_proc->Location = System::Drawing::Point(1050, 142);
			this->ok_del_proc->Name = L"ok_del_proc";
			this->ok_del_proc->Size = System::Drawing::Size(75, 23);
			this->ok_del_proc->TabIndex = 21;
			this->ok_del_proc->Text = L"Удалить";
			this->ok_del_proc->UseVisualStyleBackColor = true;
			this->ok_del_proc->Click += gcnew System::EventHandler(this, &Form1::ok_del_proc_Click);
			// 
			// ok_del_task
			// 
			this->ok_del_task->Location = System::Drawing::Point(1050, 193);
			this->ok_del_task->Name = L"ok_del_task";
			this->ok_del_task->Size = System::Drawing::Size(75, 23);
			this->ok_del_task->TabIndex = 24;
			this->ok_del_task->Text = L"Удалить";
			this->ok_del_task->UseVisualStyleBackColor = true;
			this->ok_del_task->Click += gcnew System::EventHandler(this, &Form1::ok_del_task_Click);
			// 
			// task_del_text
			// 
			this->task_del_text->Location = System::Drawing::Point(940, 195);
			this->task_del_text->Name = L"task_del_text";
			this->task_del_text->Size = System::Drawing::Size(100, 20);
			this->task_del_text->TabIndex = 23;
			this->task_del_text->Text = L"0";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(924, 179);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(188, 13);
			this->label8->TabIndex = 22;
			this->label8->Text = L"Индекс задания для удаления (>=1)";
			// 
			// label9
			// 
			this->label9->Location = System::Drawing::Point(924, 219);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(217, 32);
			this->label9->TabIndex = 25;
			this->label9->Text = L"Для удаления задания также требуется ввести ID его процесса в поле выше.";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->task_to_end);
			this->groupBox1->Controls->Add(this->task_to_begin);
			this->groupBox1->Location = System::Drawing::Point(225, 563);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(238, 35);
			this->groupBox1->TabIndex = 26;
			this->groupBox1->TabStop = false;
			// 
			// task_to_end
			// 
			this->task_to_end->AutoSize = true;
			this->task_to_end->Checked = true;
			this->task_to_end->Location = System::Drawing::Point(6, 12);
			this->task_to_end->Name = L"task_to_end";
			this->task_to_end->Size = System::Drawing::Size(109, 17);
			this->task_to_end->TabIndex = 27;
			this->task_to_end->TabStop = true;
			this->task_to_end->Text = L"В конец очереди";
			this->task_to_end->UseVisualStyleBackColor = true;
			// 
			// task_to_begin
			// 
			this->task_to_begin->AutoSize = true;
			this->task_to_begin->Location = System::Drawing::Point(121, 12);
			this->task_to_begin->Name = L"task_to_begin";
			this->task_to_begin->Size = System::Drawing::Size(114, 17);
			this->task_to_begin->TabIndex = 28;
			this->task_to_begin->Text = L"В начало очереди";
			this->task_to_begin->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1153, 639);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->ok_del_task);
			this->Controls->Add(this->task_del_text);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->ok_del_proc);
			this->Controls->Add(this->id_proc_del_text);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->add_task_butt);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->t_tasks_new);
			this->Controls->Add(this->add_proc_butt);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->t_procs_new);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->log);
			this->Controls->Add(this->ticks_text);
			this->Controls->Add(this->pause);
			this->Controls->Add(this->start);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->interval_text);
			this->Controls->Add(this->queues_text);
			this->Controls->Add(this->t_queues);
			this->Controls->Add(this->procs_text);
			this->Controls->Add(this->t_procs);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Моделирование механизма межпроцессового взаимодействия на основе очереди сообщени"
				L"й";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->t_procs))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->t_queues))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->t_procs_new))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->t_tasks_new))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: void exec_procs() //выполнение работы процессов и вывод хода работы в лог
	{

	}

	public: System::String^ gettime(void) //вернуть полную строку даты и времени в соответствии с локалью
	{
			time_t now = time(0); //получить метку времени по Гринвичу
			struct tm timeinfo;
			localtime_s(&timeinfo, &now); //локализовать время
			char* format = "%H:%M:%S ";
			char buffer[80];
			strftime(buffer, 80, format, &timeinfo); //вывести время по формату в буфер
			string str_buffer(buffer); //переписать буфер в объект string

			return gcnew System::String(str_buffer.c_str()); //и вернуть этот объект
		}
	public: void refresh_t_procs() //вывести в таблицу информацию о процессах
	{
		//обновить инфо в таблице
		//очистить все строки перед выводом
		while (0 != t_procs->RowCount)
			t_procs->Rows->RemoveAt(0);

		for (int i = 0, j = 0; i < procs.get_qty(); i++)
		{
			t_procs->Rows->Add(); //добавить новую строку в таблицу
			//заполнить строку таблицы
			t_procs->Rows[i]->Cells[0]->Value = Convert::ToString(procs.output(i)->get_id());

			string string_ = procs.output(i)->get_name();
			t_procs->Rows[i]->Cells[1]->Value = gcnew System::String(string_.c_str());

			string_ = procs.output(i)->get_owner_name();
			t_procs->Rows[i]->Cells[2]->Value = gcnew System::String(string_.c_str());

			switch (procs.output(i)->get_f_condition())
			{
			case GENERAT:
				t_procs->Rows[i]->Cells[3]->Value = L"Порождение";
				break;
			case READY:
				t_procs->Rows[i]->Cells[3]->Value = L"Готовность";
				break;
			case EXECUT:
				t_procs->Rows[i]->Cells[3]->Value = L"Выполнение";
				break;
			case WAIT:
				t_procs->Rows[i]->Cells[3]->Value = L"Ожидание";
				break;
			case DEL:
				t_procs->Rows[i]->Cells[3]->Value = L"Удаление";
				break;
			}

			t_procs->Rows[i]->Cells[4]->Value = L"";

			for (int j = 0; j < procs.output(i)->get_qty_tasks(); j++)
			{
				string_ = procs.output(i)->get_task(j);
				t_procs->Rows[i]->Cells[4]->Value += gcnew System::String(string_.c_str()) + "\r\n";
			}

			string_ = procs.output(i)->get_current_task();
			t_procs->Rows[i]->Cells[5]->Value = gcnew System::String(string_.c_str());

			t_procs->Rows[i]->Cells[6]->Value = Convert::ToString(procs.output(i)->get_qty_tasks());

		}

		this->procs_text->Text = PROCS_TEXT + Convert::ToString(procs.get_qty());

	}
	public: void refresh_t_queues() //вывести в таблицу информацию об очередях сообщений
	{
		//обновить инфо в таблице
		//очистить все строки перед выводом
		while (0 != t_queues->RowCount)
			t_queues->Rows->RemoveAt(0);

		for (int i = 0, j = 0; i < msgqs.get_qty(); i++)
		{
			t_queues->Rows[i]->Cells[0]->Value = Convert::ToString(msgqs.output(i)->get_id());
			t_queues->Rows[i]->Cells[1]->Value = Convert::ToString(msgqs.output(i) ->get_id_owner());
			for (int j=0; j < msgqs.output(i)->get_qty(); j++)
			{
				string string_ = (msgqs.output(i) ->output(j))->get_data();
				t_queues->Rows[i]->Cells[2]->Value += L"ID: " + Convert::ToString((msgqs.output(i)->output(j))->get_id()) + L", тип: " + Convert::ToString((msgqs.output(i)->output(j))->get_type()) + L", текст: \"" + gcnew System::String(string_.c_str()) + "\", ID proc sender: " + Convert::ToString((msgqs.output(i)->output(j))->get_id_sender()) + "\r\n";
			}

			t_queues->Rows[i]->Cells[3]->Value = Convert::ToString(msgqs.output(i)->get_qty());

		}

		this->queues_text->Text = QUEUES_TEXT + Convert::ToString(msgqs.get_qty());
	}

	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		t_procs_new->Rows->Add();
		t_procs_new->Rows[0]->Cells[0]->Value = "proc";
		t_procs_new->Rows[0]->Cells[1]->Value = "user";

		t_tasks_new->Rows->Add();
		t_tasks_new->Rows[0]->Cells[0]->Value = "0";
		t_tasks_new->Rows[0]->Cells[1]->Value = "";
	}
private: System::Void pause_Click(System::Object^ sender, System::EventArgs^ e) { //пауза таймера
	this->timer_exec->Enabled = false;
}
private: System::Void start_Click(System::Object^ sender, System::EventArgs^ e) { //запуск таймера
	this->timer_exec->Interval = Convert::ToDouble(this->interval_text->Text);
	this->timer_exec->Enabled = true;
}
private: System::Void timer_exec_Tick(System::Object^ sender, System::EventArgs^ e) { //тик таймера
	this->ticks_text->Text = TICK_TEXT + Convert::ToString(++all_ticks);
}
private: System::Void add_task_butt_Click(System::Object^ sender, System::EventArgs^ e) { //добавить задание
	int int_id_proc_task_new = Convert::ToDouble((t_tasks_new->Rows[0]->Cells[0]->Value)->ToString());
	string s_task_text_new = msclr::interop::marshal_as<std::string>((t_tasks_new->Rows[0]->Cells[1]->Value)->ToString());

	Process *pr1 = procs.get_process(int_id_proc_task_new);
	if (pr1 == NULL)
	{
		this->log->AppendText(gettime() + NOT_FIND_PROC_TEXT_1 + t_tasks_new->Rows[0]->Cells[0]->Value + NOT_FIND_PROC_TEXT_2 + t_tasks_new->Rows[0]->Cells[1]->Value + NOT_FIND_PROC_TEXT_3 + "\r\n");
	}
	else
	{
		if (this->task_to_end->Checked == true)
		{
			pr1->add_task(s_task_text_new);
		}
		else
		{
			pr1->add_task_to_top(s_task_text_new);
		}
		t_tasks_new->Rows[0]->Cells[1]->Value = "";

		refresh_t_procs();
	}
}
private: System::Void add_proc_butt_Click(System::Object^ sender, System::EventArgs^ e) { //добавить процесс
	string s_name_proc_new = msclr::interop::marshal_as<std::string>((t_procs_new->Rows[0]->Cells[0]->Value)->ToString());
	string s_name_owner_new = msclr::interop::marshal_as<std::string>((t_procs_new->Rows[0]->Cells[1]->Value)->ToString());

	procs.add(s_name_proc_new, s_name_owner_new);
	t_procs_new->Rows[0]->Cells[0]->Value = "proc";

	refresh_t_procs();
}
private: System::Void ok_del_proc_Click(System::Object^ sender, System::EventArgs^ e) {
	if (procs.del(Convert::ToDouble(this->id_proc_del_text->Text)) == true)
	{
		this->log->AppendText(gettime() + DEL_PROC_TEXT_1 + Convert::ToDouble(this->id_proc_del_text->Text) + DEL_PROC_TEXT_2  + "\r\n");
		this->id_proc_del_text->Text = L"0";

		refresh_t_procs();
	}
	else
	{
		this->log->AppendText(gettime() + DEL_PROC_TEXT_1 + Convert::ToDouble(this->id_proc_del_text->Text) + DEL_PROC_TEXT_2_2 + "\r\n");
	}
}
private: System::Void ok_del_task_Click(System::Object^ sender, System::EventArgs^ e) {
	int f_success = 0;
	if (procs.get_process(Convert::ToDouble(this->id_proc_del_text->Text)) != NULL)
	{
		if (procs.get_process(Convert::ToDouble(this->id_proc_del_text->Text))->delete_task(Convert::ToDouble(this->task_del_text->Text)) == true)
		{
			f_success = 1;
			this->log->AppendText(gettime() + DEL_TASK_TEXT_1 + Convert::ToDouble(this->task_del_text->Text) + DEL_TASK_TEXT_2 + Convert::ToDouble(this->id_proc_del_text->Text) + DEL_TASK_TEXT_3 + "\r\n");

			this->task_del_text->Text = L"0";

			refresh_t_procs();
		}
	}
	if (f_success == 0)
	{
		this->log->AppendText(gettime() + DEL_TASK_TEXT_1 + Convert::ToDouble(this->task_del_text->Text) + DEL_TASK_TEXT_2 + Convert::ToDouble(this->id_proc_del_text->Text) + DEL_TASK_TEXT_3_2 + "\r\n");
	}
}
}
	;
}