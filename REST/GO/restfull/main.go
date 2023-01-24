p:wqaackage main

import (
	"fmt"
	"io"
	"net/http"
	"time"

	restfull "github.com/emicklei/go-restful"
	log "github.com/sirupsen/logrus"
)

func pingTime(req *restfull.Request, rsp *restfull.Response) {
	io.WriteString(rsp, fmt.Sprintf("%s", time.Now()))
}

func main() {

	webservice := new(restfull.WebService)
	webservice.Route(webservice.GET("/ping").To(pingTime))

	restfull.Add(webservice)
	log.Infof("Listening on %s", ":8000")
	http.ListenAndServe(":8000", nil)
}
