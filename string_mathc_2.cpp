
#include <iostream>
#include <cstring>
using namespace std;

void computeLPSArray(char* pat, int M, int* lps);

void KMPSearch(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int lps[M];
	computeLPSArray(pat, M, lps);
    int flag=0;
	int i = 0;
	int j = 0;
	while (i < N) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			cout<<"Y"<<endl;
            flag=1;
            break;
			j = lps[j - 1];
		}
		else if (i < N && pat[j] != txt[i]) {
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
    if(flag==0){
        cout<<"N"<<endl;
    }
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
    int strings;
    cin>>strings;
	char txt[100];
	char pat[100];
    for(int i=0;i<strings;i++){
        cin>>txt;
        cin>>pat;
	    KMPSearch(pat, txt);
    }
	return 0;
}
