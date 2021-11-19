public class MyThreads extends Thread { // classe MyThreads herdando a classe "Thread" do Java
	
	public String name; // atributo nome da thread
    public int time; // atributo tempo de sleep da thread
    
    public MyThreads(String name, int time){ // construtor
        
    	this.name = name; 
        this.time = time;
        start(); // método que está dentro da classe Thread
        		 // serve para tornar a Thread pronta para ser executada
    }
    
    public void run(){ // método implementado para executar as threads instanciadas pela main (class Ex2)
        
    	int showTime = 0; // variável que mostra todos os tempos de execução de todas as threads
    	
        try {
            for (int i = 0; i <= 10; i++){ // loop para a execução de threads
            	
                System.out.println(this.name + "\t Tempo: " + showTime/1000 + "s\t"); // output do programa
                Thread.sleep(this.time); // tempo que o thread irá dormir
                showTime += this.time; // (somador) recebe o tempo de sleep da "Thread #n" + ela própria 
                
            } 
        } catch(Exception e) { // tratamento da exceção, caso ocorra alguma
            e.printStackTrace(); // print do tipo de exceção
        }
    }
}
