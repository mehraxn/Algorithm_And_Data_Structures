ist_t *new_element ( ) {
list_t *e_ptr;
e_ptr = (list_t *) malloc (sizeof (list_t));
if (e_ptr==NULL) {
fprintf (stderr, "Memory allocation error.\n");
exit (FAILURE);
}
return (e_ptr);
}