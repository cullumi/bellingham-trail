
#include <stdio.h>
#include <string.h>

typedef struct {
  // char tag[12];
  // char p[512];
  // char o1[128]; // Options
  // char o2[128];
  // char o3[128];
  // char r1[256]; // Responses
  // char r2[256];
  // char r3[256];
  // char rd[256];
  // char d1[12]; // Destination Tags
  // char d2[12];
  // char d3[12];
  char *tag;
  char *p;
  char *o1; // Options
  char *o2;
  char *o3;
  char *r1; // Responses
  char *r2;
  char *r3;
  char *rd;
  char *d1; // Destination Tags
  char *d2;
  char *d3;
} DiNode;

DiNode tree[4];


char* answerPrompt (DiNode prompt) {

  printf( "<> %s\n", prompt.p);
  printf( "  (1) %s\n  (2) %s\n  (3) %\n\n", prompt.o1, prompt.o2, prompt.o3);

  char* destination = NULL;
  int answer = 0;
  char* response = NULL;
  while (response == NULL){
    printf( "<> (1 , 2, or 3?):  ");
    scanf( "%d", &answer );
    switch ( answer ) {
      case 1:
        response = prompt.r1;
        destination = prompt.d1;
        break;
      case 2:
        response = prompt.r2;
        destination = prompt.d2;
        break;
      case 3:
        response = prompt.r3;
        destination = prompt.d3;
        break;
      default:
        printf("\n<< %s\n\n", prompt.rd);
    }
  }
  printf("%s\n", prompt.r1);
  printf("%s\n", prompt.d1);
  printf("\n>> %s\n\n", response);
  printf("%s\n", destination);

  return destination;
}


void breakPoint(){}

// KEEP AN EYE OUT FOR BROKEN PRINTS-- i.e., always print strings using %s.
void generateTree (FILE *fp) {
  //struct DiNode treeRoot[4];
  DiNode node; // Check this out later:  https://stackoverflow.com/questions/10162152/how-to-work-with-string-fields-in-a-c-struct
  int i = 1;
  int j = 0;
  char line[512] = "Hello World My Name Is Ian, How Are You Doing Today?";

  while (fgets(line, sizeof line, fp) != NULL){
    if (strncmp(line,"\n",2)){
      //printf("breakPoint");
      // printf("%s\n", "Stuff");
      printf("%s / %d\n", line, i);
      // printf("%s\n", "Stuff");
      switch ( i % 13 ) {
        case 1: printf("%s / %s\n",node.tag, node.p); node.tag = line; printf("%s / %s\n",node.tag, node.p); break; //*strdup(line); printf("%s\n", "SET TAG"); break;
        case 2: node.p = line; break; //printf("%s\n", "SET PROMPT"); break;
        case 3: node.o1 = line; break; //printf("%s\n", "SET OP 1"); break;
        case 4: node.o2 = line; break;
        case 5: node.o3 = line; break;
        case 6: node.r1 = line; break;
        case 7: node.r2 = line; break;
        case 8: node.r3 = line; break;
        case 9: node.rd = line; break;
        case 10: node.d1 = line; break;
        case 11: node.d2 = line; break;
        case 12: node.d3 = line; break;
        default : printf("%s\n", "default switch"); break;
      }
      i++;

      // printf("%s\n", "Stuff");
      breakPoint();

      // printf("%s\n", node.tag);
      //printf("%s ||| %s ||| %s", node->tag, node->p, node->d3);
      //printf("SWITCH");
      printf("* %s\n", line);
      //char new_line[512];
      //*line = new_line;
      //printf("* %s", line);
    }
    else {
      printf("NOT SWITCH");
      printf(" \n");
      tree[j] = node;
      //treeRoot[j] = node;
      j++;
    }
  }
}

int main( int argc, const char *argv[] ){
  printf( "\n Hello, and welcome to Bellingham Trail!\n\n" );

  FILE *fp;
  printf("Attempting to open argument.\n");
  fp = fopen(argv[1], "r");
  if (!fp) {
    printf("Attempting to open default\n");
    fp = fopen("belTrail.txt", "r");
    if (!fp) {
      printf("Could not find %s, and could not find default gamefile.\n\n", argv[1]);
      return 0;
    }
  }
  printf("Opened a file? %d\n\n", fp);

  //struct DiNode* treeRoot = generateTree(fp);
  generateTree(fp);
  answerPrompt(tree[0]);
  //return generateTree(fp);
  return 0;
}
