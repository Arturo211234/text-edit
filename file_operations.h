size_t newFile(char **buffer, size_t *buffer_size, char *fileName){
 /* In this function, we'll be setting the buffer_size to 2, and
  * the first element of buffer to a space
  */
 
 *buffer_size = 2;
 *buffer = (char *) malloc(*(buffer_size) * 2);
 *buffer[0] = (char) ' ';
 buffer[1] = (char) '\0';
 printf("File \"%s\" is created and ready to edit!\n", fileName); // Completely unnecessary, but it
                                                                  // Makes the compiler not whine about
                                                                  // an unused variable, so it's whatever :)
 *buffer_size = (*buffer_size) * 2;
 return 0;
}

size_t openFile(char **buffer, size_t *buffer_size, char *fileName){
 FILE *file; 
 file = fopen(fileName, "r+");

 if(file == NULL){
  printf("Cannot open file \"%s\"\n", fileName);
  exit(1);
 }

 fseek(file, 0, SEEK_END);
 *buffer_size = (size_t) ftell(file);
 rewind(file);
 *buffer = (char *) malloc((*buffer_size) * 2);
 size_t ret_val = fread((*buffer), 1, (*buffer_size), file);
 if(ret_val != (*buffer_size)){
  puts("Unable to read file");
  exit(1);
 }
 printf("Bytes Read: %ld\n", ret_val);
 fclose(file);
 *buffer_size = (*buffer_size) * 2;
 return ret_val;
}

