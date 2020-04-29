using Newtonsoft.Json;
using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Xml;
using System.Xml.Linq;
using System.Xml.Serialization;

namespace Lufthansa
{
    class Program
    {

        static void Main(string[] args)
        {
            //List<Airport> airports = GetAirports();
            //List<City> cities = GetCities();
        }

        //    private static List<City> GetCities()
        //    {
        //        XmlDocument doc = new XmlDocument();
        //        //Change it
        //        doc.Load("C:\\Users\\Sohrab\\Desktop\\Lufthansa\\Lufthansa\\Resources\\City.xml");
        //        List<City> cities = new List<City>();
        //        XmlNode idNodes = doc.SelectSingleNode("CityResource/Cities");
        //        foreach (XmlNode node in idNodes.ChildNodes)
        //        {
        //            City city = ConvertNode<City>(node);
        //            cities.Add(city);
        //        }
        //        return cities;
        //    }

        //    private static List<Airport> GetAirports()
        //    {
        //        XmlDocument doc = new XmlDocument();
        //        //Change it
        //        doc.Load("C:\\Users\\Sohrab\\Desktop\\Lufthansa\\Lufthansa\\Resources\\Airports.xml");
        //        List<Airport> airports = new List<Airport>();
        //        XmlNode idNodes = doc.SelectSingleNode("AirportResource/Airports");
        //        foreach (XmlNode node1 in idNodes.ChildNodes)
        //        {
        //            Airport airport = ConvertNode<Airport>(node1);
        //            airports.Add(airport);
        //        }

        //        return airports;
        //    }

        //    private static T ConvertNode<T>(XmlNode node) where T : class
        //    {
        //        MemoryStream stm = new MemoryStream();

        //        StreamWriter stw = new StreamWriter(stm);
        //        stw.Write(node.OuterXml);
        //        stw.Flush();

        //        stm.Position = 0;

        //        XmlSerializer ser = new XmlSerializer(typeof(T));
        //        T result = (ser.Deserialize(stm) as T);

        //        return result;
        //    }
    }
}
