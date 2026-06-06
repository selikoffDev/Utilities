#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <map>

enum LogLevel {
   INFO,
   WARN,
   ALERT,
   ERROR
};

enum Style {
   BLANK,
   BOLD,
   FAINT,
   ITALIC,
   UNERLINE,
   BLINK,
   HIDDEN,
   STRIKETHROUGH
};

enum Color {
   DEFAULT_FG,
   DEFAULT_BG,

   BLACK_FG,
   BLACK_BG,
   BLACK_FG_BRIGHT,
   BLACK_BG_BRIGHT,

   RED_FG,
   RED_BG,
   RED_FG_BRIGHT,
   RED_BG_BRIGHT,

   GREEN_FG,
   GREEN_BG,
   GREEN_FG_BRIGHT,
   GREEN_BG_BRIGHT,

   YELLOW_FG,
   YELLOW_BG,
   YELLOW_FG_BRIGHT,
   YELLOW_BG_BRIGHT,
   
   BLUE_FG,
   BLUE_BG,
   BLUE_FG_BRIGHT,
   BLUE_BG_BRIGHT,

   MAGENTA_FG,
   MAGENTA_BG,
   MAGENTA_FG_BRIGHT,
   MAGENTA_BG_BRIGHT,

   CYAN_FG,
   CYAN_BG,
   CYAN_FG_BRIGHT,
   CYAN_BG_BRIGHT,

   WHITE_FG,
   WHITE_BG,
   WHITE_FG_BRIGHT,
   WHITE_BG_BRIGHT
};

enum Symbol {
   CHECK,
   X,

   alpha,
   beta,
   gamma,
   delta,
   epsilon,
   zeta,
   eta,
   theta,
   lambda,
   mu,
   nu,
   pi,
   rho,
   sigma,
   phi,
   psi,
   omega,
   DELTA,
   THETA,
   EPSILON,
   PHI,
   PSI,
   OMEGA
};

struct Logger {
   Logger();

   void log(const std::string& msg, const LogLevel& lvl=LogLevel::INFO) const;
   std::string constructAnsiString(Color col, Style sty) const;
   std::string constructSymbolString(Symbol sym) const;

   void terminalTest() const;
   void logLevelTest() const;
   void symbolTest() const;

   static const std::map<Color,std::string> mColorMap;
   static const std::map<Style,std::string> mStyleMap;
   static const std::map<Color,std::string> mColorNameMap;
   static const std::map<Style,std::string> mStyleNameMap;
   static const std::map<Symbol,std::string> mSymMap;
   static const std::map<Symbol,std::string> mSymNameMap;

   static const std::map<LogLevel,Color> mLevelMap;
   static const std::string mAnsiStart; 
   static const std::string mAnsiEnd; 
   static const std::string mAnsiReset; 
};

#endif
