#include <stdio.h>

#ifdef DEBUG
#define D(x) x
#else
#define D(x)
#endif

#define MAXCAND     25
#define MAXBALLOT   1005

int candidate_count;
char candidate[MAXCAND][256];
int ballot_count;
int ballot_first[MAXBALLOT];
int ballot[MAXBALLOT][MAXCAND];


int is_member(int set[], int n, int elem)
{
    int i;

    for(i=n-1; i>=0; i--) {
        if(set[i] == elem)
            return 1;
    }

    return 0;
}
void voting()
{
    int i, j, v, min;
    int votes[MAXCAND];

    int bn = 0;
    int banished[MAXCAND];

    int lbn;
    int last_banished[MAXCAND];

    while(1) {
        lbn = 0;
        for(i=0; i<candidate_count; i++)
            votes[i] = 0;


        for(i=0; i<ballot_count; i++) {
            v = ballot[i][ ballot_first[i] ]-1; /* minha 1a opcao (indice 0) */
            votes[v]++;
        }
        for(i=0; i<candidate_count; i++) {
            if(votes[i] > (double)ballot_count * 0.50) {
                D(printf("--vencedor--\n"));
                printf("%s\n", candidate[i]);
                return;
            }
        }


        min = 99999;
        for(i=0; i<candidate_count; i++) {
            if(votes[i] < min && !is_member(banished, bn, i))
                min = votes[i];
        }

        for(i=0; i<candidate_count; i++) {
            if(votes[i] == min && !is_member(banished, bn, i)) {
                banished[bn++] = i;
                last_banished[lbn++] = i;
                D(printf("banished = %d (%s)\n", i, candidate[i]));
            }
        }


        for(i=0; i<ballot_count; i++) {
            while(is_member(banished, bn, ballot[i][ ballot_first[i] ]-1)) { /* retirando 1a opcao */
                ballot_first[i]++;
                if(ballot_first[i] >= candidate_count) { /* ja removi todo mundo! */
                    D(printf("--empate--\n"));
                    for(j=0; j<lbn; j++)
                        printf("%s\n", candidate[ last_banished[j] ]);
                    return;
                }
            }
        }

    }
}
int main()
{
    int t, i, n;
    char line[256], *p;

    gets(line);
    sscanf(line, "%d", &t);
    gets(line);
    while(t--) {
        gets(line);
        sscanf(line, "%d", &candidate_count);
        if(candidate_count == 0) {
            gets(line);
            if(t>0) printf("\n");
            continue;
        }
        for(i=0; i<candidate_count; i++)
            gets(candidate[i]);

        ballot_count = 0;
        while(gets(line) && line[0] != '\0') {
            ballot_first[ballot_count] = 0;
            for(i=0,p=line; sscanf(p, "%d%n", &ballot[ballot_count][i++], &n)>0; p+=n);
            ballot_count++;
        }
        voting();
        if(t > 0) printf("\n");
    }

    return 0;
}
