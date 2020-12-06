# FinalProject_Caulk
Repo for Caleb Caulk's final project  
  
Phase #1 (Description)  

The basic idea is to take all the ski resorts in the state of Colorado and data initially obtained from OpenSnow.com to determine which resorts will get the most snow from a storm in inches and store that data in a maxHeap. There will also be a graph to represent the highway system and resorts and distances from each other and starting points Boulder and Denver. Then there an algorithm that will calculate which resort would be the best one to visit based off of snow accumulation and distance from a starting point and other factors such as percentage open and current snow.
  
This final project will implement min and max Heaps and a Graph. This program will include a Class that represents a resort which will store data like base depth, capacity, crowded(how crowded the resort is), predicted snow, and name. Snow total data from OpenSnow.com will be put in a csv file formated ("resort name, snow prediction total in inches"). The program will make several Heaps, min and max, all based on different data. For example one max heap will be for predicted snow, another max heap for most snow currently, and another min heap for distance from location x. The program will also make a graph from the resort ojects based on distances on the major highways in Colorado and distances in miles. The Graph class will need to read distances and resorts from a seperate csv file so the Graph will be implemented seperate from the resort class and will not contain objects of the resort class instead it will have structs of resorts and edges(distances). The max and min heaps will be implemented seperate from the resort class as well but will consist of objects of the resort classs. 
  
Some functions that will implemented will be an algorithm that will calculate the best place to ski in Colorado based on current condidtions or future conditions this will be done in the main. This will also take into account pass type. Another function will be to show resorts within x miles of a pregiven location. Another function would be to find the resort with the most green, blue, or black runs. There will be at least four files to compile which will be final.cpp, resort.cpp, heap.cpp, graph.cpp. To run the program use g++ -std=c++11 final.cpp resort.cpp heap.cpp graph.cpp and will take in command line arguments for snow predictions and map ex) ./final snowpredictions.csv mapofColorado.csv All of the code will be in the code folder.
  
Future implementation (this is to expand on the project and not necessarily be implemented by 12/7/2020)  
If time allows there can be several future capabilities to this program that could be implemented. The first one would be to gather real time data from certain websites that have models to predict snow. This would involve a webscraper. Some models could be the Univeristy of Utah Models or European or American models. This would be something to expand the final project on. Another capability would be to use several models and data to determine the best palce to ski. This would involve another Class such as a Model class that holds all the resorts will all snow predictions from that model from the web and holds different max and min heaps because the data would be different. Then there would need to be a vector or array of several models that all show different best resorts to ski at based on serveral models instead of one. This would expand the project from only getting data from OpenSnow.com to getting data from several models. Then there could be another algorithm to then determine the best palce to ski based on multiple models.  
  
Phase #2 (Implementation)  
  
Project Summary-  
  This Project is to help some decide where to ski or snowboard. Based on information in the csv files (the only one you should modify is the SnowPredictions.csv and only modify the numbers). The program will first get all the resorts from Resorts.csv (don't touch) and make a Graph based on the highway system from MapOfColorado.csv (also don't touch). Then using that data and SnowPRedictions.csv data there are many heaps that are created each based on a different aspect. You can choose a starting point such as Denver or Boulder or a ski resort and the program will give you suggestions of where to ski for the best time

  How to run-  
  To run type:  
  g++ final.cpp Graph.cpp Heap.cpp Resort.cpp -o final  
  ./final Resorts.csv MapOfColorado.csv SnowPredictions.csv  
  This should run the program add the -std=c++11 if necessary.
  You can and should modify the numbers in the SnowPredictions.csv file to get different results the numbers in this file represent the predicted snow in inches at each resort  
  Options:  
  For all options the heap will not re push resorts back so once a resort is read it will not reappear. The only exception is 4,5,7,8 which can be reset with option 9 because it is dependent on a start location X  
  1-3 self-explanatory returns what it says it will  
  4 Will return the first closest resort to the location X which is user provided use once then use 5 to get the second and third and so on closets resorts to X until 9 is hit  
  5 Will return the next closest resort from X and is an extension of 4 (type 4,5,5, . . . not 4,4,5 . . . )
  -To reset the destition X hit 9  
  6- Will return the best resort based on a calculation in Resort.cpp and shows the score  
  7- Will return the best resort (based on a calculation in Resort.cpp) that is based around a starting location X hit 7 once then 8 to get the second and third and so one best resorts from X until 9 is hit which will reset the location  
  8- Will return the second and third and so on best resorts to ski at based on the location X choosen in 7 is an extension of 7  
  9-Will reset the destition and destition heaps so you can change the destitions is 4 and 7. You must hit this before hitting 4 or 7 again to get correct results  
  10-quit  

  Dependencies-  
  all files are in the code folder and should not require anything else

  System Requirements-  
  Should work on all systems

  Team members-  
  Caleb Caulk

  Contributors-  
  Caleb Caulk

  Open issues/ bugs-  
  The options 7 and 8 give a score that is to low

