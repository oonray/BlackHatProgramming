package helpers

import (
	"context"
	"fmt"
	log "github.com/go-kit/kit/log"
	met "github.com/go-kit/kit/metrics"
	"time"
)

type InstrumentationMiddleware struct {
	RCount   met.Counter
	RLatency met.Histogram
	Next     EncryptService
}

func (mw InstrumentationMiddleware) Encrypt(ctx context.Context, key string, text string) (output string, err error) {
	defer func(begin time.Time) {
		lvs := []string{"method", "encrypt", "error", fmt.Sprint(err != nil)}
		mw.RCount.Wiht(lvs...).Observer(time.Since(begin).Seconds())
	}(time.Now())
}

func (mw InstrumentationMiddleware) Decrypt(ctx context.Context, key string, text string) (output string, err error) {
}
