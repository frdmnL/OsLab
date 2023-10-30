#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Process
{
    std::string name;
    int priority;
    int serviceTime;
    int turnaroundTime;
};

void calculateTurnaroundTime(std::vector<Process> &processes)
{
    processes[0].turnaroundTime = processes[0].serviceTime;
    for (std::size_t i = 1; i < processes.size(); i++)
    {
        processes[i].turnaroundTime = processes[i - 1].turnaroundTime + processes[i].serviceTime;
    }
}

float calculateAverageTurnaroundTime(const std::vector<Process> &processes)
{
    float totalTurnaroundTime = 0.0;
    for (const auto &process : processes)
    {
        totalTurnaroundTime += process.turnaroundTime;
    }
    return totalTurnaroundTime / processes.size();
}

int main()
{
    std::vector<Process> processes;
    int numProcesses = 3;

    // 输入进程信息
    for (int i = 0; i < numProcesses; i++)
    {
        Process process;
        std::cin >> process.name >> process.priority >> process.serviceTime;
        process.turnaroundTime = 0;
        processes.push_back(process);
    }

    // 按优先级排序
    std::sort(processes.begin(), processes.end(), [](const Process &p1, const Process &p2)
              { return p1.priority > p2.priority; });

    // 计算周转时间
    calculateTurnaroundTime(processes);

    // 计算平均作业周转时间
    float averageTurnaroundTime = calculateAverageTurnaroundTime(processes);

    // 输出结果
    std::cout << std::fixed << std::setprecision(1);
    std::cout << averageTurnaroundTime << std::endl;

    return 0;
}