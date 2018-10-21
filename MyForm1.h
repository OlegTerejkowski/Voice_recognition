#pragma once

#include "MyForm1.h"
#include "sndfile.h"
//#include "fftw3.h"
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <complex>
#include <algorithm>
#include <Windows.h>
#include <valarray>

namespace KursovaWF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//using namespace MySql::Data::MySqlClient;
	using namespace std;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
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
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox2;

	protected:

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(694, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(86, 28);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Exit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(196, 14);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(307, 45);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Identification";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(120, 142);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(126, 45);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"Enter file name";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(225, 218);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(130, 41);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Identificate";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(596, 218);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(119, 45);
			this->label3->TabIndex = 5;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(308, 147);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(103, 40);
			this->textBox2->TabIndex = 6;
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(808, 517);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



		//matrix of changing
		vector<vector<double> > Matr(vector<double>ai, vector<double>bj) {
			int i = ai.size();
			int j = bj.size();
			vector<vector<double> >dij(i, vector<double>(j));
			for (size_t c = 0; c < i; c++)
			{
				for (size_t d = 0; d < j; d++)
				{
					dij[c][d] = abs(ai[c] - bj[d]);
				}

			}

			return dij;
		}

		//matrix of transformation
		vector<vector<double> > mTransform(vector<vector<double> >dij) {
			int i = dij.size();                                      //c = i, d = j
			int j = dij[0].size();                                     //?????????
			vector<vector<double> > aij(i, vector<double>(j));
			aij[0][0] = dij[0][0];

			for (size_t c = 1; c < i; c++)
			{
				aij[c][0] = dij[c][0] + aij[c - 1][0];
			}

			for (size_t d = 1; d < j; d++)
			{
				aij[0][d] = dij[0][d] + aij[0][d - 1];
			}

			for (size_t c = 1; c < i; c++)
			{
				for (size_t d = 1; d < j; d++)
				{
					aij[c][d] = dij[c][d] + min(aij[c - 1][d - 1], min(aij[c - 1][d], aij[c][d - 1]));
				}

			}

			return aij;
		}

		//minimal distance
		

		vector<double>  mDist(vector<vector<double> >aij, vector<double>  minDist) {
			int i = aij.size() - 1;                                      //c = i, d = j
			int j = aij[0].size() - 1;

			minDist.push_back(aij[i][j]);

			do {
				if (i>0 && j>0)
					if (aij[i - 1][j - 1] <= aij[i - 1][j])
						if (aij[i - 1][j - 1] <= aij[i][j - 1]) { i--; j--; }
						else j--;
					else
						if (aij[i - 1][j] <= aij[i][j - 1])i--; else j--;
				else if (i == 0)j--; else i--;
				minDist.push_back(aij[i][j]);
			} while (i != 0 || j != 0);

			return minDist;
		}

		double GC(vector<vector<double> >minDist) {
			double glob = 0;
			int i = minDist.size();                                      //c = i, d = j
			int j = minDist[0].size();
			int lgth = i * j;
			for (size_t c = 0; c < i; c++)
			{
				for (size_t d = 0; d < j; d++)
				{
					glob += minDist[c][d];
				}
			}
			glob = glob / lgth;
			return glob;

		}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

		
		vector<double>ai;
		vector<double>bj;
		ifstream file1;
		file1.open("Cn.txt");
		string line1;
		string line2;
		while (getline(file1, line1)) {
			ai.push_back(atof(line1.c_str()));
		}
		ifstream file2;
		file2.open("Cn.txt");
		while (getline(file2, line2)) {
			bj.push_back(atof(line2.c_str()));
		}
		int sI = ai.size();
		int sJ = bj.size();
		vector<vector<double> > dij(sI, vector<double>(sJ));
		dij = Matr(ai, bj);
		vector<vector<double> > aij(sI, vector<double>(sJ));
		aij = mTransform(dij);
		vector<double>  md;

		md = mDist(aij, md);



		double gc = 0;
		for (size_t i = 0; i < md.size(); i++)
		{
			gc += md[i];
		}

		gc = gc / md.size();
		if (gc == 0)
		{
			label3->Text = "The command is: one";
		}
		else
		{
			label3->Text = "Undefined command";
		}
		//label3->Text = Convert::ToString(gc);
		file1.close();
		file2.close();
	

	}
};
}
