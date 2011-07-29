#ifndef __vtkFreehandController_h
#define __vtkFreehandController_h

#include "PlusConfigure.h"

#include "vtkObject.h"
#include "vtkDataCollector.h"
#include "vtkRenderer.h"

class vtkTrackedFrameList;
class QVTKWidget;
class vtkXMLDataElement;

//-----------------------------------------------------------------------------

/*!
* \brief Controller of the freehand calibration application
*/
class vtkFreehandController : public vtkObject
{
public:
	/*!
	* \brief New
	*/
	static vtkFreehandController *New();

	/*!
	* \brief Instance getter for the singleton class
	* \return Instance object
	*/
	static vtkFreehandController* GetInstance();

public:
	/*!
	* \brief Initialize object, connect to devices, load configuration
	*/
	PlusStatus Initialize();

	/*!
	 * \brief Sets tracking only flag and forwards the request to vtkDataCollector
	 * \return Tracking only flag
	 */
	void SetTrackingOnly(bool); 

	//TODO
	PlusStatus StartDataCollection();

	//TODO
	static vtkXMLDataElement* LookupElementWithNameContainingChildWithNameAndAttribute(vtkXMLDataElement* aConfig, const char* aElementName, const char* aChildName, const char* aChildAttributeName, const char* aChildAttributeValue);

	//TODO
	static vtkXMLDataElement* vtkFreehandController::ParseXMLOrFillWithInternalData(const char* aConfigFile);

public:
	// Set/Get functions for canvas
	QVTKWidget* GetCanvas() { return this->Canvas; };
	void SetCanvas(QVTKWidget* aCanvas) { this->Canvas = aCanvas; };

	// Set/Get macros for member variables
	vtkSetMacro(Initialized, bool); 
	vtkGetMacro(Initialized, bool); 
	vtkBooleanMacro(Initialized, bool); 

	vtkGetMacro(TrackingOnly, bool); 
	vtkBooleanMacro(TrackingOnly, bool); 

	vtkSetMacro(RecordingFrameRate, int); 
	vtkGetMacro(RecordingFrameRate, int); 

	vtkSetStringMacro(ConfigurationFileName); 
	vtkGetStringMacro(ConfigurationFileName); 

	vtkSetStringMacro(OutputFolder); 
	vtkGetStringMacro(OutputFolder); 

	vtkGetObjectMacro(DataCollector, vtkDataCollector); 
	vtkSetObjectMacro(DataCollector, vtkDataCollector); 

	vtkGetObjectMacro(CanvasRenderer, vtkRenderer);
	vtkSetObjectMacro(CanvasRenderer, vtkRenderer);

	vtkGetObjectMacro(ConfigurationData, vtkXMLDataElement); 

protected:
	vtkSetObjectMacro(ConfigurationData, vtkXMLDataElement); 

protected:
	/*!
	* \brief Constructor
	*/
	vtkFreehandController();

	/*!
	* \brief Destructor
	*/
	virtual ~vtkFreehandController();	

protected:
	//! Tracker object
	vtkDataCollector*				DataCollector;

	//! Initialization flag
	bool							Initialized;

	//! Flag determining if there is image recording beside tracker recording
	bool							TrackingOnly;

	//! Desired frame rate of synchronized recording
	int								RecordingFrameRate;

	//! Used configuration file name
	char*							ConfigurationFileName;

	//! Configuration root element
	vtkXMLDataElement*				ConfigurationData;

	//! Output folder
	char*							OutputFolder;

	//! Canvas object for real-time 3D visualization
	QVTKWidget*						Canvas;

	//! Renderer for the canvas
	vtkRenderer*					CanvasRenderer; 

private:
	//! Instance of the singleton
	static vtkFreehandController*	Instance;
};

#endif
