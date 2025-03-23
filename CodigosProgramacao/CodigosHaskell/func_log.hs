main :: IO()
main = do
    let x = 1
    let valor_log = log x
    putStrLn $ "Logaritmo natural de " ++ show x ++ " = " ++ show valor_log