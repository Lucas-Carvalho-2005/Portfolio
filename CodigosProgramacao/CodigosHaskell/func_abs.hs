main :: IO()
main = do
    let x = -5
    let valor_abs = abs x
    putStrLn $ "Valor absoluto de " ++ show x ++ ": " ++ show valor_abs