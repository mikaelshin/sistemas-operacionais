// MIKAEL SHIN, 10843441

public class EP3 {
	
	public static void main(String[] args) {
    
        MyThread[] thread = new MyThread[2];
    
        for(int i = 0; i <= 1; i++){
            
            thread[i] = new MyThread("T" + i);
        }
	}
}
