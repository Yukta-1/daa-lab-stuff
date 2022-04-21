#include <iostream>
#include <string.h>
using namespace std;
void computeLPSArray(char* pat, int M, int* lps);
void KMP(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int lps[M];
	computeLPSArray(pat, M, lps);
	int i = 0;
	int j = 0;
    int checker=0;
	while (i < N) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			cout<<"Y";
            checker++;
			j = lps[j - 1];
		}
		else if (i < N && pat[j] != txt[i]) {
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
    if(checker==0)
        cout<<"N";
}
void computeLPSArray(char* pat, int M, int* lps)
{
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0) {
				len = lps[len - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

int main()
{
    int num;
    cin>>num;
    char texters_input[num][20];
    char patterns_input[num][20];
    int i=0;
    while (i<num){
        cin>>texters_input[i];
        cin>>patterns_input[i];
        i++;
    }
    int j=0;
    while(j<num){
        KMP(patterns_input[j], texters_input[j]);
        j++;
    }
	return 0;
}
