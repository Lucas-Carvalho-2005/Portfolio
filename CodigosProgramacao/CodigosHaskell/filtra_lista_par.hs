main :: IO ()
main = do
    let filtraPares xs = [x | x <- xs, even x]
    print (filtraPares [2,3,4,5])