// Author: Diego Emilio Moreno Sanchez
// This program is a simple implementation of a CPU scheduler
// using the Round Robin algorithm and the shortest job first
// algorithm.
package main

import (
  "fmt"
  "math/rand"
  "text/tabwriter"
  "os"
)

// Process struct
type Process struct {
  id int 
  burstTime int 
  arrivalTime int 
  priority int 
}

type ClockCycle struct {
  process Process
  time float64 
}

// Menus 
func menu() {
  fmt.Println("CPU Scheduler")
  fmt.Println("1. Shortest Job First")
  fmt.Println("2. Round Robin")
  fmt.Println("3. Exit")
  fmt.Print("Enter an option: ")
}

func menuProcess() {
  fmt.Println("Process")
  fmt.Println("1. Generate random processes")
  fmt.Println("2. Enter processes manually")
  fmt.Println("3. Back")
  fmt.Print("Enter an option: ")
}

func shortestJobFirst() {
  var option int 
  var numberOfProcesses int
  for {
    menuProcess()
    fmt.Scanln(&option)
    switch option {
    case 1:
      fmt.Println("Enter the number of processes: ")
      fmt.Scanln(&numberOfProcesses)
      processes, totalTime := generateRandomProcess(numberOfProcesses)
      printProcesses(processes, totalTime)
      shortestJobFirstAlgorithm(processes, totalTime)
    case 2:
      fmt.Println("Enter the number of processes: ")
      fmt.Scanln(&numberOfProcesses)
      processes, totalTime := enterProcessManually(numberOfProcesses)
      printProcesses(processes, totalTime)
      shortestJobFirstAlgorithm(processes, totalTime)
    case 3:
      return
    default:
      fmt.Println("Invalid option")
    }
  }
}

func roundRobin() {
  var option int 
  var numberOfProcesses int
  var timeSlice int
  for {
    menuProcess()
    fmt.Scanln(&option)
    switch option {
    case 1:
      fmt.Println("Enter the number of processes: ")
      fmt.Scanln(&numberOfProcesses)
      processes, totalTime := generateRandomProcess(numberOfProcesses)
      fmt.Println("Enter the time slice: ")
      fmt.Scanln(&timeSlice)
      printProcesses(processes, totalTime)
      roundRobinAlgorithm(processes, totalTime, timeSlice)
    case 2:
      fmt.Println("Enter the number of processes: ")
      fmt.Scanln(&numberOfProcesses)
      processes, totalTime := enterProcessManually(numberOfProcesses)
      fmt.Println("Enter the time slice: ")
      fmt.Scanln(&timeSlice)
      printProcesses(processes, totalTime)
      roundRobinAlgorithm(processes, totalTime, timeSlice)
    case 3:
      return
    default:
      fmt.Println("Invalid option")
    }
  }
}

// Algorithms 
func shortestJobFirstAlgorithm(processes []Process, totalTime float64) {

  var currentCPUTime float64 = 0
  var clockCycle []ClockCycle 
  var processQueue []Process
  var isCPUIdle bool = true
  var nextFreeTime float64 = 0

  for currentCPUTime < totalTime {
    // Add the processes to the process queue 
    for _, process := range processes {
      if float64(process.arrivalTime) == currentCPUTime {
        processQueue = append(processQueue, process)
      }
    }

    if currentCPUTime >= nextFreeTime {
      isCPUIdle = true
    }

    // If the process queue is not empty
    if len(processQueue) > 0 && isCPUIdle {
      // Sort the process queue by burst time
      // and add the process to the clock cycle 
      // array 
      processQueue = sortProcessQueue(processQueue)
      clockCycle = append(clockCycle, ClockCycle{ 
        process: processQueue[0],
        time: currentCPUTime,
      })
      processQueue = processQueue[1:]
      isCPUIdle = false
      nextFreeTime = currentCPUTime + float64(clockCycle[len(clockCycle) - 1].process.burstTime)
    }

    currentCPUTime++
  }

  // Print the clock cycle array
  w := tabwriter.NewWriter(os.Stdout, 0, 0, 1, ' ', tabwriter.Debug)
  fmt.Fprintln(w, "ID\tBurst Time\tArrival Time\tReal Arrival Time\tPriority\tTime")
  for _, clock := range clockCycle {
    fmt.Fprintf(w, "%d\t%d\t%d\t%.2f\t%d\t%.2f\n", clock.process.id, clock.process.burstTime, clock.process.arrivalTime, clock.time, clock.process.priority, clock.time)
  }
  w.Flush()

}

func sortProcessQueue(processQueue []Process) []Process { 
  for i := 0; i < len(processQueue); i++ {
    for j := i + 1; j < len(processQueue); j++ {
      if processQueue[i].burstTime > processQueue[j].burstTime {
        processQueue[i], processQueue[j] = processQueue[j], processQueue[i]
      }
    }
  }
  return processQueue
}

/*
The round robin algorithm is a pre-emptive scheduling algorithm that assigns a fixed time unit per process. 
If the process is not finished within the time slice, the process is moved to the end of the queue. 
The algorithm is simple and easy to implement, but it is not the most efficient algorithm. 

The algorithm works as follows: 
1. Add the processes to the process queue. 
2. If the process queue is not empty, assign the process to the CPU. 
3. If the process is not finished within the time slice, move the process to the end of the queue. 
4. Repeat the process until all processes are finished. 
*/
func roundRobinAlgorithm(processes []Process, totalTime float64, timeSlice int) {
  
  var currentCPUTime float64 = 0
  var clockCycle []ClockCycle 
  var processQueue []Process
  var isCPUIdle bool = true
  var nextFreeTime float64 = 0

  for currentCPUTime < totalTime {
    // Add the processes to the process queue 
    for _, process := range processes {
      if float64(process.arrivalTime) == currentCPUTime {
        processQueue = append(processQueue, process)
      }
    }

    if currentCPUTime >= nextFreeTime {
      isCPUIdle = true
    }

    // If the process queue is not empty
    if len(processQueue) > 0 && isCPUIdle {
      // Add the process to the clock cycle array 
      clockCycle = append(clockCycle, ClockCycle{ 
        process: processQueue[0],
        time: currentCPUTime,
      })
      // If the process is not finished within the time slice
      if processQueue[0].burstTime > timeSlice {
        processQueue[0].burstTime -= timeSlice
        processQueue = append(processQueue, processQueue[0])
      }
      processQueue = processQueue[1:]
      isCPUIdle = false
      nextFreeTime = currentCPUTime + float64(timeSlice)
    }

    currentCPUTime++
  }

  // Print the clock cycle array
  w := tabwriter.NewWriter(os.Stdout, 0, 0, 1, ' ', tabwriter.Debug)
  fmt.Fprintln(w, "ID\tBurst Time\tArrival Time\tReal Arrival Time\tPriority\tTime")
  for _, clock := range clockCycle {
    fmt.Fprintf(w, "%d\t%d\t%d\t%.2f\t%d\t%.2f\n", clock.process.id, clock.process.burstTime, clock.process.arrivalTime, clock.time, clock.process.priority, clock.time)
  }
  w.Flush()

}

// Utils
func generateRandomProcess(numberOfProcesses int) (processes []Process, totalTime float64) {
  maxArrivalTime := 0
  for i := 0; i < numberOfProcesses; i++ {
    burstTime := rand.Intn(10)
    arrivalTime := rand.Intn(10)
    processes = append(processes, Process{
      id: i,
      burstTime: burstTime,
      arrivalTime: arrivalTime,
      priority: rand.Intn(10),
    })
    if arrivalTime > maxArrivalTime {
      maxArrivalTime = arrivalTime 
    }
    totalTime += float64(burstTime)
  }
  return processes, totalTime + float64(maxArrivalTime)
}

func enterProcessManually(numberOfProcesses int) (processes []Process, totalTime float64) {
  maxArrivalTime := 0
  for i := 0; i < numberOfProcesses; i++ {
    var process Process
    fmt.Println("Enter the burst time of the process ", i + 1, ": ")
    fmt.Scanln(&process.burstTime)
    fmt.Println("Enter the arrival time of the process ", i + 1, ": ")
    fmt.Scanln(&process.arrivalTime)
    fmt.Println("Enter the priority of the process ", i + 1, ": ")
    fmt.Scanln(&process.priority)
    process.id = i
    processes = append(processes, process)
    totalTime += float64(process.burstTime)
    if process.arrivalTime > maxArrivalTime {
      maxArrivalTime = process.arrivalTime
    }
  }
  return processes, totalTime + float64(maxArrivalTime)
}

func printProcesses(processes []Process, totalTime float64) {
  w := tabwriter.NewWriter(os.Stdout, 0, 0, 1, ' ', tabwriter.Debug)
  fmt.Fprintln(w, "ID\tBurst Time\tArrival Time\tPriority")
  for _, process := range processes {
    fmt.Fprintf(w, "%d\t%d\t%d\t%d\n", process.id, process.burstTime, process.arrivalTime, process.priority)
  }
  fmt.Fprintln(w, "Total Time\t", totalTime)
  w.Flush()
}

func main() {

  // Options
  var option int

  for {
    menu()
    fmt.Scanln(&option)
    switch option {
    case 1:
      shortestJobFirst()
    case 2:
      roundRobin()
    case 3:
      return
    default:
      fmt.Println("Invalid option")
    }
  }
}
