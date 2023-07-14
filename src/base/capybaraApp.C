#include "capybaraApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
capybaraApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

capybaraApp::capybaraApp(InputParameters parameters) : MooseApp(parameters)
{
  capybaraApp::registerAll(_factory, _action_factory, _syntax);
}

capybaraApp::~capybaraApp() {}

void 
capybaraApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<capybaraApp>(f, af, s);
  Registry::registerObjectsTo(f, {"capybaraApp"});
  Registry::registerActionsTo(af, {"capybaraApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
capybaraApp::registerApps()
{
  registerApp(capybaraApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
capybaraApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  capybaraApp::registerAll(f, af, s);
}
extern "C" void
capybaraApp__registerApps()
{
  capybaraApp::registerApps();
}
