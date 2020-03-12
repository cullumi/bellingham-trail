
#include <stdio.h>
#include <string.h>

struct DiNode {
  char* tag;
  char* p;
  char* o1; // Options
  char* o2;
  char* o3;
  char* r1; // Responses
  char* r2;
  char* r3;
  char* rd;
  char* d1; // Destination Tags
  char* d2;
  char* d3;
};

char* answerPrompt (struct DiNode* prompt) {

  printf( "<> %s\n", prompt->p);
  printf( "  (1) %s\n  (2) %s\n  (3) %\n\n", prompt->o1, prompt->o2, prompt->o3);

  char* destination = NULL;
  int answer;
  char* response = NULL;
  while (response == NULL){
    printf( "<> (1 , 2, or 3?):  ");
    scanf( "%d", &answer );
    switch ( answer ) {
      case 1:
        response = prompt->r1;
        destination = prompt->d1;
        break;
      case 2:
        response = prompt->r2;
        destination = prompt->d2;
        break;
      case 3:
        response = prompt->r3;
        destination = prompt->d3;
        break;
      default:
        printf("\n<< %s\n\n", prompt->rd);
    }
  }
  printf("\n>> %s\n\n", response);

  return destination;
}

void breakPoint(){}

/*struct DiNode**/int generateTree (FILE *fp) {
  struct DiNode* treeRoot[4];
  struct DiNode* node;
  int i = 1;
  int j = 0;
  char line[512];

  breakPoint();

  while (fgets(line, sizeof line, fp) != NULL){

    breakPoint();

    if (strncmp(line,"\n",1)){
      switch ( i ) {
        case 1: node->tag = line; break;
        case 2: node->p = line; break;
        case 3: node->o1 = line; break;
        case 4: node->o2 = line; break;
        case 5: node->o3 = line; break;
        case 6: node->r1 = line; break;
        case 7: node->r2 = line; break;
        case 8: node->r3 = line; break;
        case 9: node->rd = line; break;
        case 10: node->d1 = line; break;
        case 11: node->d2 = line; break;
        case 12: node->d3 = line; break;
        default : break;
      }
      i++;

      breakPoint();

      printf("* %s", line);
    }
    else {
      printf(" \n");
      treeRoot[j] = node;
      j++;
      i = 1;
    }
  }

  return 0;//treeRoot;
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
  return generateTree(fp);
}
