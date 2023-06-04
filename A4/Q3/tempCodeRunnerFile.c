    printf("as strings:\n");
    while (tok_nums != NULL)
    {   
        printf ("%s\n",tok_nums);
        tok_nums = strtok (NULL, " /*%+-");
    }