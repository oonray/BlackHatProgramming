package numGenerator

func generator() func() int {
	var i = 0
	return func() int {
		i++
		return i
	}
}
