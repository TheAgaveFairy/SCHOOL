#ifndef ASSIGN6_H
#define ASSIGN6_H

#define myReader(buffer)  memset(buffer,0,sizeof(buffer));\
                          fgets(buffer,sizeof(buffer),stdin);\
                          buffer[strcspn(buffer, "\n")] = '\0'



#endif