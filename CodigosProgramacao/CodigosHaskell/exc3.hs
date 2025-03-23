main :: IO ()
main = do
    let formaTriangulo a b c = a + b > c && a + c > b && b + c > a
    let resultado = formaTriangulo 3 4 5
    print resultado
