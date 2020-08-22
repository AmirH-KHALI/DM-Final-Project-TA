using System;
using System.Collections.Generic;
using System.Text;


// NOTE: Generated code may require at least .NET Framework 4.5 or .NET Core/Standard 2.0.
/// <remarks/>
[System.SerializableAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
[System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = false)]
public class City
{
    private string cityCodeField;

    private string countryCodeField;

    private CityNames namesField;

    private string utcOffsetField;

    private string timeZoneIdField;

    private CityAirports airportsField;

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
    public CityNames Names
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

    /// <remarks/>
    public CityAirports Airports
    {
        get
        {
            return this.airportsField;
        }
        set
        {
            this.airportsField = value;
        }
    }
}

/// <remarks/>
[System.SerializableAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
public partial class CityNames
{

    private CityNamesName nameField;

    /// <remarks/>
    public CityNamesName Name
    {
        get
        {
            return this.nameField;
        }
        set
        {
            this.nameField = value;
        }
    }
}

/// <remarks/>
[System.SerializableAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
public partial class CityNamesName
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

/// <remarks/>
[System.SerializableAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
public partial class CityAirports
{

    private string airportCodeField;

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
}

