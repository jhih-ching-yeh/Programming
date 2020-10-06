#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

int Find_index(int a[], int num) // 找出num在array中的哪個位置
{
    for(int k=1;k<=a[0];k++)
    {
        if(a[k]==num)
        return k;
    }

    return 0;
}

void Delete(int a[], int num) // 刪除num，實際上沒有刪除，只是把num設為0並移到最後面，再利用a[0]控制array中前多少個數字是可用的
{
    int position = Find_index(a, num); // 找出num的位置

    if(position!=0) // 如果num存在array中
    {
        a[position] = 0; // 要刪掉的值設為0，表示不存在
        for(int i=position;i<a[0];i++) // 把num移到最後面
            std::swap(a[i], a[i+1]);
        a[0]--; // 可用的數字減1
    }

}

void Clear(int a[]) // 清掉整個array
{
    for(int i=1;i<=a[0];i++)
        a[i] = 0;
    a[0] = 0; // 可用的數字設為0，表示array中沒有數字可以使用
}

void PrintResult(int a[], int n) // 印出結果
{
    for(int i=1;i<=n;i++)
        printf("%d ", a[i]);
}

int main() {

    int n,m;
    scanf("%d %d", &n, &m);
    int e[n+5], e_rest[n+5]; // e_rest: 目前可錄取的人數
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &e[i]);
        e_rest[i] = e[i]; // 目前可錄取的人數初始值 = 原本可錄取人數
    }
    char c;

    int University[n+5][m+5];
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &University[i][1]);
        int j=2;
        while((c=getchar())!='\n')
        {
            scanf("%d", &University[i][j]);
            j++;
        }
        University[i][j] = 0; // 在order list最後面加一個0，代表array的結尾
        University[i][0] = j-1; // 每一個University的第0個位置存 這個University還有多少個值可用
    }

    int Applicant[m+5][n+5];
    for(int i=1;i<=m;i++)
    {
        scanf("%d", &Applicant[i][1]);
        int j=2;
        while((c=getchar())!='\n')
        {
            scanf("%d", &Applicant[i][j]);
            j++;
        }
        Applicant[i][j] = 0; // 在order list最後面加一個0，代表array的結尾
        Applicant[i][0] = j-1; // 每一個Applicant的第0個位置存 這個Applicant還有多少個值可用
    }

    int activate=1;
    int stop=0;
    int now=1;

    while(stop!=m)
    {
        while(activate==1)
        {
            activate=0; // 如果沒有人配對成功 -> activate=0 -> 跳出迴圈
            for(int i=1;i<=m;i++)
            {
                if(Applicant[i][0]!=0) // 如果第i個Applicant存在 (還沒配對成功)
                {
                    int first_Uni = Applicant[i][now]; // first_Uni: 第i個Applicant的第now個志願大學
                    int position = Find_index(University[first_Uni], i); // 到第first_Uni個University找第i個人在哪個位置

                    if(position<=e[first_Uni]) // 如果位置在可錄取的名額內->執行下列工作 (配對成功)
                    {
                        Clear(Applicant[i]); // 清除第i個Applicant
                        e_rest[first_Uni]--; // 可錄取名額-1

                        for(int j=1;j<=n;j++) // 到 除了配對成功以外的University 刪除 剛剛錄取的Applicant
                        {
                            if(j!=first_Uni)
                            {
                                Delete(University[j], i); //在第j個Universuty array 刪除 第i個Applicant
                            }
                        }
                        if(e_rest[first_Uni]==0) // 如果第first_Uni個University收滿了
                        {
                            for(int j=1;j<=m;j++) // 去 每一個Applicant的list 刪除 這個學校
                            {
                                Delete(Applicant[j], first_Uni); //在第j個Applicant array 刪除 第first_Uni個University
                            }
                        }
                        activate = 1; // 有配對成功->讓迴圈繼續，重複執行同樣的步驟

                        if(now!=1) // 如果目前不是在配對Applicant的第一志願
                        {
                            for(int j=1;j<=m;j++) // 因為有配對成功，所以所有Applicant從第一志願開始檢查
                            {
                                if(Applicant[j][0]!=0)
                                    now = 1;
                            }
                            break; // 回到第一個Applicant開始配對
                        }
                    }
                }
            }
        }

        for(int i=1;i<=m;i++) // 如果所有Applicant都配對失敗->找下一個志願
        {
            if(Applicant[i][now+1]!=0) // 如果目前志願的下一個值不等於0(0表示不存在)
                now++;
            else // 如果所有人的志願都找完了 -> stop會等於 m(Applicant人數) -> 配對結束
                stop++;
        }
        activate = 1;
    }

    /*印出結果*/
    for(int i=1;i<=n;i++)
    {
        printf("U_%d: ", i);
        PrintResult(University[i], e[i]-e_rest[i]); // 實際錄取的名額 = 原本的名額 - 剩下的名額
        printf("\n");
    }

    return 0;
}


