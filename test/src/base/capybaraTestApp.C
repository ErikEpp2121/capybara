//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "capybaraTestApp.h"
#include "capybaraApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
capybaraTestApp::validParams()
{
  InputParameters params = capybaraApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

capybaraTestApp::capybaraTestApp(InputParameters parameters) : MooseApp(parameters)
{
  capybaraTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

capybaraTestApp::~capybaraTestApp() {}

void
capybaraTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  capybaraApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"capybaraTestApp"});
    Registry::registerActionsTo(af, {"capybaraTestApp"});
  }
}

void
capybaraTestApp::registerApps()
{
  registerApp(capybaraApp);
  registerApp(capybaraTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
capybaraTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  capybaraTestApp::registerAll(f, af, s);
}
extern "C" void
capybaraTestApp__registerApps()
{
  capybaraTestApp::registerApps();
}
