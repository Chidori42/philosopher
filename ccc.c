char *get_next_line(int fd)
{
    static char *buffer[BUFFER_SIZE + 1];
    char *line;
    char *new_line;
    int byt;
    int cpy;

    line = strdup(buffer);
    while(!(new_line = strchr(line, '\n')) && byt = read(fd, buffer, BUFFER_SIZE))
    {
        buffer[byt] = 0;
        line = strjoin(line, buffer);
    }
    if (strle(line) == 0)
        return (free(line), NULL)
    if (new_line)
    {
        cpy = new_line - line + 1;
        srcpy(buffer, new_line + 1);
    }
    else
    {
        cpy = strlen(line);
        buffer[0] = 0;
    }
    line[cpy] = 0;
    return (NULL);
}