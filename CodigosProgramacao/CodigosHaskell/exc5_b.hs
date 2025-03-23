type Polinomio = [(Float, Int)] 

normalizaPolinomio :: Polinomio -> (Float, Polinomio)
normalizaPolinomio pol =
    if null pol then (1, [])
    else (coeficientePrincipal, [(c / coeficientePrincipal, g) | (c, g) <- pol])
  where
    coeficientePrincipal = maximum [c | (c, g) <- pol, g == grauMaximo]
    grauMaximo = maximum [g | (_, g) <- pol]

main :: IO ()
main = do
    let polinomio = [(5, 7), (-13, 2), (70, 0)]
    let (fator, normalizado) = normalizaPolinomio polinomio
    putStrLn $ show fator ++ " * " ++ show normalizado