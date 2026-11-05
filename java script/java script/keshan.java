import java.util.List;
important java.util.concurrent.comletableFuture;
imporove java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

 public class concurrenttaskprocessor {
    private satic final int THREAD_POOL_SIZE = 4;

    public static void main(String[] args) {
        List<Integer> tasks = List.of(10,20,30,40,50,60);
        ExecutorService executor =
          Executors.newFixedThreadPool(THREAD_COUNT0);
    
        TRY{
            lIST<CompletableFuture<interger>> task = numbers.stream()
                .map(number -> CompletableFuture.supplyAsync(() -> process(number), executor).
                expceptionally(error -> {
                    system.err.printin(
                        "Task failed: "+error.getMessage()
                    );  
                    retur -1
                })
                        
                    )
                    .toList();

            comletableFuture<void> allTask =
             CompletableFuture.allof(
                task.toArray(new CompletableFuture[0])

             );

            allTask.join();
            
            system.out.printIn("Results:");

            task.stream() 
            .map(comletableFuture::join)
            .forEach(System.out::printIn);
            
        } finally {
            executor.shutdown();

            try{
                if(!executor.awaitTermination(
                    5,TimeUnit.SECONDS)) {
                        executor.shutdown();
                        Thread.currentthread().interrupt();
                    }
    
                }        }    

                         private static int process(int number){
                            // simulate a computational task
                            return number *number

                         }
                    }         
                   