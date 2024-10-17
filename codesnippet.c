typedef char string[MAXCHAR];

int main(void){
    string* wordlist = malloc(FILELEN*sizeof(string));
    
    getfromfile(wordlist, FILENAME);

    unsigned long long val = specificVal("retinas");

    for(int i=0; i<FILELEN; i++){
        if( val == specificVal(wordlist[i]) ){
            printf("%s\n", wordlist[i]);
        }
    }

    return 0;
}

unsigned long long specificVal(const string s){
    int primes[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
    unsigned long long val = 1;

    for(int i=0; i<strlen(s); i++){
        val *= primes[s[i] - 'a'];
    }
    return val;
}
