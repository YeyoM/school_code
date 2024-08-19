package main

import (
  "fmt"
  "math"
  "math/rand"
  "time"

  // plots 
  "gonum.org/v1/plot"
	"gonum.org/v1/plot/plotter"
	"gonum.org/v1/plot/vg"
  "image/color"
)

// Function f(x) = 2x^2 * cos(x) - 5x
func f(x float64) float64 {
  return 2*math.Pow(x, 2)*math.Cos(x) - 5*x
}

// Derivative f'(x) = 4x * cos(x) - 2x^2 * sin(x) - 5
func fPrime(x float64) float64 {
  return 4*x*math.Cos(x) - 2*math.Pow(x, 2)*math.Sin(x) - 5
}

// Gradient descent implementation
func gradientDescent(eta float64, iterations int) float64 {
  // Initialize x randomly
  // Initialize x randomly within the interval [-5, 5]
  rand.Seed(time.Now().UnixNano())
  x := -5 + rand.Float64()*(5-(-5))

  // storing all the values of x, so in case the optimization is not converging or it stuck in local minima
  var xValues []float64

  for i := 0; i < iterations; i++ {
    grad := fPrime(x)       // Compute the gradient at x
    x = x - eta * grad      // Update x
    fmt.Printf("Iteration %d: x = %.6f, f(x) = %.6f\n", i, x, f(x))
    xValues = append(xValues, x)

    if i > 5 {
      // Check if the optimization is converging
      if math.Abs(xValues[i] - xValues[i-5]) < 0.000001 {
        fmt.Println("Optimization converged")
        break
      }
    }
  }

  return x
}

func plotFunction(xValues []float64) {
  // CHANGE NAME TO p
  p := plot.New()

  p.Title.Text = "Gradient Descent"
  p.X.Label.Text = "X"
  p.Y.Label.Text = "Y"
  
  // Plot the function f(x) = 2x^2 * cos(x) - 5x
  fPlotter := plotter.NewFunction(func(x float64) float64 { return 2*math.Pow(x, 2)*math.Cos(x) - 5*x })
  fPlotter.Color = color.RGBA{B: 255, A: 255}

  // Plot the gradient descent path using xValues
  pts := make(plotter.XYs, len(xValues))
  for i, x := range xValues {
    pts[i].X = x
    pts[i].Y = f(x)
  }

  line, points, err := plotter.NewLinePoints(pts)
  if err != nil {
    panic(err)
  }

  line.Color = color.RGBA{R: 255, A: 255}
  points.Color = color.RGBA{R: 255, A: 255}

  p.Add(line, points, fPlotter)

  p.Legend.Add("f(x) = 2x^2 * cos(x) - 5x", fPlotter)
  p.Legend.Add("Gradient Descent", line, points)

  p.X.Min = -5
  p.X.Max = 5
  p.Y.Min = -50
  p.Y.Max = 50

  if err := p.Save(4*vg.Inch, 4*vg.Inch, "gradient_descent.png"); err != nil {
    panic(err)
  }

  fmt.Println("Plot saved to gradient_descent.png")
}

func main() {
  learningRate := 0.01   // Eta
  iterations := 1000     // Number of iterations

  // Run gradient descent
  minimum := gradientDescent(learningRate, iterations)
  fmt.Printf("Found minimum at x = %.6f, f(x) = %.6f\n", minimum, f(minimum))

  // Plot the function and the gradient descent path 
  plotFunction([]float64{minimum})
}

