#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "file_operations.h"

#define NEW_BUFFER_SIZE           2
#define POSSIBLE_COMMANDS_COUNT   4


uint8_t match(char *string, char *dictionary[], size_t count, uint8_t *index){
 for(uint8_t i = 0; i < count; i++){
   if(strcmp(string, dictionary[i]) == 0){
    *index = i;
    return 1;
   }
 }
 return 0;
}

int main(int argc, char *argv[]){

 size_t text_buffer_size; // This is the # of elements in the text buffer
 char *buffer;            // This will hold all the text

 char *commands[] = {"new", "create", "open", "read"};
 uint8_t command;

 size_t (*run_command[4])(char **buffer, size_t *buffer_size, char *fileName);


 if(argc < 3){
  printf("Usage for this program is:\n%s [COMMAND] [FILE]\n", argv[0]);
  exit(1);
 }
 if(match(argv[1], commands, POSSIBLE_COMMANDS_COUNT, &command) == 0){
  printf("Commmand \"%s\" not recognized\n", argv[1]);
  exit(1);
 }


 run_command[0] = newFile;
 run_command[1] = newFile;  // The "new" and "create" commands do the exact same thing lol
 run_command[2] = openFile;
 run_command[3] = openFile; // Same thing with "open" and "read"

 run_command[command](&buffer, &text_buffer_size, argv[2]);
 buffer[(text_buffer_size / 2)] = '\0';
 printf("%s", buffer); 
 free(buffer);

 return 0;
}
