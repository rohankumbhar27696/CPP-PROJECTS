#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <chrono>
#include <sys/stat.h>
#include <sys/types.h>
#include <bits/stdc++.h>
#include <dirent.h>
#include <fstream>
#include <ctime>

// #include <filesystem>
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif


#define RETRY_CNT 		5



// int signup( class Person *sptr);
// int login( class Person *sptr );
// void contactus();
// void printmenu();
// void directory_contents ( char * directory_path );
// bool findfolder( char * cur_path, string filename);
// string convertToString(char* a, int size);
// char *convertTochararr(string& a, int size);



using namespace std;


bool LOG_FOLDER_EXITS = 0;
bool REGU_FOLDER_EXITS = 0;

char LOG_FILE_PATH [ 400 ] = {0} ;
char REGU_FILE_PATH [ 400 ] = {0} ;



class Person
{
	public:
		string username;

		int setname()
		{

			cout << "				ENTER UR NAME 			\n" << endl;
			cin  >> name ;

			return 1;
 		};
 		int setname( string str)
 		{
 			name = str;
 			return 1;
 		}

 		string getname()
 		{
 			return name;
 		}

		bool findfolder( char * cur_path, string filename)
		{
			  DIR *dh;
			  struct dirent * contents; 
			  
			  dh = opendir ( cur_path );

			  if ( !dh )
			  {
			    cout << "The given directory is not found";
			    return 0;
			  }

			  while ( ( contents = readdir ( dh ) ) != NULL )
			  {
			    string name = contents->d_name;
			    if( name == filename )
			    {
			    	return 0;
			    }
			  }  

			  return 1;
		}


 		int checkusernamepresent()
 		{
 			string filename = username + ".txt" ;
 			int ret = findfolder( REGU_FILE_PATH , filename );

 			return ret;
 		}

 		int setusername( string str)
 		{
 			username = str;
 			return 1;
 		} 		


		int setusername()
		{
			int retry_cnt = RETRY_CNT;
			while( 1 )
			{
				cout << "				ENTER UR USERNAME 			\n" << endl;
				cin  >> username ;

				int ret = checkusernamepresent();

				if( ret )
				{
					return 1;

				}
				else
				{
					cout << "USERNAME ALREADY TAKEN " << endl;

					if( RETRY_CNT == 0 )
					{
						return 0;
					}
					
				}



			}
			
			/*
				
					PROVIDE CHECK TO USERNAME;

			*/

			return 1;			

 		};

 		string getusername()
 		{
 			return username;

 		}



 		int setpassword( string str)
 		{
 			password = str;
 			return 1;
 		} 


 		int setpassword()
 		{
 			cout << "				ENTER UR PASSWORD. 			\n" << endl;
			cin  >> password ;
			/*

					PROVIDE CHECK REQUIREMENT TO PASSWORD

			*/	

			return 1;

 		}

 		string getpassword()
 		{
 			return password;
 		}



 		int setphoneno( string str)
 		{
 			phoneno = str;
 			return 1;
 		} 

  		int setphoneno()
 		{
 			cout << "				ENTER UR PHONENO 			\n" << endl;
			cin  >> phoneno ;

			return 1;
 		}	

 		string getphoneno()
 		{
 			return phoneno;
 		}	

 		int setemailid( string str)
 		{
 			email_id = str;
 			return 1;
 		} 




  		int setemailid()
 		{
 			cout << "				ENTER UR EMAILID 			\n" << endl;
			cin  >> email_id ;

			return 1;
 		}

 		string getemailid()
 		{
 			return email_id;
 		}


 		void  previewinfo()
 		{
 			char choice = 0;

 			while(1)
 			{ 
	 			cout << "DO U WANT PREVIEW YOUR INFO ? (Y/N) \n" << endl;

	 			cin  >> choice ;

	 			if( choice == 'y' || choice =='Y')
	 			{
	 				cout << "			*** PREVIEW *** 			\n\n";
	 				cout << "NAME 			: " << name 		<< endl;
	 				cout << "USERNAME 		: " << username 	<< endl;
	 				cout << "PHONENO 		: " << phoneno 		<< endl;
	 				cout << "EMAILID 		: " << email_id 	<< endl;

	 				break;


	 			}
	 			else if( choice == 'n' || choice == 'N') 
	 			{
	 				break;
	 			}
	 			else
	 			{
	 				cout << "ENTER Y(YES) / N (NO) ONLY..." << endl;
	 			}

	 		}		

 			

 		}


	private:
		string name;
		string password;
		string phoneno;
		// bool rememberme;
		string email_id;

};



string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

char *convertTochararr(string& a, int size)
{
    char i;
    char* s = (char *)calloc(250 , sizeof(char));
   	cout<< a << " " << size << " " << s <<endl;

    for (i = 0; i < size; i++) {
        s[i] =  a[i];

        // printf("s[ %d ] = %c --- a[ %d ] = %c \n",i,s[i],i,a[i] );
        


    }

    return s;
}


int signup( class Person *sptr)
{

	cout << "\033[2J\033[1;1H";
	cout << "			****	LOGIN SYSTEM	****			\n\n\n" << endl;
	cout << "				SINGUP PAGE				\n\n" << endl;

	int index = 0 , ret = 0;


	while( 1 )
	{
		switch ( index )
		{
			case 0 :	{
							ret = sptr->setname();
							if( ret )
							{
								index = index + 1 ;
								ret = 0;	

								printf("\n\nNAME IS SET!!!\n");
							}
							else
							{
								// ret = ;
								printf("\n\nNAME IS NOT SET\n");
							}
						}		
						break;  

			case 1 :	{
							ret = sptr->setusername();
							if( ret )
							{
								index = index + 1 ;
								ret = 0;
								printf("\n\nUSERNAME IS SET!!!\n");
							}
							else
							{
								// ret = ;
								printf("\n\nUSERNAME IS NOT SET\n");
							}				
						}

						break;  

			case 2 :	{
							ret = sptr->setpassword();
							if( ret )
							{
								index = index + 1 ;
								ret = 0;
								printf("\n\nPASSWORD IS SET!!!\n");
							}
							else
							{
								// ret = ;
								printf("\n\nPASSWORD IS NOT SET\n");
							}
						}


						break; 

			case 3 :	{
							ret = sptr->setphoneno();
							if( ret )
							{
								index = index + 1 ;
								ret = 0;
								printf("\n\nPHONENO IS SET!!!\n");
							}
							else
							{
								// ret = ;
								printf("\n\nPHONENO IS NOT SET\n");
							}
						}



						break;

			case 4 :	{
							ret = sptr->setemailid();
							if( ret )
							{
								index = index + 1 ;
								ret = 0;
								printf("\n\nEMAILID IS SET!!!\n");
							}
							else
							{
								// ret = ;
								printf("\n\nEMAILID IS NOT SET\n");
							}
						}


						break;


			case 5 :	{
							sptr -> previewinfo();
							cout << "\n\n\n" <<endl;

							string regufilepath = 	convertToString( REGU_FILE_PATH , strlen(REGU_FILE_PATH));

							string userfileloc =  regufilepath+ "/"+(sptr->username )+ ".txt" ;

							cout << "REGUSER FILE PATH : " << userfileloc << endl ;  

							fstream  afile;

							afile.open(userfileloc, ios::app | ios::in );

							afile << sptr->getpassword() << "," << sptr->getname() << ","  << sptr->getphoneno() << "," << sptr->getemailid ()<< endl;	

							afile.close();

							cout << "USER REGISTERED SUCCESFULLY !!!!" << endl ;
							return 1;
						}	

						break;

						

			default:	cout << "default\n";
						ret = 0;
						return 0;





		}		
	}








}


bool findfolder( char * cur_path, string filename)
{
  DIR *dh;
  struct dirent * contents; 
  
  dh = opendir ( cur_path );

  if ( !dh )
  {
    cout << "The given directory is not found";
    return 0;
  }

  while ( ( contents = readdir ( dh ) ) != NULL )
  {
    string name = contents->d_name;
    if( name == filename )
    {
    	return 0;
    }
  }  

  return 1;
}

int login( class Person *sptr )
{

	string uname; 
	string password;
	bool find = 0;

	cout << "			**** LOGIN ****			\n\n" << endl;

	cout << "ENTER UR USERNAME : " ;
	cin >> uname ;

	cout << "ENTER UR PASSWORD : ";
	cin >> password ;

	string filename = uname + ".txt" ;
	// find = findfolder( REGU_FILE_PATH , filename );

	string regufilepath = 	convertToString( REGU_FILE_PATH , strlen(REGU_FILE_PATH));

	string userfileloc =  regufilepath+ "/"+(uname)+ ".txt" ;



	find = findfolder( REGU_FILE_PATH , filename );
	// cout << "file : " << filename << "  " << find << endl ;
	// cout << REGU_FILE_PATH << endl;

	if( find == 0 )
	{

		fstream regfile;
		string file_data;



		regfile.open( userfileloc , ios::in  )	;

		regfile >> file_data ;

		vector <string> tokens;

		stringstream check1(file_data);

		string intermediate;
		int cnt = 0 ;

	    while( getline(check1, intermediate, ',') )
	    {
	    	if( cnt == 0 )
	    	{
	    		sptr->setusername(uname);
	    		sptr->setpassword(intermediate);
	    		cnt++;
	    	} 
	    	else if( cnt == 1)
	    	{
	    		sptr->setname(intermediate);
	    		cnt++;
	    	}
	    	else if( cnt == 2)
	    	{
	    		sptr->setphoneno(intermediate);
	    		cnt++;
	    	}
	    	else if( cnt == 3)
	    	{
	    		sptr->setemailid(intermediate);
	    		cnt++;
	    	}	    	

	    }	

	    if( password == sptr->getpassword() )
	    {
	    	return 1;
	    }
	    else
	    {
	    	return 0;
	    }





	}
	else
	{
		// cout << "USERNAME OR PASSWORD IS INCORRECT " << endl;
		return 0;
	}





}


void contactus()
{
	cout << "			**** CUSTOMER CARE ****			\n\n" << endl;
	cout << "	EMAIL    : rohan***********@gmail.com " << endl;
	cout << "	PHONENO  : 88888888888 " << endl;

}



void printmenu()
{
	cout << "\033[2J\033[1;1H";

	printf("				****	LOGIN SYSTEM	****			\n");
	printf("\n\n");
	printf("					ENTER UR CHOICE		\n");
	printf("						1 . LOGIN\n");
	printf("						2 . SIGNUP\n");
	printf("						3 . CONTACT US\n");
	printf("						4 . EXIT\n");
}


void directory_contents ( char * directory_path )
{  
  DIR *dh;
  struct dirent * contents; 
  
  dh = opendir ( directory_path );
  
  if ( !dh )
  {
    cout << "The given directory is not found";
    return;
  }
  while ( ( contents = readdir ( dh ) ) != NULL )
  {
    string name = contents->d_name;
    cout << name << endl;
  }
  closedir ( dh );
}








void makemainfolder()
{
	bool find = 0;

	char cur_path[256]={0};

    getcwd(cur_path, 256);
    bool main_folder = 1;

    cout << "CURRENT PATH : " << cur_path << endl;


    find = findfolder(cur_path,"LOGIN_SYSTEM");

    if( find )
    {
    	cout << "CREATING FOLDER LOGIN_SYSTEM....\n" << endl ;

//	    if (mkdir("LOGIN_SYSTEM", 0777) == -1)  //FOR Liniux or ubuntu
		if (mkdir("LOGIN_SYSTEM") == -1)
	    {
	        cerr << "Error :  " << strerror(errno) << endl;
	        main_folder = 0;
	  	}
	    else
	    {
	        cout << "LOGIN_SYSTEM FOLDER CREATED" << endl;   	
	    }
    }
    else
    {
    	cout << "FOLDER ALREADY EXITS.....\n" << endl ;
    }


}



void makereguserfolder()
{
	bool find = 0;

	char cur_path[256]={0};

    getcwd(cur_path, 256);
    bool main_folder = 1;	
    string str_new_path ,str_cur_path;

    cout << "CURRENT PATH : " << cur_path << endl;

    str_cur_path = convertToString(cur_path,strlen(cur_path));

    str_new_path = str_cur_path + "/LOGIN_SYSTEM/" ;

    char *new_path = (char *)calloc(250 , sizeof(char));

    new_path = convertTochararr(str_new_path, str_new_path.length());

    cout << "NEW PATH : " << new_path << endl;

    if( new_path != NULL )
    {
    	find = findfolder(new_path,"LOGIN_SYSTEM");

    	free( new_path ) ;

    	if( find )
    	{
    		string file_path = str_new_path + "LS_REG_USERS";

    		char *file_buff = (char *)calloc(250 , sizeof(char));

    		file_buff = convertTochararr(file_path, file_path.length());
	
			cout << "FILE PATH : " << file_buff << endl ;	
    		if( file_buff != NULL )
    		{
//	  			if (mkdir(file_buff, 0777) == -1)        #for linux or ubuntu
				if (mkdir(file_buff) == -1)
				{
				        cerr << "Error :  " << strerror(errno) << endl;
				        main_folder = 0;
				        memcpy ( REGU_FILE_PATH, file_buff, strlen(file_buff) );
				        free(file_buff); 
				        return ;
				}
				else
				{
					cout << "FOLDER CREATED" <<endl ;
					memcpy ( REGU_FILE_PATH, file_buff, strlen(file_buff) );
					free(file_buff); 
					REGU_FOLDER_EXITS = 1;
					return;
				}    
				
							
    		}

 		
    	}
    	else
    	{
    		string file_path = str_new_path + "LS_REG_USERS";

    		char *file_buff = (char *)calloc(250 , sizeof(char));

    		file_buff = convertTochararr(file_path, file_path.length());

    		memcpy ( REGU_FILE_PATH, file_buff, strlen(file_buff) );

    		free(file_buff);

    		cout << "FOLDER ALREADY EXITS"	<< endl ;
    		REGU_FOLDER_EXITS = 1;
    		return;

    	}

    }
}


void makelogfolder()
{
	bool find = 0;

	char cur_path[256]={0};

    getcwd(cur_path, 256);
    bool main_folder = 1;	
    string str_new_path ,str_cur_path;

    cout << "CURRENT PATH : " << cur_path << endl;

    str_cur_path = convertToString(cur_path,strlen(cur_path));

    str_new_path = str_cur_path + "/LOGIN_SYSTEM/" ;

    char *new_path = (char *)calloc(250 , sizeof(char));

    new_path = convertTochararr(str_new_path, str_new_path.length());

    cout << "NEW PATH : " << new_path << endl;

    if( new_path != NULL )
    {
    	find = findfolder(new_path,"LOGIN_SYSTEM");

    	free( new_path ) ;

    	if( find )
    	{
    		string file_path = str_new_path + "LS_LOG_USERS";

    		char *file_buff = (char *)calloc(250 , sizeof(char));

    		file_buff = convertTochararr(file_path, file_path.length());
	
			cout << "FILE PATH : " << file_buff << endl ;	
    		if( file_buff != NULL )
    		{
//	  			if (mkdir(file_buff, 0777) == -1) // for linux or ubunutu
				if (mkdir(file_buff) == -1)
				{
				        cerr << "Error :  " << strerror(errno) << endl;
				        main_folder = 0;
				        memcpy ( LOG_FILE_PATH, file_buff, strlen(file_buff) );
				        free(file_buff); 
				        return ;
				}
				else
				{
					cout << "FOLDER CREATED" <<endl ;
					
					LOG_FOLDER_EXITS = 1; 
					memcpy ( LOG_FILE_PATH, file_buff, strlen(file_buff) );

					free(file_buff);
					return;
				}    
				
							
    		}

 		
    	}
    	else
    	{
    		cout << "FOLDER ALREADY EXITS"	<< endl ;
    		string file_path = str_new_path + "LS_LOG_USERS";

    		char *file_buff = (char *)calloc(250 , sizeof(char));

    		file_buff = convertTochararr(file_path, file_path.length());

    		memcpy ( LOG_FILE_PATH, file_buff, strlen(file_buff) );

    		free(file_buff);

    		LOG_FOLDER_EXITS = 1;
    		return;

    	}

    }
}

void writelogfile(string activity , class Person *sptr )
{
	string logfilepath = 	convertToString( LOG_FILE_PATH , strlen(LOG_FILE_PATH));
	string logfileloc =  logfilepath+ "/"+"allog"+ ".txt" ;


	fstream  afile;
	afile.open(logfileloc, ios::app | ios::in );
	time_t now = time(0);
	tm *ltm = localtime(&now);

	afile << activity << " - " << sptr->username << " - " <<  to_string( ltm->tm_mday)  << "/" <<  to_string( ltm->tm_mon ) << "/"  << to_string( ltm->tm_year) << " - " << to_string( ltm->tm_hour) <<":"<< to_string( ltm->tm_min) <<":"<< to_string( ltm->tm_sec) <<endl;

	afile.close();


}

void makeprogfile()
{

	makemainfolder();
	makereguserfolder();
	makelogfolder();


}

int main()
{

	unsigned int choice = 0,ret=0;
	Person user;

	makeprogfile();


	cout << "LOG FOLDER PATH : " << LOG_FILE_PATH << endl;
	cout << "REGU FOLDER PATH : " << REGU_FILE_PATH << endl;






    


    











	while(1)
	{

		switch ( choice )
		{
			case 0:	printmenu();
					scanf("%d",&choice);
					break;

			case 1: ret = login(&user);
					if( ret )
					{
						cout << "LOGIN SUCCESFULL " <<endl;
						writelogfile("LOGIN",&user);

						


						
						choice = 5;
					}
					else
					{
						cout << "USERNAME OR PASSWORD IS INCORRECT" <<endl ;
						choice = 1;
					}
						
					break;		


			case 2: ret = signup(&user );

					if( ret )
					{
						cout << " GOING TO LOGIN PAGE....." << endl;
						writelogfile("SINGUP",&user);

						choice = 1;


					}
					else
					{
						cout << " SOME ERROR OCCURED GOING TO MAIN MENU"<<endl;
						choice = 0;
					}

					break;


			case 3: contactus();
					exit(0);
					break;

			case 4: exit(0);

			case 5: cout << "			**** WELCOME ****			" << endl;
					while( 1 )
					{
						string  in;
						cin >> 	in;
						cout << "REC : " << in << endl;
						if( in == "exit")
						{
							return 0;
						}
					}	 


			// case 3:
			// case 3:
		}		
	}



}

