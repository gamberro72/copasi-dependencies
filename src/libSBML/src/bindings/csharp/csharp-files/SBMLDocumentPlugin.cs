/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.4
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace libsbmlcs {

 using System;
 using System.Runtime.InteropServices;

/** 
 * @sbmlpackage{core}
 *
@htmlinclude pkg-marker-core.html Template class for the %SBMLDocument Plugin class needed
 * by all packages.
 *
 * Plugin objects for the SBMLDocument element must be this class or a
 * derived class of this class.  Package developers should use this class
 * as-is if only 'required' attribute is added in the SBMLDocument element by
 * their packages.  Otherwise, developers must implement a derived class of
 * this class and use that class as the plugin object for the SBMLDocument
 * element.
 */

public class SBMLDocumentPlugin : SBasePlugin {
	private HandleRef swigCPtr;
	
	internal SBMLDocumentPlugin(IntPtr cPtr, bool cMemoryOwn) : base(libsbmlPINVOKE.SBMLDocumentPlugin_SWIGUpcast(cPtr), cMemoryOwn)
	{
		//super(libsbmlPINVOKE.SBMLDocumentPluginUpcast(cPtr), cMemoryOwn);
		swigCPtr = new HandleRef(this, cPtr);
	}
	
	internal static HandleRef getCPtr(SBMLDocumentPlugin obj)
	{
		return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
	}
	
	internal static HandleRef getCPtrAndDisown (SBMLDocumentPlugin obj)
	{
		HandleRef ptr = new HandleRef(null, IntPtr.Zero);
		
		if (obj != null)
		{
			ptr             = obj.swigCPtr;
			obj.swigCMemOwn = false;
		}
		
		return ptr;
	}

  ~SBMLDocumentPlugin() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          libsbmlPINVOKE.delete_SBMLDocumentPlugin(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  
/**
   *  Constructor
   *
   * @param uri the URI of package 
   * @param prefix the prefix for the given package
   * @param sbmlns the SBMLNamespaces object for the package
   */ public
 SBMLDocumentPlugin(string uri, string prefix, SBMLNamespaces sbmlns) : this(libsbmlPINVOKE.new_SBMLDocumentPlugin__SWIG_0(uri, prefix, SBMLNamespaces.getCPtr(sbmlns)), true) {
    if (libsbmlPINVOKE.SWIGPendingException.Pending) throw libsbmlPINVOKE.SWIGPendingException.Retrieve();
  }

  
/**
   * Copy constructor. Creates a copy of this object.
   */ public
 SBMLDocumentPlugin(SBMLDocumentPlugin orig) : this(libsbmlPINVOKE.new_SBMLDocumentPlugin__SWIG_1(SBMLDocumentPlugin.getCPtr(orig)), true) {
    if (libsbmlPINVOKE.SWIGPendingException.Pending) throw libsbmlPINVOKE.SWIGPendingException.Retrieve();
  }

  
/**
   * Creates and returns a deep copy of this SBMLDocumentPlugin object.
   * 
   * @return a (deep) copy of this object
   */ public new
 SBasePlugin clone() {
    IntPtr cPtr = libsbmlPINVOKE.SBMLDocumentPlugin_clone(swigCPtr);
    SBMLDocumentPlugin ret = (cPtr == IntPtr.Zero) ? null : new SBMLDocumentPlugin(cPtr, true);
    return ret;
  }

  
/**
   *
   * Sets the bool value of 'required' attribute of corresponding package
   * in SBMLDocument element.
   *
   * @param value the bool value of 'required' attribute of corresponding 
   * package in SBMLDocument element.
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values
   * returned by this function are:
   * @li @link libsbmlcs.libsbml.LIBSBML_OPERATION_SUCCESS LIBSBML_OPERATION_SUCCESS @endlink
   * @li @link libsbmlcs.libsbml.LIBSBML_UNEXPECTED_ATTRIBUTE LIBSBML_UNEXPECTED_ATTRIBUTE @endlink
   */ public
 int setRequired(bool value) {
    int ret = libsbmlPINVOKE.SBMLDocumentPlugin_setRequired(swigCPtr, value);
    return ret;
  }

  
/**
   *
   * Returns the bool value of 'required' attribute of corresponding 
   * package in SBMLDocument element.
   *
   * @return the bool value of 'required' attribute of corresponding
   * package in SBMLDocument element.
   */ public
 bool getRequired() {
    bool ret = libsbmlPINVOKE.SBMLDocumentPlugin_getRequired(swigCPtr);
    return ret;
  }

  
/**
   * Predicate returning @c true or @c false depending on whether this
   * SBMLDocumentPlugin's 'required' attribute has been set.
   *
   * @return @c true if the 'required' attribute of this SBMLDocument has been
   * set, @c false otherwise.
   */ public
 bool isSetRequired() {
    bool ret = libsbmlPINVOKE.SBMLDocumentPlugin_isSetRequired(swigCPtr);
    return ret;
  }

  
/**
   * Unsets the value of the 'required' attribute of this SBMLDocumentPlugin.
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li @link libsbmlcs.libsbml.LIBSBML_OPERATION_SUCCESS LIBSBML_OPERATION_SUCCESS @endlink
   * @li @link libsbmlcs.libsbml.LIBSBML_OPERATION_FAILED LIBSBML_OPERATION_FAILED @endlink
   */ public
 int unsetRequired() {
    int ret = libsbmlPINVOKE.SBMLDocumentPlugin_unsetRequired(swigCPtr);
    return ret;
  }

  
/** */ /* libsbml-internal */ public
 bool isCompFlatteningImplemented() {
    bool ret = libsbmlPINVOKE.SBMLDocumentPlugin_isCompFlatteningImplemented(swigCPtr);
    return ret;
  }

  
/**
   * Check consistency function.
   */ /* libsbml-internal */ public
 long checkConsistency() { return (long)libsbmlPINVOKE.SBMLDocumentPlugin_checkConsistency(swigCPtr); }

}

}
