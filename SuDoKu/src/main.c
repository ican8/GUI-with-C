#include <gtk/gtk.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"sudoku_generator.h"
#include"sudoku_solver.h"

/* global variable */
/* difficulty :- easy- 61 medium-50 hard-25 */
int difficulty = 61;

/* generator :- this will receive malloced memory */
int** generator_puzzle;

int** play_puzzle;

/*solver puzzle */
/*
int** solver_puzzle */	

void set_props();

void open_dialog(const char* str);	

GtkWidget* wid[9][9];

GtkWidget *grid1;
GtkWidget *grid2;
GtkWidget *grid3;
GtkWidget *grid4;
GtkWidget *grid5;
GtkWidget *grid6;
GtkWidget *grid7;
GtkWidget *grid8;
GtkWidget *grid9;

GtkWidget *solve_btn;
GtkWidget *generate_btn;
GtkWidget *check_btn;

GtkWidget *label1;

GtkWidget *radio_easy;
GtkWidget *radio_medium;
GtkWidget *radio_hard;


GtkWidget *seperator1;
GtkWidget *seperator2;
GtkWidget *seperator3;
GtkWidget *seperator4;
GtkWidget *seperator5;
GtkWidget *seperator6;
GtkWidget *seperator7;
GtkWidget *seperator8;

/*void set_range_increments(){
	int i,j;
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			gtk_spin_button_set_range( GTK_SPIN_BUTTON(wid[i][j]), 0.0 , 9.0);
			gtk_spin_button_set_increments( GTK_SPIN_BUTTON(wid[i][j]) , 1.0, 1.0);
			
		}
	}
}*/

GtkWidget       *window;

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    //GtkWidget       *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);
    
    grid1 = GTK_WIDGET(gtk_builder_get_object(builder,"grid1"));
    grid2 = GTK_WIDGET(gtk_builder_get_object(builder,"grid2"));
    grid3 = GTK_WIDGET(gtk_builder_get_object(builder,"grid3"));
    grid4 = GTK_WIDGET(gtk_builder_get_object(builder,"grid4"));
    grid5 = GTK_WIDGET(gtk_builder_get_object(builder,"grid5"));
    grid6 = GTK_WIDGET(gtk_builder_get_object(builder,"grid6"));
    grid7 = GTK_WIDGET(gtk_builder_get_object(builder,"grid7"));
    grid8 = GTK_WIDGET(gtk_builder_get_object(builder,"grid8"));
    grid9 = GTK_WIDGET(gtk_builder_get_object(builder,"grid9"));
    
    solve_btn = GTK_WIDGET(gtk_builder_get_object(builder,"solve_btn"));
    generate_btn = GTK_WIDGET(gtk_builder_get_object(builder,"generate_btn"));
    check_btn = GTK_WIDGET(gtk_builder_get_object(builder,"check_btn"));
    label1 = GTK_WIDGET(gtk_builder_get_object(builder,"label1"));
    
   
    radio_easy = GTK_WIDGET(gtk_builder_get_object(builder,"easy"));
    radio_medium = GTK_WIDGET(gtk_builder_get_object(builder,"medium"));
    radio_hard = GTK_WIDGET(gtk_builder_get_object(builder,"hard"));
   
    
    
    seperator1 = GTK_WIDGET(gtk_builder_get_object(builder,"seperator1"));
    seperator2 = GTK_WIDGET(gtk_builder_get_object(builder,"seperator2"));
    seperator3 = GTK_WIDGET(gtk_builder_get_object(builder,"seperator3"));
    seperator4 = GTK_WIDGET(gtk_builder_get_object(builder,"seperator4"));
    seperator5 = GTK_WIDGET(gtk_builder_get_object(builder,"seperator5"));
    seperator6 = GTK_WIDGET(gtk_builder_get_object(builder,"seperator6"));
    seperator7 = GTK_WIDGET(gtk_builder_get_object(builder,"seperator7"));
    seperator8 = GTK_WIDGET(gtk_builder_get_object(builder,"seperator8"));
    
    
    wid[0][0] = GTK_WIDGET(gtk_builder_get_object(builder,"entry1"));
    wid[0][1] = GTK_WIDGET(gtk_builder_get_object(builder,"entry2"));
    wid[0][2] = GTK_WIDGET(gtk_builder_get_object(builder,"entry3"));
    wid[0][3] = GTK_WIDGET(gtk_builder_get_object(builder,"entry4"));
    wid[0][4] = GTK_WIDGET(gtk_builder_get_object(builder,"entry5"));
    wid[0][5] = GTK_WIDGET(gtk_builder_get_object(builder,"entry6"));
    wid[0][6] = GTK_WIDGET(gtk_builder_get_object(builder,"entry7"));
    wid[0][7] = GTK_WIDGET(gtk_builder_get_object(builder,"entry8"));
    wid[0][8] = GTK_WIDGET(gtk_builder_get_object(builder,"entry9"));
   
    
    wid[1][0] = GTK_WIDGET(gtk_builder_get_object(builder,"entry10"));
    wid[1][1] = GTK_WIDGET(gtk_builder_get_object(builder,"entry11"));
    wid[1][2] = GTK_WIDGET(gtk_builder_get_object(builder,"entry12"));
    wid[1][3] = GTK_WIDGET(gtk_builder_get_object(builder,"entry13"));
    wid[1][4] = GTK_WIDGET(gtk_builder_get_object(builder,"entry14"));
    wid[1][5] = GTK_WIDGET(gtk_builder_get_object(builder,"entry15"));
    wid[1][6] = GTK_WIDGET(gtk_builder_get_object(builder,"entry16"));
    wid[1][7] = GTK_WIDGET(gtk_builder_get_object(builder,"entry17"));
    wid[1][8] = GTK_WIDGET(gtk_builder_get_object(builder,"entry18"));
 
    wid[2][0] = GTK_WIDGET(gtk_builder_get_object(builder,"entry19"));
    wid[2][1] = GTK_WIDGET(gtk_builder_get_object(builder,"entry20"));
    wid[2][2] = GTK_WIDGET(gtk_builder_get_object(builder,"entry21"));
    wid[2][3] = GTK_WIDGET(gtk_builder_get_object(builder,"entry22"));
    wid[2][4] = GTK_WIDGET(gtk_builder_get_object(builder,"entry23"));
    wid[2][5] = GTK_WIDGET(gtk_builder_get_object(builder,"entry24"));
    wid[2][6] = GTK_WIDGET(gtk_builder_get_object(builder,"entry25"));
    wid[2][7] = GTK_WIDGET(gtk_builder_get_object(builder,"entry26"));
    wid[2][8] = GTK_WIDGET(gtk_builder_get_object(builder,"entry27"));
   
    
    wid[3][0] = GTK_WIDGET(gtk_builder_get_object(builder,"entry28"));
    wid[3][1] = GTK_WIDGET(gtk_builder_get_object(builder,"entry29"));
    wid[3][2] = GTK_WIDGET(gtk_builder_get_object(builder,"entry30"));
    wid[3][3] = GTK_WIDGET(gtk_builder_get_object(builder,"entry31"));
    wid[3][4] = GTK_WIDGET(gtk_builder_get_object(builder,"entry32"));
    wid[3][5] = GTK_WIDGET(gtk_builder_get_object(builder,"entry33"));
    wid[3][6] = GTK_WIDGET(gtk_builder_get_object(builder,"entry34"));
    wid[3][7] = GTK_WIDGET(gtk_builder_get_object(builder,"entry35"));
    wid[3][8] = GTK_WIDGET(gtk_builder_get_object(builder,"entry36"));
    
    wid[4][0] = GTK_WIDGET(gtk_builder_get_object(builder,"entry37"));
    wid[4][1] = GTK_WIDGET(gtk_builder_get_object(builder,"entry38"));
    wid[4][2] = GTK_WIDGET(gtk_builder_get_object(builder,"entry39"));
    wid[4][3] = GTK_WIDGET(gtk_builder_get_object(builder,"entry40"));
    wid[4][4] = GTK_WIDGET(gtk_builder_get_object(builder,"entry41"));
    wid[4][5] = GTK_WIDGET(gtk_builder_get_object(builder,"entry42"));
    wid[4][6] = GTK_WIDGET(gtk_builder_get_object(builder,"entry43"));
    wid[4][7] = GTK_WIDGET(gtk_builder_get_object(builder,"entry44"));
    wid[4][8] = GTK_WIDGET(gtk_builder_get_object(builder,"entry45"));
    
    wid[5][0] = GTK_WIDGET(gtk_builder_get_object(builder,"entry46"));
    wid[5][1] = GTK_WIDGET(gtk_builder_get_object(builder,"entry47"));
    wid[5][2] = GTK_WIDGET(gtk_builder_get_object(builder,"entry48"));
    wid[5][3] = GTK_WIDGET(gtk_builder_get_object(builder,"entry49"));
    wid[5][4] = GTK_WIDGET(gtk_builder_get_object(builder,"entry50"));
    wid[5][5] = GTK_WIDGET(gtk_builder_get_object(builder,"entry51"));
    wid[5][6] = GTK_WIDGET(gtk_builder_get_object(builder,"entry52"));
    wid[5][7] = GTK_WIDGET(gtk_builder_get_object(builder,"entry53"));
    wid[5][8] = GTK_WIDGET(gtk_builder_get_object(builder,"entry54"));
    
    wid[6][0] = GTK_WIDGET(gtk_builder_get_object(builder,"entry55"));
    wid[6][1] = GTK_WIDGET(gtk_builder_get_object(builder,"entry56"));
    wid[6][2] = GTK_WIDGET(gtk_builder_get_object(builder,"entry57"));
    wid[6][3] =  GTK_WIDGET(gtk_builder_get_object(builder,"entry58"));
    wid[6][4] = GTK_WIDGET(gtk_builder_get_object(builder,"entry59"));
    wid[6][5] = GTK_WIDGET(gtk_builder_get_object(builder,"entry60"));
    wid[6][6] = GTK_WIDGET(gtk_builder_get_object(builder,"entry61"));
    wid[6][7] = GTK_WIDGET(gtk_builder_get_object(builder,"entry62"));
    wid[6][8] = GTK_WIDGET(gtk_builder_get_object(builder,"entry63"));
    
    wid[7][0] = GTK_WIDGET(gtk_builder_get_object(builder,"entry64"));
    wid[7][1] = GTK_WIDGET(gtk_builder_get_object(builder,"entry65"));
    wid[7][2] = GTK_WIDGET(gtk_builder_get_object(builder,"entry66"));
    wid[7][3] = GTK_WIDGET(gtk_builder_get_object(builder,"entry67"));
    wid[7][4] = GTK_WIDGET(gtk_builder_get_object(builder,"entry68"));
    wid[7][5] = GTK_WIDGET(gtk_builder_get_object(builder,"entry69"));
    wid[7][6] = GTK_WIDGET(gtk_builder_get_object(builder,"entry70"));
    wid[7][7] = GTK_WIDGET(gtk_builder_get_object(builder,"entry71"));
    wid[7][8] = GTK_WIDGET(gtk_builder_get_object(builder,"entry72")); 
    
    wid[8][0] = GTK_WIDGET(gtk_builder_get_object(builder,"entry73"));
    wid[8][1] = GTK_WIDGET(gtk_builder_get_object(builder,"entry74"));
    wid[8][2] = GTK_WIDGET(gtk_builder_get_object(builder,"entry75"));
    wid[8][3] = GTK_WIDGET(gtk_builder_get_object(builder,"entry76"));
    wid[8][4] = GTK_WIDGET(gtk_builder_get_object(builder,"entry77"));
    wid[8][5] = GTK_WIDGET(gtk_builder_get_object(builder,"entry78"));
    wid[8][6] = GTK_WIDGET(gtk_builder_get_object(builder,"entry79"));
    wid[8][7] = GTK_WIDGET(gtk_builder_get_object(builder,"entry80"));
    wid[8][8] = GTK_WIDGET(gtk_builder_get_object(builder,"entry81"));
  
    
    /* set the properties of text entries */
   set_props();	   
    
    
    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();

    return 0;
}

void on_solve_btn_clicked(){

		int** solver_puzzle;
		int i;
		
		solver_puzzle = (int **)malloc(sizeof(int *) * 9);
	
		for(i = 0; i < 9; i++)
			solver_puzzle[i] = (int *)malloc(sizeof(int) * 9);
	
		
		 
		int row,col;
	
		for(row = 0; row < 9; row++){
			for(col = 0; col < 9; col++){
			
				
				sscanf( gtk_entry_get_text( GTK_ENTRY(wid[row][col]) ) , "%d", &i );
				solver_puzzle[row][col] = i;
				
				if( (solver_puzzle[row][col] >= 1) && (solver_puzzle[row][col] <= 9) )
					continue;
				else
					solver_puzzle[row][col] = 0;
			}
		}
					
					
		if( solve(solver_puzzle) ){
	
			char temp[2];
	
			for(row = 0; row < 9; row++){
				for(col = 0; col < 9; col++){
				
					sprintf(temp,"%d", solver_puzzle[row][col]);
					gtk_entry_set_text( GTK_ENTRY(wid[row][col]), temp );
				}
			}
			
		}
	
		else{
			// put couldn't solve message
			gtk_label_set_text(GTK_LABEL(label1),"NO SOLUTION!");
			
			//open_dialog("No Solution !!");
		}
		

}

void on_check_btn_clicked(){
	
	int row,col;
	
	for(row = 0; row < 9; row++)
		for(col = 0; col < 9; col++)
			 gtk_entry_set_text( GTK_ENTRY(wid[row][col]) , "") ;
		

}


void on_easy_toggled(GtkRadioButton *b){
	gboolean t = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
	if(t)
		difficulty = 61;

}

void on_medium_toggled(GtkRadioButton *b){
	gboolean t = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
	if(t)
		difficulty = 50;

}


void on_hard_toggled(GtkRadioButton *b){
	gboolean t = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
	if(t)
		difficulty = 25;

}


void on_generate_btn_clicked(){
	
		generator_puzzle = help(difficulty);
		int row,col;
		char temp[2];
		
		for(row = 0; row < 9; row++){
			for(col = 0; col < 9; col++){
				sprintf(temp,"%d", generator_puzzle[row][col]);
				gtk_entry_set_text( GTK_ENTRY(wid[row][col]), temp );
			}
		}
	
	
}

void set_props(){
	int i,j;
	for(i = 0; i < 9; i++){
		for(j = 0; j <  9; j++){
			/* allow only one char to enter in the text entry*/
			gtk_entry_set_max_length( GTK_ENTRY(wid[i][j]), 1);
		}
	}
}

/*
void open_dialog(const char* str){
	GtkWidget *dialog, *label;
	dialog = gtk_dialog_new_with_buttons("NO Solution!!",GTK_WINDOW(window),GTK_DIALOG_DESTROY_WITH_PARENT,GTK_STOCK_OK,GTK_RESPONSE_NONE,NULL);
	label = gtk_label_new(str);
	//gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog)), label, 0, 0, 0);
	
	g_signal_connect_swapped(GTK_OBJECT(dialog),"response",G_CALLBACK(gtk_widget_destroy),GTK_OBJECT(dialog));
	 
	gtk_container_add(GTK_CONTAINER (GTK_DIALOG(dialog)->box),label);
	
	gtk_widget_show_all(dialog);
	//gtk_dialog_run(GTK_DIALOG(dialog));
	//gtk_widget_destroy(dialog);
	
}
*/	

void on_play_mode_toggle_btn_toggled(GtkToggleButton *b){
	gboolean t = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
	if(t){
		//int** play_puzzle;
		int i;
		
		play_puzzle = (int **)malloc(sizeof(int *) * 9);
	
		for(i = 0; i < 9; i++)
			play_puzzle[i] = (int *)malloc(sizeof(int) * 9);
	
		
		 
		int row,col;
	
		for(row = 0; row < 9; row++){
			for(col = 0; col < 9; col++){
			
				
				sscanf( gtk_entry_get_text( GTK_ENTRY(wid[row][col]) ) , "%d", &i );
				play_puzzle[row][col] = i;
				
				if( (play_puzzle[row][col] >= 1) && (play_puzzle[row][col] <= 9) )
					continue;
				else
					play_puzzle[row][col] = 0;
			}
		}
			if ( ! solve(play_puzzle)){
				printf("not solveable in play mode\n");
			}		
			
	
	
	}
	else{
		int row, col,i;
		for(row = 0; row < 9; row++){
			for(col = 0; col < 9 ; col++){
				
				sscanf( gtk_entry_get_text( GTK_ENTRY(wid[row][col]) ) , "%d", &i );
				
				if( i != play_puzzle[row][col]){
					gtk_label_set_text(GTK_LABEL(label1),"YOU LOST IN PLAY MODE!");
					return;
				}
			}
		}
		
		gtk_label_set_text(GTK_LABEL(label1),"YOU WIN IN PLAY MODE!");
				
	}
	
}
		
		
	

void on_window_main_destroy()
{
    gtk_main_quit();
}
