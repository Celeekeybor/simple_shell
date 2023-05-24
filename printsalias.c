#include "main.h"
/**
 * Prints the selected aliases based on the given names.
 *
 * @param names A pointer to an array of null-terminated strings representing the names of aliases.
 *              The array is terminated with a NULL pointer.
 *return 0;
 */
void print_selected_aliases(char** names) {
while (*names != NULL) {
Alias* curr = alias_list;
while (curr != NULL) {
if (strcmp(curr->name, *names) == 0) {
print_alias(curr);
break;
}
curr = curr->next;
}
names++;
}
}
