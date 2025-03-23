main :: IO()
main = do
    let somaDoisPrimeiros (x:y:_) = x + y
    print (somaDoisPrimeiros [5,3,2,4])