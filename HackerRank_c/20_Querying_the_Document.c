#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5
char* kth_word_in_mth_sentence_of_nth_paragraph(char**** doc, int k, int m, int n) {
    return doc[n-1][m-1][k-1];
}   

char** kth_sentence_in_mth_paragraph(char**** doc, int k, int m) { 

return doc[m-1][k-1];
}

char*** kth_paragraph(char**** doc, int k) {
    return doc[k-1];
}

char**** get_document(char* t) {
    char ****doc;
    int i,j,vm=0,sm=0,pm=0,lm=0,m=0;
    doc=malloc(sizeof(char***));
    doc[0]=malloc(sizeof(char**));
    doc[0][0]=malloc(sizeof(char*));
    doc[0][0][0]=malloc(sizeof(char));
    for(m=0;t[m]!='\0';m++)
    {
        if(t[m]=='\n')
        {
            pm++;
            doc=realloc(doc,(pm+1)*sizeof(char***));
            vm=0;
            sm=0;
            lm=0;
            doc[pm]=malloc(sizeof(char**));
            doc[pm][0]=malloc(sizeof(char*));
            doc[pm][0][0]=malloc(sizeof(char));
        }
        else if(t[m]=='.')
        {
            doc[pm][sm][vm][lm]='\0';
            sm++;
            (doc[pm])=realloc((doc[pm]),(sm+1)*sizeof(char**));
            vm=0;
            lm=0;
            doc[pm][sm]=malloc(sizeof(char*));
            doc[pm][sm][0]=malloc(sizeof(char));
        }
        else if(t[m]==' ')
        {
            doc[pm][sm][vm][lm]='\0';
            vm++;
            (doc[pm][sm])=realloc((doc[pm][sm]),(vm+1)*sizeof(char*));
            doc[pm][sm][vm]=malloc(sizeof(char));
            lm=0;
        } 
        else
        {
            
            (doc[pm][sm][vm])=realloc((doc[pm][sm][vm]),(lm+1)*sizeof(char));
            doc[pm][sm][vm][lm]=t[m];
            lm++;
        }  
    }  
        
    return doc;
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}