int is_valid(int** puzzle, int row, int col, int num);

void print_puzzle(int** puzzle);

int is_empty(int** puzzle, int row, int col);

 int check_row(int** puzzle,int row, int col, int num);

int check_col(int** puzzle, int row, int col, int num);

int get_box_no(int row, int col);

int check_box(int** puzzle,int row,int col,int num);

int solve(int** puzzle);

int wrapper_funtion(int** puzzle, int row, int col);

