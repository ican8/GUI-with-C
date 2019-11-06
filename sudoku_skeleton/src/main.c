#include <gtk/gtk.h>
#include<stdlib.h>
#include<stdio.h>

GtkWidget* wid[9][9];

/*
GtkWidget *spinbutton00;
GtkWidget *spinbutton01;
GtkWidget *spinbutton02;
GtkWidget *spinbutton03;
GtkWidget *spinbutton04;
GtkWidget *spinbutton05;
GtkWidget *spinbutton06;
GtkWidget *spinbutton07;
GtkWidget *spinbutton08;
GtkWidget *spinbutton10;
GtkWidget *spinbutton12;
GtkWidget *spinbutton13;
GtkWidget *spinbutton14;
GtkWidget *spinbutton15;
GtkWidget *spinbutton16;
GtkWidget *spinbutton00;
GtkWidget *spinbutton00;
GtkWidget *spinbutton00;*/

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

GtkWidget *seperator1;
GtkWidget *seperator2;
GtkWidget *seperator3;
GtkWidget *seperator4;
GtkWidget *seperator5;
GtkWidget *seperator6;
GtkWidget *seperator7;
GtkWidget *seperator8;

void set_range_increments(){
	int i,j;
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			gtk_spin_button_set_range( GTK_SPIN_BUTTON(wid[i][j]), 0.0 , 9.0);
			gtk_spin_button_set_increments( GTK_SPIN_BUTTON(wid[i][j]) , 1.0, 1.0);
		}
	}
}

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);
    
    // get pointers to the two labels
    grid1 = GTK_WIDGET(gtk_builder_get_object(builder,"grid1"));
    grid2 = GTK_WIDGET(gtk_builder_get_object(builder,"grid2"));
    grid3 = GTK_WIDGET(gtk_builder_get_object(builder,"grid3"));
    grid4 = GTK_WIDGET(gtk_builder_get_object(builder,"grid4"));
    grid5 = GTK_WIDGET(gtk_builder_get_object(builder,"grid5"));
    grid6 = GTK_WIDGET(gtk_builder_get_object(builder,"grid6"));
    grid7 = GTK_WIDGET(gtk_builder_get_object(builder,"grid7"));
    grid8 = GTK_WIDGET(gtk_builder_get_object(builder,"grid8"));
    grid9 = GTK_WIDGET(gtk_builder_get_object(builder,"grid9"));
    
    seperator1 = GTK_WIDGET(gtk_builder_get_object(builder,"seperator1"));
    seperator2 = GTK_WIDGET(gtk_builder_get_object(builder,"seperator2"));
    seperator3 = GTK_WIDGET(gtk_builder_get_object(builder,"seperator3"));
    seperator4 = GTK_WIDGET(gtk_builder_get_object(builder,"seperator4"));
    seperator5 = GTK_WIDGET(gtk_builder_get_object(builder,"seperator5"));
    seperator6 = GTK_WIDGET(gtk_builder_get_object(builder,"seperator6"));
    seperator7 = GTK_WIDGET(gtk_builder_get_object(builder,"seperator7"));
    seperator8 = GTK_WIDGET(gtk_builder_get_object(builder,"seperator8"));
    
    
    wid[0][0] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton00"));
    wid[0][1] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton01"));
    wid[0][2] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton02"));
    wid[0][3] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton03"));
    wid[0][4] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton04"));
    wid[0][5] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton05"));
    wid[0][6] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton06"));
    wid[0][7] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton07"));
    wid[0][8] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton08"));
    
    wid[1][0] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton10"));
    wid[1][1] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton11"));
    wid[1][2] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton12"));
    wid[1][3] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton13"));
    wid[1][4] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton14"));
    wid[1][5] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton15"));
    wid[1][6] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton16"));
    wid[1][7] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton17"));
    wid[1][8] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton18"));
    
    wid[2][0] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton20"));
    wid[2][1] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton21"));
    wid[2][2] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton22"));
    wid[2][3] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton23"));
    wid[2][4] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton24"));
    wid[2][5] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton25"));
    wid[2][6] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton26"));
    wid[2][7] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton27"));
    wid[2][8] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton28"));
    
    wid[3][0] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton30"));
    wid[3][1] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton31"));
    wid[3][2] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton32"));
    wid[3][3] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton33"));
    wid[3][4] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton34"));
    wid[3][5] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton35"));
    wid[3][6] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton36"));
    wid[3][7] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton37"));
    wid[3][8] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton38"));
    
    wid[4][0] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton40"));
    wid[4][1] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton41"));
    wid[4][2] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton42"));
    wid[4][3] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton43"));
    wid[4][4] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton44"));
    wid[4][5] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton45"));
    wid[4][6] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton46"));
    wid[4][7] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton47"));
    wid[4][8] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton48"));
    
    wid[5][0] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton50"));
    wid[5][1] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton51"));
    wid[5][2] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton52"));
    wid[5][3] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton53"));
    wid[5][4] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton54"));
    wid[5][5] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton55"));
    wid[5][6] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton56"));
    wid[5][7] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton57"));
    wid[5][8] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton58"));
    
    wid[6][0] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton60"));
    wid[6][1] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton61"));
    wid[6][2] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton62"));
    wid[6][3] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton63"));
    wid[6][4] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton64"));
    wid[6][5] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton65"));
    wid[6][6] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton66"));
    wid[6][7] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton67"));
    wid[6][8] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton68"));
    
    wid[7][0] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton70"));
    wid[7][1] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton71"));
    wid[7][2] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton72"));
    wid[7][3] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton73"));
    wid[7][4] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton74"));
    wid[7][5] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton75"));
    wid[7][6] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton76"));
    wid[7][7] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton77"));
    wid[7][8] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton78"));
    
    wid[8][0] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton80"));
    wid[8][1] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton81"));
    wid[8][2] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton82"));
    wid[8][3] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton83"));
    wid[8][4] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton84"));
    wid[8][5] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton85"));
    wid[8][6] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton86"));
    wid[8][7] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton87"));
    wid[8][8] = GTK_WIDGET(gtk_builder_get_object(builder,"spinbutton88"));
    
    
    
   set_range_increments();	   
    
    
    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();

    return 0;
}

/* called when button is clicked
void on_btn_hello_clicked()
{
    static unsigned int count = 0;
    char str_count[30] = {0};
    
    gtk_label_set_text(GTK_LABEL(g_lbl_hello), "Hello, world!");
    count++;
    sprintf(str_count, "%d", count);
    gtk_label_set_text(GTK_LABEL(g_lbl_count), str_count);
}
*/
// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}
