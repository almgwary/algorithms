import java.util.ArrayList;
import java.util.Random;

/**
 * Oct 28, 2015 10:29:55 PM
 * RouletWheel
 * @author Almgwary
 * 
 */
public class RouletteWheel {

	private  ArrayList<Double> fittness ; 
	private  ArrayList<Double> fittnessPopulation ;
	private  ArrayList<Double> wheelProbiblty ;
	private  ArrayList<Integer> selection ;
	int totalPopulationSize ;
	int size ;
    
	
	public RouletteWheel() {
		
	}

	public ArrayList<Integer> run (ArrayList<Double> fittness){
		//initilazation
		this.fittness = new ArrayList<Double>();
		selection= new ArrayList<Integer>();
		fittnessPopulation = new ArrayList<Double>();
		wheelProbiblty = new ArrayList<Double>();
		totalPopulationSize= 0 ;
		this.size =0;
		//initial values
		this.fittness = fittness ;
		this.size = fittness.size();
		//RouletteWheel Algorithm
		calculateTotalsize();
		calculateFittnessPropablity();
		calculateWheelProbalbity(); 
		calculateSellection();
		
		System.out.println(selection);
		return selection;
	}
	
	private void calculateTotalsize (){
		for(int i =0 ; i <size;++i){
			totalPopulationSize +=fittness.get(i);
		}
	}
	
	private void calculateFittnessPropablity (){
		for(int i=0; i<size;++i){
			fittnessPopulation.add((double) (fittness.get(i)/totalPopulationSize));
		}
	}

	private void calculateWheelProbalbity(){
 		wheelProbiblty.add(fittnessPopulation.get(0));
		for(int i=1;i<size;++i){
			wheelProbiblty.add(fittnessPopulation.get(i)+wheelProbiblty.get(i-1));
		}
	}

	private void calculateSellection (){
		Random random = new Random ();
		for(int i = 0; i<size ;++i){
			double r = Math.random();//random.nextDouble()%100;
			//System.out.println("-------------------"+r);
			for(int j= 1; j<size ;++j){
				if(wheelProbiblty.get(j)>r){
					selection.add(j-1);
					break ;
				}
				else if(j == size-1){
					selection.add(j);
				}
			}
		}
	}
}
