#include "one_path.h"

vector<int>*
DijkstraMin(int Cities, int MainPeak, vector<vector<int>> TableLength)
{
    vector<int> MinDist(Cities);
    bool VisitTop[Cities];
    for (int i = 0; i < Cities; ++i) {
        if (!TableLength[MainPeak][i])
            MinDist[i] = INT_MAX;
        else
            MinDist[i] = TableLength[MainPeak][i];
        VisitTop[i] = false;
    }

    MinDist[MainPeak] = 0;
    int Index = 0, U = 0;
    for (int i = 0; i < Cities; ++i) {
        int Min = INT_MAX;
        for (int j = 0; j < Cities; ++j) {
            if (!VisitTop[j] and MinDist[j] < Min) {
                Min = MinDist[j];
                Index = j;
            }
        }
        U = Index;
        VisitTop[U] = true;
        for (int j = 0; j < Cities; ++j) {
            if (!VisitTop[j] and TableLength[U][j] != 0
                and MinDist[U] != INT_MAX
                and (MinDist[U] + TableLength[U][j] < MinDist[j])) {
                MinDist[j] = MinDist[U] + TableLength[U][j];
            }
        }
    }

    for (int i = 0; i < Cities; ++i) {
        for (int j = 0; j < Cities; ++j) {
            cout << "|" << setw(4) << TableLength[i][j] << " ";
        }
        cout << "|" << endl;
    }
    return &MinDist;
}

vector<int>*
DijkstraMax(int Cities, int MainPeak, vector<vector<int>> TableLength)
{
    vector<int> MaxDist(Cities);
    bool VisitTop[Cities];
    for (int i = 0; i < Cities; ++i) {
        if (!TableLength[MainPeak][i])
            MaxDist[i] = INT_MIN;
        else
            MaxDist[i] = TableLength[MainPeak][i];
        VisitTop[i] = false;
    }

    MaxDist[MainPeak] = 0;
    int Index = 0, U = 0;
    for (int i = 0; i < Cities; ++i) {
        int Max = -1;
        for (int j = 0; j < Cities; ++j) {
            if (!VisitTop[j] and MaxDist[j] > Max) {
                Max = MaxDist[j];
                Index = j;
            }
        }
        U = Index;
        VisitTop[U] = true;
        for (int j = 0; j < Cities; ++j) {
            if (!VisitTop[j] and TableLength[U][j] != 0
                and MaxDist[U] != INT_MIN
                and (MaxDist[U] + TableLength[U][j] > MaxDist[j])) {
                MaxDist[j] = MaxDist[U] + TableLength[U][j];
            }
        }
    }
    return &MaxDist;
}