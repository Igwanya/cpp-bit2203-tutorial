#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFontDatabase>

#include <QLocale>
#include <QTranslator>
#include <iostream>

#include <boost/log/trivial.hpp>
#include <boost/program_options.hpp>

#include "tut/config.h"
#include "tut/ch1.hpp"
#include "tut/ch2.hpp"
#include "tut/ch3.hpp"
#include "bit2203/bit2203.hpp"

#include <chrono>

int main(int argc, char **argv)
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

  QGuiApplication app(argc, argv);

  boost::program_options::options_description desc{"Allowed options"};
  desc.add_options()
      ("help", "Display this help message")
      ("version", "Displays the program version")
      ;
  boost::program_options::variables_map vm;
  boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
  boost::program_options::notify(vm);

  if (vm.count("help")) std::cout << desc << "\n";
  //if (vm.count("version")) std::cout << "Program version : "<< learncpp_VERSION_MAJOR << "." << learncpp_VERSION_MINOR << std::endl;

  bit2203::exe_08();
  // tut::ch3::exe_3_17();

  // intro_to_c_plus_plus::ch2::exe_2_18();

  QTranslator translator;
  const QStringList uiLanguages = QLocale::system().uiLanguages();
  for (const QString &locale : uiLanguages) {
      const QString baseName = "ui_" + QLocale(locale).name();
      if (translator.load(":/i18n/" + baseName)) {
          app.installTranslator(&translator);
          break;
        }
    }

  QFontDatabase fontdb;
  int err = fontdb.addApplicationFont("qrc:/icons/fontello.ttf");
  if (err == -1) {
      BOOST_LOG_TRIVIAL(warning) <<"Failed to load fontello.ttf\n";
    }

  QQmlApplicationEngine engine;
  const QUrl url(QStringLiteral("qrc:/main.qml"));
  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                   &app, [url](QObject *obj, const QUrl &objUrl) {
    if (!obj && url == objUrl)
      QCoreApplication::exit(-1);
  }, Qt::QueuedConnection);
  engine.load(url);

  //  BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
  //  BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
  //  BOOST_LOG_TRIVIAL(info) << "An informational severity message";
  //  BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
  //  BOOST_LOG_TRIVIAL(error) << "An error severity message";
  //  BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";
  return app.exec();
}
