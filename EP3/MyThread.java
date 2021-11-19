import java.util.concurrent.Semaphore;

public class MyThread extends Thread { 
    
	public static int loop = 1000000000; 
	public static Semaphore mutex = new Semaphore(1);
	public String name; // atributo nome da thread

    public MyThread(String name){ 
        
    	this.name = name; 
    	start();
    }
    
    public void run(){
       
        System.out.println(this.name + " chegou no run().");
        
        try {
            while(true){
                while(mutex.availablePermits() == 0){
                    Thread.sleep(1);
                }
                if(mutex.availablePermits() == 1){
                    mutex.acquire();
                    secaoCritica();
                }
                secaoNaoCritica();
                Thread.sleep(1000);
            }
	    } catch(Exception e) {
	        
	    }
    }
    
    public void secaoCritica(){
        
        System.out.println(this.name + ": ENTRANDO na Seção Crítica...");
	    
	    try {
	        
    	    System.out.println("Semáforo: " + mutex.availablePermits());
    	    for (int i = 0; i < loop; i++){
    	        i = i;
    	    }
    	    System.out.println(this.name + ": SAINDO da Seção Crítica...");
    	    mutex.release();
    	    System.out.println("Semáforo: " + mutex.availablePermits()); 
	    } catch(Exception e) {
	        
	    }
    }
    
    public void secaoNaoCritica(){
        
        for (int i = 0; i < loop; i++)
	        i = i;
	    System.out.println("--------------------------------------");
    }
}
