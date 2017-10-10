package com.bartek.ccr.common.monad;

import com.bartek.ccr.common.functional.CheckedCallable;
import com.bartek.ccr.common.functional.CheckedRunnable;

import java.util.function.Function;

public class Try <T> {
    private CheckedCallable<T> callable;

    private Try(CheckedCallable<T> callable) {
        this.callable = callable;
    }

    public static <T> Try<T> of(CheckedCallable<T> callable) {
        return new Try<>(callable);
    }

    public static Try<Void> run(CheckedRunnable runnable) {
        return new Try<>(() -> {
            runnable.run();
            return null;
        });
    }

    public <E extends Throwable> T getOrElseThrow(Function<? super Throwable, E> exceptionSupplier) throws E {
        try {
            return callable.call();
        } catch (Throwable throwable) {
            throw exceptionSupplier.apply(throwable);
        }
    }

    public Try andThenTry(CheckedCallable<T> callable) {
        return Try.of(callable);
    }

    public Try andThenTry(CheckedRunnable runnable) {
        return Try.run(runnable);
    }
}