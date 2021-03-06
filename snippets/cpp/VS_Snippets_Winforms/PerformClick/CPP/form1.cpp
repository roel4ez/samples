#using <System.Data.dll>
#using <System.Windows.Forms.dll>
#using <System.dll>
#using <System.Drawing.dll>

using namespace System;
using namespace System::Drawing;
using namespace System::Collections;
using namespace System::ComponentModel;
using namespace System::Windows::Forms;
using namespace System::Data;

/// <summary>
/// Summary description for Form1.
/// </summary>
public ref class Form1: public System::Windows::Forms::Form
{
private:

   /// <summary>
   /// Required designer variable.
   /// </summary>
   System::ComponentModel::Container^ components;

public:
   Form1()
   {
      components = nullptr;
      InitializeComponent();
      CreateMyMenu();
   }

public:

   /// <summary>
   /// Clean up any resources being used.
   /// </summary>
   ~Form1()
   {
      if ( components != nullptr )
      {
         delete components;
      }
   }

private:

   /// <summary>
   /// Required method for Designer support - do not modify
   /// the contents of this method with the code editor.
   /// </summary>
   void InitializeComponent()
   {
      //
      // Form1
      //
      this->ClientSize = System::Drawing::Size( 292, 276 );
      this->Name = "Form1";
      this->Text = "Form1";
      this->Load += gcnew System::EventHandler( this, &Form1::Form1_Load );
   }

   /// <summary>
   // <snippet1>
public:
   void CreateMyMenu()
   {
      // Create a main menu object.
      MainMenu^ mainMenu1 = gcnew MainMenu;

      // Create empty menu item objects.
      MenuItem^ menuItem1 = gcnew MenuItem;
      MenuItem^ menuItem2 = gcnew MenuItem;

      // Set the caption of the menu items.
      menuItem1->Text = "&File";
      menuItem2->Text = "&Edit";

      // Add the menu items to the main menu.
      mainMenu1->MenuItems->Add( menuItem1 );
      mainMenu1->MenuItems->Add( menuItem2 );

      // Add functionality to the menu items.
      menuItem1->Click += gcnew System::EventHandler( this, &Form1::menuItem1_Click );
      menuItem2->Click += gcnew System::EventHandler( this, &Form1::menuItem2_Click );

      // Assign mainMenu1 to the form.
      this->Menu = mainMenu1;

      // Perform a click on the File menu item.
      menuItem1->PerformClick();
   }

private:
   void menuItem1_Click( Object^ /*sender*/, System::EventArgs^ /*e*/ )
   {
      MessageBox::Show( "You clicked the File menu.", "The Event Information" );
   }

   void menuItem2_Click( Object^ /*sender*/, System::EventArgs^ /*e*/ )
   {
      MessageBox::Show( "You clicked the Edit menu.", "The Event Information" );
   }
   // </snippet1>

   void Form1_Load( Object^ /*sender*/, System::EventArgs^ /*e*/ ){}
};

/// The main entry point for the application.
/// </summary>

[STAThread]
int main()
{
   Application::Run( gcnew Form1 );
}
