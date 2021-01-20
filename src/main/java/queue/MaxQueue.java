package queue;

import java.util.LinkedList;

public class MaxQueue {
    private LinkedList<Integer> list;
    private int maxValue;

    public MaxQueue() {
        list = new LinkedList();
        maxValue = -1;
    }

    public int max_value() {
        if (list.isEmpty())
            return -1;
        if (maxValue != -1)
            return maxValue;
        for (Integer integer : list) {
            if (maxValue < integer)
                maxValue = integer;
        }
        return maxValue;
    }

    public void push_back(int value) {
        list.add(value);
        if (maxValue != -1 && value > maxValue)
            maxValue = value;
    }

    public int pop_front() {
        Integer peek = list.peek();
        if (peek == null)
            return -1;
        if (peek == maxValue)
            maxValue = -1;
        return list.pop();
    }
}
