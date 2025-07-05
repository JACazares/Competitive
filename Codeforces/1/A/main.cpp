readNumbers :: String -> [Int]
readNumbers = map read . words

main = do
    input <- getLine
    let x = readNumbers input
        a = (x !! 2)
        n = (x !! 0)
        m = (x !! 1)
        n0 = ceiling (fromIntegral n / fromIntegral a)
        m0 = ceiling (fromIntegral m / fromIntegral a)
    print (n0 * m0)
