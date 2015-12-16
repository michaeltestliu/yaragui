#ifndef __MAIN_CONTROLLER_H__
#define __MAIN_CONTROLLER_H__

/* this class arbitrates scan engine operations on behalf of the GUI */

#include "main_window.h"
#include "settings.h"
#include "ruleset_manager.h"
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>

class MainController
{
public:

  MainController(int argc, char* argv[], boost::asio::io_service& io);

private:

  void handleChangeTarget(const std::string& file);
  void handleChangeRuleset(RulesetView::Ref ruleset);

  void handleScanResult(const std::string& target, ScannerRule::Ref rule);

  void scan();

  boost::asio::io_service& m_io;
  boost::shared_ptr<Settings> m_settings;
  boost::shared_ptr<RulesetManager> m_rm;
  boost::shared_ptr<MainWindow> m_mainWindow;

  std::string m_target;
  RulesetView::Ref m_ruleset;

};

#endif // __MAIN_CONTROLLER_H__
