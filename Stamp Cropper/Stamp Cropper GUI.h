#pragma once

#using <mscorlib.dll>
#include <type_traits>

#include <stdio.h>
#include <string>
#include <iostream>
#include <io.h>
#include <time.h>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui.hpp>

#include <msclr/marshal.h>
#include <msclr\marshal_cppstd.h>

// Global variables
char buffer[100];
char filepathBuffer[100];
char trackBarBuffer[100];
char buttonBuffer[100];

int movingAverageWidth = 20;
double percentageTooBlack = 0.005;

int rowCount;
int columnCount;

bool show = false;
bool busy = false;

int trackNr = 1;
int scannr = 1;
std::string path = "D:\\Documenten\\Scans\\";
std::string country;
std::string michelNr;
int rotation = 0;
double bezelWidth = 150;
double binaryThreshold = 128;
double blacknessThreshold = 200;
double obliquenessThreshold = 25;
cv::Mat finalImageRotation;

namespace StampCropper {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Collections;

	/// <summary>
	/// Summary for StampCropperGUI
	/// </summary>
	public ref class StampCropperGUI : public System::Windows::Forms::Form
	{
	public:
		StampCropperGUI(void)
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
		~StampCropperGUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::TrackBar^  trackBar2;
	private: System::Windows::Forms::TrackBar^  trackBar3;
	private: System::Windows::Forms::CheckBox^  checkBox1;

	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TrackBar^  trackBar4;
	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::Windows::Forms::ToolTip^  toolTip2;
	private: System::Windows::Forms::ToolTip^  toolTip3;
	private: System::Windows::Forms::ToolTip^  toolTip4;
	private: System::Windows::Forms::ToolTip^  toolTip5;

	private: System::Windows::Forms::ToolTip^  toolTip7;
	private: System::Windows::Forms::ToolTip^  toolTip8;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::DirectoryServices::DirectoryEntry^  directoryEntry1;
	private: System::Windows::Forms::TrackBar^  trackBar5;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::ToolTip^  toolTip6;





	private: System::ComponentModel::IContainer^  components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->trackBar4 = (gcnew System::Windows::Forms::TrackBar());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip2 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip3 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip4 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip5 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip7 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip8 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->directoryEntry1 = (gcnew System::DirectoryServices::DirectoryEntry());
			this->trackBar5 = (gcnew System::Windows::Forms::TrackBar());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->toolTip6 = (gcnew System::Windows::Forms::ToolTip(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar5))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(409, 468);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(200, 28);
			this->button1->TabIndex = 0;
			this->button1->TabStop = false;
			this->button1->Text = L"Manual Reset";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &StampCropperGUI::button1_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(728, 461);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(110, 30);
			this->button3->TabIndex = 2;
			this->button3->TabStop = false;
			this->button3->Text = L"Previous";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &StampCropperGUI::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(844, 461);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(110, 30);
			this->button4->TabIndex = 3;
			this->button4->TabStop = false;
			this->button4->Text = L"Next";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &StampCropperGUI::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(960, 461);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(110, 30);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Save";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &StampCropperGUI::button5_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(688, 387);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseLeave += gcnew System::EventHandler(this, &StampCropperGUI::pictureBox1_MouseLeave);
			this->pictureBox1->MouseHover += gcnew System::EventHandler(this, &StampCropperGUI::pictureBox1_MouseHover);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(109, 464);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(50, 32);
			this->textBox1->TabIndex = 6;
			this->textBox1->TabStop = false;
			this->textBox1->Text = L"0001";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &StampCropperGUI::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(109, 428);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(500, 32);
			this->textBox2->TabIndex = 7;
			this->textBox2->TabStop = false;
			this->textBox2->Text = L"D:\\Documenten\\Scans\\";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &StampCropperGUI::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(259) {
				L"Algerije", L"Angola", L"Benin",
					L"Botswana", L"Burkina Faso", L"Burundi", L"Centraal-Afrikaanse Republiek", L"Comoren", L"Congo-Brazzaville", L"Congo-Kinshasa",
					L"Djibouti", L"Egypte", L"Equatoriaal-Guinea", L"Eritrea", L"Ethiopië", L"Gabon", L"Gambia", L"Ghana", L"Guinee", L"Guinee-Bissau",
					L"Ivoorkust", L"Kaapverdië", L"Kameroen", L"Kenia", L"Lesotho", L"Liberia", L"Libië", L"Madagaskar", L"Malawi", L"Mali", L"Marokko",
					L"Mauritanië", L"Mauritius", L"Mozambique", L"Namibië", L"Niger", L"Nigeria", L"Oeganda", L"Rwanda", L"Sao Tomé en Principe",
					L"Senegal", L"Seychellen", L"Sierra Leone", L"Somalië", L"Soedan", L"Swaziland", L"Tanzania", L"Togo", L"Tsjaad", L"Tunesië",
					L"Zambia", L"Zimbabwe", L"Zuid-Afrika", L"Zuid-Soedan", L"Australië", L"Fiji", L"Kiribati", L"Marshalleilanden", L"Micronesia",
					L"Nauru", L"Nieuw-Zeeland", L"Palau", L"Papoea-Nieuw-Guinea", L"Salomonseilanden", L"Samoa", L"Tonga", L"Tuvalu", L"Vanuatu",
					L"Afghanistan", L"Armenië", L"Azerbeidzjan", L"Bahrein", L"Bangladesh", L"Bhutan", L"Brunei", L"Cambodja", L"China", L"Cyprus",
					L"Filipijnen", L"Georgië", L"India", L"Indonesië", L"Irak", L"Iran", L"Israël", L"Japan", L"Jemen", L"Jordanië", L"Kazachstan",
					L"Kirgizië", L"Koeweit", L"Laos", L"Libanon", L"Maldiven", L"Maleisië", L"Mongolië", L"Myanmar", L"Nepal", L"Noord-Korea", L"Oezbekistan",
					L"Oman", L"Oost-Timor", L"Pakistan", L"Palestina", L"Qatar", L"Rusland", L"Saoedi-Arabië", L"Singapore", L"Sri Lanka", L"Syrië",
					L"Tadzjikistan", L"Thailand", L"Turkije", L"Turkmenistan", L"Verenigde Arabische Emiraten", L"Vietnam", L"Zuid-Korea", L"Albanië",
					L"Andorra", L"België", L"Bosnië en Herzegovina", L"Bulgarije", L"Denemarken", L"Duitsland", L"Estland", L"Finland", L"Frankrijk",
					L"Griekenland", L"Hongarije", L"Ierland", L"IJsland", L"Italië", L"Kroatië", L"Letland", L"Liechtenstein", L"Litouwen", L"Luxemburg",
					L"Macedonië", L"Malta", L"Moldavië", L"Monaco", L"Montenegro", L"Nederland", L"Noorwegen", L"Oekraïne", L"Oostenrijk", L"Polen",
					L"Portugal", L"Roemenië", L"Rusland", L"San Marino", L"Servië", L"Slovenië", L"Slowakije", L"Spanje", L"Tsjechië", L"Turkije",
					L"Vaticaanstad", L"Verenigd Koninkrijk", L"Wit-Rusland", L"Zweden", L"Zwitserland", L"Antigua en Barbuda", L"Bahama\'s", L"Barbados",
					L"Belize", L"Canada", L"Costa Rica", L"Cuba", L"Dominica", L"Dominicaanse Republiek", L"El Salvador", L"Grenada", L"Guatemala",
					L"Haïti", L"Honduras", L"Jamaica", L"Mexico", L"Nicaragua", L"Panama", L"Saint Kitts en Nevis", L"Saint Lucia", L"Saint Vincent en de Grenadines",
					L"Verenigde Staten", L"Argentinië", L"Bolivia", L"Brazilië", L"Chili", L"Colombia", L"Ecuador", L"Guyana", L"Paraguay", L"Peru",
					L"Suriname", L"Trinidad en Tobago", L"Uruguay", L"Venezuela", L"Abchazië", L"ADRS", L"Donetsk", L"Islamitische Staat", L"Loegansk",
					L"Nagorno-Karabach", L"Noord-Cyprus", L"Somaliland", L"Taiwan", L"Transnistrië", L"Zuid-Ossetië", L"Amerikaanse Maagdeneilanden",
					L"Amerikaans-Somoa", L"Guam", L"Noordelijke Marianen", L"Puerto Rico", L"Christmaseiland", L"Cocoseilanden", L"Norfolk", L"Akrotiri en Dhekelia",
					L"Anguilla", L"Bermuda", L"Brits Indische Oceaanterritorium", L"Britse Maagdeneilanden", L"Falklandeilanden", L"Gibraltar", L"Guernsey",
					L"Jersey", L"Kaaimaneilanden", L"Man", L"Montserrat", L"Pitcairneilanden", L"Sint-Helena, Ascension en Tristan da Cunha", L"Turks- en Caicoseilanden",
					L"Zuid-Georgia en de Zuidelijke Sandwicheilanden", L"Hongkong", L"Macau", L"Faeröer", L"Groenland", L"Åland", L"Frans-Guyana",
					L"Frans-Polynesië", L"Guadeloupe", L"Martinique", L"Mayotte", L"Nieuw-Caledonië", L"Réunion", L"Saint-Barthélemy", L"Saint-Pierre en Miquelon",
					L"Sint-Maarten", L"Wallis en Futuna", L"Aruba", L"Bonaire", L"Curaçao", L"Saba", L"Sint Eustatius", L"Sint Maarten", L"Cookeilanden",
					L"Niue", L"Tokelau", L"Jan Mayen", L"Spitsbergen"
			});
			this->textBox3->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->textBox3->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(870, 12);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(200, 32);
			this->textBox3->TabIndex = 8;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &StampCropperGUI::textBox3_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(870, 48);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(200, 32);
			this->textBox4->TabIndex = 9;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &StampCropperGUI::textBox4_TextChanged);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label1->Location = System::Drawing::Point(46, 431);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 24);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Path:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label2->Location = System::Drawing::Point(12, 470);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(91, 24);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Scan Nr.:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label3->Location = System::Drawing::Point(769, 15);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(86, 24);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Country:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label4->Location = System::Drawing::Point(748, 51);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(105, 24);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Michel Nr.:";
			this->label4->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label5->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label5->Location = System::Drawing::Point(820, 113);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(92, 24);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Rotation:";
			this->label5->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->label5->Click += gcnew System::EventHandler(this, &StampCropperGUI::label5_Click);
			// 
			// label6
			// 
			this->label6->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label6->Location = System::Drawing::Point(789, 175);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(123, 24);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Bezel Width:";
			this->label6->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->label6->Click += gcnew System::EventHandler(this, &StampCropperGUI::label6_Click);
			// 
			// label7
			// 
			this->label7->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label7->Location = System::Drawing::Point(756, 237);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(156, 24);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Binary Treshold:";
			this->label7->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->label7->Click += gcnew System::EventHandler(this, &StampCropperGUI::label7_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->LargeChange = 1;
			this->trackBar1->Location = System::Drawing::Point(918, 113);
			this->trackBar1->Maximum = 3;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(150, 56);
			this->trackBar1->TabIndex = 17;
			this->trackBar1->TabStop = false;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &StampCropperGUI::trackBar1_Scroll);
			this->trackBar1->MouseEnter += gcnew System::EventHandler(this, &StampCropperGUI::trackBar1_MouseEnter);
			this->trackBar1->MouseLeave += gcnew System::EventHandler(this, &StampCropperGUI::trackBar1_MouseLeave);
			// 
			// trackBar2
			// 
			this->trackBar2->LargeChange = 10;
			this->trackBar2->Location = System::Drawing::Point(918, 175);
			this->trackBar2->Maximum = 200;
			this->trackBar2->Minimum = 100;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(150, 56);
			this->trackBar2->TabIndex = 18;
			this->trackBar2->TabStop = false;
			this->trackBar2->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBar2->Value = 150;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &StampCropperGUI::trackBar2_Scroll);
			this->trackBar2->MouseEnter += gcnew System::EventHandler(this, &StampCropperGUI::trackBar2_MouseEnter);
			this->trackBar2->MouseLeave += gcnew System::EventHandler(this, &StampCropperGUI::trackBar2_MouseLeave);
			// 
			// trackBar3
			// 
			this->trackBar3->LargeChange = 10;
			this->trackBar3->Location = System::Drawing::Point(918, 237);
			this->trackBar3->Maximum = 192;
			this->trackBar3->Minimum = 64;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(150, 56);
			this->trackBar3->TabIndex = 19;
			this->trackBar3->TabStop = false;
			this->trackBar3->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBar3->Value = 128;
			this->trackBar3->Scroll += gcnew System::EventHandler(this, &StampCropperGUI::trackBar3_Scroll);
			this->trackBar3->MouseEnter += gcnew System::EventHandler(this, &StampCropperGUI::trackBar3_MouseEnter);
			this->trackBar3->MouseLeave += gcnew System::EventHandler(this, &StampCropperGUI::trackBar3_MouseLeave);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox1->Location = System::Drawing::Point(728, 424);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(129, 28);
			this->checkBox1->TabIndex = 20;
			this->checkBox1->TabStop = false;
			this->checkBox1->Text = L"Auto Reset";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox3->Location = System::Drawing::Point(876, 424);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(151, 28);
			this->checkBox3->TabIndex = 22;
			this->checkBox3->TabStop = false;
			this->checkBox3->Text = L"Auto Remove";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// label8
			// 
			this->label8->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(688, 363);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(224, 24);
			this->label8->TabIndex = 23;
			this->label8->Text = L"Obliqueness Threshold:";
			this->label8->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->label8->UseMnemonic = false;
			this->label8->Click += gcnew System::EventHandler(this, &StampCropperGUI::label8_Click);
			// 
			// trackBar4
			// 
			this->trackBar4->BackColor = System::Drawing::SystemColors::Control;
			this->trackBar4->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->trackBar4->Location = System::Drawing::Point(918, 361);
			this->trackBar4->Maximum = 50;
			this->trackBar4->Name = L"trackBar4";
			this->trackBar4->Size = System::Drawing::Size(150, 56);
			this->trackBar4->TabIndex = 24;
			this->trackBar4->TabStop = false;
			this->trackBar4->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBar4->Value = 25;
			this->trackBar4->Scroll += gcnew System::EventHandler(this, &StampCropperGUI::trackBar4_Scroll);
			this->trackBar4->MouseEnter += gcnew System::EventHandler(this, &StampCropperGUI::trackBar4_MouseEnter);
			this->trackBar4->MouseLeave += gcnew System::EventHandler(this, &StampCropperGUI::trackBar4_MouseLeave);
			// 
			// toolTip1
			// 
			this->toolTip1->AutoPopDelay = 30000;
			this->toolTip1->InitialDelay = 500;
			this->toolTip1->ReshowDelay = 100;
			// 
			// toolTip2
			// 
			this->toolTip2->AutoPopDelay = 30000;
			this->toolTip2->InitialDelay = 500;
			this->toolTip2->ReshowDelay = 100;
			// 
			// toolTip3
			// 
			this->toolTip3->AutoPopDelay = 30000;
			this->toolTip3->InitialDelay = 500;
			this->toolTip3->ReshowDelay = 100;
			// 
			// toolTip4
			// 
			this->toolTip4->AutoPopDelay = 30000;
			this->toolTip4->InitialDelay = 500;
			this->toolTip4->ReshowDelay = 100;
			// 
			// toolTip5
			// 
			this->toolTip5->AutoPopDelay = 30000;
			this->toolTip5->InitialDelay = 500;
			this->toolTip5->ReshowDelay = 100;
			// 
			// toolTip7
			// 
			this->toolTip7->AutoPopDelay = 30000;
			this->toolTip7->InitialDelay = 500;
			this->toolTip7->ReshowDelay = 100;
			// 
			// toolTip8
			// 
			this->toolTip8->AutoPopDelay = 30000;
			this->toolTip8->InitialDelay = 500;
			this->toolTip8->ReshowDelay = 100;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox2->Location = System::Drawing::Point(688, 0);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(402, 226);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 25;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Visible = false;
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(978, 393);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(59, 24);
			this->label9->TabIndex = 26;
			this->label9->Text = L"25 px";
			this->label9->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label9->Visible = false;
			// 
			// label10
			// 
			this->label10->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(978, 269);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(38, 24);
			this->label10->TabIndex = 27;
			this->label10->Text = L"0.5";
			this->label10->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label10->Visible = false;
			// 
			// label11
			// 
			this->label11->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(973, 207);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(63, 24);
			this->label11->TabIndex = 28;
			this->label11->Text = L"150%";
			this->label11->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label11->Visible = false;
			// 
			// label12
			// 
			this->label12->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(918, 145);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(30, 24);
			this->label12->TabIndex = 29;
			this->label12->Text = L"0°";
			this->label12->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label12->Visible = false;
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &StampCropperGUI::backgroundWorker1_DoWork);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &StampCropperGUI::backgroundWorker1_RunWorkerCompleted);
			// 
			// trackBar5
			// 
			this->trackBar5->BackColor = System::Drawing::SystemColors::Control;
			this->trackBar5->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->trackBar5->LargeChange = 100;
			this->trackBar5->Location = System::Drawing::Point(918, 299);
			this->trackBar5->Maximum = 1000;
			this->trackBar5->Minimum = 100;
			this->trackBar5->Name = L"trackBar5";
			this->trackBar5->Size = System::Drawing::Size(150, 56);
			this->trackBar5->SmallChange = 10;
			this->trackBar5->TabIndex = 30;
			this->trackBar5->TabStop = false;
			this->trackBar5->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBar5->Value = 200;
			this->trackBar5->Scroll += gcnew System::EventHandler(this, &StampCropperGUI::trackBar5_Scroll);
			this->trackBar5->MouseEnter += gcnew System::EventHandler(this, &StampCropperGUI::trackBar5_MouseEnter);
			this->trackBar5->MouseLeave += gcnew System::EventHandler(this, &StampCropperGUI::trackBar5_MouseLeave);
			// 
			// label13
			// 
			this->label13->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(714, 299);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(198, 24);
			this->label13->TabIndex = 31;
			this->label13->Text = L"Blackness Threshold:";
			this->label13->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->label13->UseMnemonic = false;
			this->label13->Click += gcnew System::EventHandler(this, &StampCropperGUI::label13_Click);
			// 
			// label14
			// 
			this->label14->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(930, 331);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(58, 24);
			this->label14->TabIndex = 32;
			this->label14->Text = L"2.0%";
			this->label14->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label14->Visible = false;
			// 
			// StampCropperGUI
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Inherit;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1082, 503);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->trackBar5);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->trackBar4);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->trackBar3);
			this->Controls->Add(this->trackBar2);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"StampCropperGUI";
			this->Text = L"Stamp Cropper";
			this->Load += gcnew System::EventHandler(this, &StampCropperGUI::StampCropperGUI_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar5))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

//
// Textboxes
//

private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	//
	// Scan Nr.
	//
	if (textBox1->Text->Length != 0) {
		std::string scannrString = msclr::interop::marshal_as<std::string>(textBox1->Text);
		scannr = stoi(scannrString);
		if (scannrString.length() == 4 && busy == false) {
			busy = true;
			backgroundWorker1->RunWorkerAsync();
		}
	}
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	//
	// Path
	//
	path = msclr::interop::marshal_as<std::string>(textBox2->Text);
	if (path[path.size()] != '\\') {
		path += '\\';
	}
}
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	//
	// Country
	//
	country = msclr::interop::marshal_as<std::string>(textBox3->Text);
}
private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	//
	// Michel Nr.
	//
	michelNr = msclr::interop::marshal_as<std::string>(textBox4->Text);
}

//
// Trackbars
//

private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
	//
	// Rotation 
	//
	rotation = trackBar1->Value;
	sprintf(trackBarBuffer, "%u°", 90 * trackBar1->Value);
	System::String^ data = gcnew System::String(trackBarBuffer);
	label12->Location = System::Drawing::Point(918 + 120 * trackBar1->Value / 3, 145);
	label12->Text = data;
	if (busy == false) {
		busy = true;
		backgroundWorker1->RunWorkerAsync();
	}
}
private: System::Void trackBar2_Scroll(System::Object^  sender, System::EventArgs^  e) {
	//
	// Bezel width
	//
	bezelWidth = trackBar2->Value;
	sprintf(trackBarBuffer, "%u%%", trackBar2->Value);
	System::String^ data = gcnew System::String(trackBarBuffer);
	label11->Location = System::Drawing::Point(918 + 110 * (trackBar2->Value - 100) / 100, 207);
	label11->Text = data;
	if (busy == false) {
		busy = true;
		backgroundWorker1->RunWorkerAsync();
	}
}
private: System::Void trackBar3_Scroll(System::Object^  sender, System::EventArgs^  e) {
	//
	// Binary Treshold
	//
	binaryThreshold = trackBar3->Value;
	sprintf(trackBarBuffer, "%0.2f", trackBar3->Value / 256.0);
	System::String^ data = gcnew System::String(trackBarBuffer);
	label10->Location = System::Drawing::Point(918 + 120 * (trackBar3->Value - 64) / 128, 269);
	label10->Text = data;
	if (busy == false) {
		busy = true;
		backgroundWorker1->RunWorkerAsync();
	}
}
private: System::Void trackBar4_Scroll(System::Object^  sender, System::EventArgs^  e) {
	//
	// Obliqueness Threshold
	//
	obliquenessThreshold = trackBar4->Value;
	sprintf(trackBarBuffer, "%u px", trackBar4->Value);
	System::String^ data = gcnew System::String(trackBarBuffer);
	label9->Location = System::Drawing::Point(918 + 110 * trackBar4->Value / 50, 393);
	label9->Text = data;
	if (busy == false) {
		busy = true;
		backgroundWorker1->RunWorkerAsync();
	}
}
private: System::Void trackBar5_Scroll(System::Object^  sender, System::EventArgs^  e) {
	//
	// Blackness Threshold
	//
	blacknessThreshold = trackBar5->Value;
	if (blacknessThreshold == 1000) {
		sprintf(trackBarBuffer, "%2.0f%%", trackBar5->Value / 100.0);
	}
	else {
		sprintf(trackBarBuffer, "%2.1f%%", trackBar5->Value / 100.0);
	}
	
	System::String^ data = gcnew System::String(trackBarBuffer);
	label14->Location = System::Drawing::Point(918 + 110 * (trackBar5->Value - 100) / 900, 331);
	label14->Text = data;
	if (busy == false) {
		busy = true;
		backgroundWorker1->RunWorkerAsync();
	}
}

//
// MouseEnter
//

private: System::Void trackBar1_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	label12->Visible = true;
}
private: System::Void trackBar2_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	label11->Visible = true;
}
private: System::Void trackBar3_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	label10->Visible = true;
}
private: System::Void trackBar5_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	label14->Visible = true;
}
private: System::Void trackBar4_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	label9->Visible = true;
}

//
// MouseHover
//

private: System::Void pictureBox1_MouseHover(System::Object^ sender, System::EventArgs^ e) {
	pictureBox2->Visible = true;
}

//
// MouseLeave
//

private: System::Void pictureBox1_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	pictureBox2->Visible = false;
}
private: System::Void trackBar1_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	label12->Visible = false;
}
private: System::Void trackBar2_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	label11->Visible = false;
}
private: System::Void trackBar3_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	label10->Visible = false;
}
private: System::Void trackBar5_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	label14->Visible = false;
}
private: System::Void trackBar4_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	label9->Visible = false;
}

//
// Labels
//
private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
	trackBar1_Scroll(sender, e);
}
private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
	trackBar2_Scroll(sender, e);
}
private: System::Void label7_Click(System::Object^  sender, System::EventArgs^  e) {
	trackBar3_Scroll(sender, e);
}
private: System::Void label13_Click(System::Object^  sender, System::EventArgs^  e) {
	trackBar5_Scroll(sender, e);
}
private: System::Void label8_Click(System::Object^  sender, System::EventArgs^  e) {
	trackBar4_Scroll(sender, e);
}

//
// Buttons
//

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	//
	// Manual reset
	//
	rotation = 0;
	trackBar1->Value = 0;
	bezelWidth = 150;
	trackBar2->Value = 150;
	binaryThreshold = 128;
	trackBar3->Value = 128;
	obliquenessThreshold = 25;
	trackBar4->Value = 25;
	blacknessThreshold = 200;
	trackBar5->Value = 200;
	if (busy == false) {
		busy = true;
		backgroundWorker1->RunWorkerAsync();
	}
	trackBar1_Scroll(sender, e);
	trackBar2_Scroll(sender, e);
	trackBar3_Scroll(sender, e);
	trackBar5_Scroll(sender, e);
	trackBar4_Scroll(sender, e);
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	//
	// Previous
	//
	if (checkBox1->Checked) {
		button1_Click(sender, e);
	}
	
	// Update pictureBox1
	char *cpath = &path[0u];
	sprintf(buttonBuffer, "%slt%04d.jpg", cpath, scannr);

	int offset = 0;
	for (int i = 1; i < scannr; i++) {
		sprintf(buttonBuffer, "%slt%04d.jpg", cpath, scannr - i);
		if (_access(buttonBuffer, 0) != -1) {
			scannr -= i;
			offset = i;
			break;
		}
	}

	if (!busy) {
		busy = true;
		backgroundWorker1->RunWorkerAsync();
	}
	else {
		scannr += offset;
	}

	// Update textBox1
	sprintf(buttonBuffer, "%04d", scannr);
	System::String^ data = gcnew System::String(buttonBuffer);
	textBox1->Text = data;
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	//
	// Next
	//
	// Reset of autoReset is true
	if (checkBox1->Checked) {
		button1_Click(sender, e);
	}

	// Update pictureBox1
	char *cpath = &path[0u];

	int offset = 0;
	for (int i = 1; i < 100; i++) {
		sprintf(buttonBuffer, "%slt%04d.jpg", cpath, scannr + i);
		if (_access(buttonBuffer, 0) != -1) {
			scannr += i;
			offset = i;
			break;
		}
	}

	if (!busy) {
		busy = true;
		backgroundWorker1->RunWorkerAsync();
	}
	else {
		scannr -= offset;
	}

	// Update textBox1
	sprintf(buttonBuffer, "%04d", scannr);
	System::String^ data = gcnew System::String(buttonBuffer);
	textBox1->Text = data;
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	//
	// Save
	//
	char *savePath = &path[0u];
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	char buf2[200];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
	char *ccountry = &country[0u];
	char *cmichelNr = &michelNr[0u];

	if (_access(savePath, 0) != -1) {
		if (trackNr == 1) {
			char buf3[20];
			sprintf(buf3, "%s nr*", buf);
			System::String^ search = gcnew System::String(buf3);
			array<System::String^>^ savedFiles = Directory::GetFiles(textBox2->Text, search);
			char b[2];
			if (savedFiles->Length > 0) {
				b[0] = savedFiles[savedFiles->Length - 1][strlen(savePath) + 14];
				b[1] = savedFiles[savedFiles->Length - 1][strlen(savePath) + 15];
				trackNr = 1 + std::stoi(b);
			}
		}
		sprintf(buf2, "%s%s nr %02d %s %s.jpg", savePath, buf, trackNr, ccountry, cmichelNr);
		cv::imwrite(buf2, finalImageRotation);
		trackNr++;
	}

	if (checkBox3->Checked) {
		remove(buffer);
	}
	
	// Reset of autoReset is true
	if (checkBox1->Checked) {
		button1_Click(sender, e);
	}

	// Update pictureBox1
	int offset = 0;
	for (int i = 1; i < 100; i++) {
		sprintf(buttonBuffer, "%slt%04d.jpg", savePath, scannr + i);
		if (_access(buttonBuffer, 0) != -1) {
			scannr += i;
			offset = i;
			break;
		}
	}

	if (!busy) {
		busy = true;
		backgroundWorker1->RunWorkerAsync();
	}
	else {
		scannr -= offset;
	}

	// Update textBox1
	sprintf(buttonBuffer, "%04d", scannr);
	System::String^ data = gcnew System::String(buttonBuffer);
	textBox1->Text = data;
}

//
// Tooltips
//

private: System::Void StampCropperGUI_Load(System::Object^  sender, System::EventArgs^  e) {
	button1_Click(sender, e);
	this->toolTip1->SetToolTip(this->label5, L"Rotate the image by a multiple of 90 degrees.");
	this->toolTip2->SetToolTip(this->label6, L"Increase this value to increase the amount of black space around the stamps if possible.");
	this->toolTip3->SetToolTip(this->label7, L"Value that determines which darkness corresponds to black."
											 L"\nDecrease value if the image contains to much black."
											 L"\nIncrease if the image contrains to much white."
											 L"\nNormalized range of [0.3, 0.7] (default 0.5). ");
	this->toolTip4->SetToolTip(this->label8, L"Amount of pixels of the edges that are automatically removed to account for obliqueness (sloped edge)."
											 L"\nThe higher the obliqueness, the higher this value should be (amount in pixels)."
											 L"\nLower this value if the image is too close to the edge.");
	this->toolTip5->SetToolTip(this->checkBox1, L"Resets the values of rotation, bezel width, binary threshold and blackness threshold automatically once previous, next or save is pressed.");
	this->toolTip6->SetToolTip(this->label13, L"Value that determines which percentage of a row (column) must be black in order for the entire row (column) to be classified as black."
											  L"\nIncrease if an abnormality causes a row (column) to be of an inconsistent darkness"
											  L"\nRange of 1%-10% (default 2%)");
	this->toolTip7->SetToolTip(this->checkBox3, L"Removes the original image once the cropped version is saved.");
	this->toolTip8->SetToolTip(this->button1, L"Resets the values of rotation, bezel width, binary threshold and blackness threshold.");
}

//
// BackgroundWorkers
//

private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
	// Update pictureBox1
	char *cpath = &path[0u];
	sprintf(buffer, "%slt%04d.jpg", cpath, scannr);
	System::String^ filepath = gcnew System::String(buffer);
	if (_access(buffer, 0) != -1) {
		// Read image and convert into grayscale
		cv::Mat imageMat = cv::imread(buffer, CV_LOAD_IMAGE_COLOR); // Load image
		cv::Mat grayscaleMatWhite; // (imageMat.size(), CV_8U); // Initialize grayscale image
		
		// cv::cvtColor(imageMat, grayscaleMatWhite, CV_BGR2GRAY); // Convert image to grayscale
		cv::Mat temp, bgr[3];
		cv::split(imageMat, bgr);                   // Split src into B,G,R channels
		(cv::max)(bgr[0], bgr[1], temp);            // Find minimum between B and G channels
		(cv::max)(temp, bgr[2], grayscaleMatWhite); // Find minimum between temp and R channels

		// First time converting to binary
		cv::Mat binaryMatWhite(grayscaleMatWhite.size(), grayscaleMatWhite.type()); // Initialize binary image
		cv::threshold(grayscaleMatWhite, binaryMatWhite, binaryThreshold, 1, cv::THRESH_BINARY); // Convert grayscale to binary

		int rowAmount = binaryMatWhite.size[0]; // Number of rows
		int columnAmount = binaryMatWhite.size[1]; // Number of columns
		double percentageBlack = 0.0001 * blacknessThreshold;

		// Sum of rows and columns of binary image
		cv::Mat columnSum, rowSum; // Initialize arrays for the summed columns and rows
		cv::reduce(binaryMatWhite, columnSum, 0, CV_REDUCE_SUM, CV_32S); // Sum columns of image to columnSum
		cv::reduce(binaryMatWhite, rowSum, 1, CV_REDUCE_SUM, CV_32S); // Sum rows of image to rowSum

		cv::Mat intermediateColumns(rowAmount, columnAmount, CV_8UC3);
		columnCount = 0; // Counter for the amount of remaining columns
		for (int i = obliquenessThreshold; i < columnAmount - obliquenessThreshold; i++) { // Sum over the columns
			if (percentageBlack * rowAmount < columnSum.at<int>(0, i) && columnSum.at<int>(0, i) < (1 - percentageBlack) * rowAmount) {
				imageMat.col(i).copyTo(intermediateColumns.col(columnCount)); // Copy column of original image to finalColumns
				columnCount++;
			}
		}

		if (columnCount == 0) {	columnCount++; }

		cv::Mat intermediateRows(rowAmount, columnAmount, CV_8UC3);
		rowCount = 0; // Counter for the amount of remaining columns
		for (int i = obliquenessThreshold; i < rowAmount - obliquenessThreshold; i++) { // Sum over the columns
			if (percentageBlack * columnAmount < rowSum.at<int>(i, 0) && rowSum.at<int>(i, 0) < (1 - percentageBlack) * columnAmount) {
				intermediateColumns.row(i).copyTo(intermediateRows.row(rowCount)); // Copy column of original image to finalColumns
				rowCount++;
			}
		}

		if (rowCount == 0) { rowCount++; }

		cv::Mat intermediateImage = intermediateRows(cv::Rect(0, 0, columnCount, rowCount));

		cv::Mat grayscaleMat; // (intermediateImage.size(), CV_8U); // Initialize grayscale image
		
		// cv::cvtColor(intermediateImage, grayscaleMat, CV_BGR2GRAY); // Convert image to grayscale
		cv::split(intermediateImage, bgr);     // Split src into B,G,R channels
		(cv::max)(bgr[0], bgr[1], temp);       // Find minimum between B and G channels
		(cv::max)(temp, bgr[2], grayscaleMat); // Find minimum between temp and R channels
																	// Second time converting to binary
		cv::Mat binaryMat(grayscaleMat.size(), grayscaleMat.type()); // Initialize binary image
		cv::threshold(grayscaleMat, binaryMat, binaryThreshold, 1, cv::THRESH_BINARY); // Convert grayscale to binary

		rowAmount = binaryMat.size[0]; // Number of rows
		columnAmount = binaryMat.size[1]; // Number of columns

		// Sum of rows and columns of binary image
		cv::reduce(binaryMat, columnSum, 0, CV_REDUCE_SUM, CV_32S); // Sum columns of image to columnSum
		cv::reduce(binaryMat, rowSum, 1, CV_REDUCE_SUM, CV_32S); // Sum rows of image to rowSum

		// Compare the blackness of the rows and columns to a preset value (0 if not too black, 255 if too black)
		cv::compare(columnSum, percentageBlack * rowAmount, columnSum, CV_CMP_LT); // Compage the columns 
		cv::compare(rowSum, percentageBlack * columnAmount, rowSum, CV_CMP_LT); // Compare the rows

		// Moving average of columns
		cv::Mat finalColumns(rowAmount, columnAmount, CV_8UC3); // Initialize image storing only remaining columns
		columnCount = 0; // Counter for the amount of remaining columns
		for (int i = obliquenessThreshold; i < columnAmount - obliquenessThreshold; i++) { // Sum over the columns
			if (cv::countNonZero(columnSum(cv::Range::all(), cv::Range(max(0, i - movingAverageWidth), min(columnAmount - 1, i + movingAverageWidth)))) 
					< percentageTooBlack * bezelWidth * (2 * movingAverageWidth + 1)) { // If the neighbourhood is not too black
				intermediateImage.col(i).copyTo(finalColumns.col(columnCount)); // Copy column of original image to finalColumns
				columnCount++; // Add to the counter
			}
		}

		if (columnCount == 0) { columnCount++; }

		// Moving average of rows
		cv::Mat finalRows(rowAmount, columnAmount, CV_8UC3); // Initialize image storing only remaining rows
		rowCount = 0; // Counter for the amount of remaining rows
		for (int i = obliquenessThreshold; i < rowAmount - obliquenessThreshold; i++) {
			if (cv::countNonZero(rowSum(cv::Range(max(0, i - movingAverageWidth), min(rowAmount - 1, i + movingAverageWidth)), cv::Range::all()))
					< percentageTooBlack * bezelWidth * (2 * movingAverageWidth + 1)) { // If the neighbourhood is not too black
				finalColumns.row(i).copyTo(finalRows.row(rowCount)); // Copy row of finalColumns to finalRows
				rowCount++; // Add to the counter
			}
		}

		if (rowCount == 0) { rowCount++; }

		// Crop image to only the remaining columns and rows
		cv::Mat finalImageFourBits;
		cvtColor(finalRows(cv::Rect(0, 0, columnCount, rowCount)), finalImageFourBits, CV_BGR2BGRA);
		if (rotation > 0) {
			cv::rotate(finalImageFourBits, finalImageRotation, rotation - 1);
		}
		else {
			finalImageRotation = finalImageFourBits;
		}

		// Release the krakens (Memory of Mat objects)
		imageMat.release();
		grayscaleMatWhite.release();
		binaryMatWhite.release();
		intermediateColumns.release();
		intermediateRows.release();
		intermediateImage.release();
		grayscaleMat.release();
		binaryMat.release();
		finalColumns.release();
		finalRows.release();
		finalImageFourBits.release();
		temp.release();
	}
}
private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
	busy = false;
	if (path[path.size() - 1] != '\\') {
		path += '\\';
	}

	char *cpath = &path[0u];
	sprintf(filepathBuffer, "%slt%04d.jpg", cpath, scannr);
	System::String^ filepath = gcnew System::String(buffer);
	if (_access(buffer, 0) != -1) {
		pictureBox2->Image = pictureBox2->Image->FromFile(filepath);
		// Display image
		System::Drawing::Graphics^ graphics = pictureBox1->CreateGraphics();
		System::Drawing::SolidBrush^ blackBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);
		System::IntPtr ptr(finalImageRotation.ptr());
		System::Drawing::Bitmap^ bitmap = gcnew System::Drawing::Bitmap(finalImageRotation.cols, finalImageRotation.rows, finalImageRotation.step, System::Drawing::Imaging::PixelFormat::Format32bppRgb, ptr);
		if (rotation == 1 || rotation == 3) {
			std::swap(rowCount, columnCount);
		}
		
		if (pictureBox1->Width * rowCount > columnCount * pictureBox1->Height) {
			double width = pictureBox1->Height * columnCount / rowCount;
			System::Drawing::RectangleF leftRect(0, 0, 0.5 * (pictureBox1->Width - width), pictureBox1->Height);
			graphics->FillRectangle(blackBrush, leftRect);
			System::Drawing::RectangleF rightRect(0.5 * (pictureBox1->Width + width), 0, 0.5 * (pictureBox1->Width - width), pictureBox1->Height);
			graphics->FillRectangle(blackBrush, rightRect);
			System::Drawing::RectangleF rect(0.5 * (pictureBox1->Width - width), 0, width, pictureBox1->Height);
			graphics->DrawImage(bitmap, rect);
		}
		else {
			double height = pictureBox1->Width * rowCount / columnCount;
			System::Drawing::RectangleF topRect(0, 0, pictureBox1->Width, 0.5 * (pictureBox1->Height - height));
			graphics->FillRectangle(blackBrush, topRect);
			System::Drawing::RectangleF bottomRect(0, 0.5 * (pictureBox1->Height + height), pictureBox1->Width, 0.5 * (pictureBox1->Height - height));
			graphics->FillRectangle(blackBrush, bottomRect);
			System::Drawing::RectangleF rect(0, 0.5 * (pictureBox1->Height - height), pictureBox1->Width, height);
			graphics->DrawImage(bitmap, rect);
		}
	}
	
}
};
}