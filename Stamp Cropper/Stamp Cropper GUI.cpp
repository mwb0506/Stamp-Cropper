#include "Stamp Cropper GUI.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	StampCropper::StampCropperGUI form;
	Application::Run(%form);
}
