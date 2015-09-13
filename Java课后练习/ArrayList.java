/*2、自己实现ArrayList<String>类，命名为MyArrayList，注意你的实现应主要使用数组及对数组的操作，不要直接调用ArrayList的接口方法。在此基础上，实现一个用于效率比较的程序，比较MyArrayList的主要方法与ArrayList的相应方法的运行效率。*/


    public MyArraylist() {  
        values = (E[]) new Object[capacity];  
    }  
  
    public MyArraylist(int capacity) {  
        this.capacity = capacity;  
        values = (E[]) new Object[this.capacity];  
    }  
  
    public void put(E e) {  
        if (e == null) {  
            throw new RuntimeException("The value should not be null.");  
        }  
        if (size >= capacity) {  
            enlargeCapacity();  
        }  
        values[size] = e;  
        size++;  
    }  
  
    public E get(int index) {  
        if (index >= size) {  
            throw new RuntimeException("The index:" + index + " is out of band.");  
        }  
        return values[index];  
    }  
  
    public void remove(int index) {  
        if (index >= size) {  
            throw new RuntimeException("The index:" + index + " is out of band.");  
        }  
        for (int i = index; i < size - 1; i++) {  
            values[i] = values[i + 1];  
        }  
        values[size - 1] = null;  
        size--;  
    }  
  
    private void enlargeCapacity() {  
        capacity = capacity * 2;  
        E[] tmpValues = (E[]) new Object[capacity];  
        System.arraycopy(values, 0, tmpValues, 0, size);  
        values = tmpValues;  
    }  
  
    public String toString() {  
        StringBuilder sb = new StringBuilder();  
        sb.append("[");  
        for (int i = 0; i < size; i++) {  
            sb.append(values[i]).append(",");  
        }  
        if (size > 0) {  
            sb.deleteCharAt(sb.length() - 1);  
        }  
        sb.append("]");  
        return sb.toString();  
    }  
  
    public static void main(String[] args) {  
        MyArraylist<String> myList = new MyArraylist<String>();  
        myList.put("1");  
        myList.put("2");  
        myList.put("3");  
        myList.put("4");  
        myList.put("5");  
        myList.put("6");  
        myList.put("7");  
        myList.put("8");  
        myList.put("9");  
        myList.remove(7);  
        System.out.println(myList.toString());  
    }  
  
}  