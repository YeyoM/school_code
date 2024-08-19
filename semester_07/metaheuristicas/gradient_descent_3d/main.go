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

// Function f(x, y) = x^2 + 3y
func f(x float64, y float64) float64 {
  return math.Pow(x, 2) + 3*y
}

// Partial derivative of f(x, y) with respect to x
// f'(x) = 2x
func fPrimeX(x float64) float64 {
  return 2*x
}

// Partial derivative of f(x, y) with respect to y
// f'(y) = 3
func fPrimeY() float64 {
  return 3
}

// Gradient descent (3d) implementation
func gradientDescent(eta float64, iterations int) (float64, float64) {
  // Initialize x and y randomly
  // Initialize x and y randomly within the interval [-10, 10]
  rand.Seed(time.Now().UnixNano())
  x := -10 + rand.Float64()*(10-(-10))
  y := -10 + rand.Float64()*(10-(-10))
  z := f(x, y)

  // storing all the values of x, so in case the optimization is not converging or it stuck in local minima
  var xValues []float64
  var yValues []float64
  var zValues []float64

  for i := 0; i < iterations; i++ {
    gradx := fPrimeX(x)      // Compute gradient of x
    grady := fPrimeY()       // Compute gradient of y

    x = x - eta * gradx      // Update x
    y = y - eta * grady      // Update y
    z = f(x, y)              // Update z

    fmt.Printf("Iteration %d: x = %.6f, y = %.6f, f(x, y) = %.6f\n", i, x, y, z)

    xValues = append(xValues, x)
    yValues = append(yValues, y)
    zValues = append(zValues, z)

    if i > 5 {
      // Check if the optimization is converging
      if math.Abs(xValues[i] - xValues[i-5]) < 0.000001 && math.Abs(yValues[i] - yValues[i-5]) < 0.000001 {
        fmt.Println("Optimization converged")
        break
      }
    }
  }

  return x, y
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
    pts[i].Y = f(x, 0)
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
  minimumx, minimumy := gradientDescent(learningRate, iterations)
  fmt.Printf("Found minimum at x = %.6f, y = %.6f, f(x) = %.6f\n", minimumx, minimumy, f(minimumx, minimumy))

  // Plot the function and the gradient descent path 
  plotFunction([]float64{minimumx})
}

