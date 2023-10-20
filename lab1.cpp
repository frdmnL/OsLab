#include <iostream>
#include <algorithm>

using namespace std;

#define MAXSIZE 4

int number;

struct process
{
    string pid;
    double come_time;
    double run_time;
    double begin_time;
    double over_time;
    double round_time;
    double avg_time;
    double HRR;
}pc[MAXSIZE];

bool CmpByComeTime(process p1, process p2)
{
    return p1.come_time < p2.come_time;
}

bool CmpByPid(process p1, process p2)
{
    return p1.pid < p2.pid;
}

bool CmpByRunTime(process p1, process p2)
{
    return p1.run_time == p2.run_time ? p1.come_time < p2.come_time : p1.come_time;
}

bool CmpByHRR(process p1, process p2)
{
    return p1.HRR > p2.HRR;
}

void get_beginAndOver_time()
{
    for (int i = 0; i < number;i++)
    {
        if(i == 0)
        {
            pc[i].begin_time = pc[i].come_time;
        }
        else
        {
            pc[i].begin_time = pc[i - 1].over_time;
        }
        pc[i].over_time = pc[i].begin_time + pc[i].run_time;
    }
}

void get_roundAndAvg_time()
{
    for (int i = 0; i < number;++i)
    {
        pc[i].round_time = pc[i].over_time - pc[i].come_time;
        pc[i].avg_time = pc[i].round_time * 1.0 / pc[i].run_time;
    }
}

void get_HRR(int beg)
{
    for (int i = beg; i < number;i++)
    {
        pc[i].HRR = (pc[beg - 1].over_time - pc[i].come_time) * 1.0 / pc[i].run_time;
    }
}

void FCFS()
{
    sort(pc, pc + number, CmpByComeTime);
    get_beginAndOver_time();
    get_roundAndAvg_time();
}

void SJF()
{
    sort(pc, pc + number, CmpByComeTime);
    sort(pc + 1, pc + number, CmpByRunTime);
    get_beginAndOver_time();
    get_roundAndAvg_time();
}

void HRRN()
{
    sort(pc, pc + number, CmpByComeTime);
    for (int i = 1; i < number;++i)
    {
        get_HRR(i);
        sort(pc + i, pc + number, CmpByHRR);
    }
    get_beginAndOver_time();
    get_roundAndAvg_time();
}

void printResult()
{
    cout << "执行顺序： ";
    for (int i = 0; i < number;i++)
    {
        cout << pc[i].pid << " ";
    }
    cout << endl;
    cout << "作业名" << '\t' << "到达时" << '\t' << "运行时" << '\t' << "开始时" << '\t' << "完成时" << '\t' << "周转时" << '\t' << "带权周转时" << '\t' << endl;

    sort(pc, pc + number, CmpByPid);
    double sum_round_time = 0.0;
    double avg_sum_round_time = 0.0;
    double sum_avg_time = 0.0;
    double avg_sum_avg_time = 0.0;
    for (int i = 0; i < number;++i)
    {
        sum_round_time += pc[i].round_time;
        sum_avg_time += pc[i].avg_time;
        cout << pc[i].pid << '\t' << pc[i].come_time << '\t' << pc[i].run_time << '\t' << pc[i].begin_time << '\t' << pc[i].over_time << '\t' << pc[i].round_time << '\t' << pc[i].avg_time << endl;
    }
    avg_sum_round_time = sum_round_time * 1.0 / number;
    avg_sum_avg_time = sum_avg_time * 1.0 / number;
    cout << "平均周转时间：" << avg_sum_round_time << endl
         << "平均带权周转时间：" << avg_sum_avg_time << endl;
}

int main()
{
    cout << "请输入进程个数：";
    cin >> number;

    cout << endl;
    cout << "请分别输入进程的名称、到达时间和运行时间：" << endl;
    for (int i = 0; i < number;i++)
    {
        cin >> pc[i].pid >> pc[i].come_time >> pc[i].run_time;
    }

    cout << endl;
    SJF();
    cout << "the result of SJF are:" << endl;
    printResult();

    cout << endl;
    HRRN();
    cout << "the results of HRNN are:" << endl;
    printResult();

    cout << endl;
    system("pause");
    return 0;
}