main :: IO()
main = do
    let x = 3.4
    let valor_floor = floor x
    putStr $ "O maior inteiro menor ou igual a " ++ show x
    putStr $ " é " ++ show valor_floor