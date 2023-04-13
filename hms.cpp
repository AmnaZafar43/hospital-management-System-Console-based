//--------Libraries------------
#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
//------------
//--------Prototypes-------
string who(string Parrusername[], string arrpassword[]);
void hms_header();
void addData(string username, string password, string role, string rolearrusername[], string arrpassword[]);
void header();
string Admin_menu();
string Doctor_menu();
string Patient_menu();
void add_doctors(string doc_name[], int doc_age[], string doc_spec[], string doc_gender[], string doc_mob[], string doc_blood[], string doc_id[], string doc_mail[], string doc_add[]);
void view_doctors(string doc_name[], int doc_age[], string doc_spec[], string doc_gender[], string doc_mob[], string doc_blood[], string doc_id[], string doc_mail[], string doc_add[]);
void delete_doctors(string doc_name[], int doc_age[], string doc_spec[], string doc_gender[], string doc_mob[], string doc_blood[], string doc_id[], string doc_mail[], string doc_add[]);
void update_doctors(string doc_name[], int doc_age[], string doc_spec[], string doc_gender[], string doc_mob[], string doc_blood[], string doc_id[], string doc_mail[], string doc_add[]);
void add_patients(string p_name[], int p_age[], string p_blood[], string p_disease[], string p_cnic[], string p_mob[], string p_add[], string p_gender[], string p_id[]);
void view_patients(string p_name[], int p_age[], string p_blood[], string p_disease[], string p_cnic[], string p_mob[], string p_add[], string p_gender[], string p_id[]);
void update_patients();
void view_appointments(string doc_name[], string p_name[], int p_age[], string p_blood[], string p_disease[], string p_cnic[], string p_mob[], string p_add[], string p_gender[], string p_id[]);
void book_appointments(string doc_name[], string p_name[], int p_age[], string p_blood[], string p_disease[], string p_cnic[], string p_mob[], string p_add[], string p_gender[], string p_id[]);
void update_patients(string p_name[], int p_age[], string p_blood[], string p_disease[], string p_cnic[], string p_mob[], string p_add[], string p_gender[], string p_id[]);
void delete_patients(string p_name[], int p_age[], string p_blood[], string p_disease[], string p_cnic[], string p_mob[], string p_add[], string p_gender[], string p_id[]);
void clear_screen();
string Doctor_menu();
void search_name(string p_name[], int p_age[], string p_blood[], string p_disease[], string p_cnic[], string p_mob[], string p_add[], string p_gender[], string p_id[]);
void prescription();
void view_prescription();
void doctor_sort(string doc_name[], int doc_age[], string doc_spec[], string doc_gender[], string doc_mob[], string doc_blood[], string doc_id[], string doc_mail[], string doc_add[]);
void patient_sort(string p_name[], int p_age[], string p_blood[], string p_disease[], string p_cnic[], string p_mob[], string p_add[], string p_gender[], string p_id[]);
void available_test();
void reports();
int menu();
void random_salary();
void update_salary();
void view_instructions();
void main_options();
void view_records(string p_name[], int p_age[], string p_blood[], string p_disease[], string p_cnic[], string p_mob[], string p_add[], string p_gender[], string p_id[]);
void load_doctordata(string doc_name[], int doc_age[], string doc_spec[], string doc_gender[], string doc_mob[], string doc_blood[], string doc_id[], string doc_mail[], string doc_add[]);
void load_patientdata(string p_name[], int p_age[], string p_blood[], string p_disease[], string p_cnic[], string p_mob[], string p_add[], string p_gender[], string p_id[]);
void parseData();
void update_patientdata(string doc_name[], string p_name[], int p_age[], string p_blood[], string p_disease[], string p_cnic[], string p_mob[], string p_add[], string p_gender[], string p_id[]);
void update_doctordata(string doc_name[], int doc_age[], string doc_spec[], string doc_gender[], string doc_mob[], string doc_blood[], string doc_id[], string doc_mail[], string doc_add[]);
//-----------------------------

//--------Variables----------
string login = " ";
const int size = 20;
int doc = 0;
int count = 0;
int pat = 0;
int tests = 0;
int pat_no = 0;
string prescriptions;
string arrrole[size];
//------------------------
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
// ------------------------------main-----------------------------------------
main()
{
  string arrusername[size];
  string arrpassword[size];
  string arrrole[size];
  int doc_age[size];
  int p_age[size];
  string p_name[size];
  string p_blood[size];
  string p_disease[size];
  string p_cnic[size];
  string p_mob[size];
  string p_add[size];
  string p_gender[size];
  string p_id[size];
  string test[size];
  string doc_name[size];
  string doc_spec[size];
  string doc_mob[size];
  string doc_blood[size];
  string doc_gender[size];
  string doc_mail[size];
  string doc_add[size];
  string doc_id[size];
  clear_screen();
  load_doctordata(doc_name, doc_age, doc_spec, doc_gender, doc_mob, doc_blood, doc_id, doc_mail, doc_add);
  load_patientdata(p_name, p_age, p_blood, p_disease, p_cnic, p_mob, p_add, p_gender, p_id);
  patient_sort(p_name, p_age, p_blood, p_disease, p_cnic, p_mob, p_add, p_gender, p_id);
  doctor_sort(doc_name, doc_age, doc_spec, doc_gender, doc_mob, doc_blood, doc_id, doc_mail, doc_add);
  int option = 0;
  addData("admin", "321", "Admin", arrusername, arrpassword);
  addData("doctor", "321", "Doctor", arrusername, arrpassword);
  addData("patient", "321", "Patient", arrusername, arrpassword);
  while (option < 5)
  {

    clear_screen();
    header();
    hms_header();
    option = menu();
    if (option == 1)
    { // start of if
      string w = who(arrusername, arrpassword);
      system("cls");
      string adminop = " ";
      if (w == "Admin")
      {

        patient_sort(p_name, p_age, p_blood, p_disease, p_cnic, p_mob, p_add, p_gender, p_id);
        clear_screen();
        while (true)
        { // start of while
          adminop = Admin_menu();
          if (adminop == "1")
          {
            clear_screen();
            header();
            add_doctors(doc_name, doc_age, doc_spec, doc_gender, doc_mob, doc_blood, doc_id, doc_mail, doc_add);
            clear_screen();
          }
          else if (adminop == "2")
          {
            doctor_sort(doc_name, doc_age, doc_spec, doc_gender, doc_mob, doc_blood, doc_id, doc_mail, doc_add);
            clear_screen();
            header();
            view_doctors(doc_name, doc_age, doc_spec, doc_gender, doc_mob, doc_blood, doc_id, doc_mail, doc_add);
            clear_screen();
          }
          else if (adminop == "3")
          {
            doctor_sort(doc_name, doc_age, doc_spec, doc_gender, doc_mob, doc_blood, doc_id, doc_mail, doc_add);
            clear_screen();
            header();
            view_doctors(doc_name, doc_age, doc_spec, doc_gender, doc_mob, doc_blood, doc_id, doc_mail, doc_add);
            delete_doctors(doc_name, doc_age, doc_spec, doc_gender, doc_mob, doc_blood, doc_id, doc_mail, doc_add);
            clear_screen();
          }
          else if (adminop == "4")
          {
            clear_screen();
            header();
            update_doctors(doc_name, doc_age, doc_spec, doc_gender, doc_mob, doc_blood, doc_id, doc_mail, doc_add);
            clear_screen();
          }
          else if (adminop == "5")
          {
            patient_sort(p_name, p_age, p_blood, p_disease, p_cnic, p_mob, p_add, p_gender, p_id);
            clear_screen();
            header();
            view_patients(p_name, p_age, p_blood, p_disease, p_cnic, p_mob, p_add, p_gender, p_id);
            clear_screen();
          }
          else if (adminop == "6")
          {
            clear_screen();
            header();
            view_patients(p_name, p_age, p_blood, p_disease, p_cnic, p_mob, p_add, p_gender, p_id);
            delete_patients(p_name, p_age, p_blood, p_disease, p_cnic, p_mob, p_add, p_gender, p_id);
            clear_screen();
          }
          else if (adminop == "7")
          {
            clear_screen();
            header();
            available_test();
            clear_screen();
          }
          else if (adminop == "8")
          {
            clear_screen();
            header();
            view_appointments(doc_name, p_name, p_age, p_blood, p_disease, p_cnic, p_mob, p_add, p_gender, p_id);
            clear_screen();
          }
          else if (adminop == "9")
          {
            clear_screen();
            header();
            view_instructions();
            clear_screen();
          }
          else if (adminop == "10")
          {
            clear_screen();
            break;
          }
          else
          {
            cout << "Invalid Option" << endl;
            clear_screen();
          }
        }
      }
      else
      {
        cout << "Invalid input" << endl;
      }
      clear_screen();
      update_doctordata(doc_name, doc_age, doc_spec, doc_gender, doc_mob, doc_blood, doc_id, doc_mail, doc_add);
    }
    else if (option == 2)
    { // start of if
      doctor_sort(doc_name, doc_age, doc_spec, doc_gender, doc_mob, doc_blood, doc_id, doc_mail, doc_add);
      patient_sort(p_name, p_age, p_blood, p_disease, p_cnic, p_mob, p_add, p_gender, p_id);
      string w = who(arrusername, arrpassword);
      if (w == "Doctor")
      {
        clear_screen();
        string doctorop = " ";
        while (true)
        { // start of while
          doctorop = Doctor_menu();
          if (doctorop == "1")
          {
            clear_screen();
            header();
            add_patients(p_name, p_age, p_blood, p_disease, p_cnic, p_mob, p_add, p_gender, p_id);
            clear_screen();
          }
          else if (doctorop == "2")
          {
            clear_screen();
            header();
            patient_sort(p_name, p_age, p_blood, p_disease, p_cnic, p_mob, p_add, p_gender, p_id);
            view_patients(p_name, p_age, p_blood, p_disease, p_cnic, p_mob, p_add, p_gender, p_id);
            clear_screen();
          }
          else if (doctorop == "3")
          {
            clear_screen();
            header();
            patient_sort(p_name, p_age, p_blood, p_disease, p_cnic, p_mob, p_add, p_gender, p_id);
            delete_patients(p_name, p_age, p_blood, p_disease, p_cnic, p_mob, p_add, p_gender, p_id);
            clear_screen();
          }
          else if (doctorop == "4")
          {
            clear_screen();
            header();
            search_name(p_name, p_age, p_blood, p_disease, p_cnic, p_mob, p_add, p_gender, p_id);
            clear_screen();
          }
          else if (doctorop == "5")
          {
            clear_screen();
            header();
            prescription();
            clear_screen();
          }
          else if (doctorop == "6")
          {
            clear_screen();
            header();
            view_appointments(doc_name, p_name, p_age, p_blood, p_disease, p_cnic, p_mob, p_add, p_gender, p_id);
            clear_screen();
          }
          else if (doctorop == "7")
          {
            clear_screen();
            header();
            available_test();
            clear_screen();
          }
          else if (doctorop == "8")
          {
            clear_screen();
            header();
            view_instructions();
            clear_screen();
          }
          else if (doctorop == "9")
          {
            break;
          }
          else
          {
            cout << "Invalid option " << endl;
            clear_screen();
          }
        }
      }
      else
      {
        cout << "Invalid " << endl;
        clear_screen();
      }
      update_patientdata(doc_name, p_name, p_age, p_blood, p_disease, p_cnic, p_mob, p_add, p_gender, p_id);
    }
    else if (option == 3)
    { // start of if
      doctor_sort(doc_name, doc_age, doc_spec, doc_gender, doc_mob, doc_blood, doc_id, doc_mail, doc_add);
      patient_sort(p_name, p_age, p_blood, p_disease, p_cnic, p_mob, p_add, p_gender, p_id);
      string w = who(arrusername, arrpassword);
      if (w == "Patient")
      {
        clear_screen();
        string patientop = " ";
        while (true)
        { // start of while
          patientop = Patient_menu();
          if (patientop == "1")
          {
            clear_screen();
            header();
            book_appointments(doc_name, p_name, p_age, p_blood, p_disease, p_cnic, p_mob, p_add, p_gender, p_id);
            clear_screen();
          }
          else if (patientop == "2")
          {
            clear_screen();
            header();
            view_appointments(doc_name, p_name, p_age, p_blood, p_disease, p_cnic, p_mob, p_add, p_gender, p_id);
            clear_screen();
          }
          else if (patientop == "3")
          {
            clear_screen();
            header();
            view_doctors(doc_name, doc_age, doc_spec, doc_gender, doc_mob, doc_blood, doc_id, doc_mail, doc_add);
            clear_screen();
          }
          else if (patientop == "4")
          {
            clear_screen();
            header();
            view_records(p_name, p_age, p_blood, p_disease, p_cnic, p_mob, p_add, p_gender, p_id);
            clear_screen();
          }
          else if (patientop == "5")
          {
            clear_screen();
            header();
            view_prescription();
            clear_screen();
          }
          else if (patientop == "6")
          {
            break;
          }
          else
          {
            cout << "Invalid " << endl;
            clear_screen();
          }
        }
      }
      else
      {
        cout << "Invalid " << endl;
        clear_screen();
      }
    }
    else if (option == 4)
    {
      clear_screen();
      header();
      view_instructions();
    }
  }
}

string who(string arrusername[], string arrpassword[])
//-----Take user name and password and return the role-----
{
  SetConsoleTextAttribute(h, 7);
  string role;
  string username, password;
  cout << "\nEnter username ";
  cin >> username;
  cout << "Enter password ";
  cin >> password;
  for (int i = 0; i < size; i++)
  {
    if (arrusername[i] == username && arrpassword[i] == password)
    {
      login = username;
      return arrrole[i];
    }
  }
  login = " ";
  SetConsoleTextAttribute(h, 7);
  return "Invalid";
}

void main_options()
{
  //----------Option for modules in which you want to go-------------------
  int option;
  cout << "Enter your option ";
  cin >> option;
}
void addData(string username, string password, string role, string arrusername[], string arrpassword[]) //-----Add data in arrays----
{
  //--------------Add data in array--------------------
  if (count < size)
  {
    arrusername[count] = username;
    arrpassword[count] = password;
    arrrole[count] = role;
    count++;
  }
  else
  {
    cout << "Sorry!no space";
  }
}
void header()
//-----------Header of System-------------
{

  SetConsoleTextAttribute(h, 9);
  cout << "\t\t ____         ____  ____           ____   ________________ " << endl;
  cout << "\t\t |  |         |  |  |  | |        ||  |   |                " << endl;
  cout << "\t\t |  |         |  |  |  |  |      | |  |   |                " << endl;
  cout << "\t\t |  |         |  |  |  |   |    |  |  |   |                " << endl;
  cout << "\t\t |  |_________|  |  |  |    |  |   |  |   |                " << endl;
  cout << "\t\t |               |  |  |     |     |  |   |_______________ " << endl;
  cout << "\t\t |   _________   |  |  |           |  |                  | " << endl;
  cout << "\t\t |  |         |  |  |  |           |  |                  | " << endl;
  cout << "\t\t |  |         |  |  |  |           |  |                  | " << endl;
  cout << "\t\t |  |         |  |  |  |           |  |                  | " << endl;
  cout << "\t\t |__|         |__|  |__|           |__|   _______________| " << endl;
  SetConsoleTextAttribute(h, 9);
}

void hms_header()
{
  //--------------Sub_header---------------
  SetConsoleTextAttribute(h, 3);
  cout << "\n\n\n";
  cout << "\t\t\t*****************************************************" << endl;
  cout << "\t\t\t********                                     ********" << endl;
  cout << "\t\t\t          Service Hospital Management System         " << endl;
  cout << "\t\t\t********                                     ********" << endl;
  cout << "\t\t\t*****************************************************" << endl;
  SetConsoleTextAttribute(h, 3);
}

int menu()
{
  //-----------Menu-------------
  int option;
  SetConsoleTextAttribute(h, 10);
  cout << "\n";
  cout << "\t ____________________________________________________ " << endl;
  cout << "\t|                                                    | " << endl;
  cout << "\t|                  1- Admin                          |" << endl;
  cout << "\t|                  2- Doctor                         |" << endl;
  cout << "\t|                  3- Patient                        |" << endl;
  cout << "\t|                  4- Instructions                   |" << endl;
  cout << "\t|                  5- Exit                           |" << endl;
  cout << "\t|____________________________________________________|" << endl;
  SetConsoleTextAttribute(h, 10);
  cout << "Enter your option ";
  cin >> option;
  return option;
}
void clear_screen()
{
  //------------To clear screen--------------
  cout << "Press any key to continue " << endl;
  getch();
  system("CLS");
}

string Admin_menu()
{
  //-----------------Admin options----------------------
  header();
  cout << endl;
  string option;
  SetConsoleTextAttribute(h, 4);
  cout << "\t\t _________________" << endl;
  cout << "\t\t|                 |" << endl;
  cout << "\t\t|     ADMIN       |" << endl;
  cout << "\t\t|_________________|" << endl;
  cout << "\n\n";
  cout << "\t\t      1- Add Doctors..." << endl;
  cout << "\t\t      2- View Doctors..." << endl;
  cout << "\t\t      3- Delete Doctors..." << endl;
  cout << "\t\t      4- Update Doctors..." << endl;
  cout << "\t\t      5- View Patient..." << endl;
  cout << "\t\t      6- Delete Patient..." << endl;
  cout << "\t\t      7- View Available Test Details..." << endl;
  cout << "\t\t      8- View Appointments..." << endl;
  cout << "\t\t      9- View Instructions..." << endl;
  cout << "\t\t     10- Logout..." << endl;
  cout << "\n";
  cout << "\t\t_____________________________________________" << endl;
  SetConsoleTextAttribute(h, 4);
  cout << endl;
  SetConsoleTextAttribute(h, 7);
  cout << "\nEnter your option ";
  cin >> option;
  SetConsoleTextAttribute(h, 7);
  return option;
}

string Doctor_menu()
{
  //---------------------Doctor options-------------------------
  header();
  cout << endl;
  string option;
  SetConsoleTextAttribute(h, 4);
  cout << "\t\t _________________" << endl;
  cout << "\t\t|                 |" << endl;
  cout << "\t\t|     DOCTOR      |" << endl;
  cout << "\t\t|_________________|" << endl;
  cout << "\n\n";
  cout << "\t\t1- Add Patient..." << endl;
  cout << "\t\t2- View Patients..." << endl;
  cout << "\t\t3- Delete Patients..." << endl;
  cout << "\t\t4- Search Patient By Name..." << endl;
  cout << "\t\t5- Give prescription..." << endl;
  cout << "\t\t6- View Apointments..." << endl;
  cout << "\t\t7- Laboratory Test..." << endl;
  cout << "\t\t8- View Instructions..." << endl;
  cout << "\t\t9- Logout..." << endl;
  cout << "\n";
  cout << "\t\t_____________________________________________" << endl;
  SetConsoleTextAttribute(h, 4);
  cout << endl;
  SetConsoleTextAttribute(h, 7);
  cout << "\nEnter your option ";
  cin >> option;
  SetConsoleTextAttribute(h, 7);
  return option;
}

string Patient_menu()
{
  //-----------------Patient menu--------------------
  header();
  cout << "\n";
  string option;
  SetConsoleTextAttribute(h, 4);
  cout << "\t\t _________________" << endl;
  cout << "\t\t|                 |" << endl;
  cout << "\t\t|     PATIENT     |" << endl;
  cout << "\t\t|_________________|" << endl;
  cout << "\n\n";
  cout << "\t\t1- Book Appointments..." << endl;
  cout << "\t\t2- View Apointments..." << endl;
  cout << "\t\t3- View Doctors..." << endl;
  cout << "\t\t4- View his/her Record..." << endl;
  cout << "\t\t5- View Prescriptions..." << endl;
  cout << "\t\t6- Logout..." << endl;
  cout << "\n";
  cout << "\t\t_____________________________________________" << endl;
  SetConsoleTextAttribute(h, 4);
  cout << endl;
  SetConsoleTextAttribute(h, 7);
  cout << "\n Enter your option ";
  cin >> option;
  SetConsoleTextAttribute(h, 7);
  return option;
}
void add_doctors(string doc_name[], int doc_age[], string doc_spec[], string doc_gender[], string doc_mob[], string doc_blood[], string doc_id[], string doc_mail[], string doc_add[])
{
  //----------------Add a doctor---------------------
  string mobile, blood;
  fstream file;
  SetConsoleTextAttribute(h, 7);
  cout << "\n\n\n";
  file.open("doctor.txt", ios::app);
  cout << "Enter doctor name... ";
  cin >> doc_name[doc];
  cout << "Enter doctor gender... ";
  cin >> doc_gender[doc];
  cout << "Enter doctor age... ";
  cin >> doc_age[doc];
  cout << "Enter specialization... ";
  cin >> doc_spec[doc];
  while (true)
  {
    cout << "Enter blood group... ";
    cin >> blood;
    if (blood.length() == 1 || blood.length() == 2 || blood.length() == 3)
    {
      doc_blood[doc] = blood;
      break;
    }
    else
    {
      cout << "Invalid" << endl;
    }
  }
  cout << "Enter doctor's ID... ";
  cin >> doc_id[doc];
  while (true)
  {

    cout << "Enter mobile no... ";
    cin >> mobile;
    if (mobile.length() == 11)
    {
      doc_mob[doc] = mobile;
      break;
    }
    else
    {
      cout << "Invalid" << endl;
    }
  }
  cout << "Enter doctor address... ";
  cin >> doc_add[doc];
  cout << "Enter Doctor's e-mail... ";
  cin >> doc_mail[doc];
  if (doc != 0)
  {
    file << endl;
  }
  file << doc_name[doc] << "," << doc_gender[doc] << "," << doc_age[doc] << "," << doc_spec[doc] << "," << doc_blood[doc] << "," << doc_id[doc] << "," << doc_mob[doc] << "," << doc_add[doc] << "," << doc_mail[doc];
  file.close();
  cout << "\n\n";
  SetConsoleTextAttribute(h, 7);
  doc++;
}

void view_doctors(string doc_name[], int doc_age[], string doc_spec[], string doc_gender[], string doc_mob[], string doc_blood[], string doc_id[], string doc_mail[], string doc_add[])
{
  //----------------View all doctors------------------
  cout << doc;
  int salary = 0;
  srand(time(0));
  SetConsoleTextAttribute(h, 4);
  cout << endl;
  cout << "\n\n\n\n";
  cout << "\t\t _________________" << endl;
  cout << "\t\t|                 |" << endl;
  cout << "\t\t|  VIEW DOCTORS   |" << endl;
  cout << "\t\t|_________________|" << endl;
  cout << "\n\n\n";
  SetConsoleTextAttribute(h, 4);
  SetConsoleTextAttribute(h, 9);
  cout << "*************************************************************************************************************************" << endl;
  SetConsoleTextAttribute(h, 9);
  SetConsoleTextAttribute(h, 4);
  cout << "\tDoctor Name\tDoctor ID\tGender\t\tAge\tSpecialization\tBlood_Group\tMobile-No\tAddress\t\tEmail" << endl;
  cout << "_________________________________________________________________________________________________________________________" << endl;
  SetConsoleTextAttribute(h, 4);
  SetConsoleTextAttribute(h, 8);
  for (int i = 0; i < doc; i++)
  {
    salary = salary + rand();
    salary = salary * 3;
    SetConsoleTextAttribute(h, 7);
    if (doc_id[i] != " ")
    {

      cout << "\t" << doc_name[i] << "\t\t" << doc_id[i] << "\t\t" << doc_gender[i] << "\t"<< " " << doc_age[i] << "\t"<< " " << doc_spec[i] << "\t"<< " " << doc_blood[i] << "\t" << " " << doc_mob[i] << "\t"<< " " << doc_add[i] << "\t"<< " " << doc_mail[i] << endl;
    }
    SetConsoleTextAttribute(h, 7);
  }
  SetConsoleTextAttribute(h, 9);
  cout << "*************************************************************************************************************************" << endl;
  SetConsoleTextAttribute(h, 9);
}

void delete_doctors(string doc_name[], int doc_age[], string doc_spec[], string doc_gender[], string doc_mob[], string doc_blood[], string doc_id[], string doc_mail[], string doc_add[])
{
  //---------------Delete doctor------------------
  string id, status;
  cout << "\n\n\n";
  cout << "     Press y for Continue to delete and n to go back :    ";
  cin >> status;
  if (status == "y" || status == "Y")
  {
    cout << "Enter doctor id ";
    cin >> id;
    for (int i = 0; i < doc; i++)
    {
      if (id == doc_id[i])
      {
        if (i != doc - 1)
        {
          for (int j = i; j < (doc); j++)
          {
            doc_name[j] = doc_name[j + 1];
            doc_age[j] = doc_age[j + 1];
            doc_blood[j] = doc_blood[j + 1];
            doc_spec[j] = doc_spec[j + 1];
            doc_mob[j] = doc_mob[j + 1];
            doc_blood[j] = doc_blood[j + 1];
            doc_gender[j] = doc_gender[j + 1];
            doc_mail[j] = doc_mail[j + 1];
            doc_add[j] = doc_add[j + 1];
            doc_id[j] = doc_id[j + 1];
          }
        }
        else
        {
        }
        doc--;
      }
    }
  }
}

void update_doctors(string doc_name[], int doc_age[], string doc_spec[], string doc_gender[], string doc_mob[], string doc_blood[], string doc_id[], string doc_mail[], string doc_add[])
{
  //------------------Update record----------------------------
  int idx;
  SetConsoleTextAttribute(h, 7);
  cout << "\n\n\n\n";
  cout << "\tEnter doctor's ID ";
  cin >> id;
  cout << "\tEnter which thing you want to change ";
  cin >> change;
  SetConsoleTextAttribute(h, 7);
  for (int i = 0; i < doc; i++)
  {
    if (id == doc_id[i])
    {
      idx = i;
      if (change == "name" || change == "Name" || change == "NAME")
      {
        SetConsoleTextAttribute(h, 7);
        cout << "\tEnter doctor name... ";
        cin >> doc_name[idx];
        SetConsoleTextAttribute(h, 7);
        cout << "\n\n";
        SetConsoleTextAttribute(h, 4);
        cout << "\t\t _________________" << endl;
        cout << "\t\t|                 |" << endl;
        cout << "\t\t|  UPDATE DOCTORS |" << endl;
        cout << "\t\t|_________________|" << endl;
        SetConsoleTextAttribute(h, 4);
        cout << "\n\n";
        SetConsoleTextAttribute(h, 9);
        cout << "*************************************************************************************************************************" << endl;
        SetConsoleTextAttribute(h, 9);
        SetConsoleTextAttribute(h, 4);
        cout << "\tDoctor Name\tDoctor ID\tGender\tAge\tSpecialization\tBlood_Group\tMobile-No\tAddress\tEmail" << endl;
        cout << "_________________________________________________________________________________________________________" << endl;
        SetConsoleTextAttribute(h, 4);
        SetConsoleTextAttribute(h, 7);
        cout << "\t" << doc_name[idx] << "\t" << doc_id[idx] << "\t" << doc_gender[idx] << "\t" << doc_age[idx] << "\t" << doc_spec[idx] << "\t" << doc_blood[idx] << "\t" << doc_mob[idx] << "\t" << doc_add[idx] << "\t" << doc_mail[idx] << endl;
        SetConsoleTextAttribute(h, 7);
        SetConsoleTextAttribute(h, 9);
        cout << "*************************************************************************************************************************" << endl;
        SetConsoleTextAttribute(h, 9);
      }
      else if (change == "id" || change == "Id" || change == "ID")
      {
        cout << "\tEnter doctor ID... ";
        cin >> doc_id[idx];
        cout << "\n\n";
        cout << "\t\t _________________" << endl;
        cout << "\t\t|                 |" << endl;
        cout << "\t\t|  UPDATE DOCTORS |" << endl;
        cout << "\t\t|_________________|" << endl;
        cout << "*************************************************************************************************************************" << endl;
        cout << "\tDoctor Name\tDoctor ID\tGender\tAge\tSpecialization\tBlood_Group\tMobile-No\tAddress\tEmail" << endl;
        cout << "\t" << doc_name[i] << "\t" << doc_id[idx] << "\t" << doc_gender[i] << "\t" << doc_age[i] << "\t" << doc_spec[i] << "\t" << doc_blood[i] << "\t" << doc_mob[i] << "\t" << doc_add[i] << "\t" << doc_mail[i] << endl;
        cout << "*************************************************************************************************************************" << endl;
      }
      else if (change == "gender" || change == "Gender" || change == "GENDER")
      {
        cout << "\tEnter doctor gender... ";
        cin >> doc_gender[idx];
        cout << "\n\n";
        cout << "\t\t _________________" << endl;
        cout << "\t\t|                 |" << endl;
        cout << "\t\t|  UPDATE DOCTORS |" << endl;
        cout << "\t\t|_________________|" << endl;
        cout << "*************************************************************************************************************************" << endl;
        cout << "\tDoctor Name\tDoctor ID\tGender\tAge\tSpecialization\tBlood_Group\tMobile-No\tAddress\tEmail" << endl;
        cout << "\t" << doc_name[i] << "\t" << doc_id[i] << "\t" << doc_gender[idx] << "\t" << doc_age[i] << "\t" << doc_spec[i] << "\t" << doc_blood[i] << "\t" << doc_mob[i] << "\t" << doc_add[i] << "\t" << doc_mail[i] << endl;
        cout << "*************************************************************************************************************************" << endl;
      }
      else if (change == "age" || change == "AGE" || change == "Age")
      {
        cout << "\tEnter doctor age... ";
        cin >> doc_age[idx];
        cout << "\n\n";
        cout << "\t\t _________________" << endl;
        cout << "\t\t|                 |" << endl;
        cout << "\t\t|  UPDATE DOCTORS |" << endl;
        cout << "\t\t|_________________|" << endl;
        cout << "*************************************************************************************************************************" << endl;
        cout << "\tDoctor Name\tDoctor ID\tGender\tAge\tSpecialization\tBlood_Group\tMobile-No\tAddress\tEmail" << endl;
        cout << "\t" << doc_name[i] << "\t" << doc_id[i] << "\t" << doc_gender[i] << "\t" << doc_age[idx] << "\t" << doc_spec[i] << "\t" << doc_blood[i] << "\t" << doc_mob[i] << "\t" << doc_add[i] << "\t" << doc_mail[i] << endl;
        cout << "*************************************************************************************************************************" << endl;
      }
      else if (change == "specialization" || change == "Spec" || change == "spec" || change == "Specialization")
      {
        cout << "\tEnter doctor specialization... ";
        cin >> doc_spec[idx];
        cout << "\n\n";
        cout << "\t\t _________________" << endl;
        cout << "\t\t|                 |" << endl;
        cout << "\t\t|  UPDATE DOCTORS |" << endl;
        cout << "\t\t|_________________|" << endl;
        cout << "*************************************************************************************************************************" << endl;
        cout << "\tDoctor Name\tDoctor ID\tGender\tAge\tSpecialization\tBlood_Group\tMobile-No\tAddress\tEmail" << endl;
        cout << "\t" << doc_name[i] << "\t" << doc_id[i] << "\t" << doc_gender[i] << "\t" << doc_age[i] << "\t" << doc_spec[idx] << "\t" << doc_blood[i] << "\t" << doc_mob[i] << "\t" << doc_add[i] << "\t" << doc_mail[i] << endl;
        cout << "*************************************************************************************************************************" << endl;
      }
      else if (change == "blood" || change == "Blood" || change == "BLOOD")
      {
        cout << "\tEnter doctor blood group... ";
        cin >> doc_blood[idx];
        cout << "\n\n";
        cout << "\t\t _________________" << endl;
        cout << "\t\t|                 |" << endl;
        cout << "\t\t|  UPDATE DOCTORS |" << endl;
        cout << "\t\t|_________________|" << endl;
        cout << "*************************************************************************************************************************" << endl;
        cout << "\tDoctor Name\tDoctor ID\tGender\tAge\tSpecialization\tBlood_Group\tMobile-No\tAddress\tEmail" << endl;
        cout << "\t" << doc_name[i] << "\t" << doc_id[i] << "\t" << doc_gender[i] << "\t" << doc_age[i] << "\t" << doc_spec[i] << "\t" << doc_blood[idx] << "\t" << doc_mob[i] << "\t" << doc_add[i] << "\t" << doc_mail[i] << endl;
        cout << "*************************************************************************************************************************" << endl;
      }
      else if (change == "mobile" || change == "Mobile" || change == "MOBILE")
      {
        cout << "\tEnter doctor mobile no... ";
        cin >> doc_mob[idx];
        cout << "\n\n";
        cout << "\t\t _________________" << endl;
        cout << "\t\t|                 |" << endl;
        cout << "\t\t|  UPDATE DOCTORS |" << endl;
        cout << "\t\t|_________________|" << endl;
        cout << "*************************************************************************************************************************" << endl;
        cout << "\tDoctor Name\tDoctor ID\tGender\tAge\tSpecialization\tBlood_Group\tMobile-No\tAddress\tEmail" << endl;
        cout << "\t" << doc_name[i] << "\t" << doc_id[i] << "\t" << doc_gender[i] << "\t" << doc_age[i] << "\t" << doc_spec[i] << "\t" << doc_blood[i] << "\t" << doc_mob[idx] << "\t" << doc_add[i] << "\t" << doc_mail[i] << endl;
        cout << "*************************************************************************************************************************" << endl;
      }
      else if (change == "address" || change == "Address" || change == "ADDRESS")
      {
        cout << "\tEnter doctor address... ";
        cin >> doc_add[idx];
        cout << "\n\n";
        cout << "\t\t _________________" << endl;
        cout << "\t\t|                 |" << endl;
        cout << "\t\t|  UPDATE DOCTORS |" << endl;
        cout << "\t\t|_________________|" << endl;
        cout << "*************************************************************************************************************************" << endl;
        cout << "\tDoctor Name\tDoctor ID\tGender\tAge\tSpecialization\tBlood_Group\tMobile-No\tAddress\tEmail" << endl;
        cout << "\t" << doc_name[i] << "\t" << doc_id[i] << "\t" << doc_gender[i] << "\t" << doc_age[i] << "\t" << doc_spec[i] << "\t" << doc_blood[i] << "\t" << doc_mob[i] << "\t" << doc_add[idx] << "\t" << doc_mail[i] << endl;
        cout << "*************************************************************************************************************************" << endl;
      }
      else if (change == "email" || change == "mail" || change == "e_mail" || change == "Email")
      {
        cout << "\tEnter doctor email... ";
        cin >> doc_mail[idx];
        cout << "\n\n";
        cout << "\t\t _________________" << endl;
        cout << "\t\t|                 |" << endl;
        cout << "\t\t|  UPDATE DOCTORS |" << endl;
        cout << "\t\t|_________________|" << endl;
        cout << "*************************************************************************************************************************" << endl;
        cout << "\tDoctor Name\tDoctor ID\tGender\tAge\tSpecialization\tBlood_Group\tMobile-No\tAddress\tEmail" << endl;
        cout << "\t" << doc_name[i] << "\t" << doc_id[i] << "\t" << doc_gender[i] << "\t" << doc_age[i] << "\t" << doc_spec[i] << "\t" << doc_blood[i] << "\t" << doc_mob[i] << "\t" << doc_add[i] << "\t" << doc_mail[idx] << endl;
        cout << "*************************************************************************************************************************" << endl;
      }
      else
      {
        cout << "Enter valid thing for change " << endl;
      }
    }
    SetConsoleTextAttribute(h, 8);
  }
}

void add_patients(string p_name[], int p_age[], string p_blood[], string p_disease[], string p_cnic[], string p_mob[], string p_add[], string p_gender[], string p_id[])
{
  //--------------------------Add patient--------------------------
  fstream file;
  string option, blood, cnic, mobile;
  SetConsoleTextAttribute(h, 7);
  cout << "\n\n\n";
  file.open("patient.txt", ios::app);
  cout << "Enter patient name... ";
  cin >> p_name[pat];
  cout << "Enter patient age... ";
  cin >> p_age[pat];
  cout << "Enter patient disease... ";
  cin >> p_disease[pat];
  while (true)
  {
    cout << "Enter blood group... ";
    cin >> blood;
    if (blood.length() == 1 || blood.length() == 2 || blood.length() == 3)
    {
      p_blood[pat] = blood;
      break;
    }
    else
    {
      cout << "Invalid" << endl;
    }
  }
  while (true)
  {
    cout << "Enter cnic number";
    cin >> cnic;
    if (cnic.length() == 13)
    {
      p_cnic[pat] = cnic;
      break;
    }
    else
    {
      cout << "Invalid" << endl;
    }
  }
  cout << "Enter patient id...";
  cin >> p_id[pat];
  cout << "Enter patient gender... ";
  cin >> p_gender[pat];
  while (true)
  {
    cout << "Enter mobile no";
    cin >> mobile;
    if (mobile.length() == 11)
    {
      p_mob[pat] = mobile;
      break;
    }
    else
    {
      cout << "Invalid" << endl;
    }
  }
  cout << "Enter patient address... ";
  cin >> p_add[pat];
  cout << "Did doctor recommend you any test... ";
  cin >> option;
  if (pat != 0)
  {
    file << endl;
  }

  file << p_name[pat] << "," << p_age[pat] << "," << p_disease[pat] << "," << p_blood[pat] << "," << p_cnic[pat] << "," << p_id[pat] << "," << p_gender[pat] << "," << p_mob[pat] << "," << p_add[pat];
  file.close();
  cout << "\n\n";
  SetConsoleTextAttribute(h, 7);
  pat++;
}

void view_patients(string p_name[], int p_age[], string p_blood[], string p_disease[], string p_cnic[], string p_mob[], string p_add[], string p_gender[], string p_id[])
{
  //--------------------View all patients---------------------------
  cout << "\n\n\n\n";
  SetConsoleTextAttribute(h, 4);
  cout << "\t\t _________________" << endl;
  cout << "\t\t|                 |" << endl;
  cout << "\t\t|  VIEW PATIENTS  |" << endl;
  cout << "\t\t|_________________|" << endl;
  SetConsoleTextAttribute(h, 4);
  cout << "\n\n\n";
  SetConsoleTextAttribute(h, 9);
  cout << "*************************************************************************************************************************" << endl;
  SetConsoleTextAttribute(h, 9);
  SetConsoleTextAttribute(h, 4);
  cout << "\tPatient Name\tID\tAge\tDisease\t\tGender\tBlood_Group\tCNIC\tMobile-No\tAddress" << endl;
  cout << "___________________________________________________________________________________________________________________________" << endl;
  SetConsoleTextAttribute(h, 4);
  for (int i = 0; i < pat; i++)
  {
    if (p_id[i] != " ")
    {
      SetConsoleTextAttribute(h, 7);
      cout << "\t" << p_name[i] << "\t" << p_id[i] << "\t" << p_age[i] << "\t" << p_disease[i] << "\t" << p_gender[i] << "\t" << p_blood[i] << "\t" << p_cnic[i] << "\t" << p_mob[i] << "\t" << p_add[i] << endl;
      SetConsoleTextAttribute(h, 7);
    }
  }
  SetConsoleTextAttribute(h, 9);
  cout << "*************************************************************************************************************************" << endl;
  SetConsoleTextAttribute(h, 9);
}

void update_patients(string p_name[], int p_age[], string p_blood[], string p_disease[], string p_cnic[], string p_mob[], string p_add[], string p_gender[], string p_id[])
{
  //--------------------------Update patient--------------------
  int idx;
  SetConsoleTextAttribute(h, 8);
  string id, change, name, gender, age, disease, blood, mob, add, cnic;
  cout << "Enter patient's ID ";
  cin >> id;
  cout << "Enter which thing you want to change ";
  cin >> change;

  for (int i = 0; i < pat; i++)
  {
    if (id == p_id[i])
    {
      idx = i;
      if (change == "name" || change == "Name" || change == "NAME")
      {
        cout << "Enter patient name... ";
        cin >> p_name[idx];
        cout << "\n\n\n\n";
        cout << "\t\t _________________" << endl;
        cout << "\t\t|                 |" << endl;
        cout << "\t\t|  UPDATE PATIENT |" << endl;
        cout << "\t\t|_________________|" << endl;
        cout << "\n\n\n";
        cout << "*************************************************************************************************************************" << endl;
        cout << "\tPatient Name\tID\tAge\tDisease\tGender\tBlood_Group\tCNIC\tMobile-No\tAddress" << endl;
        cout << "\t" << p_name[idx] << "\t" << p_id[i] << "\t" << p_age[i] << "\t" << p_disease[i] << "\t" << p_gender[i] << "\t" << p_blood[i] << "\t" << p_cnic[i] << "\t" << p_mob[i] << "\t" << p_add[i] << endl;
        cout << "*************************************************************************************************************************" << endl;
      }
      else if (change == "id" || change == "Id" || change == "ID")
      {
        cout << "Enter patient ID... ";
        cin >> p_id[idx];
        cout << "\n\n\n\n";
        cout << "\t\t _________________";
        cout << "\t\t|                 |" << endl;
        cout << "\t\t|  UPDATE PATIENT |" << endl;
        cout << "\t\t|_________________|" << endl;
        cout << "\n\n\n";
        cout << "*************************************************************************************************************************" << endl;
        cout << "\tPatient Name\tID\tAge\tDisease\tGender\tBlood_Group\tCNIC\tMobile-No\tAddress" << endl;
        cout << "\t" << p_name[i] << "\t" << p_id[idx] << "\t" << p_age[i] << "\t" << p_disease[i] << "\t" << p_gender[i] << "\t" << p_blood[i] << "\t" << p_cnic[i] << "\t" << p_mob[i] << "\t" << p_add[i] << endl;
        cout << "*************************************************************************************************************************" << endl;
      }
      else if (change == "gender" || change == "Gender" || change == "GENDER")
      {
        cout << "Enter doctor gender... ";
        cin >> p_gender[idx];
        cout << "\n\n\n\n";
        cout << "\t\t _________________" << endl;
        cout << "\t\t|                 |" << endl;
        cout << "\t\t|  UPDATE PATIENT |" << endl;
        cout << "\t\t|_________________|" << endl;
        cout << "\n\n\n";
        cout << "*************************************************************************************************************************" << endl;
        cout << "\tPatient Name\tID\tAge\tDisease\tGender\tBlood_Group\tCNIC\tMobile-No\tAddress" << endl;
        cout << "\t" << p_name[i] << "\t" << p_id[i] << "\t" << p_age[i] << "\t" << p_disease[i] << "\t" << p_gender[idx] << "\t" << p_blood[i] << "\t" << p_cnic[i] << "\t" << p_mob[i] << "\t" << p_add[i] << endl;
        cout << "*************************************************************************************************************************" << endl;
      }
      else if (change == "age" || change == "AGE" || change == "Age")
      {
        cout << "Enter doctor age... ";
        cin >> p_age[idx];
        cout << "\n\n\n\n";
        cout << "\t\t _________________" << endl;
        cout << "\t\t|                 |" << endl;
        cout << "\t\t|  UPDATE PATIENT |" << endl;
        cout << "\t\t|_________________|" << endl;
        cout << "\n\n\n";
        cout << "*************************************************************************************************************************" << endl;
        cout << "\tPatient Name\tID\tAge\tDisease\tGender\tBlood_Group\tCNIC\tMobile-No\tAddress" << endl;
        cout << "\t" << p_name[i] << "\t" << p_id[i] << "\t" << p_age[idx] << "\t" << p_disease[i] << "\t" << p_gender[i] << "\t" << p_blood[i] << "\t" << p_cnic[i] << "\t" << p_mob[i] << "\t" << p_add[i] << endl;
        cout << "*************************************************************************************************************************" << endl;
      }
      else if (change == "disease" || change == "Disease" || change == "DISEASE" || change == "dis" || change == "Dis")
      {
        cout << "Enter Patient disaese... ";
        cin >> p_disease[idx];
        cout << "\n\n\n\n";
        cout << "\t\t _________________" << endl;
        cout << "\t\t|                 |" << endl;
        cout << "\t\t|  UPDATE PATIENT |" << endl;
        cout << "\t\t|_________________|" << endl;
        cout << "\n\n\n";
        cout << "*************************************************************************************************************************" << endl;
        cout << "\tPatient Name\tID\tAge\tDisease\tGender\tBlood_Group\tCNIC\tMobile-No\tAddress" << endl;
        cout << "\t" << p_name[i] << "\t" << p_id[i] << "\t" << p_age[i] << "\t" << p_disease[idx] << "\t" << p_gender[i] << "\t" << p_blood[i] << "\t" << p_cnic[i] << "\t" << p_mob[i] << "\t" << p_add[i] << endl;
        cout << "*************************************************************************************************************************" << endl;
      }
      else if (change == "blood" || change == "Blood" || change == "BLOOD")
      {
        cout << "Enter patient blood group... ";
        cin >> p_blood[idx];
        cout << "\n\n\n\n";
        cout << "\t\t _________________" << endl;
        cout << "\t\t|                 |" << endl;
        cout << "\t\t|  UPDATE PATIENT |" << endl;
        cout << "\t\t|_________________|" << endl;
        cout << "\n\n\n";
        cout << "*************************************************************************************************************************" << endl;
        cout << "\tPatient Name\tID\tAge\tDisease\tGender\tBlood_Group\tCNIC\tMobile-No\tAddress" << endl;
        cout << "\t" << p_name[i] << "\t" << p_id[i] << "\t" << p_age[i] << "\t" << p_disease[i] << "\t" << p_gender[i] << "\t" << p_blood[idx] << "\t" << p_cnic[i] << "\t" << p_mob[i] << "\t" << p_add[i] << endl;
        cout << "*************************************************************************************************************************" << endl;
      }
      else if (change == "mobile" || change == "Mobile" || change == "MOBILE")
      {
        cout << "Enter patient mobile no... ";
        cin >> p_mob[idx];
        cout << "\n\n\n\n";
        cout << "\t\t _________________" << endl;
        cout << "\t\t|                 |" << endl;
        cout << "\t\t|  UPDATE PATIENT |" << endl;
        cout << "\t\t|_________________|" << endl;
        cout << "\n\n\n";
        cout << "*************************************************************************************************************************" << endl;
        cout << "\tPatient Name\tID\tAge\tDisease\tGender\tBlood_Group\tCNIC\tMobile-No\tAddress" << endl;
        cout << "\t" << p_name[i] << "\t" << p_id[i] << "\t" << p_age[i] << "\t" << p_disease[i] << "\t" << p_gender[i] << "\t" << p_blood[i] << "\t" << p_cnic[i] << "\t" << p_mob[idx] << "\t" << p_add[i] << endl;
        cout << "*************************************************************************************************************************" << endl;
      }
      else if (change == "address" || change == "Address" || change == "ADDRESS" || change == "add")
      {
        cout << "Enter patient address... ";
        cin >> p_add[idx];
        cout << "\n\n\n\n";
        cout << "\t\t _________________" << endl;
        cout << "\t\t|                 |" << endl;
        cout << "\t\t|  UPDATE PATIENT |" << endl;
        cout << "\t\t|_________________|" << endl;
        cout << "\n\n\n";
        cout << "*************************************************************************************************************************" << endl;
        cout << "\tPatient Name\tID\tAge\tDisease\tGender\tBlood_Group\tCNIC\tMobile-No\tAddress" << endl;
        cout << "\t" << p_name[i] << "\t" << p_id[i] << "\t" << p_age[i] << "\t" << p_disease[i] << "\t" << p_gender[i] << "\t" << p_blood[i] << "\t" << p_cnic[i] << "\t" << p_mob[i] << "\t" << p_add[idx] << endl;
        cout << "*************************************************************************************************************************" << endl;
      }
      else if (change == "cnic" || change == "CNIC" || change == "Cnic")
      {
        cout << "Enter patient cnic... ";
        cin >> p_cnic[idx];
        cout << "\n\n\n\n";
        cout << "\t\t _________________" << endl;
        cout << "\t\t|                 |" << endl;
        cout << "\t\t|  UPDATE PATIENT |" << endl;
        cout << "\t\t|_________________|" << endl;
        cout << "\n\n\n";
        cout << "*************************************************************************************************************************" << endl;
        cout << "\tPatient Name\tID\tAge\tDisease\tGender\tBlood_Group\tCNIC\tMobile-No\tAddress" << endl;
        cout << "\t" << p_name[i] << "\t" << p_id[i] << "\t" << p_age[i] << "\t" << p_disease[i] << "\t" << p_gender[i] << "\t" << p_blood[i] << "\t" << p_cnic[idx] << "\t" << p_mob[i] << "\t" << p_add[i] << endl;
        cout << "*************************************************************************************************************************" << endl;
      }
      else
      {
        cout << "Enter valid thing for change " << endl;
      }
    }
    else
    {
      cout << "\t\n No,match found!!" << endl;
    }
  }
  SetConsoleTextAttribute(h, 8);
}

void delete_patients(string p_name[], int p_age[], string p_blood[], string p_disease[], string p_cnic[], string p_mob[], string p_add[], string p_gender[], string p_id[])
{
  //-------------------Delete patient---------------------
  string id, status;
  cout << "\n\n\n";
  cout << "     Press y for Continue to delete and n for bypass   :    ";
  cin >> status;
  if (status == "y")
  {
    cout << "Enter patient id ";
    cin >> id;
    for (int i = 0; i < pat; i++)
    {
      if (id == p_id[i])
      {
        if (i != pat - 1)
        {
          for (int j = i; j < (pat); j++)
          {
            p_name[j] = p_name[j + 1];
            p_age[j] = p_age[j + 1];
            p_blood[j] = p_blood[j + 1];
            p_disease[j] = p_disease[j + 1];
            p_mob[j] = p_mob[j + 1];
            p_blood[j] = p_blood[j + 1];
            p_cnic[j] = p_cnic[j + 1];
            p_gender[j] = p_gender[j + 1];
            p_add[j] = p_add[j + 1];
            p_id[j] = p_id[j + 1];
          }
        }
        else
        {
        }
        pat--;
      }
    }
  }
}

void book_appointments(string doc_name[size], string p_name[], int p_age[], string p_blood[], string p_disease[], string p_cnic[], string p_mob[], string p_add[], string p_gender[], string p_id[])
{
  //-----------------------Book appointments wih doctor---------------------
  int age;
  string name, dis, blood, cnic, d_name;
  SetConsoleTextAttribute(h, 7);
  cout << "\n\n";
  cout << "Enter patient name... ";
  cin >> name;
  cout << "Enter patient age... ";
  cin >> age;
  cout << "Enter patient disease... ";
  cin >> dis;
  cout << "Enter blood-group... ";
  cin >> blood;
  cout << "Enter your CNIC... ";
  cin >> cnic;
  cout << "\n";
  cout << "******** AVAILABLE DOCTORS *********" << endl;
  cout << "1- Dr.Cato " << endl;
  cout << "2- Dr.Sam " << endl;
  cout << "3- Dr.Hazel" << endl;
  cout << "\n";
  cout << "Enter doctor name for appointment... ";
  cin >> d_name;
  if (pat_no <= 15)
  {
    p_name[pat] = name;
    p_age[pat] = age;
    p_disease[pat] = dis;
    p_blood[pat] = blood;
    p_cnic[pat] = cnic;
    doc_name[doc] = d_name;
    cout << "\t\t\t Appointment Booked!" << endl;
    cout << "\n\n";
    pat_no++;
  }
  else
  {
    cout << "\t\t Appointment not booked! Try next day." << endl;
  }
  SetConsoleTextAttribute(h, 7);
}

void view_appointments(string doc_name[], string p_name[], int p_age[], string p_blood[], string p_disease[], string p_cnic[], string p_mob[], string p_add[], string p_gender[], string p_id[])
{
  //----------------------View Appointments-------------------------
  SetConsoleTextAttribute(h, 4);
  cout << "\t\t ___________________" << endl;
  cout << "\t\t|                   |" << endl;
  cout << "\t\t| VIEW APPOINTMENTS |" << endl;
  cout << "\t\t|___________________|" << endl;
  SetConsoleTextAttribute(h, 4);
  cout << "\n\n\n";
  SetConsoleTextAttribute(h, 9);
  cout << "*************************************************************************************************************************" << endl;
  SetConsoleTextAttribute(h, 9);
  SetConsoleTextAttribute(h, 4);
  cout << "\tPatient Name\tPatient Age\tPatient Disease\tPatient blood group\tPatient Cnic\tDoctor Name" << endl;
  cout << "_________________________________________________________________________________________________________________________" << endl;
  SetConsoleTextAttribute(h, 4);
  SetConsoleTextAttribute(h, 7);
  for (int i = 0; i < pat; i++)
  {
    cout << "\t" << p_name[i] << "\t\t" << p_age[i] << "\t\t" << p_disease[i] << "\t\t" << p_blood[i] << "\t\t" << p_cnic[i] << "\t\t" << doc_name[i] << endl;
  }
  SetConsoleTextAttribute(h, 7);
  SetConsoleTextAttribute(h, 9);
  cout << "*************************************************************************************************************************" << endl;
  SetConsoleTextAttribute(h, 9);
  SetConsoleTextAttribute(h, 7);
}

void search_name(string p_name[], int p_age[], string p_blood[], string p_disease[], string p_cnic[], string p_mob[], string p_add[], string p_gender[], string p_id[])
{
  //--------------------search patient by name------------------------
  SetConsoleTextAttribute(h, 7);
  string name;
  cout << "\n\n\n";
  cout << "Enter patient name ";
  cin >> name;
  SetConsoleTextAttribute(h, 7);
  cout << endl;
  cout << "\n\n\n\n";
  SetConsoleTextAttribute(h, 4);
  cout << "\t\t _________________" << endl;
  cout << "\t\t|                 |" << endl;
  cout << "\t\t|  VIEW PATIENT   |" << endl;
  cout << "\t\t|_________________|" << endl;
  SetConsoleTextAttribute(h, 4);
  cout << "\n\n\n";
  SetConsoleTextAttribute(h, 9);
  cout << "*************************************************************************************************************************" << endl;
  SetConsoleTextAttribute(h, 9);
  SetConsoleTextAttribute(h, 4);
  cout << "\tPatient Name\tID\tAge\tDisease\tGender\tBlood_Group\tCNIC\tMobile-No\tAddress" << endl;
  cout << "____________________________________________________________________________________________________________________________" << endl;
  SetConsoleTextAttribute(h, 4);
  SetConsoleTextAttribute(h, 7);
  for (int i = 0; i < pat; i++)
  {
    if (name == p_name[i])
    {
      cout << "\t" << p_name[i] << "\t" << p_id[i] << "\t" << p_age[i] << "\t" << p_disease[i] << "\t" << p_gender[i] << "\t" << p_blood[i] << "\t" << p_cnic[i] << "\t" << p_mob[i] << "\t" << p_add[i] << endl;
      break;
      SetConsoleTextAttribute(h, 7);
    }
    else
    {
      cout << "Invalid name" << endl;
      break;
    }
  }
  SetConsoleTextAttribute(h, 9);
  cout << "*************************************************************************************************************************" << endl;
  SetConsoleTextAttribute(h, 9);
}

void view_instructions()
{
  //-----------------View hospital instructions---------------------
  SetConsoleTextAttribute(h, 7);
  cout << "\n\n\n";
  cout << "1- Make sure you are visiting hospital during visiting hours." << endl;
  cout << "2- Keep your voice low down and phone on silent in earmarked zone." << endl;
  cout << "3- Don't break hospital rules or violate safety." << endl;
  cout << "4- Don't touch any type of equipment." << endl;
  cout << "5- We provide advancing healthcare quality and patient safety." << endl;
  cout << "6- We are making healthcare data and perfomance measures transparent and publicly available." << endl;
  cout << "\n\n\n";
  SetConsoleTextAttribute(h, 7);
}

void available_test()
{
  string test_name;
  SetConsoleTextAttribute(h, 4);
  cout << "\t\t _________________" << endl;
  cout << "\t\t|                 |" << endl;
  cout << "\t\t|  TEST DETAILS   |" << endl;
  cout << "\t\t|_________________|" << endl;
  SetConsoleTextAttribute(h, 4);
  cout << "\n\n\n";
  SetConsoleTextAttribute(h, 9);
  cout << "\t ECG      " << endl;
  cout << "\t Liver Panel" << endl;
  cout << "\t Hemoglobin A1C" << endl;
  cout << "\t CBC          " << endl;
  SetConsoleTextAttribute(h, 9);
  cout << "\n\n";
  SetConsoleTextAttribute(h, 7);
  cout << " Enter your test name ";
  cin >> test_name;
  if (test_name == "ECG" || test_name == "Ecg" || test_name == "ecg")
  {

    cout << "Available" << endl;
  }
  else if (test_name == "Liver panel" || test_name == "LP" || test_name == "lp" || test_name == "liver panel")
  {
    cout << "Available" << endl;
  }
  else if (test_name == "hmg" || test_name == "Hmg" || test_name == "hemoglobin")
  {
    cout << "Available" << endl;
  }
  else if (test_name == "cbc" || test_name == "Cbc" || test_name == "CBC")
  {
    cout << "Available" << endl;
  }
  else
  {
    cout << "Not Available" << endl;
  }
  SetConsoleTextAttribute(h, 7);
}

void prescription()
{
  SetConsoleTextAttribute(h, 4);
  cout << "\n\n\n";
  cout << "\t\t _________________" << endl;
  cout << "\t\t|                 |" << endl;
  cout << "\t\t|  PRESCRIPTIONS  |" << endl;
  cout << "\t\t|_________________|" << endl;
  SetConsoleTextAttribute(h, 4);
  cout << "\n\n";
  SetConsoleTextAttribute(h, 7);
  cout << "Medicines given " << endl;
  cout << "-----1-    Drop Calpol 100" << endl;
  cout << " PARACETAMOL(100MG) " << endl;
  cout << "  0.75ml_Stat " << endl;
  cout << "-----2-    Syrup ibugesic Plus" << endl;
  cout << "  2ml - SoS" << endl;
  cout << "-----3-    Drop Ascroil LS" << endl;
  cout << " AMBROXOL(7.5)+LEVOSALBUTAMOL(0.25MG)+GUAIFENSIN" << endl;
  cout << "  1ml -3 times a day X 5 days(O--O--O)" << endl;
  cout << "-----4-    Drop Atarax" << endl;
  cout << "  HYDROXYZINE(6 MG)" << endl;
  cout << "  0.5ml- 2 times a day X 5 days(O--O)" << endl;
  cout << "-----5-     Nasoclear Nasal " << endl;
  cout << "  3 times a day X 5 days(O--O--O)" << endl;

  SetConsoleTextAttribute(h, 7);
}

void view_prescription()
{
  prescription();
}

void view_records(string p_name[], int p_age[], string p_blood[], string p_disease[], string p_cnic[], string p_mob[], string p_add[], string p_gender[], string p_id[])
{
  string name;
  cout << "\n\n\n";
  cout << "Enter patient name ";
  cin >> name;
  SetConsoleTextAttribute(h, 7);
  cout << endl;
  cout << "\n\n\n\n";
  SetConsoleTextAttribute(h, 4);
  cout << "\t\t _________________" << endl;
  cout << "\t\t|                 |" << endl;
  cout << "\t\t|  VIEW PATIENT   |" << endl;
  cout << "\t\t|_________________|" << endl;
  SetConsoleTextAttribute(h, 4);
  cout << "\n\n\n";
  SetConsoleTextAttribute(h, 9);
  cout << "*************************************************************************************************************************" << endl;
  SetConsoleTextAttribute(h, 9);
  SetConsoleTextAttribute(h, 4);
  cout << "\tPatient Name\tID\tAge\tDisease\tGender\tBlood_Group\tCNIC\tMobile-No\tAddress" << endl;
  cout << "____________________________________________________________________________________________________________________________" << endl;
  SetConsoleTextAttribute(h, 4);
  for (int i = 0; i <= pat; i++)
  {
    if (name == p_name[i])
    {
      SetConsoleTextAttribute(h, 7);
      cout << "\t" << p_name[i] << "\t" << p_id[i] << "\t" << p_age[i] << "\t" << p_disease[i] << "\t" << p_gender[i] << "\t" << p_blood[i] << "\t" << p_cnic[i] << "\t" << p_mob[i] << "\t" << p_add[i] << endl;
      break;
      SetConsoleTextAttribute(h, 7);
    }
    else
    {
      cout << "Invalid name" << endl;
      break;
    }
  }
  SetConsoleTextAttribute(h, 9);
  cout << "*************************************************************************************************************************" << endl;
  SetConsoleTextAttribute(h, 9);
}

string parseData(string record, int field)
{
  int commacount = 1;
  string item;
  int index = 0;
  while (true)
  {
    char ch = record[index];
    if (ch == '\0')
    {

      return item;
    }
    if (ch == ',')
    {
      commacount++;
    }
    else if (commacount == field)
    {
      item = item + ch;
    }
    index++;
  }
  return item;
}

void load_doctordata(string doc_name[], int doc_age[], string doc_spec[], string doc_gender[], string doc_mob[], string doc_blood[], string doc_id[], string doc_mail[], string doc_add[])
{
  string word;
  fstream file;
  file.open("doctor.txt", ios::in);
  if (!file)
    return;
  while (!file.eof())
  {
    getline(file, word);
    if (word != " " && word != "" && word != "\0")
    {
      doc_name[doc] = parseData(word, 1);
      doc_gender[doc] = parseData(word, 2);
      doc_age[doc] = stoi(parseData(word, 3));
      doc_spec[doc] = parseData(word, 4);
      doc_blood[doc] = parseData(word, 5);
      doc_id[doc] = parseData(word, 6);
      doc_mob[doc] = parseData(word, 7);
      doc_add[doc] = parseData(word, 8);
      doc_mail[doc] = parseData(word, 9);
      doc++;
    }
  }
  cout << doc;
  getch();
  file.close();
}
void load_patientdata(string p_name[], int p_age[], string p_blood[], string p_disease[], string p_cnic[], string p_mob[], string p_add[], string p_gender[], string p_id[])
{
  string word;
  fstream file;
  file.open("patient.txt", ios::in);
  if (!file)
    return;
  while (!file.eof())
  {
    getline(file, word);
    if (word != " " && word != "" && word != "\0")
    {
      p_name[pat] = parseData(word, 1);
      p_age[pat] = stoi(parseData(word, 2));
      p_disease[pat] = parseData(word, 3);
      p_blood[pat] = parseData(word, 4);
      p_cnic[pat] = parseData(word, 5);
      p_id[pat] = parseData(word, 6);
      p_gender[pat] = parseData(word, 7);
      p_mob[pat] = parseData(word, 8);
      p_add[pat] = parseData(word, 9);
      pat++;
    }
  }
}

void update_patientdata(string doc_name[], string p_name[], int p_age[], string p_blood[], string p_disease[], string p_cnic[], string p_mob[], string p_add[], string p_gender[], string p_id[])
{
  fstream file;
  file.open("patient.txt", ios::out);
  for (int i = 0; i < pat; i++)
  {
    file << p_name[i] << "," << p_age[i] << "," << p_disease[i] << "," << p_blood[i] << "," << p_cnic[i] << "," << p_id[i] << "," << p_gender[i] << "," << p_mob[i] << "," << p_add[i] << endl;
  }
  file.close();
}

void update_doctordata(string doc_name[], int doc_age[], string doc_spec[], string doc_gender[], string doc_mob[], string doc_blood[], string doc_id[], string doc_mail[], string doc_add[])
{
  fstream file;
  file.open("doctor.txt", ios::out);
  for (int i = 0; i < (doc); i++)
  {
    file << doc_name[i] << "," << doc_gender[i] << "," << doc_age[i] << "," << doc_spec[i] << "," << doc_blood[i] << "," << doc_id[i] << "," << doc_mob[i] << "," << doc_add[i] << "," << doc_mail[i] << endl /* << "," << days[doc]*/;
  }
  file.close();
}
void doctor_sort()
{
  int min = 0, temp1;
  string temp;
  for (int i = 0; i < doc; i++)
  {
    for (int j = i + 1; j < doc; j++)
    {
      if (doc_age[j] < doc_age[i])
      {
        temp = doc_name[i];
        doc_name[i] = doc_name[j];
        doc_name[j] = temp;

        temp = doc_id[i];
        doc_id[i] = doc_id[j];
        doc_id[j] = temp;

        temp = doc_gender[i];
        doc_gender[i] = doc_gender[j];
        doc_gender[j] = temp;

        temp1 = doc_age[i];
        doc_age[i] = doc_age[j];
        doc_age[j] = temp1;

        temp = doc_blood[i];
        doc_blood[i] = doc_blood[j];
        doc_blood[j] = temp;

        temp = doc_add[i];
        doc_add[i] = doc_add[j];
        doc_add[j] = temp;

        temp = doc_spec[i];
        doc_spec[i] = doc_spec[j];
        doc_spec[j] = temp;

        temp = doc_mob[i];
        doc_mob[i] = doc_mob[j];
        doc_mob[j] = temp;

        temp = doc_mail[i];
        doc_mail[i] = doc_mail[j];
        doc_mail[j] = temp;
      }
    }
  }
}
void patient_sort(string p_name[], int p_age[], string p_blood[], string p_disease[], string p_cnic[], string p_mob[], string p_add[], string p_gender[], string p_id[])
{
  int min = 0, temp1;
  string temp;
  for (int i = 0; i < doc; i++)
  {
    for (int j = i + 1; j < doc; j++)
    {
      if (p_age[j] < p_age[i])
      {
        temp = p_name[i];
        p_name[i] = p_name[j];
        p_name[j] = temp;

        temp = p_id[i];
        p_id[i] = p_id[j];
        p_id[j] = temp;

        temp = p_gender[i];
        p_gender[i] = p_gender[j];
        p_gender[j] = temp;

        temp1 = p_age[i];
        p_age[i] = p_age[j];
        p_age[j] = temp1;

        temp = p_blood[i];
        p_blood[i] = p_blood[j];
        p_blood[j] = temp;

        temp = p_cnic[i];
        p_cnic[i] = p_cnic[j];
        p_cnic[j] = temp;

        temp = p_disease[i];
        p_disease[i] = p_disease[j];
        p_disease[j] = temp;

        temp = p_mob[i];
        p_mob[i] = p_mob[j];
        p_mob[j] = temp;
      }
    }
  }
}
