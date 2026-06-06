#include "logger.hpp"

#include <iostream>
#include <sstream>
#include <chrono>
#include <format>

const std::map<Color,std::string> Logger::mColorMap = {
   {Color::DEFAULT_FG, "39"},
   {Color::DEFAULT_BG, "49"},
   {Color::BLACK_FG, "30"},
   {Color::BLACK_BG, "40"},
   {Color::BLACK_FG_BRIGHT, "90"},
   {Color::BLACK_BG_BRIGHT, "100"},
   {Color::RED_FG, "31"},
   {Color::RED_BG, "41"},
   {Color::RED_FG_BRIGHT, "91"},
   {Color::RED_BG_BRIGHT, "101"},
   {Color::GREEN_FG, "32"},
   {Color::GREEN_BG, "42"},
   {Color::GREEN_FG_BRIGHT, "92"},
   {Color::GREEN_BG_BRIGHT, "102"},
   {Color::YELLOW_FG, "33"},
   {Color::YELLOW_BG, "43"},
   {Color::YELLOW_FG_BRIGHT, "93"},
   {Color::YELLOW_BG_BRIGHT, "103"},
   {Color::BLUE_FG, "34"},
   {Color::BLUE_BG, "44"},
   {Color::BLUE_FG_BRIGHT, "94"},
   {Color::BLUE_BG_BRIGHT, "104"},
   {Color::MAGENTA_FG, "35"},
   {Color::MAGENTA_BG, "45"},
   {Color::MAGENTA_FG_BRIGHT, "95"},
   {Color::MAGENTA_BG_BRIGHT, "105"},
   {Color::CYAN_FG, "36"},
   {Color::CYAN_BG, "46"},
   {Color::CYAN_FG_BRIGHT, "96"},
   {Color::CYAN_BG_BRIGHT, "106"},
   {Color::WHITE_FG, "37"},
   {Color::WHITE_BG, "47"},
   {Color::WHITE_FG_BRIGHT, "97"},
   {Color::WHITE_BG_BRIGHT, "107"}
};

const std::map<Color,std::string> Logger::mColorNameMap = {
   {Color::DEFAULT_FG, "Default Fore"},
   {Color::DEFAULT_BG, "Default Back"},
   {Color::BLACK_FG, "Black Fore"},
   {Color::BLACK_BG, "Black Back"},
   {Color::BLACK_FG_BRIGHT, "Black Fore - Bright"},
   {Color::BLACK_BG_BRIGHT, "Black Back - Bright"},
   {Color::RED_FG, "Red Fore"},
   {Color::RED_BG, "Red Back"},
   {Color::RED_FG_BRIGHT, "Red Fore - Bright"},
   {Color::RED_BG_BRIGHT, "Red Back - Bright"},
   {Color::GREEN_FG, "Green Fore"},
   {Color::GREEN_BG, "Green Back"},
   {Color::GREEN_FG_BRIGHT, "Green Fore - Bright"},
   {Color::GREEN_BG_BRIGHT, "Green Back - Bright"},
   {Color::YELLOW_FG, "Yellow Fore"},
   {Color::YELLOW_BG, "Yellow Back"},
   {Color::YELLOW_FG_BRIGHT, "Yellow Fore - Bright"},
   {Color::YELLOW_BG_BRIGHT, "Yellow Back - Bright"},
   {Color::BLUE_FG, "Blue Fore"},
   {Color::BLUE_BG, "Blue Back"},
   {Color::BLUE_FG_BRIGHT, "Blue Fore - Bright"},
   {Color::BLUE_BG_BRIGHT, "Blue Back - Bright"},
   {Color::MAGENTA_FG, "Magenta Fore"},
   {Color::MAGENTA_BG, "Magenta Back"},
   {Color::MAGENTA_FG_BRIGHT, "Magenta Fore - Bright"},
   {Color::MAGENTA_BG_BRIGHT, "Magenta Back - Bright"},
   {Color::CYAN_FG, "Cyan Fore"},
   {Color::CYAN_BG, "Cyan Back"},
   {Color::CYAN_FG_BRIGHT, "Cyan Fore - Bright"},
   {Color::CYAN_BG_BRIGHT, "Cyan Back - Bright"},
   {Color::WHITE_FG, "White Fore"},
   {Color::WHITE_BG, "White Back"},
   {Color::WHITE_FG_BRIGHT, "White Fore - Bright"},
   {Color::WHITE_BG_BRIGHT, "White Back - Bright"}
};

const std::map<Style,std::string> Logger::mStyleMap = {
   {Style::BLANK, ""},
   {Style::BOLD, "1"},
   {Style::FAINT, "2"},
   {Style::ITALIC, "3"},
   {Style::UNERLINE, "4"},
   {Style::BLINK, "5"},
   {Style::HIDDEN, "8"},
   {Style::STRIKETHROUGH, "9"}
};

const std::map<Style,std::string> Logger::mStyleNameMap = {
   {Style::BLANK, "Blank"},
   {Style::BOLD, "Bold"},
   {Style::FAINT, "Faint"},
   {Style::ITALIC, "Italic"},
   {Style::UNERLINE, "Underline"},
   {Style::BLINK, "Blink"},
   {Style::HIDDEN, "Hidden"},
   {Style::STRIKETHROUGH, "Strikethrough"}
};

const std::map<Symbol,std::string> Logger::mSymMap = {
   {Symbol::CHECK, "\u2714"},
   {Symbol::X, "\u2718"},
   {Symbol::null, "\u2205"},
   {Symbol::R_ARROW, "\u27A4"},

   {Symbol::DELTA, "\u0394"},
   {Symbol::THETA, "\u0398"},
   {Symbol::EPSILON, "\u03A3"},
   {Symbol::PHI, "\u03A6"},
   {Symbol::PSI, "\u03A8"},
   {Symbol::OMEGA, "\u03A9"},
   {Symbol::alpha, "\u03B1"},
   {Symbol::beta, "\u03B2"},
   {Symbol::gamma, "\u03B3"},
   {Symbol::delta, "\u03B4"},
   {Symbol::epsilon, "\u03B5"},
   {Symbol::zeta, "\u03B6"},
   {Symbol::eta, "\u03B7"},
   {Symbol::theta, "\u03B8"},
   {Symbol::lambda, "\u03BB"},
   {Symbol::mu, "\u03BC"},
   {Symbol::nu, "\u03BD"},
   {Symbol::pi, "\u03C0"},
   {Symbol::rho, "\u03C1"},
   {Symbol::sigma, "\u03C3"},
   {Symbol::phi, "\u03C6"},
   {Symbol::psi, "\u03C8"},
   {Symbol::omega, "\u03C9"}
};

const std::map<Symbol,std::string> Logger::mSymNameMap = {
   {Symbol::CHECK, "Check-mark"},
   {Symbol::X, "X-mark"},
   {Symbol::null, "Null-mark"},
   {Symbol::R_ARROW, "Right Arrow"},


   {Symbol::DELTA, "Capital Delta"},
   {Symbol::THETA, "Capital Theta"},
   {Symbol::EPSILON, "Capital Epsilon"},
   {Symbol::PHI, "Capital Phi"},
   {Symbol::PSI, "Capital Psi"},
   {Symbol::OMEGA, "Capital Omega"},

   {Symbol::alpha, "Lower-case Alpha"},
   {Symbol::beta, "Lower-case Beta"},
   {Symbol::gamma, "Lower-case Gamma"},
   {Symbol::delta, "Lower-case Delta"},
   {Symbol::epsilon, "Lower-case Epsilon"},
   {Symbol::zeta, "Lower-case Zeta"},
   {Symbol::eta, "Lower-case Eta"},
   {Symbol::theta, "Lower-case Theta"},
   {Symbol::lambda, "Lower-case Lambda"},
   {Symbol::mu, "Lower-case Mu"},
   {Symbol::nu, "Lower-case Nu"},
   {Symbol::pi, "Lower-case Pi"},
   {Symbol::rho, "Lower-case Rho"},
   {Symbol::sigma, "Lower-case Sigma"},
   {Symbol::phi, "Lower-case Phi"},
   {Symbol::psi, "Lower-case Psi"},
   {Symbol::omega, "Lower-case Omega"}
};

const std::map<LogLevel,Color> Logger::mLevelMap = {
   {LogLevel::INFO,  Color::CYAN_FG_BRIGHT},
   {LogLevel::ALERT, Color::MAGENTA_FG_BRIGHT},
   {LogLevel::WARN,  Color::YELLOW_FG_BRIGHT},
   {LogLevel::ERROR, Color::RED_FG_BRIGHT},
};

const std::string Logger::mAnsiStart = {"\033["};
const std::string Logger::mAnsiEnd = {"m"};
const std::string Logger::mAnsiReset = {"\033[0m"};

Logger::Logger() {
}

void Logger::log(const std::string& msg, const LogLevel& lvl) const {
   auto now = std::chrono::time_point_cast<std::chrono::duration<int64_t,std::ratio<1,1000>>>(std::chrono::system_clock::now());
   std::string timeStr = std::format("{:%Y-%m-%d %H:%M:%S}", now);

   std::ostringstream os;
   os << constructAnsiString(DEFAULT_FG,BOLD) << timeStr 
      << constructAnsiString(mLevelMap.at(lvl),BOLD)<< " | ";

   switch (lvl) {
   case LogLevel::INFO:
      os << "INFO    | "<< mAnsiReset;
      break;
   case LogLevel::WARN:
      os << "WARNING | "<< mAnsiReset;
      break;
   case LogLevel::ALERT:
      os << "ALERT   | "<< mAnsiReset;
      break;
   case LogLevel::ERROR:
      os << "ERROR   | "<< mAnsiReset;
      break;
   }

   os << msg;

   std::cout << os.str() << std::endl;
}

std::string Logger::constructAnsiString(Color col, Style sty) const {
   std::ostringstream os {""};
   if (mStyleMap.at(sty) == "") {
      os << mAnsiStart << mColorMap.at(col) << mAnsiEnd;
   }
   else {
      os << mAnsiStart << mColorMap.at(col) << ";" << mStyleMap.at(sty) << mAnsiEnd;
   }
   return os.str();
}

std::string Logger::constructSymbolString(Symbol sym) const {
   return mSymMap.at(sym);
}

void Logger::terminalTest() const {
   std::ostringstream os {""};

   for (auto color: mColorMap) {
      Color cKey = color.first;
      std::cout << mColorNameMap.at(cKey) << std::endl;
      for (auto style: mStyleMap) {
         Style sKey = style.first;
         os << constructAnsiString(cKey,sKey);
         os << "\t" << mColorNameMap.at(cKey) << " | "
            << mStyleNameMap.at(sKey) << mAnsiReset << std::endl;
         std::cout << os.str();
         os.str("");
         os.clear();
      }
   }
}

void Logger::logLevelTest() const {
   log("Info Test", LogLevel::INFO);
   log("Alert Test", LogLevel::ALERT);
   log("Warning Test", LogLevel::WARN);
   log("Error Test", LogLevel::ERROR);
}

void Logger::symbolTest() const {
   std::ostringstream os {""};

   for (const auto& [key,value]: mSymMap) {
      os << mSymNameMap.at(key) << " | " << value << std::endl;
      std::cout << os.str();

      os.str("");
      os.clear();
   }
}
