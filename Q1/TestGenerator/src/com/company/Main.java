package com.company;
import javafx.util.Pair;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.net.Inet4Address;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

class Airport {
    public String name;
    public String code;
    public double x;
    public double y;

    public Airport (String name, String code, double x, double y) {
        this.name = name;
        this.code = code;
        this.x = x;
        this.y = y;
    }

    @Override
    public String toString() {
        return name + "\n" + code + "\n" + x + " " + y;
    }
}

public class Main {

    public static void main(String[] args) {
        ArrayList<Airport> airports = new ArrayList<>();
        try {
            File myObj = new File("Out_1.txt");
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                String data = myReader.nextLine();
                String[] splited = data.split("\\s+");
                String name = new String();
                for (int i = 3; i < splited.length; ++i) {
                    name += splited[i] + " ";
                }
                airports.add(new Airport(name, splited[0], Double.parseDouble(splited[1]), Double.parseDouble(splited[2])));
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }

        try {
            for (int i = 0; i < 40; ++i) {
                String inputsDirectoryPath = "C:\\Users\\asus\\Desktop\\projects\\Discrete Math final project template\\Q1\\TestGenerator\\inputs\\";
                FileWriter myWriter = new FileWriter(inputsDirectoryPath + "In_" + (i + 1) + ".txt");

                //generate airports number
                int airportsNumber = (int)(Math.random() * 10) + i;
                myWriter.write(airportsNumber + " ");
                System.out.println(airportsNumber);

                //generate edges number
                int edgesNumber = (int)(Math.random() * (airportsNumber * (airportsNumber - 1) / 2));
                myWriter.write(edgesNumber + "\n");
                System.out.println(edgesNumber);

                //find random airports
                boolean[] mark = new boolean[airports.size()];
                ArrayList<Airport> airports1 = new ArrayList<>();
                while (airportsNumber > 0) {
                    int temp = (int)(Math.random() * airports.size());
                    if (!mark[temp]) {
                        mark[temp] = true;
                        airports1.add(airports.get(temp));
                        airportsNumber--;
                    }
                }
                airportsNumber = airports1.size();

                //print airports name
                for (Airport airport : airports1) {
                    myWriter.write(airport.code + " " + airport.name + "\n");
                    System.out.println(airport.code + " " + airport.name);
                }




                //generate edges
                ArrayList<Pair<Integer, Integer>> edges = new ArrayList<>();
                while (edgesNumber > 0) {
                    Pair<Integer, Integer> temp = new Pair<Integer, Integer>((int)(Math.random() * airportsNumber), (int)(Math.random() * airportsNumber));
                    System.out.println(temp.getKey() + " " + temp.getValue());
                    if (temp.getKey() != temp.getValue() && !edges.contains(temp) &&
                            !edges.contains(new Pair<Integer, Integer>(temp.getValue(), temp.getValue()))) {
                        edges.add(temp);
                        edgesNumber--;
                    }
                }

                //print edges
                for (Pair<Integer, Integer> edge : edges) {
                    myWriter.write(airports1.get(edge.getKey()).code + " " + airports1.get(edge.getValue()).code + '\n');
                    System.out.println(airports1.get(edge.getKey()).code + " " + airports1.get(edge.getValue()).code);
                }
                myWriter.close();
                System.out.println(i + " done!");
            }
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }
}
