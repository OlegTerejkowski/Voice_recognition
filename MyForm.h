#pragma once
//#pragma comment(lib, "libsndfile-1.lib")

#define _CRT_SECURE_NO_WARNINGS


//#ifdef __cplusplus
/*extern "C"
{
#include "sndfile.h"
//#include "fftw3.h"
}
#endif*/
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

#define REAL 0
#define IMAG 1



namespace KursovaWF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  recognitionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  recognitionToolStripMenuItem1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;

	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::TextBox^  textBox1;





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
			this->recognitionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->recognitionToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->recognitionToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(825, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// recognitionToolStripMenuItem
			// 
			this->recognitionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->recognitionToolStripMenuItem1 });
			this->recognitionToolStripMenuItem->Name = L"recognitionToolStripMenuItem";
			this->recognitionToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->recognitionToolStripMenuItem->Text = L"File";
			this->recognitionToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::recognitionToolStripMenuItem_Click);
			// 
			// recognitionToolStripMenuItem1
			// 
			this->recognitionToolStripMenuItem1->Name = L"recognitionToolStripMenuItem1";
			this->recognitionToolStripMenuItem1->Size = System::Drawing::Size(138, 22);
			this->recognitionToolStripMenuItem1->Text = L"Recognition";
			this->recognitionToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::recognitionToolStripMenuItem1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(715, 27);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(87, 30);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Exit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(342, 149);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(128, 43);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Calculate FFT";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(342, 274);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(128, 43);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Calculate filters";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(342, 410);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(139, 48);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Calculate mel-cepstral";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(42, 149);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(227, 43);
			this->label1->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(42, 274);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(227, 43);
			this->label2->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(42, 415);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(227, 43);
			this->label3->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(42, 30);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(227, 43);
			this->label4->TabIndex = 8;
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(342, 30);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(128, 43);
			this->button5->TabIndex = 9;
			this->button5->Text = L"Read WAV file";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// label5
			// 
			this->label5->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(673, 132);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(102, 43);
			this->label5->TabIndex = 10;
			// 
			// label6
			// 
			this->label6->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label6->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(673, 195);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(102, 43);
			this->label6->TabIndex = 11;
			// 
			// label7
			// 
			this->label7->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label7->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(673, 252);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(102, 43);
			this->label7->TabIndex = 12;
			// 
			// label9
			// 
			this->label9->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label9->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(673, 318);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(102, 43);
			this->label9->TabIndex = 14;
			// 
			// label10
			// 
			this->label10->BackColor = System::Drawing::SystemColors::Control;
			this->label10->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(550, 132);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(102, 43);
			this->label10->TabIndex = 15;
			this->label10->Text = L"Frames";
			// 
			// label11
			// 
			this->label11->BackColor = System::Drawing::SystemColors::Control;
			this->label11->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(550, 195);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(102, 43);
			this->label11->TabIndex = 16;
			this->label11->Text = L"SampleRate";
			// 
			// label12
			// 
			this->label12->BackColor = System::Drawing::SystemColors::Control;
			this->label12->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(550, 252);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(102, 43);
			this->label12->TabIndex = 17;
			this->label12->Text = L"Channels";
			// 
			// label14
			// 
			this->label14->BackColor = System::Drawing::SystemColors::Control;
			this->label14->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label14->Location = System::Drawing::Point(550, 318);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(102, 43);
			this->label14->TabIndex = 19;
			this->label14->Text = L"Read items: ";
			// 
			// label15
			// 
			this->label15->BackColor = System::Drawing::SystemColors::Control;
			this->label15->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label15->Location = System::Drawing::Point(550, 71);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(225, 43);
			this->label15->TabIndex = 20;
			this->label15->Text = L"Information about file";
			this->label15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(275, 34);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(64, 39);
			this->textBox1->TabIndex = 21;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(825, 525);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		

	/*	void fft(fftw_complex *in, fftw_complex *out, int N) {
			fftw_plan plan = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
			fftw_execute(plan);
			fftw_destroy_plan(plan);
			fftw_cleanup();
		}
		void ifft(fftw_complex *in, fftw_complex *out, int N) {
			fftw_plan plan = fftw_plan_dft_1d(N, in, out, FFTW_BACKWARD, FFTW_ESTIMATE);
			fftw_execute(plan);
			fftw_destroy_plan(plan);
			fftw_cleanup();
			for (size_t i = 0; i < N; i++)
			{
				out[i][REAL] /= N;
				out[i][IMAG] /= N;

			}
		}*/


		//filter parametres            M - count of filters, F - chastota discret, N - registration count
		double B(double b) {
			double Bv;


			Bv = 1125 * log(1 + b / 700);         //b - ?????

			return Bv;
		}

		double B_forvard(double b) {
			double Bv;

			Bv = 700 * (exp(b / 1125) - 1);

			return Bv;
		}

		double fm(int m, int N, double F, int M, double f1, double fh) {
			double f;
			double bh = B(fh);
			double b1 = B(f1);
			double B_f = B_forvard(b1 + m * ((bh - b1) / (M + 1)));

			f = (N / F)*B_f;

			return f;
		}

		double Hm(double k, int m, int M, int N, double F, double f1, double fh) {     //m - number of filter
			double h;
			double fm_1 = fm(m - 1, N, F, M, f1, fh);
			double fm_plus1 = fm(m + 1, N, F, M, f1, fh);
			double fm_simple = fm(m, N, F, M, f1, fh);
			if (k<fm_1)
			{
				h = 0;
			}
			if (k >= fm_1 && k<fm_simple)
			{
				h = (k - fm_1) / (fm_simple - fm_1);             //1<=m=<M ?????
			}
			if (k >= fm_simple && k<fm_plus1)
			{
				h = (fm_plus1 - k) / (fm_plus1 - fm_simple);
			}
			if (k>fm_plus1)
			{
				h = 0;
			}

			return h;
		}






#pragma endregion
	private: System::Void recognitionToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void recognitionToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
		MyForm1^ f2 = gcnew MyForm1();
		f2->ShowDialog();
		
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	//first point
	//we have done the reading wav file to filedata.out

	vector<double>arr;
	ifstream array;
	string line;




	
	
	typedef void(*FNFUNC)();
	HMODULE h = LoadLibrary("libsndfile-1");
	if (h)
	{
		FNFUNC fn = (FNFUNC)GetProcAddress(h, "sf_open");
		if (fn)
			fn(); // call the function
	}
	SNDFILE *sf;
	SF_INFO info;
	int num_channels;
	int num, num_items;
	int *buf;
	int f, sr, c;
	int i, j;
	FILE *out;

	/* Open the WAV file. */
	
	info.format = 0;
	sf = sf_open("1b.wav", SFM_READ, &info);
	if (sf == NULL)
	{
		//printf("Failed to open the file.\n");
		label4->Text = "Failed to open the file.\n";
		//exit(-1);
	}
	/* Print some of the info, and figure out how much data to read. */
	f = info.frames;
	sr = info.samplerate;
	c = info.channels;
	//printf("frames=%d\n", f);
	label5->Text = Convert::ToString(f);
	//printf("samplerate=%d\n", sr);
	label6->Text = Convert::ToString(sr);
	//printf("channels=%d\n", c);
	label7->Text = Convert::ToString(c);
	num_items = f * c;
	//printf("num_items=%d\n", num_items);
	label8->Text = Convert::ToString(num_items);
	/* Allocate space for the data to be read, then read it. */
	buf = (int *)malloc(num_items * sizeof(int));
	num = sf_read_int(sf, buf, num_items);
	sf_close(sf);
	//printf("Read %d items\n", num);
	label9->Text = Convert::ToString(num);
	/* Write the data to filedata.out.*/
	out = fopen("filedata1.txt", "w");
	for (i = 0; i < num; i += c)
	{
		for (j = 0; j < c; ++j)
			fprintf(out, "%d ", buf[i + j]);
		fprintf(out, "\n");
	}
	fclose(out);



}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	vector<double>arr; 
	ifstream array;
	string line;
	



	if ((num & 1) != 0)
	{
		num = num - 1;
	}

	fftw_complex *cnum;

	cnum = (fftw_complex*)fftw_malloc(num * sizeof(fftw_complex));

	for (size_t i = 0; i < num; i++)
	{

		cnum[i][REAL] = buf[i];
		cnum[i][IMAG] = 0;
	}


	fftw_complex *y;

	y = (fftw_complex*)fftw_malloc(num * sizeof(fftw_complex));





	//cout << "FFT = " << endl;
	fft(cnum, y, num);
	label1->Text = "FFT read";
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	for (size_t i = 0; i < num; i++)
	{
		y[i][REAL] = y[i][REAL] * (0.54 - 0.46*cos(2 * PI*i / (num - 1)));
		y[i][IMAG] = y[i][IMAG] * (0.54 - 0.46*cos(2 * PI*i / (num - 1)));
	}


}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {

}
};
}
