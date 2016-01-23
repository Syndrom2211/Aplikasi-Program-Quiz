/******************************************
TUGAS AKHIR PRODAS-8
Program Kuis Mahasiswa Teknik Informatika

Anggota Kelompok :
1. Firdamdam Sasmita
2. Budi Satria Utama
3. Fiki Priantono
4. Dadan Mustafa Kamal
5. Fali Falyaoma
6. Rizka Abdul Rozaq
7. Gingga Ismu Muttaqin Hadiko

List Metode :
- IF Statement
- Pengulangan
- Array
- Struct
- Sorting
- Manipulasi String
- FILE
*******************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <fstream>
#include <windows.h>

using namespace std;

//======================================KUMPULAN FUNGSI SEDERHANA========================================
void bersih(){ system("CLS"); }
void udah(){ system("PAUSE"); }
void garispanjang(){ cout<<"===============================================================================\n"; }
void garispendek(){ cout<<"============================"<<endl; }
void judul(){ garispendek();cout<<"Program Kuis Mahasiswa IF\n";garispendek(); }
void logberhasil(){ bersih();cout<<"\aLOGIN BERHASIL\n";garispanjang(); }
void tabelheader(){
	cout<<"| No |   NIM   |       Nama       |     Jurusan     |  Jumlah Benar  |  Nilai |\n";
	cout<<"|----|---------|------------------|-----------------|----------------|--------|\n";
}
void tabelfooter(){
	cout<<"|    |         |                  |                 |                |        |\n"; 
}

//======================================STRUCT UNTUK SOAL================================================
struct soal{
    long int nim;
    char nama[10]; //Array
    char jurusan[10]; //Array
    int nilai;
    int tn;
    int jumlah;
};

//======================================DEKLARASI FUNGSI GOTOXY==========================================
void gotoxy(int x,int y){
	 COORD coord;
  	 coord.X = x;
	 coord.Y = y;
	 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//=============================================SOAL - SOAL===============================================
void soal_1(){
	cout<<"1. Dibawah ini yang merupakan High Level Language, kecuali?\n";garispanjang();
	cout<<"a.Bahasa Fortran\n";
	cout<<"b.COBOL\n";
	cout<<"c.Assembly\n";
	cout<<"d.Bahasa C\n";
	cout<<"e.Bahasa Pascal\n";garispanjang();
}    

void soal_2(){
	cout<<"2. Untuk mematikkan komputer OS Windows yaitu dengan perintah?\n";
	garispanjang();
	cout<<"a.Start\n";
	cout<<"b.ShutDown\n";
	cout<<"c.Exit\n";
	cout<<"d.Power off\n";
	cout<<"e.Standby\n";
	garispanjang();
}

void soal_3(){
	cout<<"3. Software animasi yang memakai script?\n";
	garispanjang();
	cout<<"a.3ds Max\n";
	cout<<"b.Maya\n";
	cout<<"c.After Effects\n";
	cout<<"d.Flash\n";
	cout<<"e.Cinema 4D\n";
	garispanjang();
}

void soal_4(){
	cout<<"4. Domain .go.id berarti?\n";
	garispanjang();
	cout<<"a.Domain tersebut milik suatu perkumpulan\n";
	cout<<"b.Domain tersebut milik pribadi perorangan\n";
	cout<<"c.Domain tersebut milik suatu perusahaan\n";
	cout<<"d.Domain tersebut milik suatu kampus\n";
	cout<<"e.Domain tersebut milik pemerintahan\n";
	garispanjang();
}

void soal_5(){
	cout<<"5. Windows Server 2003 mulai dikerjakan pada tahun?\n";
	garispanjang();
	cout<<"a.Awal tahun 2000\n";
	cout<<"b.Awal tahun 2003\n";
	cout<<"c.Akhir tahun 2000\n";
	cout<<"d.Pertengahan tahun 2003\n";
	cout<<"e.Awal tahun 2001\n";
	garispanjang();
}
//=======================================================================================================

int main(int argc, char ** argv[]){
	//----------
	ifstream fi; // Membaca File
	ofstream fo; // Menulis File
	//----------
    soal mhs[5];
    soal srt;
    //----------
    char 
	username[30]="admin",
	password[30];
    //----------
    int i,n,jumlah;
    int j;
    int nilai[5];
    int tn[5];
    char pil;
    char ulang;
    int menu;
    //----------
	
    do{
    	judul();
    	cout<<"Masukkan Username : ";cin>>username;
		cout<<"Masukkan Password : ";cin>>password;
    	if(strcmp(username,password)==0){
    		logberhasil();
    		cout<<"Banyak Mahasiswa yang Ikut Ujian : ";cin>>n;			
			fo.open("Data.DAT", ios::binary | ios::trunc);
			
			if (!fo.is_open()){
                cout<<"File gagal dibuka";
                udah();}
			
	    	for(i=1;i<=n;i++){
	    		bersih();
	    		cout<<"Mahasiswa ke : "<<i<<endl;
	    		garispanjang();
	    		cout<<"NIM     : ";cin>>mhs[i].nim;
	    		cout<<"Nama    : ";cin>>mhs[i].nama;
	    		cout<<"Jurusan : ";cin>>mhs[i].jurusan;	    		
	    		bersih();	
	    		cout<<"Soal... \n";
	    		//-------------------------------------- 
	        	soal_1();
	        	cout<<"Jawaban : ";cin>>pil;	   
	        	if(pil=='c'){
	            	nilai[i]=1;
	        	}else{
	            	nilai[i]=0;
	        	}
	        	jumlah=0;
	        	jumlah=jumlah+nilai[i];
				//--------------------------------------  
	        	soal_2();
	        	cout<<"Jawaban : ";cin>>pil;
	        	if(pil=='b'){
	        	    nilai[i]=1;
	        	}else{
	            	nilai[i]=0;
	        	}
	        	jumlah=jumlah+nilai[i];
				//--------------------------------------
	        	soal_3();
	        	cout<<"Jawaban : ";cin>>pil;
	        	if(pil=='d'){
	            	nilai[i]=1;
	        	}else{
	            	nilai[i]=0;
	        	}
	        	jumlah=jumlah+nilai[i];
				//--------------------------------------
	        	soal_4();
		        cout<<"Jawaban : ";cin>>pil;
		        if(pil=='e'){
		            nilai[i]=1;
		        }else{
		            nilai[i]=0;
		        }
		        jumlah=jumlah+nilai[i];
				//--------------------------------------
				soal_5();
		        cout<<"Jawaban : ";cin>>pil;
		        if(pil=='e'){
		            nilai[i]=1;
		        }else{
		            nilai[i]=0;
		        }
		        jumlah=jumlah+nilai[i];
		        mhs[i].jumlah=jumlah;
		        //--------------------------------------
	        	mhs[i].nilai=jumlah;
				if(mhs[i].nilai=0){
           			mhs[i].nilai=jumlah+nilai[i];
        		}else{
            		mhs[i].nilai;
        		}
	
	        	mhs[i].tn=jumlah*10+mhs[i].nilai;
	        	
	        	udah();
	        }
	        fo.write((char *) &mhs, sizeof(mhs)); // menulis ke file
	        fo.close();
	    	bersih();
	    
		    do{
		    	cout<<"Output Nilai Mahasiswa \n";
		    	cout<<"Masukkan Password : ";cin>>password;      //Tampilan output admin
		    	if(strcmp(username,password)==0){
		    		bersih();
		    		cout<<"Tampilan data nilai Mahasiswa\n";
		    		garispanjang();
		    		tabelheader();
                    
		    		fi.open("Data.DAT", ios::binary| ios::out);
		    		if (!fi.is_open()){
                       cout<<"File gagal dibuka";
                       udah();
                    }
				    fi.read((char *) &mhs, sizeof(mhs));
				    
					for(i=1;i<=n;i++){
						gotoxy(0,3+i);tabelfooter();
						gotoxy(2,3+i);cout<<i;
						gotoxy(7,3+i);cout<<mhs[i].nim;
						gotoxy(17,3+i);cout<<mhs[i].nama;
						gotoxy(36,3+i);cout<<mhs[i].jurusan;
						gotoxy(60,3+i);cout<<mhs[i].jumlah;
						gotoxy(72,3+i);cout<<mhs[i].tn;
					}
					fi.close();
					
					cout<<endl;
		    		garispanjang();
		    		cout<<"Pilihan Sorting Dengan NIM \n";
		    		cout<<"1. Sorting NIM Ascending \n";
				    cout<<"2. Sorting NIM Descending \n";
				    garispanjang();
				    cout<<"Masukkan Pilihan Anda [1..2] : ";cin>>menu;
		    		if(menu==1){ //SORTING BERDASARKAN NIM
		    			fi.open("Data.DAT", ios::binary| ios::out);
		    		    if (!fi.is_open()){
                           cout<<"File gagal dibuka";
                           udah();
                        }
			            fi.read((char *) &mhs, sizeof(mhs));
					    for(i=1;i<n;i++){
					        for(j=1;j<=n-i;j++){
					            if(mhs[j].nim>mhs[j+1].nim){
					                //TUKAR NIM
					                srt=mhs[j];
					                mhs[j]=mhs[j+1];
					                mhs[j+1]=srt;   
					            }
					        }
					    }
					    bersih();
					    cout<<"Tampilan data nilai Mahasiswa \n";
				        cout<<"Sesudah sorting dengan NIM terkecil Ascending\n";
					    garispanjang();
					    tabelheader();
					    
				    
					    for(i=1;i<=n;i++){
                           gotoxy(0,4+i);tabelfooter();
						   gotoxy(2,4+i);cout<<i;
						   gotoxy(7,4+i);cout<<mhs[i].nim;
						   gotoxy(17,4+i);cout<<mhs[i].nama;
						   gotoxy(36,4+i);cout<<mhs[i].jurusan;
						   gotoxy(60,4+i);cout<<mhs[i].jumlah;
						   gotoxy(72,4+i);cout<<mhs[i].tn;
					    }
					    fi.close();
						
				    }else if(menu==2){
				    	fi.open("Data.DAT", ios::binary| ios::out);
		    		    if (!fi.is_open()){
                           cout<<"File gagal dibuka";
                           udah();
                        }
			            fi.read((char *) &mhs, sizeof(mhs));
					    for(i=1;i<n;i++){
					        for(j=1;j<=n-i;j++){
					            if(mhs[j].nim<mhs[j+1].nim){
					                //TUKAR NIM
					                srt=mhs[j];
					                mhs[j]=mhs[j+1];
					                mhs[j+1]=srt;   
					            }
					        }
					    }
                        bersih();
				        cout<<"Tampilan data nilai Mahasiswa \n";
				        cout<<"Sesudah sorting dengan NIM terkecil Descending\n";
				        garispanjang();
				        tabelheader();
				    
					    for(i=1;i<=n;i++){
                           gotoxy(0,4+i);tabelfooter();
						   gotoxy(2,4+i);cout<<i;
						   gotoxy(7,4+i);cout<<mhs[i].nim;
						   gotoxy(17,4+i);cout<<mhs[i].nama;
						   gotoxy(36,4+i);cout<<mhs[i].jurusan;
						   gotoxy(60,4+i);cout<<mhs[i].jumlah;
						   gotoxy(72,4+i);cout<<mhs[i].tn;
					    }
					    fi.close();
                    }
				
		    	}else{
					cout<<"Menu tidak tersedia \n";
				}
				cout<<endl;
			    garispanjang();
			    cout<<"Apakah anda ingin kembali ke menu sorting [Y/y] : ";cin>>ulang;
			    bersih();
		    }while(ulang=='Y'||ulang=='y');                                      
		    udah();
		    return 0;
	    }else{                                  
	        cout<<"Login Gagal \a\a\a\a";
		}
		garispanjang();
    	cout<<"Apakah anda ingin mengulang login tampilan output [Y/y] : ";cin>>ulang;
    	bersih();
    }while(ulang=='Y'||ulang=='y');
    return 0;
}
