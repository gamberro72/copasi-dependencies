/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.4
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace libsbml {

 using System;
 using System.Runtime.InteropServices;

/** 
 * @sbmlpackage{core}
 *
@htmlinclude pkg-marker-core.html Base class for SBML converters.
 *
 * @htmlinclude libsbml-facility-only-warning.html
 *
 * The SBMLConverter class is the base class for the various SBML @em
 * converters: classes of objects that transform or convert SBML documents.
 * These transformations can involve essentially anything that can be written
 * algorithmically; examples include converting the units of measurement in a
 * model, or converting from one Level+Version combination of SBML to
 * another.  Applications can also create their own converters by subclassing
 * SBMLConverter and following the examples of the existing converters.
 *
 * *
 * @section using-converters General information about the use of SBML converters
 *
 * The use of all the converters follows a similar approach.  First, one
 * creates a ConversionProperties object and calls
 * ConversionProperties::addOption(@if java ConversionOption@endif)
 * on this object with one arguments: a text string that identifies the desired
 * converter.  (The text string is specific to each converter; consult the
 * documentation for a given converter to find out how it should be enabled.)
 *
 * Next, for some converters, the caller can optionally set some
 * converter-specific properties using additional calls to
 * ConversionProperties::addOption(@if java ConversionOption@endif).
 * Many converters provide the ability to
 * configure their behavior to some extent; this is realized through the use
 * of properties that offer different options.  The default property values
 * for each converter can be interrogated using the method
 * SBMLConverter::getDefaultProperties() on the converter class in question .
 *
 * Finally, the caller should invoke the method
 * SBMLDocument::convert(@if java ConversionProperties@endif)
 * with the ConversionProperties object as an argument.
 *
 * @subsection converter-example Example of invoking an SBML converter
 *
 * The following code fragment illustrates an example using
 * SBMLReactionConverter, which is invoked using the option string @c
 * 'replaceReactions':
 *
 * @if cpp
 * @code{.cpp}
ConversionProperties props;
props.addOption('replaceReactions');
@endcode
@endif
@if python
@code{.py}
config = ConversionProperties()
if config != None:
  config.addOption('replaceReactions')
@endcode
@endif
@if java
@code{.java}
ConversionProperties props = new ConversionProperties();
if (props != null) {
  props.addOption('replaceReactions');
} else {
  // Deal with error.
}
@endcode
@endif
 *
 * In the case of SBMLReactionConverter, there are no options to affect
 * its behavior, so the next step is simply to invoke the converter on
 * an SBMLDocument object.  Continuing the example code:
 *
 * @if cpp
 * @code{.cpp}
// Assume that the variable 'document' has been set to an SBMLDocument object.
int status = document->convert(props);
if (status != LIBSBML_OPERATION_SUCCESS)
{
  cerr << 'Unable to perform conversion due to the following:' << endl;
  document->printErrors(cerr);
}
@endcode
@endif
@if python
@code{.py}
  # Assume that the variable 'document' has been set to an SBMLDocument object.
  status = document.convert(config)
  if status != LIBSBML_OPERATION_SUCCESS:
    # Handle error somehow.
    print('Error: conversion failed due to the following:')
    document.printErrors()
@endcode
@endif
@if java
@code{.java}
  // Assume that the variable 'document' has been set to an SBMLDocument object.
  status = document.convert(config);
  if (status != libsbml.LIBSBML_OPERATION_SUCCESS)
  {
    // Handle error somehow.
    System.out.println('Error: conversion failed due to the following:');
    document.printErrors();
  }
@endcode
@endif
 *
 * Here is an example of using a converter that offers an option. The
 * following code invokes SBMLStripPackageConverter to remove the
 * SBML Level&nbsp;3 @em %Layout package from a model.  It sets the name
 * of the package to be removed by adding a value for the option named
 * @c 'package' defined by that converter:
 *
 * @if cpp
 * @code{.cpp}
ConversionProperties props;
props.addOption('stripPackage');
props.addOption('package', 'layout');

int status = document->convert(props);
if (status != LIBSBML_OPERATION_SUCCESS)
{
    cerr << 'Unable to strip the Layout package from the model';
    cerr << 'Error returned: ' << status;
}
@endcode
@endif
@if python
@code{.py}
def strip_layout_example(document):
  config = ConversionProperties()
  if config != None:
    config.addOption('stripPackage')
    config.addOption('package', 'layout')
    status = document.convert(config)
    if status != LIBSBML_OPERATION_SUCCESS:
      # Handle error somehow.
      print('Error: unable to strip the Layout package.')
      print('LibSBML returned error: ' + OperationReturnValue_toString(status).strip())
  else:
    # Handle error somehow.
    print('Error: unable to create ConversionProperties object')
@endcode
@endif
@if java
@code{.java}
ConversionProperties config = new ConversionProperties();
if (config != None) {
  config.addOption('stripPackage');
  config.addOption('package', 'layout');
  status = document.convert(config);
  if (status != LIBSBML_OPERATION_SUCCESS) {
    // Handle error somehow.
    System.out.println('Error: unable to strip the Layout package');
    document.printErrors();
  }
} else {
  // Handle error somehow.
  System.out.println('Error: unable to create ConversionProperties object');
}
@endcode
@endif
 *
 * @subsection available-converters Available SBML converters in libSBML
 *
 * LibSBML provides a number of built-in converters; by convention, their
 * names end in @em Converter. The following are the built-in converters
 * provided by libSBML @htmlinclude libsbml-version.html:
 *
 * @copydetails doc_list_of_libsbml_converters
 *
 *
 */

public class SBMLConverter : IDisposable {
	private HandleRef swigCPtr;
	protected bool swigCMemOwn;
	
	internal SBMLConverter(IntPtr cPtr, bool cMemoryOwn)
	{
		swigCMemOwn = cMemoryOwn;
		swigCPtr    = new HandleRef(this, cPtr);
	}
	
	internal static HandleRef getCPtr(SBMLConverter obj)
	{
		return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
	}
	
	internal static HandleRef getCPtrAndDisown (SBMLConverter obj)
	{
		HandleRef ptr = new HandleRef(null, IntPtr.Zero);
		
		if (obj != null)
		{
			ptr             = obj.swigCPtr;
			obj.swigCMemOwn = false;
		}
		
		return ptr;
	}

  ~SBMLConverter() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          libsbmlPINVOKE.delete_SBMLConverter(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
    }
  }

  
/**
   * Creates a new SBMLConverter object.
   */ public
 SBMLConverter() : this(libsbmlPINVOKE.new_SBMLConverter__SWIG_0(), true) {
    SwigDirectorConnect();
  }

  
/**
   * Creates a new SBMLConverter object with a given name.
   * 
   * @param name the name for the converter to create
   */ public
 SBMLConverter(string name) : this(libsbmlPINVOKE.new_SBMLConverter__SWIG_1(name), true) {
    SwigDirectorConnect();
  }

  
/**
   * Copy constructor; creates a copy of an SBMLConverter object.
   *
   * @param c the SBMLConverter object to copy.
   *
   * @throws SBMLConstructorException
   * Thrown if the argument @p orig is @c null.
   */ public
 SBMLConverter(SBMLConverter c) : this(libsbmlPINVOKE.new_SBMLConverter__SWIG_2(SBMLConverter.getCPtr(c)), true) {
    if (libsbmlPINVOKE.SWIGPendingException.Pending) throw libsbmlPINVOKE.SWIGPendingException.Retrieve();
    SwigDirectorConnect();
  }

  
/**
   * Creates and returns a deep copy of this SBMLConverter object.
   *
   * @return the (deep) copy of this SBMLConverter object.
   */ public new
 SBMLConverter clone() {
	SBMLConverter ret
	    = (SBMLConverter) libsbml.DowncastSBMLConverter((SwigDerivedClassHasMethod("clone", swigMethodTypes0) ? libsbmlPINVOKE.SBMLConverter_cloneSwigExplicitSBMLConverter(swigCPtr) : libsbmlPINVOKE.SBMLConverter_clone(swigCPtr)), true);
	return ret;
}

  
/**
   * Returns the SBML document that is the subject of the conversions.
   *
   * @return the current SBMLDocument object.
   */ public new
 SBMLDocument getDocument() {
    IntPtr cPtr = (SwigDerivedClassHasMethod("getDocument", swigMethodTypes1) ? libsbmlPINVOKE.SBMLConverter_getDocumentSwigExplicitSBMLConverter__SWIG_0(swigCPtr) : libsbmlPINVOKE.SBMLConverter_getDocument__SWIG_0(swigCPtr));
    SBMLDocument ret = (cPtr == IntPtr.Zero) ? null : new SBMLDocument(cPtr, false);
    return ret;
  }

  
/**
   * Returns the default properties of this converter.
   *
   * A given converter exposes one or more properties that can be adjusted
   * in order to influence the behavior of the converter.  This method
   * returns the @em default property settings for this converter.  It is
   * meant to be called in order to discover all the settings for the
   * converter object.  The run-time properties of the converter object can
   * be adjusted by using the method
   * SBMLConverter::setProperties(ConversionProperties props).
   *
   * @return the default properties for the converter.
   *
   * @see setProperties(@if java ConversionProperties@endif)
   * @see matchesProperties(@if java ConversionProperties@endif)
   */ public new
 ConversionProperties getDefaultProperties() {
    ConversionProperties ret = new ConversionProperties((SwigDerivedClassHasMethod("getDefaultProperties", swigMethodTypes3) ? libsbmlPINVOKE.SBMLConverter_getDefaultPropertiesSwigExplicitSBMLConverter(swigCPtr) : libsbmlPINVOKE.SBMLConverter_getDefaultProperties(swigCPtr)), true);
    return ret;
  }

  
/**
   * Returns the target SBML namespaces of the currently set properties.
   *
   * SBML namespaces are used by libSBML to express the Level+Version of
   * the SBML document (and, possibly, any SBML Level&nbsp;3 packages in
   * use). Some converters' behavior is affected by the SBML namespace
   * configured in the converter.  For example, the actions of
   * SBMLLevelVersionConverter, the converter for converting SBML documents
   * from one Level+Version combination to another, are fundamentally
   * dependent on the SBML namespaces being targeted.
   *
   * @return the SBMLNamespaces object that describes the SBML namespaces
   * in effect.
   */ public new
 SBMLNamespaces getTargetNamespaces() {
	SBMLNamespaces ret
	    = (SBMLNamespaces) libsbml.DowncastSBMLNamespaces((SwigDerivedClassHasMethod("getTargetNamespaces", swigMethodTypes4) ? libsbmlPINVOKE.SBMLConverter_getTargetNamespacesSwigExplicitSBMLConverter(swigCPtr) : libsbmlPINVOKE.SBMLConverter_getTargetNamespaces(swigCPtr)), false);
	return ret;
}

  
/**
   * Predicate returning @c true if this converter's properties matches a
   * given set of configuration properties.
   *
   * @param props the configuration properties to match.
   *
   * @return @c true if this converter's properties match, @c false
   * otherwise.
   */ public new
 bool matchesProperties(ConversionProperties props) {
    bool ret = (SwigDerivedClassHasMethod("matchesProperties", swigMethodTypes5) ? libsbmlPINVOKE.SBMLConverter_matchesPropertiesSwigExplicitSBMLConverter(swigCPtr, ConversionProperties.getCPtr(props)) : libsbmlPINVOKE.SBMLConverter_matchesProperties(swigCPtr, ConversionProperties.getCPtr(props)));
    if (libsbmlPINVOKE.SWIGPendingException.Pending) throw libsbmlPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  
/**
   * Sets the current SBML document to the given SBMLDocument object.
   *
   * @param doc the document to use for this conversion.
   *
   * @return integer value indicating the success/failure of the operation.
   * @if clike The value is drawn from the enumeration
   * #OperationReturnValues_t. @endif The set of possible values that may
   * be returned ultimately depends on the specific subclass of
   * SBMLConverter being used, but the default method can return the
   * following values:
   * @li @link libsbmlcs#LIBSBML_OPERATION_SUCCESS LIBSBML_OPERATION_SUCCESS@endlink
   */ public new
 int setDocument(SBMLDocument doc) {
    int ret = (SwigDerivedClassHasMethod("setDocument", swigMethodTypes6) ? libsbmlPINVOKE.SBMLConverter_setDocumentSwigExplicitSBMLConverter(swigCPtr, SBMLDocument.getCPtr(doc)) : libsbmlPINVOKE.SBMLConverter_setDocument(swigCPtr, SBMLDocument.getCPtr(doc)));
    return ret;
  }

  
/**
   * Sets the configuration properties to be used by this converter.
   *
   * @param props the ConversionProperties object defining the properties
   * to set.
   *
   * @return integer value indicating the success/failure of the operation.
   * @if clike The value is drawn from the enumeration
   * #OperationReturnValues_t. @endif The set of possible values that may
   * be returned ultimately depends on the specific subclass of
   * SBMLConverter being used, but the default method can return the
   * following values:
   * @li @link libsbmlcs#LIBSBML_OPERATION_SUCCESS LIBSBML_OPERATION_SUCCESS@endlink
   * @li @link libsbmlcs#LIBSBML_OPERATION_FAILED LIBSBML_OPERATION_FAILED@endlink
   *
   * @see getProperties()
   * @see matchesProperties(@if java ConversionProperties@endif)
   */ public new
 int setProperties(ConversionProperties props) {
    int ret = (SwigDerivedClassHasMethod("setProperties", swigMethodTypes7) ? libsbmlPINVOKE.SBMLConverter_setPropertiesSwigExplicitSBMLConverter(swigCPtr, ConversionProperties.getCPtr(props)) : libsbmlPINVOKE.SBMLConverter_setProperties(swigCPtr, ConversionProperties.getCPtr(props)));
    return ret;
  }

  
/**
   * Returns the current properties in effect for this converter.
   *
   * A given converter exposes one or more properties that can be adjusted
   * in order to influence the behavior of the converter.  This method
   * returns the current properties for this converter; in other words, the
   * settings in effect at this moment.  To change the property values, you
   * can use SBMLConverter::setProperties(ConversionProperties props).
   *
   * @return the currently set configuration properties.
   *
   * @see setProperties(@if java ConversionProperties@endif)
   * @see matchesProperties(@if java ConversionProperties@endif)
   */ public new
 ConversionProperties getProperties() {
    IntPtr cPtr = (SwigDerivedClassHasMethod("getProperties", swigMethodTypes8) ? libsbmlPINVOKE.SBMLConverter_getPropertiesSwigExplicitSBMLConverter(swigCPtr) : libsbmlPINVOKE.SBMLConverter_getProperties(swigCPtr));
    ConversionProperties ret = (cPtr == IntPtr.Zero) ? null : new ConversionProperties(cPtr, false);
    return ret;
  }

  
/**
   * Perform the conversion.
   *
   * This method causes the converter to do the actual conversion work,
   * that is, to convert the SBMLDocument object set by
   * SBMLConverter::setDocument(@if java SBMLDocument@endif) and
   * with the configuration options set by
   * SBMLConverter::setProperties(@if java ConversionProperties@endif).
   *
   * @return  integer value indicating the success/failure of the operation.
   * @if clike The value is drawn from the enumeration
   * #OperationReturnValues_t. @endif The set of possible values that may
   * be returned depends on the converter subclass; please consult
   * the documentation for the relevant class to find out what the
   * possibilities are.
   */ public new
 int convert() {
    int ret = (SwigDerivedClassHasMethod("convert", swigMethodTypes9) ? libsbmlPINVOKE.SBMLConverter_convertSwigExplicitSBMLConverter(swigCPtr) : libsbmlPINVOKE.SBMLConverter_convert(swigCPtr));
    return ret;
  }

  
/**  
   * Returns the name of this converter. 
   *
   * @return a name for this converter
   */ public
 string getName() {
    string ret = libsbmlPINVOKE.SBMLConverter_getName(swigCPtr);
    return ret;
  }

  private void SwigDirectorConnect() {
    if (SwigDerivedClassHasMethod("clone", swigMethodTypes0))
      swigDelegate0 = new SwigDelegateSBMLConverter_0(SwigDirectorclone);
    if (SwigDerivedClassHasMethod("getDocument", swigMethodTypes1))
      swigDelegate1 = new SwigDelegateSBMLConverter_1(SwigDirectorgetDocument__SWIG_0);
    if (SwigDerivedClassHasMethod("getDocument", swigMethodTypes2))
      swigDelegate2 = new SwigDelegateSBMLConverter_2(SwigDirectorgetDocument__SWIG_1);
    if (SwigDerivedClassHasMethod("getDefaultProperties", swigMethodTypes3))
      swigDelegate3 = new SwigDelegateSBMLConverter_3(SwigDirectorgetDefaultProperties);
    if (SwigDerivedClassHasMethod("getTargetNamespaces", swigMethodTypes4))
      swigDelegate4 = new SwigDelegateSBMLConverter_4(SwigDirectorgetTargetNamespaces);
    if (SwigDerivedClassHasMethod("matchesProperties", swigMethodTypes5))
      swigDelegate5 = new SwigDelegateSBMLConverter_5(SwigDirectormatchesProperties);
    if (SwigDerivedClassHasMethod("setDocument", swigMethodTypes6))
      swigDelegate6 = new SwigDelegateSBMLConverter_6(SwigDirectorsetDocument);
    if (SwigDerivedClassHasMethod("setProperties", swigMethodTypes7))
      swigDelegate7 = new SwigDelegateSBMLConverter_7(SwigDirectorsetProperties);
    if (SwigDerivedClassHasMethod("getProperties", swigMethodTypes8))
      swigDelegate8 = new SwigDelegateSBMLConverter_8(SwigDirectorgetProperties);
    if (SwigDerivedClassHasMethod("convert", swigMethodTypes9))
      swigDelegate9 = new SwigDelegateSBMLConverter_9(SwigDirectorconvert);
    libsbmlPINVOKE.SBMLConverter_director_connect(swigCPtr, swigDelegate0, swigDelegate1, swigDelegate2, swigDelegate3, swigDelegate4, swigDelegate5, swigDelegate6, swigDelegate7, swigDelegate8, swigDelegate9);
  }

  private bool SwigDerivedClassHasMethod(string methodName, Type[] methodTypes) {
    System.Reflection.MethodInfo methodInfo = this.GetType().GetMethod(methodName, System.Reflection.BindingFlags.Public | System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance, null, methodTypes, null);
    bool hasDerivedMethod = methodInfo.DeclaringType.IsSubclassOf(typeof(SBMLConverter));
    return hasDerivedMethod;
  }

  private IntPtr SwigDirectorclone() {
    return SBMLConverter.getCPtr(clone()).Handle;
  }

  private IntPtr SwigDirectorgetDocument__SWIG_0() {
    return SBMLDocument.getCPtr(getDocument()).Handle;
  }

  private IntPtr SwigDirectorgetDocument__SWIG_1() {
    return SBMLDocument.getCPtr(getDocument()).Handle;
  }

  private IntPtr SwigDirectorgetDefaultProperties() {
    return ConversionProperties.getCPtr(getDefaultProperties()).Handle;
  }

  private IntPtr SwigDirectorgetTargetNamespaces() {
    return SBMLNamespaces.getCPtr(getTargetNamespaces()).Handle;
  }

  private bool SwigDirectormatchesProperties(IntPtr props) {
    return matchesProperties(new ConversionProperties(props, false));
  }

  private int SwigDirectorsetDocument(IntPtr doc) {
    return setDocument((doc == IntPtr.Zero) ? null : new SBMLDocument(doc, false));
  }

  private int SwigDirectorsetProperties(IntPtr props) {
    return setProperties((props == IntPtr.Zero) ? null : new ConversionProperties(props, false));
  }

  private IntPtr SwigDirectorgetProperties() {
    return ConversionProperties.getCPtr(getProperties()).Handle;
  }

  private int SwigDirectorconvert() {
    return convert();
  }

  public delegate IntPtr SwigDelegateSBMLConverter_0();
  public delegate IntPtr SwigDelegateSBMLConverter_1();
  public delegate IntPtr SwigDelegateSBMLConverter_2();
  public delegate IntPtr SwigDelegateSBMLConverter_3();
  public delegate IntPtr SwigDelegateSBMLConverter_4();
  public delegate bool SwigDelegateSBMLConverter_5(IntPtr props);
  public delegate int SwigDelegateSBMLConverter_6(IntPtr doc);
  public delegate int SwigDelegateSBMLConverter_7(IntPtr props);
  public delegate IntPtr SwigDelegateSBMLConverter_8();
  public delegate int SwigDelegateSBMLConverter_9();

  private SwigDelegateSBMLConverter_0 swigDelegate0;
  private SwigDelegateSBMLConverter_1 swigDelegate1;
  private SwigDelegateSBMLConverter_2 swigDelegate2;
  private SwigDelegateSBMLConverter_3 swigDelegate3;
  private SwigDelegateSBMLConverter_4 swigDelegate4;
  private SwigDelegateSBMLConverter_5 swigDelegate5;
  private SwigDelegateSBMLConverter_6 swigDelegate6;
  private SwigDelegateSBMLConverter_7 swigDelegate7;
  private SwigDelegateSBMLConverter_8 swigDelegate8;
  private SwigDelegateSBMLConverter_9 swigDelegate9;

  private static Type[] swigMethodTypes0 = new Type[] {  };
  private static Type[] swigMethodTypes1 = new Type[] {  };
  private static Type[] swigMethodTypes2 = new Type[] {  };
  private static Type[] swigMethodTypes3 = new Type[] {  };
  private static Type[] swigMethodTypes4 = new Type[] {  };
  private static Type[] swigMethodTypes5 = new Type[] { typeof(ConversionProperties) };
  private static Type[] swigMethodTypes6 = new Type[] { typeof(SBMLDocument) };
  private static Type[] swigMethodTypes7 = new Type[] { typeof(ConversionProperties) };
  private static Type[] swigMethodTypes8 = new Type[] {  };
  private static Type[] swigMethodTypes9 = new Type[] {  };
}

}
