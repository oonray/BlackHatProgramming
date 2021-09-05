package main

import (
	"github.com/sirupsen/logrus"
	"html/template"
	"os"
)

var x = `
<html>
	<body>
		Hello {{.}}
	</body>
</html>
`

func main() {
	t, err := template.New("hello").Parse(x)
	if err != nil {
		logrus.Errorf("Could not parse template")
		return
	}

	t.Execute(os.Stdout, "<script>alert('world')</script>")
}
