type Pol = [(Float, Int)]

derivadaPolinomio :: Pol -> Pol
derivadaPolinomio pol = [(c * fromIntegral g, g - 1) | (c, g) <- pol, g > 0]

main :: IO ()
main = do
    let pol1 = [(3.5, 3), (2.0, 4), (1.5, 3), (7.1, 5)]
    let derivada = derivadaPolinomio pol1
    print derivada
