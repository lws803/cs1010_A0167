long long maxSum = players[0].value;
    long long sum = maxSum;
    int maxLeft = 0;
    int maxRight = 0;
    int left = 0;
    int right = 1;
    long long currentMin;
    while (right < playerNumber) {

        currentMin = (long long)players[left].value + (long long)players[left+1].value;
        
        while (currentMin < players[right].value) {
                left++;
                currentMin = players[left].value + players[left + 1].value;
                sum -= players[left-1].value;
                
        }
        sum += players[right].value;
        if (sum > maxSum) {
            maxSum = sum;
            maxLeft = left;
            maxRight = right;
        }
        right++;
    }