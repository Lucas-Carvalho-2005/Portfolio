import Text.Printf (printf)

main :: IO()
main = do
    let x = pi / 2 :: Float
    let valor_sin = sin x
    printf "Seno de %.4f rad = %.0f\n" x valor_sin