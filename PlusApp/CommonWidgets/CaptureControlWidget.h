/*=Plus=header=begin======================================================
Program: Plus
Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
See License.txt for details.
=========================================================Plus=header=end*/ 

#ifndef __CaptureControlWidget_h
#define __CaptureControlWidget_h

#include "PlusConfigure.h"
#include "ui_CaptureControlWidget.h"
#include "vtkVirtualStreamDiscCapture.h"
#include <QString>
#include <QWidget>

class QTimer;

//-----------------------------------------------------------------------------

/*! \class CaptureControlWidget 
* \brief Control vtkVirtualStreamDiscCapture devices
* \ingroup PlusAppCaptureClient
*/
class CaptureControlWidget : public QWidget
{
  Q_OBJECT

public:
  /*!
  * Constructor
  * \param aParent Parent main window
  * \param aFlags widget flag
  */
  CaptureControlWidget(QWidget* aParent, Qt::WFlags aFlags = 0);

  /*!
  * Destructor
  */
  ~CaptureControlWidget();

  /*! \brief Reset toolbox to initial state - */
  virtual void Reset();

  virtual double GetMaximumFrameRate() const;

  virtual void SetCaptureDevice(vtkVirtualStreamDiscCapture& aDevice){ m_Device = &aDevice; }

protected:
  /*!
  * Saves recorded tracked frame list to file
  * \param aOutput Output file
  * \return Success flag
  */
  PlusStatus SaveToMetafile(std::string aOutput);

  /*!
  * Save data to file
  */
  void WriteToFile(QString& aFilename);

protected:
  /*! Timer triggering the */
  QTimer* m_RecordingTimer;

  /*! device to interact with */
  vtkVirtualStreamDiscCapture* m_Device;

protected:
  Ui::CaptureControlWidget ui;
};

#endif
