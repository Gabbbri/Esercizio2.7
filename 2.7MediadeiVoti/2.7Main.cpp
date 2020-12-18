/* Il programma chiede il numero totale di studenti partecipanti all'esame
   Per ogni studente viene inserito il voto e stampata la media dell'esame.
   Questo verrà fatto su file di testo esterni, definendo degli stream personalizzati

   */


  #include <iostream>
  #include <fstream>
  #include "media.hpp"
  using namespace std;

  int main (int argc, char* argv[]) {

      //controllo sull'inserimento dei parametri da riga di comando
      if (argc != 3) {
          cout << "Devi inserire come parametri: file.txt di lettura e file.txt di scrittura";
          exit(0);
      }
      
      //inizializzazione degli stream e loro apertura
      fstream input, output;

      input.open(argv[1], ios::in);
      
      //controllo sull'esistenza del file di lettura
      if (input.fail()) {
        cout << "Il file che hai inserito non esiste\n";
        exit (0);
      }

      output.open (argv[2], ios::out | ios::app);


      int num_studenti;
    
      //fino a che la lettura fallisce (il programma trova caratteri anzichè numeri) continua a leggere. Quando trova un numero lo legge
      //while (input.fail()) 
      
      /*while (input.fail()) {
          input.clear();
          input>>num_studenti;

      }
      */

      input >> num_studenti;

      //creazione array dinamico

      int* lista_voti = new int [num_studenti];


      //riempimento dell'array con i voti  
      for (int i=0; i<num_studenti; ++i) {
          input >> lista_voti[i];
      }

      
      //mandata in output della media dei voti

      output << "\n\nLa media dell'esame è di " << media(lista_voti, num_studenti) << " punti\n";

      //deallocazione della memoria dinamica
      delete [] lista_voti;
      
      //"elimino" il puntatore così che non resti puntato a qualcosa di deallocato
      lista_voti=NULL;

      //chiusura degli stream

      input.close();
      output.close ();


      return 0;
}