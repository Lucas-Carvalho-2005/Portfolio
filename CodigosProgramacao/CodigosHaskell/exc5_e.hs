type Pol = [(Float, Int)]

grauPolinomio :: Pol -> Int
grauPolinomio = maximum . map snd

main :: IO ()
main = do
    let pol1 = [(3.4, 3), (2.0, 4), (1.5, 3), (7.1, 5)]
    let grau = grauPolinomio pol1
    print grau