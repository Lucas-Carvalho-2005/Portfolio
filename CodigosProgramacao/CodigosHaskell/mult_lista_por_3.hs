main :: IO ()
main = do
    let multPor3 xs = [x * 3 | x <- xs]
    print (multPor3 [2,3,4,5])