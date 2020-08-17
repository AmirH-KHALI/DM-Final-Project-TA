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

class DisjointUnionSets {
    int[] rank, parent;
    int n;
    int setsNum;

    public DisjointUnionSets(int n)
    {
        rank = new int[n];
        parent = new int[n];
        this.n = n;
        setsNum = n;
        makeSet();
    }

    public boolean isConnect () {
        if (setsNum == 1) {
            return true;
        }
        return false;
    }

    void makeSet()
    {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x) {

            parent[x] = find(parent[x]);

        }

        return parent[x];
    }

    void union(int x, int y)
    {
        int xRoot = find(x), yRoot = find(y);

        if (xRoot == yRoot)
            return;

        setsNum--;

        if (rank[xRoot] < rank[yRoot])

            parent[xRoot] = yRoot;

        else if (rank[yRoot] < rank[xRoot])

            parent[yRoot] = xRoot;

        else
        {
            parent[yRoot] = xRoot;

            rank[xRoot] = rank[xRoot] + 1;
        }
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
            for (int i = 0; i < 45; ++i) {
                String inputsDirectoryPath = "C:\\Users\\asus\\Desktop\\projects\\Discrete Math final project template\\Q3\\TestGenerator\\inputs\\";
                FileWriter myWriter = new FileWriter(inputsDirectoryPath + "In_" + (i + 1) + ".txt");


                //generate airports number
                int airportsNumber = (int)(Math.random() * 10) + (i * 2);
                myWriter.write(airportsNumber + " ");
                System.out.println(airportsNumber);

                //create Disjoint set
                DisjointUnionSets disjointUnionSets = new DisjointUnionSets(airportsNumber);


                System.out.println("hi");
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


                //generate edges number
                int edgesNumber = 0;


                //generate edges
                ArrayList<Pair<Integer, Integer>> edges = new ArrayList<>();
                ArrayList<Double> edgesVal = new ArrayList<>();
                while (!disjointUnionSets.isConnect()) {
                    Pair<Integer, Integer> temp = new Pair<Integer, Integer>((int)(Math.random() * airportsNumber), (int)(Math.random() * airportsNumber));
                    System.out.println(temp.getKey() + " " + temp.getValue());
                    if (temp.getKey() != temp.getValue() && !edges.contains(temp) &&
                            !edges.contains(new Pair<Integer, Integer>(temp.getValue(), temp.getValue()))) {
                        double edgeValue = (int)(Math.random() * 10) + (Math.max(getDist(airports1, temp.getValue(), temp.getKey()) - 5, 0));
                        edges.add(temp);
                        edgesVal.add(edgeValue);
                        disjointUnionSets.union(temp.getKey(), temp.getValue());
                        edgesNumber++;
                    }
                }

                //print edgesNum
                myWriter.write(edgesNumber + "\n");
                System.out.println(edgesNumber);



                //print airports name
                for (Airport airport : airports1) {
                    myWriter.write(airport.code + " " + airport.name + "\n");
                    System.out.println(airport.code + " " + airport.name);
                }

                //print edges
                for (int j = 0; j < edges.size(); ++j) {
                    Pair<Integer, Integer> edge = edges.get(j);
                    myWriter.write(airports1.get(edge.getKey()).code + " " + airports1.get(edge.getValue()).code + " " + String.format("%.2f", edgesVal.get(j)) + '\n');
                    System.out.println(airports1.get(edge.getKey()).code + " " + airports1.get(edge.getValue()).code + " " + String.format("%.2f", edgesVal.get(j)));
                }

                //print startNode
                Airport startNode = airports1.get((int)(Math.random() * airportsNumber));
                myWriter.write(startNode.code + "\n");

                //print endNode
                Airport endNode = airports1.get((int)(Math.random() * airportsNumber));
                while (endNode == startNode)
                    endNode = airports1.get((int)(Math.random() * airportsNumber));
                myWriter.write(endNode.code + "\n");

                myWriter.close();
                System.out.println(i + " done!");
            }
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    private static double getDist(ArrayList<Airport> airports1, Integer i, Integer j) {
        double deltaX = airports1.get(i).x - airports1.get(j).x;
        double deltaY = airports1.get(i).y - airports1.get(j).y;
        return Math.sqrt(deltaX * deltaX + deltaY * deltaY);
    }
}
