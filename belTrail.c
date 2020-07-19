
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct DiNode {
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

DiNode *tree[4];

char* answerPrompt (DiNode *prompt) {

  printf( " <> %s\n", prompt->p);
  printf( "   (1) %s\n   (2) %s\n   (3) %s\n\n", prompt->o1, prompt->o2, prompt->o3);

  char* destination = NULL;
  int answer = 0;
  char* response = NULL;
  while (response == NULL){
    printf( " <> (1 , 2, or 3?):  ");
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
        printf("\n << %s\n\n", prompt->rd);
    }
  }
  printf("\n >> %s\n\n", response);
  printf(" %s\n", destination);

  return destination;
}

void breakPoint(){}

// KEEP AN EYE OUT FOR BROKEN PRINTS-- i.e., always print strings using %s.
DiNode* generateTree (FILE *fp) {
  DiNode *node = malloc(sizeof(struct DiNode));
  //Check this out later:  https://stackoverflow.com/questions/10162152/how-to-work-with-string-fields-in-a-c-struct
  int i = 1;
  int j = 0;
  char line[512] = "Hello World My Name Is Ian, How Are You Doing Today?";

  while (fgets(line, sizeof line, fp) != NULL){
    if (strncmp(line,"\n",2)){
      if (line[strlen(line)-1] == '\n'){
        line[strlen(line)-1] = 0;
      }
      printf(" %d / %s\n", i, line);
      switch ( i % 13 ) {
        case 1: node->tag = strdup(line); break; //printf("%s / %s\n",node.tag, node.p); node.tag = line; printf("%s / %s\n",node.tag, node.p); break; //*strdup(line); printf("%s\n", "SET TAG"); break;
        case 2: node->p = strdup(line); break; //printf("%s\n", "SET PROMPT"); break;
        case 3: node->o1 = strdup(line); break; //printf("%s\n", "SET OP 1"); break;
        case 4: node->o2 = strdup(line); break;
        case 5: node->o3 = strdup(line); break;
        case 6: node->r1 = strdup(line); break;
        case 7: node->r2 = strdup(line); break;
        case 8: node->r3 = strdup(line); break;
        case 9: node->rd = strdup(line); break;
        case 10: node->d1 = strdup(line); break;
        case 11: node->d2 = strdup(line); break;
        case 12: node->d3 = strdup(line); break;
        default : printf(" %s\n", "default switch"); break;
      }
      i++;
      breakPoint();
    }
    else {
      printf("\n NOT SWITCH\n");
      printf(" j = %d \n\n", j);
      if (i == 13){
        tree[j] = node;
        /*printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", tree[j]->tag, tree[j]->p,
          tree[j]->o1, tree[j]->o2, tree[j]->o3, tree[j]->r1, tree[j]->r2, tree[j]->r3,
          tree[j]->rd, tree[j]->d1, tree[j]->d2, tree[j]->d3);*/
          //treeRoot[j] = node;
      }
      node = malloc(sizeof(struct DiNode));
      j++;
      i = 1;
    }
  }
  printf("\n *Tree Generated* \n\n");
  return tree[0];
}

int tagintree(char* tag)
{
    printf("// tagintree?");
    printf("---- %s ", tag);
    int i;
    for(i = 0; i < sizeof(tree) / sizeof(tree[0]); i++)
    {
        printf("%d", i);
        //printf("%s %s / %s / %d\n", "Comparing Tags...", tree[i]->tag, tag, i);
        if(strcmp(tree[i]->tag, tag) == 0){
            //printf("  In Tree: %d\n", 1);
            printf("\n");
            return 1;
        }
    }
    printf("\n");
    //printf("  In Tree: %d\n", 0);
    return 0;
}

DiNode* nodeoftag(char* tag)
{
    int i;
    for(i = 0; i < sizeof(tree) / sizeof(tree[0]); i++)
    {
        if(strcmp(tree[i]->tag, tag) == 0)//tree[i]->tag == tag)
            return tree[i];
    }
    return 0;
}

int main( int argc, const char *argv[] ){
  printf( "\n Hello, and welcome to the belTrail engine!\n\n" );

  FILE *fp;
  char *default_game_file = "belTrail.txt";
  printf(" Attempting to open game... %s\n", argv[1]);
  fp = fopen(argv[1], "r");
  if (!fp) {
    printf(" Attempting to open default instead... %s\n", default_game_file);
    fp = fopen(default_game_file, "r");
    if (!fp) {
      printf(" Could not find %s, and could not find default gamefile %s.  Exiting engine.\n\n", argv[1], default_game_file);
      return 0;
    }
  }
  printf(" Opened a file? %d\n\n", fp);

  //struct DiNode* treeRoot = generateTree(fp);
  DiNode *node = generateTree(fp);
  char *tag = node->tag;
  //printf("%d\n", tagintree(tag));
  while (tagintree(tag)){
    printf("%s\n", tag);
    char *new_tag = answerPrompt(nodeoftag(tag));
    printf("Same Tag? \'%s\' / \'%s\' / %d\n", tag, new_tag, strncmp(tag, new_tag, 2));
    // *tag = *new_tag;
    printf("%s / %d\n", new_tag, tagintree(new_tag));
    //int inTree = tagintree(new_tag);
    //printf("  In Tree: %d\n", inTree);
    // printf("%s\n", tag);
    // printf("%d\n", tagintree(tag));
  }
  // free(tree);
  return 0;
}
