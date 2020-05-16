#include "one_path.h"

void DijkstraMin(int Cities, int MainPeak, vector<vector<int>> TableLength)
{
    int MinDist[Cities];
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

    cout << "Наименьшее расстояние от " << MainPeak + 1
         << " до всех вершин: " << endl;
    for (int i = 0; i < Cities; ++i) {
        cout << MainPeak + 1 << " ---> " << i + 1 << " = ";
        if (MinDist[i] != 0)
            cout << MinDist[i] << endl;
        else
            cout << "Невозможно проехать " << endl;
    }
}