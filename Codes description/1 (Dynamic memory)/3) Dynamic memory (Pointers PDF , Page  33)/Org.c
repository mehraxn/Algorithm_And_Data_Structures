struct student {
    char s1[L], s2[L];
    int i;
    float f;
};

void my_read (struct student *v) {
    char s1[DIM], s2[DIM];
    int i; float f;
    fprintf (stdout, "Enter student details (s1 s2 i f): ");
    scanf ("%s%s%d%f", s1, s2, &i, &f);
    strcpy (v->s1, s1);
    strcpy (v->s2, s2);
    v->i = i;
    v->f = f;
    return;
}
