package com.multithreading;

public class TokenBucketFilter {
    private int MAX_TOKENS;
    // variable to note down the latest token request.
    private long lastRequestTime = System.currentTimeMillis();
    long possibleTokens = 0;

    public TokenBucketFilter(int maxTokens) {
        MAX_TOKENS = maxTokens;
    }

    synchronized void getToken() throws InterruptedException {
        if(lastRequestTime < System.currentTimeMillis()-MAX_TOKENS*1000) {
            possibleTokens = MAX_TOKENS;
        } else {
            long newTokens = (System.currentTimeMillis() - lastRequestTime)/1000;
            possibleTokens = Math.min(possibleTokens + newTokens-1, MAX_TOKENS);
            if(possibleTokens <= 0) {
                possibleTokens = 0;
                Thread.sleep(1000);
            }
        }
        lastRequestTime = System.currentTimeMillis();
        System.out.println("Granting " + Thread.currentThread().getName() + " token at " + (System.currentTimeMillis() / 1000));

    }
}
