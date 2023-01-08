package main

import (
	"crypto/sha256"
	"fmt"
	"math"
)

func reverseByteSlice(s []byte) {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
}

func main() {
	c1 := sha256.Sum256([]byte("x"))
	c2 := sha256.Sum256([]byte("X"))
	fmt.Printf("c1(hex) = %x\nc2(hex) = %x\n", c1, c2)
	fmt.Printf("c1 = %v\nc2 = %v\n", c1, c2)
	var bin1, bin2 []byte
	// 转为二进制作为 []byte存储
	for i := range c1 {
		tmp1 := c1[i]
		tmp2 := c2[i]
		for tmp1 != 0 {
			bin1 = append(bin1, tmp1&1)
			tmp1 >>= 1
		}
		for tmp2 != 0 {
			bin2 = append(bin2, tmp2&1)
			tmp2 >>= 1
		}
	}
	reverseByteSlice(bin1[:])
	reverseByteSlice(bin2[:])
	fmt.Printf("bin1 = %v\nbin2 = %v\n", bin1, bin2)
	cnt := int(math.Abs(float64(len(bin1) - len(bin2))))
	size := int(math.Min(float64(len(bin1)), float64(len(bin2))))
	for i := 0; i < size; i++ {
		if bin1[i] != bin2[i] {
			cnt++
		}
	}
	fmt.Printf("c1 和 c2 中不同 bit 的数目为：%v", cnt)
}
