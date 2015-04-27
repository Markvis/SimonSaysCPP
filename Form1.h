#pragma once
#include "simon.h"
#include "vector"
#include "algorithm"
#include "cstdlib"
#include "time.h"

namespace program_final {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  gameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  startToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  quitToolStripMenuItem;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->gameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->startToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->quitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->gameToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(589, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// gameToolStripMenuItem
			// 
			this->gameToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->startToolStripMenuItem, 
				this->quitToolStripMenuItem});
			this->gameToolStripMenuItem->Name = L"gameToolStripMenuItem";
			this->gameToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->gameToolStripMenuItem->Text = L"Game";
			// 
			// startToolStripMenuItem
			// 
			this->startToolStripMenuItem->Name = L"startToolStripMenuItem";
			this->startToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->startToolStripMenuItem->Text = L"New Game";
			this->startToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::startToolStripMenuItem_Click);
			// 
			// quitToolStripMenuItem
			// 
			this->quitToolStripMenuItem->Name = L"quitToolStripMenuItem";
			this->quitToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->quitToolStripMenuItem->Text = L"Quit";
			this->quitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::quitToolStripMenuItem_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(589, 429);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseClick);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
#pragma endregion
		rectangle ^ r,^wr;
		square ^ s,^ws;
		circle ^ c,^wc;
		ellipse ^ el,^we;

		std::vector <int> *v;
		std::vector <int>::iterator *it;
		std::vector <int>::iterator *itcn;

		cli::array <shape ^> ^ ptr2cs;
		cli::array <shape ^> ^ ptr2ws;

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 r = gcnew rectangle(380,160,Color::Aqua);
				 s = gcnew square(80,160,Color::Red);
				 c = gcnew circle(230,80,Color::LimeGreen);
				 el = gcnew ellipse(210,260,Color::Yellow);

				 wr = gcnew rectangle(380,160,Color::White);
				 ws = gcnew square(80,160,Color::White);
				 wc = gcnew circle(230,80,Color::White);
				 we = gcnew ellipse(210,260,Color::White);

				 v = new std::vector <int>;
				 it = new std::vector <int>::iterator;
				 itcn = new std::vector <int>::iterator;

				 ptr2cs = gcnew cli::array <shape ^> (4) {c,s,el,r};
				 ptr2ws = gcnew cli::array <shape ^> (4) {wc,ws,we,wr};
			 }

			 void flashshapes()
			 {
				 Graphics ^ pg = CreateGraphics();
				 int sub;

				 for(*it = v->begin(); *it != v->end();(*it)++)
				 {
					 sub = **it;
					 ptr2ws [sub]->draw(pg);
					 Thread::Sleep(300);
					 ptr2cs[sub]->draw(pg);
					 Thread::Sleep(300);
				 }
			 }

	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 Graphics ^ pg = CreateGraphics();
				 Brush ^ b = gcnew SolidBrush(Color::Black);
				 pg->FillEllipse(b,30,25,540,390);
				 r->draw(pg);
				 s->draw(pg);
				 c->draw(pg);
				 el->draw(pg);
			 }
	private: System::Void startToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 srand(time(NULL));
				 v->clear();
				 v->push_back(rand()%4);
				 *itcn = v->begin();
				 flashshapes();
			 }
			 
			 
private: System::Void Form1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 Graphics ^ pg = CreateGraphics();
			 bool gameover = false;
			 if(!gameover)
			 {
				 int x = e->X; int y = e->Y;
				 if(ptr2cs[**itcn]->containspt(x,y))
				 {
					 ptr2ws[**itcn]->draw(pg);
					 Thread::Sleep(300);
					 ptr2cs[**itcn]->draw(pg);
					 Thread::Sleep(300);
					 (*itcn)++;
				 }
				 else
				 {
					 int seq = 0;
					 for(*it = v->begin(); *it != v->end();(*it)++)
					 {
						 seq++;
					 }
					 MessageBox::Show("Gameover! " + "You're sequence # is: " + seq.ToString());
					 gameover = true;
				 }

				 if(*itcn == v->end())
				 {
					 v->push_back(rand() % 4);
					 *itcn = v->begin();
					 Thread::Sleep(400);
					 flashshapes();
				 }
			 }
		 }
private: System::Void quitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 exit(1);
		 }
};
}

