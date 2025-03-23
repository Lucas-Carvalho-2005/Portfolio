type Pol = [(Float, Int)]

calculaValor :: Pol -> Float -> Float
calculaValor pol x = sum [c * x^g | (c, g) <- pol]

main :: IO ()
main = do
    let pol1 = [(3.4, 3), (2.0, 4), (1.5, 3), (7.1, 5)]
    let valor = calculaValor pol1 2
    print valor