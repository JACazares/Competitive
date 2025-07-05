#include <iostream>
#include <algorithm>
#define MAXN 40
using namespace std;
int N, M, a[MAXN], sumFirst[(1<<(MAXN/2))], sumSecond[(1<<(MAXN/2))];
int firstHalf, secondHalf, firstIndex, secondIndex, ans=-1;

int Binaria(int index) {
    int s = 0, e = (1<<secondHalf)-1;
    int mid=0, val=0, ret=0;
    int lookingFor=M-1;
    while(s <= e) {
        mid = (s+e)/2;
        val = sumSecond[mid]+sumFirst[index];
        if(val < lookingFor) {
            ret = mid;
            s = mid+1;
        } else if(val > lookingFor)
            e = mid-1;
        else
            return mid;
    }
    return ret;
}

int main() {
    cin >> N >> M;
    for(int i=0; i<N; i++)
        cin >> a[i];
    firstHalf = N/2;
    secondHalf = N-firstHalf;
    for(int i=0; i<(1<<(firstHalf)); i++) {
        for(int j=0; j<firstHalf; j++) {
            //cout << ((i&(1<<j))>0);
            if(i&(1<<j))
                sumFirst[i] = (sumFirst[i]+(a[j]%M))%M;
        }
        //cout << "\n" << sumFirst[i] << "\n";
    }
    for(int i=0; i<(1<<(secondHalf)); i++) {
        for(int j=0; j<secondHalf; j++) {
            //cout << ((i&(1<<j))>0);
            if(i&(1<<j))
                sumSecond[i] = (sumSecond[i]+(a[j+firstHalf]%M))%M;
        }
        //cout << "\n" << sumSecond[i] << "\n";
    }
    sort(sumSecond, sumSecond+(1<<secondHalf));
    for(int i=0; i<(1<<(firstHalf)); i++) {
        firstIndex = i;
        secondIndex = Binaria(i);
        //cout << "for " << i << " -> " << secondIndex << "\n";
        //cout << "   " << sumFirst[firstIndex] << " " << sumSecond[secondIndex] << "\n";
        ans = max(ans, (sumFirst[firstIndex]+sumSecond[secondIndex])%M);
    }
    cout << ans << "\n";
    return 0;
}
