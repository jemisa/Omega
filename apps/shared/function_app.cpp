#include "function_app.h"
#include "../apps_container.h"

using namespace Poincare;

namespace Shared {

FunctionApp::Snapshot::Snapshot() :
  m_cursor(),
  m_interval(),
  m_graphModelVersion(0),
  m_valuesModelVersion(0),
  m_rangeVersion(0)
{
  m_interval.setStart(0);
  m_interval.setEnd(10);
  m_interval.setStep(1);
}

CurveViewCursor * FunctionApp::Snapshot::cursor() {
  return &m_cursor;
}

uint32_t * FunctionApp::Snapshot::graphModelVersion() {
  return &m_graphModelVersion;
}

uint32_t * FunctionApp::Snapshot::valuesModelVersion() {
  return &m_valuesModelVersion;
}

uint32_t * FunctionApp::Snapshot::rangeVersion() {
  return &m_rangeVersion;
}

Interval * FunctionApp::Snapshot::interval() {
  return &m_interval;
}

void FunctionApp::Snapshot::reset() {
  m_interval.setStart(0);
  m_interval.setEnd(10);
  m_interval.setStep(1);
  m_graphModelVersion = 0;
  m_valuesModelVersion = 0;
  m_rangeVersion = 0;
  setActiveTab(0);
}

FunctionApp::FunctionApp(Container * container, Snapshot * snapshot, ViewController * rootViewController) :
  TextFieldDelegateApp(container, snapshot, rootViewController)
{
}

void FunctionApp::willBecomeInactive() {
  if (m_modalViewController.isDisplayingModal()) {
    m_modalViewController.dismissModalViewController();
  }
  if (inputViewController()->isDisplayingModal()) {
    inputViewController()->abortTextFieldEditionAndDismiss();
  }
  ::App::willBecomeInactive();
}

}
