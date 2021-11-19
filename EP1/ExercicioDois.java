public class Main {

	public static void main(String[] args) { 

		for(int i = 1; i <= 20; i++){ // loop para instânciar as threads

			String[] name = new String[21]; // alocando 21 posições para o nome [0] - [20] 
			int[] time = new int[21]; // alocando 21 posições para o tempo de sleep [0] - [20] 

			name[i] = "Thread# " + i; // atribuindo nome à thread (Thread #n, sendo n o número do contador)
			time[i] = 1000 * i; // atribuindo tempo de sleep para a thread (para Thread #3, o tempo será de 1s * 3)
			
			if(i <= 10 || i == 20) { // instanciando a Thread #1 à #10 e pulando direto para a Thread #20.
				
				MyThreads[] thread = new MyThreads[21]; // declarando o obj. thread
				thread[i] = new MyThreads(name[i], time[i]); // instanciando o obj. passando os parâmetros esperados
			}
		}

	}

}