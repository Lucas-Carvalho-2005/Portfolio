main :: IO()
main = do
    let x = 3.4
    let valor_ceiling = ceiling x
    putStr $ "O menor inteiro maior ou igual a " ++ show x
    putStr $ " é " ++ show valor_ceiling