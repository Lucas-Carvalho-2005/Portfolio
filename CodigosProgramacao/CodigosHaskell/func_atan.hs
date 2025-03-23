main :: IO()
main = do
    let x = 0.5 :: Float
    let valor_atan = atan x
    putStr $ "Arco tangente de " ++ show x ++ " = " ++ show valor_atan
    putStr " rad"