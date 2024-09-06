#define MAX_WORD_LENGTH 100
#define MAX_WORDS 10000
int load_file(const char *file_path, char words[MAX_WORDS][MAX_WORD_LENGTH]);
void correct_words(char dictionary[MAX_WORDS][MAX_WORD_LENGTH], int dict_count, char text[MAX_WORDS][MAX_WORD_LENGTH], int text_count);
int min(int st, int nd, int rd);
int edit_distance(const char *s1, const char* s2);
int edit_distance_dyn_recursive(const char *s1, const char *s2, int lens1, int lens2, int **mat);
int edit_distance_dyn(const char *s1, const char *s2);