
// NOTE: Generated code may require at least .NET Framework 4.5 or .NET Core/Standard 2.0.
/// <remarks/>
[System.SerializableAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
[System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = false)]
public class Airport
{

    private string airportCodeField;

    private AirportPosition positionField;

    private string cityCodeField;

    private string countryCodeField;

    private string locationTypeField;

    private AirportName[] namesField;

    private string utcOffsetField;

    private string timeZoneIdField;

    /// <remarks/>
    public string AirportCode
    {
        get
        {
            return this.airportCodeField;
        }
        set
        {
            this.airportCodeField = value;
        }
    }

    /// <remarks/>
    public AirportPosition Position
    {
        get
        {
            return this.positionField;
        }
        set
        {
            this.positionField = value;
        }
    }

    /// <remarks/>
    public string CityCode
    {
        get
        {
            return this.cityCodeField;
        }
        set
        {
            this.cityCodeField = value;
        }
    }

    /// <remarks/>
    public string CountryCode
    {
        get
        {
            return this.countryCodeField;
        }
        set
        {
            this.countryCodeField = value;
        }
    }

    /// <remarks/>
    public string LocationType
    {
        get
        {
            return this.locationTypeField;
        }
        set
        {
            this.locationTypeField = value;
        }
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlArrayItemAttribute("Name", IsNullable = false)]
    public AirportName[] Names
    {
        get
        {
            return this.namesField;
        }
        set
        {
            this.namesField = value;
        }
    }

    /// <remarks/>
    public string UtcOffset
    {
        get
        {
            return this.utcOffsetField;
        }
        set
        {
            this.utcOffsetField = value;
        }
    }

    /// <remarks/>
    public string TimeZoneId
    {
        get
        {
            return this.timeZoneIdField;
        }
        set
        {
            this.timeZoneIdField = value;
        }
    }
}

/// <remarks/>
[System.SerializableAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
public class AirportPosition
{

    private AirportPositionCoordinate coordinateField;

    /// <remarks/>
    public AirportPositionCoordinate Coordinate
    {
        get
        {
            return this.coordinateField;
        }
        set
        {
            this.coordinateField = value;
        }
    }
}

/// <remarks/>
[System.SerializableAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
public partial class AirportPositionCoordinate
{

    private decimal latitudeField;

    private decimal longitudeField;

    /// <remarks/>
    public decimal Latitude
    {
        get
        {
            return this.latitudeField;
        }
        set
        {
            this.latitudeField = value;
        }
    }

    /// <remarks/>
    public decimal Longitude
    {
        get
        {
            return this.longitudeField;
        }
        set
        {
            this.longitudeField = value;
        }
    }
}

/// <remarks/>
[System.SerializableAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
public partial class AirportName
{

    private string languageCodeField;

    private string valueField;

    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute()]
    public string LanguageCode
    {
        get
        {
            return this.languageCodeField;
        }
        set
        {
            this.languageCodeField = value;
        }
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlTextAttribute()]
    public string Value
    {
        get
        {
            return this.valueField;
        }
        set
        {
            this.valueField = value;
        }
    }
}

