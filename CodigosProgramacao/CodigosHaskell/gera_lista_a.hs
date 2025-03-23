main :: IO ()
main = do
    let s = [2*n + 1 | n <- [10..40]]
    putStr $ "S = " ++ show s