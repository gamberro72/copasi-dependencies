/**
 * @file:   SedCurve.cpp
 * @brief:  Implementation of the SedCurve class
 * @author: Frank T. Bergmann
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML.  Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on
 * github: https://github.com/fbergmann/libSEDML/
 *
 * Copyright (c) 2013-2016, Frank T. Bergmann
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ------------------------------------------------------------------------ -->
 */


#include <sedml/SedCurve.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedCurve with the given level, version, and package version.
 */
SedCurve::SedCurve(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mId("")
  , mName("")
  , mLogX(false)
  , mIsSetLogX(false)
  , mLogY(false)
  , mIsSetLogY(false)
  , mXDataReference("")
  , mYDataReference("")
  , mLineColor("")
  , mFillColor("")
  , mSymbol("")
  , mLineThickness(numeric_limits<double>::quiet_NaN())
  , mIsSetLineThickness(false)
  , mLineStyle("")

{
  // set an SedNamespaces derived object of this package
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedCurve with the given SedNamespaces object.
 */
SedCurve::SedCurve(SedNamespaces* sedns)
  : SedBase(sedns)
  , mId("")
  , mName("")
  , mLogX(false)
  , mIsSetLogX(false)
  , mLogY(false)
  , mIsSetLogY(false)
  , mXDataReference("")
  , mYDataReference("")
  , mLineColor("")
  , mFillColor("")
  , mSymbol("")
  , mLineThickness(numeric_limits<double>::quiet_NaN())
  , mIsSetLineThickness(false)
  , mLineStyle("")

{
  // set the element namespace of this object
  setElementNamespace(sedns->getURI());
}


/*
 * Copy constructor for SedCurve.
 */
SedCurve::SedCurve(const SedCurve& orig)
  : SedBase(orig)
{
  mId  = orig.mId;
  mName  = orig.mName;
  mLogX  = orig.mLogX;
  mIsSetLogX  = orig.mIsSetLogX;
  mLogY  = orig.mLogY;
  mIsSetLogY  = orig.mIsSetLogY;
  mXDataReference  = orig.mXDataReference;
  mYDataReference  = orig.mYDataReference;
  mLineColor  = orig.mLineColor;
  mFillColor  = orig.mFillColor;
  mSymbol  = orig.mSymbol;
  mLineThickness  = orig.mLineThickness;
  mIsSetLineThickness  = orig.mIsSetLineThickness;
  mLineStyle  = orig.mLineStyle;
}


/*
 * Assignment for SedCurve.
 */
SedCurve&
SedCurve::operator=(const SedCurve& rhs)
{
  if (&rhs != this)
    {
      SedBase::operator=(rhs);
      mId  = rhs.mId;
      mName  = rhs.mName;
      mLogX  = rhs.mLogX;
      mIsSetLogX  = rhs.mIsSetLogX;
      mLogY  = rhs.mLogY;
      mIsSetLogY  = rhs.mIsSetLogY;
      mXDataReference  = rhs.mXDataReference;
      mYDataReference  = rhs.mYDataReference;
      mLineColor  = rhs.mLineColor;
      mFillColor  = rhs.mFillColor;
      mSymbol  = rhs.mSymbol;
      mLineThickness  = rhs.mLineThickness;
      mIsSetLineThickness  = rhs.mIsSetLineThickness;
      mLineStyle  = rhs.mLineStyle;
    }

  return *this;
}


/*
 * Clone for SedCurve.
 */
SedCurve*
SedCurve::clone() const
{
  return new SedCurve(*this);
}


/*
 * Destructor for SedCurve.
 */
SedCurve::~SedCurve()
{
}


/*
 * Returns the value of the "id" attribute of this SedCurve.
 */
const std::string&
SedCurve::getId() const
{
  return mId;
}


/*
 * Returns the value of the "name" attribute of this SedCurve.
 */
const std::string&
SedCurve::getName() const
{
  return mName;
}


/*
 * Returns the value of the "logX" attribute of this SedCurve.
 */
const bool
SedCurve::getLogX() const
{
  return mLogX;
}


/*
 * Returns the value of the "logY" attribute of this SedCurve.
 */
const bool
SedCurve::getLogY() const
{
  return mLogY;
}


/*
 * Returns the value of the "xDataReference" attribute of this SedCurve.
 */
const std::string&
SedCurve::getXDataReference() const
{
  return mXDataReference;
}


/*
 * Returns the value of the "yDataReference" attribute of this SedCurve.
 */
const std::string&
SedCurve::getYDataReference() const
{
  return mYDataReference;
}


/*
 * Returns the value of the "lineColor" attribute of this SedCurve.
 */
const std::string&
SedCurve::getLineColor() const
{
  return mLineColor;
}


/*
 * Returns the value of the "fillColor" attribute of this SedCurve.
 */
const std::string&
SedCurve::getFillColor() const
{
  return mFillColor;
}


/*
 * Returns the value of the "symbol" attribute of this SedCurve.
 */
const std::string&
SedCurve::getSymbol() const
{
  return mSymbol;
}


/*
 * Returns the value of the "lineThickness" attribute of this SedCurve.
 */
const double
SedCurve::getLineThickness() const
{
  return mLineThickness;
}


/*
 * Returns the value of the "lineStyle" attribute of this SedCurve.
 */
const std::string&
SedCurve::getLineStyle() const
{
  return mLineStyle;
}


/*
 * Returns true/false if id is set.
 */
bool
SedCurve::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Returns true/false if name is set.
 */
bool
SedCurve::isSetName() const
{
  return (mName.empty() == false);
}


/*
 * Returns true/false if logX is set.
 */
bool
SedCurve::isSetLogX() const
{
  return mIsSetLogX;
}


/*
 * Returns true/false if logY is set.
 */
bool
SedCurve::isSetLogY() const
{
  return mIsSetLogY;
}


/*
 * Returns true/false if xDataReference is set.
 */
bool
SedCurve::isSetXDataReference() const
{
  return (mXDataReference.empty() == false);
}


/*
 * Returns true/false if yDataReference is set.
 */
bool
SedCurve::isSetYDataReference() const
{
  return (mYDataReference.empty() == false);
}


/*
 * Returns true/false if lineColor is set.
 */
bool
SedCurve::isSetLineColor() const
{
  return (mLineColor.empty() == false);
}


/*
 * Returns true/false if fillColor is set.
 */
bool
SedCurve::isSetFillColor() const
{
  return (mFillColor.empty() == false);
}


/*
 * Returns true/false if symbol is set.
 */
bool
SedCurve::isSetSymbol() const
{
  return (mSymbol.empty() == false);
}


/*
 * Returns true/false if lineThickness is set.
 */
bool
SedCurve::isSetLineThickness() const
{
  return mIsSetLineThickness;
}


/*
 * Returns true/false if lineStyle is set.
 */
bool
SedCurve::isSetLineStyle() const
{
  return (mLineStyle.empty() == false);
}


/*
 * Sets id and returns value indicating success.
 */
int
SedCurve::setId(const std::string& id)
{
  return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets name and returns value indicating success.
 */
int
SedCurve::setName(const std::string& name)
{
  {
    mName = name;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets logX and returns value indicating success.
 */
int
SedCurve::setLogX(bool logX)
{
  mLogX = logX;
  mIsSetLogX = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets logY and returns value indicating success.
 */
int
SedCurve::setLogY(bool logY)
{
  mLogY = logY;
  mIsSetLogY = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets xDataReference and returns value indicating success.
 */
int
SedCurve::setXDataReference(const std::string& xDataReference)
{
  if (!(SyntaxChecker::isValidInternalSId(xDataReference)))
    {
      return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
    }
  else
    {
      mXDataReference = xDataReference;
      return LIBSEDML_OPERATION_SUCCESS;
    }
}


/*
 * Sets yDataReference and returns value indicating success.
 */
int
SedCurve::setYDataReference(const std::string& yDataReference)
{
  if (!(SyntaxChecker::isValidInternalSId(yDataReference)))
    {
      return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
    }
  else
    {
      mYDataReference = yDataReference;
      return LIBSEDML_OPERATION_SUCCESS;
    }
}


/*
 * Sets lineColor and returns value indicating success.
 */
int
SedCurve::setLineColor(const std::string& lineColor)
{
  {
    mLineColor = lineColor;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets fillColor and returns value indicating success.
 */
int
SedCurve::setFillColor(const std::string& fillColor)
{
  {
    mFillColor = fillColor;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets symbol and returns value indicating success.
 */
int
SedCurve::setSymbol(const std::string& symbol)
{
  {
    mSymbol = symbol;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets lineThickness and returns value indicating success.
 */
int
SedCurve::setLineThickness(double lineThickness)
{
  mLineThickness = lineThickness;
  mIsSetLineThickness = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets lineStyle and returns value indicating success.
 */
int
SedCurve::setLineStyle(const std::string& lineStyle)
{
  {
    mLineStyle = lineStyle;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets id and returns value indicating success.
 */
int
SedCurve::unsetId()
{
  mId.erase();

  if (mId.empty() == true)
    {
      return LIBSEDML_OPERATION_SUCCESS;
    }
  else
    {
      return LIBSEDML_OPERATION_FAILED;
    }
}


/*
 * Unsets name and returns value indicating success.
 */
int
SedCurve::unsetName()
{
  mName.erase();

  if (mName.empty() == true)
    {
      return LIBSEDML_OPERATION_SUCCESS;
    }
  else
    {
      return LIBSEDML_OPERATION_FAILED;
    }
}


/*
 * Unsets logX and returns value indicating success.
 */
int
SedCurve::unsetLogX()
{
  mLogX = false;
  mIsSetLogX = false;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets logY and returns value indicating success.
 */
int
SedCurve::unsetLogY()
{
  mLogY = false;
  mIsSetLogY = false;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets xDataReference and returns value indicating success.
 */
int
SedCurve::unsetXDataReference()
{
  mXDataReference.erase();

  if (mXDataReference.empty() == true)
    {
      return LIBSEDML_OPERATION_SUCCESS;
    }
  else
    {
      return LIBSEDML_OPERATION_FAILED;
    }
}


/*
 * Unsets yDataReference and returns value indicating success.
 */
int
SedCurve::unsetYDataReference()
{
  mYDataReference.erase();

  if (mYDataReference.empty() == true)
    {
      return LIBSEDML_OPERATION_SUCCESS;
    }
  else
    {
      return LIBSEDML_OPERATION_FAILED;
    }
}


/*
 * Unsets lineColor and returns value indicating success.
 */
int
SedCurve::unsetLineColor()
{
  mLineColor.erase();

  if (mLineColor.empty() == true)
    {
      return LIBSEDML_OPERATION_SUCCESS;
    }
  else
    {
      return LIBSEDML_OPERATION_FAILED;
    }
}


/*
 * Unsets fillColor and returns value indicating success.
 */
int
SedCurve::unsetFillColor()
{
  mFillColor.erase();

  if (mFillColor.empty() == true)
    {
      return LIBSEDML_OPERATION_SUCCESS;
    }
  else
    {
      return LIBSEDML_OPERATION_FAILED;
    }
}


/*
 * Unsets symbol and returns value indicating success.
 */
int
SedCurve::unsetSymbol()
{
  mSymbol.erase();

  if (mSymbol.empty() == true)
    {
      return LIBSEDML_OPERATION_SUCCESS;
    }
  else
    {
      return LIBSEDML_OPERATION_FAILED;
    }
}


/*
 * Unsets lineThickness and returns value indicating success.
 */
int
SedCurve::unsetLineThickness()
{
  mLineThickness = numeric_limits<double>::quiet_NaN();
  mIsSetLineThickness = false;

  if (isSetLineThickness() == false)
    {
      return LIBSEDML_OPERATION_SUCCESS;
    }
  else
    {
      return LIBSEDML_OPERATION_FAILED;
    }
}


/*
 * Unsets lineStyle and returns value indicating success.
 */
int
SedCurve::unsetLineStyle()
{
  mLineStyle.erase();

  if (mLineStyle.empty() == true)
    {
      return LIBSEDML_OPERATION_SUCCESS;
    }
  else
    {
      return LIBSEDML_OPERATION_FAILED;
    }
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedCurve::getElementName() const
{
  static const string name = "curve";
  return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedCurve::getTypeCode() const
{
  return SEDML_OUTPUT_CURVE;
}


/*
 * check if all the required attributes are set
 */
bool
SedCurve::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetLogX() == false)
    allPresent = false;

  if (isSetLogY() == false)
    allPresent = false;

  if (isSetXDataReference() == false)
    allPresent = false;

  if (isSetYDataReference() == false)
    allPresent = false;

  return allPresent;
}


/** @cond doxygen-libsedml-internal */

/*
 * write contained elements
 */
void
SedCurve::writeElements(XMLOutputStream& stream) const
{
  SedBase::writeElements(stream);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedCurve::accept(SedVisitor& v) const
{
  return false;

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedCurve::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedCurve::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("id");
  attributes.add("name");
  attributes.add("logX");
  attributes.add("logY");
  attributes.add("xDataReference");
  attributes.add("yDataReference");
  attributes.add("lineColor");
  attributes.add("fillColor");
  attributes.add("symbol");
  attributes.add("lineThickness");
  attributes.add("lineStyle");
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedCurve::readAttributes(const XMLAttributes& attributes,
                         const ExpectedAttributes& expectedAttributes)
{
  SedBase::readAttributes(attributes, expectedAttributes);

  bool assigned = false;

  //
  // id SId  ( use = "optional" )
  //
  assigned = attributes.readInto("id", mId, getErrorLog(), false);

  if (assigned == true)
    {
      // check string is not empty and correct syntax

      if (mId.empty() == true)
        {
          logEmptyString(mId, getLevel(), getVersion(), "<SedCurve>");
        }
      else if (SyntaxChecker::isValidSBMLSId(mId) == false)
        {
          logError(SedInvalidIdSyntax);
        }
    }

  //
  // name string   ( use = "optional" )
  //
  assigned = attributes.readInto("name", mName, getErrorLog(), false);

  if (assigned == true)
    {
      // check string is not empty

      if (mName.empty() == true)
        {
          logEmptyString(mName, getLevel(), getVersion(), "<SedCurve>");
        }
    }

  //
  // logX bool   ( use = "required" )
  //
  mIsSetLogX = attributes.readInto("logX", mLogX, getErrorLog(), true);

  //
  // logY bool   ( use = "required" )
  //
  mIsSetLogY = attributes.readInto("logY", mLogY, getErrorLog(), true);

  //
  // xDataReference SIdRef   ( use = "required" )
  //
  assigned = attributes.readInto("xDataReference", mXDataReference, getErrorLog(), true);

  if (assigned == true)
    {
      // check string is not empty and correct syntax

      if (mXDataReference.empty() == true)
        {
          logEmptyString(mXDataReference, getLevel(), getVersion(), "<SedCurve>");
        }
      else if (SyntaxChecker::isValidSBMLSId(mXDataReference) == false)
        {
          logError(SedInvalidIdSyntax);
        }
    }

  //
  // yDataReference SIdRef   ( use = "required" )
  //
  assigned = attributes.readInto("yDataReference", mYDataReference, getErrorLog(), true);

  if (assigned == true)
    {
      // check string is not empty and correct syntax

      if (mYDataReference.empty() == true)
        {
          logEmptyString(mYDataReference, getLevel(), getVersion(), "<SedCurve>");
        }
      else if (SyntaxChecker::isValidSBMLSId(mYDataReference) == false)
        {
          logError(SedInvalidIdSyntax);
        }
    }

  //
  // lineColor string   ( use = "optional" )
  //
  assigned = attributes.readInto("lineColor", mLineColor, getErrorLog(), false);

  if (assigned == true)
    {
      // check string is not empty

      if (mLineColor.empty() == true)
        {
          logEmptyString(mLineColor, getLevel(), getVersion(), "<SedCurve>");
        }
    }

  //
  // fillColor string   ( use = "optional" )
  //
  assigned = attributes.readInto("fillColor", mFillColor, getErrorLog(), false);

  if (assigned == true)
    {
      // check string is not empty

      if (mFillColor.empty() == true)
        {
          logEmptyString(mFillColor, getLevel(), getVersion(), "<SedCurve>");
        }
    }

  //
  // symbol string   ( use = "optional" )
  //
  assigned = attributes.readInto("symbol", mSymbol, getErrorLog(), false);

  if (assigned == true)
    {
      // check string is not empty

      if (mSymbol.empty() == true)
        {
          logEmptyString(mSymbol, getLevel(), getVersion(), "<SedCurve>");
        }
    }

  //
  // lineThickness double   ( use = "optional" )
  //
  mIsSetLineThickness = attributes.readInto("lineThickness", mLineThickness, getErrorLog(), false);

  //
  // lineStyle string   ( use = "optional" )
  //
  assigned = attributes.readInto("lineStyle", mLineStyle, getErrorLog(), false);

  if (assigned == true)
    {
      // check string is not empty

      if (mLineStyle.empty() == true)
        {
          logEmptyString(mLineStyle, getLevel(), getVersion(), "<SedCurve>");
        }
    }

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
void
SedCurve::writeAttributes(XMLOutputStream& stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetId() == true)
    stream.writeAttribute("id", getPrefix(), mId);

  if (isSetName() == true)
    stream.writeAttribute("name", getPrefix(), mName);

  if (isSetLogX() == true)
    stream.writeAttribute("logX", getPrefix(), mLogX);

  if (isSetLogY() == true)
    stream.writeAttribute("logY", getPrefix(), mLogY);

  if (isSetXDataReference() == true)
    stream.writeAttribute("xDataReference", getPrefix(), mXDataReference);

  if (isSetYDataReference() == true)
    stream.writeAttribute("yDataReference", getPrefix(), mYDataReference);

  if (isSetLineColor() == true)
    stream.writeAttribute("lineColor", getPrefix(), mLineColor);

  if (isSetFillColor() == true)
    stream.writeAttribute("fillColor", getPrefix(), mFillColor);

  if (isSetSymbol() == true)
    stream.writeAttribute("symbol", getPrefix(), mSymbol);

  if (isSetLineThickness() == true)
    stream.writeAttribute("lineThickness", getPrefix(), mLineThickness);

  if (isSetLineStyle() == true)
    stream.writeAttribute("lineStyle", getPrefix(), mLineStyle);

}


/** @endcond doxygen-libsedml-internal */


/*
 * Constructor
 */
SedListOfCurves::SedListOfCurves(unsigned int level,
                                 unsigned int version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Constructor
 */
SedListOfCurves::SedListOfCurves(SedNamespaces* sedns)
  : SedListOf(sedns)
{
  setElementNamespace(sedns->getURI());
}


/*
 * Returns a deep copy of this SedListOfCurves
 */
SedListOfCurves*
SedListOfCurves::clone() const
{
  return new SedListOfCurves(*this);
}


/*
 * Get a Curve from the SedListOfCurves by index.
*/
SedCurve*
SedListOfCurves::get(unsigned int n)
{
  return static_cast<SedCurve*>(SedListOf::get(n));
}


/*
 * Get a Curve from the SedListOfCurves by index.
 */
const SedCurve*
SedListOfCurves::get(unsigned int n) const
{
  return static_cast<const SedCurve*>(SedListOf::get(n));
}


/*
 * Get a Curve from the SedListOfCurves by id.
 */
SedCurve*
SedListOfCurves::get(const std::string& sid)
{
  return const_cast<SedCurve*>(
           static_cast<const SedListOfCurves&>(*this).get(sid));
}


/*
 * Get a Curve from the SedListOfCurves by id.
 */
const SedCurve*
SedListOfCurves::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;

  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedCurve>(sid));
  return (result == mItems.end()) ? 0 : static_cast <SedCurve*>(*result);
}


/**
 * Adds a copy the given "SedCurve" to this SedListOfCurves.
 *
 * @param sc; the SedCurve object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedListOfCurves::addCurve(const SedCurve* sc)
{
  if (sc == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;

  append(sc);
  return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedCurve objects in this SedListOfCurves.
 *
 * @return the number of SedCurve objects in this SedListOfCurves
 */
unsigned int
SedListOfCurves::getNumCurves() const
{
  return size();
}

/**
 * Creates a new SedCurve object, adds it to this SedListOfCurvess
 * SedCurve and returns the SedCurve object created.
 *
 * @return a new SedCurve object instance
 *
 * @see addSedCurve(const SedCurve* sc)
 */
SedCurve*
SedListOfCurves::createCurve()
{
  SedCurve *temp = new SedCurve();

  if (temp != NULL) appendAndOwn(temp);

  return temp;
}

/*
 * Removes the nth Curve from this SedListOfCurves
 */
SedCurve*
SedListOfCurves::remove(unsigned int n)
{
  return static_cast<SedCurve*>(SedListOf::remove(n));
}


/*
 * Removes the Curve from this SedListOfCurves with the given identifier
 */
SedCurve*
SedListOfCurves::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedCurve>(sid));

  if (result != mItems.end())
    {
      item = *result;
      mItems.erase(result);
    }

  return static_cast <SedCurve*>(item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedListOfCurves::getElementName() const
{
  static const string name = "listOfCurves";
  return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedListOfCurves::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the objects in this LIST_OF.
 */
int
SedListOfCurves::getItemTypeCode() const
{
  return SEDML_OUTPUT_CURVE;
}


/** @cond doxygen-libsedml-internal */

/*
 * Creates a new SedCurve in this SedListOfCurves
 */
SedBase*
SedListOfCurves::createObject(XMLInputStream& stream)
{
  const std::string& name   = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "curve")
    {
      object = new SedCurve(getSedNamespaces());
      appendAndOwn(object);
    }

  return object;
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Write the namespace for the Sed package.
 */
void
SedListOfCurves::writeXMLNS(XMLOutputStream& stream) const
{
  XMLNamespaces xmlns;

  std::string prefix = getPrefix();

  if (prefix.empty())
    {
      if (getNamespaces() != NULL && !getNamespaces()->hasURI(SEDML_XMLNS_L1) && !getNamespaces()->hasURI(SEDML_XMLNS_L1V2) && !getNamespaces()->hasURI(SEDML_XMLNS_L1V3))
        {
          if (getVersion() == 2) xmlns.add(SEDML_XMLNS_L1V2, prefix);
          else if (getVersion() == 3) xmlns.add(SEDML_XMLNS_L1V3, prefix);
          else xmlns.add(SEDML_XMLNS_L1V2, prefix);
        }
    }

  stream << xmlns;
}


/** @endcond doxygen-libsedml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
SedCurve_t *
SedCurve_create(unsigned int level, unsigned int version)
{
  return new SedCurve(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedCurve_free(SedCurve_t * sc)
{
  if (sc != NULL)
    delete sc;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedCurve_t *
SedCurve_clone(SedCurve_t * sc)
{
  if (sc != NULL)
    {
      return static_cast<SedCurve_t*>(sc->clone());
    }
  else
    {
      return NULL;
    }
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedCurve_getId(SedCurve_t * sc)
{
  if (sc == NULL)
    return NULL;

  return sc->getId().empty() ? NULL : safe_strdup(sc->getId().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedCurve_getName(SedCurve_t * sc)
{
  if (sc == NULL)
    return NULL;

  return sc->getName().empty() ? NULL : safe_strdup(sc->getName().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_getLogX(SedCurve_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->getLogX()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_getLogY(SedCurve_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->getLogY()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedCurve_getXDataReference(SedCurve_t * sc)
{
  if (sc == NULL)
    return NULL;

  return sc->getXDataReference().empty() ? NULL : safe_strdup(sc->getXDataReference().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedCurve_getYDataReference(SedCurve_t * sc)
{
  if (sc == NULL)
    return NULL;

  return sc->getYDataReference().empty() ? NULL : safe_strdup(sc->getYDataReference().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedCurve_getLineColor(SedCurve_t * sc)
{
  if (sc == NULL)
    return NULL;

  return sc->getLineColor().empty() ? NULL : safe_strdup(sc->getLineColor().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedCurve_getFillColor(SedCurve_t * sc)
{
  if (sc == NULL)
    return NULL;

  return sc->getFillColor().empty() ? NULL : safe_strdup(sc->getFillColor().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedCurve_getSymbol(SedCurve_t * sc)
{
  if (sc == NULL)
    return NULL;

  return sc->getSymbol().empty() ? NULL : safe_strdup(sc->getSymbol().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
double
SedCurve_getLineThickness(SedCurve_t * sc)
{
  return (sc != NULL) ? sc->getLineThickness() : numeric_limits<double>::quiet_NaN();
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedCurve_getLineStyle(SedCurve_t * sc)
{
  if (sc == NULL)
    return NULL;

  return sc->getLineStyle().empty() ? NULL : safe_strdup(sc->getLineStyle().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_isSetId(SedCurve_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->isSetId()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_isSetName(SedCurve_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->isSetName()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_isSetLogX(SedCurve_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->isSetLogX()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_isSetLogY(SedCurve_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->isSetLogY()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_isSetXDataReference(SedCurve_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->isSetXDataReference()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_isSetYDataReference(SedCurve_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->isSetYDataReference()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_isSetLineColor(SedCurve_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->isSetLineColor()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_isSetFillColor(SedCurve_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->isSetFillColor()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_isSetSymbol(SedCurve_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->isSetSymbol()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_isSetLineThickness(SedCurve_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->isSetLineThickness()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_isSetLineStyle(SedCurve_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->isSetLineStyle()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_setId(SedCurve_t * sc, const char * id)
{
  return (sc != NULL) ? sc->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_setName(SedCurve_t * sc, const char * name)
{
  return (sc != NULL) ? sc->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_setLogX(SedCurve_t * sc, int logX)
{
  return (sc != NULL) ? sc->setLogX(logX) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_setLogY(SedCurve_t * sc, int logY)
{
  return (sc != NULL) ? sc->setLogY(logY) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_setXDataReference(SedCurve_t * sc, const char * xDataReference)
{
  return (sc != NULL) ? sc->setXDataReference(xDataReference) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_setYDataReference(SedCurve_t * sc, const char * yDataReference)
{
  return (sc != NULL) ? sc->setYDataReference(yDataReference) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_setLineColor(SedCurve_t * sc, const char * lineColor)
{
  return (sc != NULL) ? sc->setLineColor(lineColor) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_setFillColor(SedCurve_t * sc, const char * fillColor)
{
  return (sc != NULL) ? sc->setFillColor(fillColor) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_setSymbol(SedCurve_t * sc, const char * symbol)
{
  return (sc != NULL) ? sc->setSymbol(symbol) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_setLineThickness(SedCurve_t * sc, double lineThickness)
{
  return (sc != NULL) ? sc->setLineThickness(lineThickness) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_setLineStyle(SedCurve_t * sc, const char * lineStyle)
{
  return (sc != NULL) ? sc->setLineStyle(lineStyle) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_unsetId(SedCurve_t * sc)
{
  return (sc != NULL) ? sc->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_unsetName(SedCurve_t * sc)
{
  return (sc != NULL) ? sc->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_unsetLogX(SedCurve_t * sc)
{
  return (sc != NULL) ? sc->unsetLogX() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_unsetLogY(SedCurve_t * sc)
{
  return (sc != NULL) ? sc->unsetLogY() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_unsetXDataReference(SedCurve_t * sc)
{
  return (sc != NULL) ? sc->unsetXDataReference() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_unsetYDataReference(SedCurve_t * sc)
{
  return (sc != NULL) ? sc->unsetYDataReference() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_unsetLineColor(SedCurve_t * sc)
{
  return (sc != NULL) ? sc->unsetLineColor() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_unsetFillColor(SedCurve_t * sc)
{
  return (sc != NULL) ? sc->unsetFillColor() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_unsetSymbol(SedCurve_t * sc)
{
  return (sc != NULL) ? sc->unsetSymbol() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_unsetLineThickness(SedCurve_t * sc)
{
  return (sc != NULL) ? sc->unsetLineThickness() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_unsetLineStyle(SedCurve_t * sc)
{
  return (sc != NULL) ? sc->unsetLineStyle() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedCurve_hasRequiredAttributes(SedCurve_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedCurve_t *
SedListOfCurves_getById(SedListOf_t * lo, const char * sid)
{
  if (lo == NULL)
    return NULL;

  return (sid != NULL) ? static_cast <SedListOfCurves *>(lo)->get(sid) : NULL;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedCurve_t *
SedListOfCurves_removeById(SedListOf_t * lo, const char * sid)
{
  if (lo == NULL)
    return NULL;

  return (sid != NULL) ? static_cast <SedListOfCurves *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


