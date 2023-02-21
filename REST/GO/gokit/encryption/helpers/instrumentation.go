package helpers

import (
	"context"
	"fmt"
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
		mw.RCount.With(lvs...).Add(1)
		mw.RLatency.With(lvs...).Observe(time.Since(begin).Seconds())
	}(time.Now())
	output, err = mw.Next.Encrypt(ctx, key, text)
	return
}

func (mw InstrumentationMiddleware) Decrypt(ctx context.Context, key string, text string) (output string, err error) {
	defer func(begin time.Time) {
		lvs := []string{"method", "encrypt", "error", fmt.Sprint(err != nil)}
		mw.RCount.With(lvs...).Add(1)
		mw.RLatency.With(lvs...).Observe(time.Since(begin).Seconds())
	}(time.Now())
	output, err = mw.Next.Decrypt(ctx, key, text)
	return
}
