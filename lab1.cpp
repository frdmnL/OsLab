#include <iostream>
struct process
{
    char processname[3];
    int occasion;
    int time;
};

int main()
{
    using namespace std;
    process task[4];
    for(int i=0;i<4;i++)
    {
        cin >> task[i].processname >> task[i].occasion >> task[i].time;
    }

    //cout << task[2].processname << ' ' << task[2].occasion << ' ' << task[2].time << endl;
    return 0;
}
// #include <iostream>
// #include <vector>
// #include <algorithm>

// struct Process {
//     std::string name;
//     int arrivalTime;
//     int executionTime;
// };

// bool compareProcesses(const Process& p1, const Process& p2) {
//     if (p1.executionTime == p2.executionTime) {
//         return p1.arrivalTime < p2.arrivalTime;
//     }
//     return p1.executionTime < p2.executionTime;
// }

// int main() {
//     std::vector<Process> processes;

//     // 输入进程信息
//     for (int i = 0; i < 4; ++i) {
//         Process p;
//         std::cin >> p.name >> p.arrivalTime >> p.executionTime;
//         processes.push_back(p);
//     }

//     // 按照非剥夺式短作业优先调度算法排序
//     std::sort(processes.begin(), processes.end(), compareProcesses);

//     // 输出进程名称
//     for (const Process& p : processes) {
//         std::cout << p.name << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }