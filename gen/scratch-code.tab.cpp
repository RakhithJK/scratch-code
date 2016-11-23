// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "gen/scratch-code.tab.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "scratch-code.tab.hpp"

// User implementation prologue.

#line 51 "gen/scratch-code.tab.cpp" // lalr1.cc:412
// Unqualified %code blocks.
#line 35 "src/scratch-code.ypp" // lalr1.cc:413

	#include "ScratchCodeDriver.hpp"

#line 57 "gen/scratch-code.tab.cpp" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 143 "gen/scratch-code.tab.cpp" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  ScratchCodeParser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  ScratchCodeParser::ScratchCodeParser (ScratchCodeDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  ScratchCodeParser::~ScratchCodeParser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  ScratchCodeParser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  ScratchCodeParser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  ScratchCodeParser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  ScratchCodeParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  ScratchCodeParser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  ScratchCodeParser::symbol_number_type
  ScratchCodeParser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  ScratchCodeParser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  ScratchCodeParser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 24: // "variable type"
        value.move< ast::Lexer::ParsedVariableType > (that.value);
        break;

      case 41: // binaryOperation
        value.move< std::shared_ptr<ast::BinaryOperation> > (that.value);
        break;

      case 35: // conditional
      case 36: // conditionalIf
        value.move< std::shared_ptr<ast::Conditional> > (that.value);
        break;

      case 39: // lValue
        value.move< std::shared_ptr<ast::LValue> > (that.value);
        break;

      case 25: // "rvalue value"
      case 40: // rValueValue
        value.move< std::shared_ptr<ast::RValueValue> > (that.value);
        break;

      case 28: // statement
        value.move< std::shared_ptr<ast::Statement> > (that.value);
        break;

      case 29: // statements
      case 30: // statementsBlockInternal
      case 31: // statementsBlock
        value.move< std::shared_ptr<ast::StatementList> > (that.value);
        break;

      case 37: // valueStandalone
      case 38: // value
        value.move< std::shared_ptr<ast::Value> > (that.value);
        break;

      case 32: // localVariableDefinition
        value.move< std::shared_ptr<ast::VariableDefinition> > (that.value);
        break;

      case 33: // localVariableDefinitions
      case 34: // localVariableDefinitionList
        value.move< std::shared_ptr<ast::VariableDefinitionList> > (that.value);
        break;

      case 23: // "identifier"
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  ScratchCodeParser::stack_symbol_type&
  ScratchCodeParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 24: // "variable type"
        value.copy< ast::Lexer::ParsedVariableType > (that.value);
        break;

      case 41: // binaryOperation
        value.copy< std::shared_ptr<ast::BinaryOperation> > (that.value);
        break;

      case 35: // conditional
      case 36: // conditionalIf
        value.copy< std::shared_ptr<ast::Conditional> > (that.value);
        break;

      case 39: // lValue
        value.copy< std::shared_ptr<ast::LValue> > (that.value);
        break;

      case 25: // "rvalue value"
      case 40: // rValueValue
        value.copy< std::shared_ptr<ast::RValueValue> > (that.value);
        break;

      case 28: // statement
        value.copy< std::shared_ptr<ast::Statement> > (that.value);
        break;

      case 29: // statements
      case 30: // statementsBlockInternal
      case 31: // statementsBlock
        value.copy< std::shared_ptr<ast::StatementList> > (that.value);
        break;

      case 37: // valueStandalone
      case 38: // value
        value.copy< std::shared_ptr<ast::Value> > (that.value);
        break;

      case 32: // localVariableDefinition
        value.copy< std::shared_ptr<ast::VariableDefinition> > (that.value);
        break;

      case 33: // localVariableDefinitions
      case 34: // localVariableDefinitionList
        value.copy< std::shared_ptr<ast::VariableDefinitionList> > (that.value);
        break;

      case 23: // "identifier"
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  ScratchCodeParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  ScratchCodeParser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
            case 23: // "identifier"

#line 75 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::string > ()).name() << " at " << &yysym.value.template as< std::string > (); }
#line 410 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 24: // "variable type"

#line 74 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << ast::Lexer::getParsedVariableTypeString(yysym.value.template as< ast::Lexer::ParsedVariableType > ()); }
#line 417 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 25: // "rvalue value"

#line 75 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::RValueValue> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::RValueValue> > (); }
#line 424 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 28: // statement

#line 75 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::Statement> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::Statement> > (); }
#line 431 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 29: // statements

#line 75 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::StatementList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::StatementList> > (); }
#line 438 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 30: // statementsBlockInternal

#line 75 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::StatementList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::StatementList> > (); }
#line 445 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 31: // statementsBlock

#line 75 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::StatementList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::StatementList> > (); }
#line 452 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 32: // localVariableDefinition

#line 75 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::VariableDefinition> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::VariableDefinition> > (); }
#line 459 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 33: // localVariableDefinitions

#line 75 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::VariableDefinitionList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::VariableDefinitionList> > (); }
#line 466 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 34: // localVariableDefinitionList

#line 75 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::VariableDefinitionList> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::VariableDefinitionList> > (); }
#line 473 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 35: // conditional

#line 75 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::Conditional> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::Conditional> > (); }
#line 480 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 36: // conditionalIf

#line 75 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::Conditional> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::Conditional> > (); }
#line 487 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 37: // valueStandalone

#line 75 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::Value> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::Value> > (); }
#line 494 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 38: // value

#line 75 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::Value> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::Value> > (); }
#line 501 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 39: // lValue

#line 75 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::LValue> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::LValue> > (); }
#line 508 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 40: // rValueValue

#line 75 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::RValueValue> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::RValueValue> > (); }
#line 515 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;

      case 41: // binaryOperation

#line 75 "src/scratch-code.ypp" // lalr1.cc:636
        { yyoutput << typeid(yysym.value.template as< std::shared_ptr<ast::BinaryOperation> > ()).name() << " at " << &yysym.value.template as< std::shared_ptr<ast::BinaryOperation> > (); }
#line 522 "gen/scratch-code.tab.cpp" // lalr1.cc:636
        break;


      default:
        break;
    }
    yyo << ')';
  }
#endif

  inline
  void
  ScratchCodeParser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  ScratchCodeParser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  ScratchCodeParser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  ScratchCodeParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  ScratchCodeParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  ScratchCodeParser::debug_level_type
  ScratchCodeParser::debug_level () const
  {
    return yydebug_;
  }

  void
  ScratchCodeParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline ScratchCodeParser::state_type
  ScratchCodeParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  ScratchCodeParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  ScratchCodeParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  ScratchCodeParser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 23 "src/scratch-code.ypp" // lalr1.cc:741
{
	//initialize the initial location (@$ evaluates to "yyla.location", thus it is not directly associated with my code)
	//"yyla" is in gen/scratch-code.tab.cpp and is a "symbol_type"=instance of "basic_symbol<by_type>" templated class
	//"basic_symbol" class contains member "location" of type "location_type"=instance of "location" class
	//"location" class is in gen/location.hh, has "begin" and "end" members of type "position"
	//"position" class is in gen/position.hh, has "filename" member of type std::string*
	yyla.location.begin.filename = yyla.location.end.filename = driver.getFilenamePointer();
}

#line 645 "gen/scratch-code.tab.cpp" // lalr1.cc:741

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex (driver));
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 24: // "variable type"
        yylhs.value.build< ast::Lexer::ParsedVariableType > ();
        break;

      case 41: // binaryOperation
        yylhs.value.build< std::shared_ptr<ast::BinaryOperation> > ();
        break;

      case 35: // conditional
      case 36: // conditionalIf
        yylhs.value.build< std::shared_ptr<ast::Conditional> > ();
        break;

      case 39: // lValue
        yylhs.value.build< std::shared_ptr<ast::LValue> > ();
        break;

      case 25: // "rvalue value"
      case 40: // rValueValue
        yylhs.value.build< std::shared_ptr<ast::RValueValue> > ();
        break;

      case 28: // statement
        yylhs.value.build< std::shared_ptr<ast::Statement> > ();
        break;

      case 29: // statements
      case 30: // statementsBlockInternal
      case 31: // statementsBlock
        yylhs.value.build< std::shared_ptr<ast::StatementList> > ();
        break;

      case 37: // valueStandalone
      case 38: // value
        yylhs.value.build< std::shared_ptr<ast::Value> > ();
        break;

      case 32: // localVariableDefinition
        yylhs.value.build< std::shared_ptr<ast::VariableDefinition> > ();
        break;

      case 33: // localVariableDefinitions
      case 34: // localVariableDefinitionList
        yylhs.value.build< std::shared_ptr<ast::VariableDefinitionList> > ();
        break;

      case 23: // "identifier"
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 89 "src/scratch-code.ypp" // lalr1.cc:859
    {
		*(driver.parsedStatementList) = *(yystack_[1].value.as< std::shared_ptr<ast::StatementList> > ());
		for(auto stmt : driver.parsedStatementList->getStatements())
			stmt->setParent(driver.parsedStatementList);
	}
#line 809 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 3:
#line 98 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Statement> > () = yystack_[0].value.as< std::shared_ptr<ast::Value> > (); }
#line 815 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 4:
#line 99 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Statement> > () = yystack_[0].value.as< std::shared_ptr<ast::Conditional> > (); }
#line 821 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 5:
#line 102 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::StatementList> > () = std::make_shared<ast::StatementList>(nullptr);
	}
#line 829 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 6:
#line 106 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yystack_[1].value.as< std::shared_ptr<ast::StatementList> > ()->addStatement(yystack_[0].value.as< std::shared_ptr<ast::Statement> > ());
		yylhs.value.as< std::shared_ptr<ast::StatementList> > () = yystack_[1].value.as< std::shared_ptr<ast::StatementList> > ();
	}
#line 838 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 7:
#line 111 "src/scratch-code.ypp" // lalr1.cc:859
    {
		for(auto varDef : yystack_[0].value.as< std::shared_ptr<ast::VariableDefinitionList> > ()->getVarDefs())
			yystack_[1].value.as< std::shared_ptr<ast::StatementList> > ()->addStatement(varDef);
		yylhs.value.as< std::shared_ptr<ast::StatementList> > () = yystack_[1].value.as< std::shared_ptr<ast::StatementList> > ();
	}
#line 848 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 8:
#line 118 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::StatementList> > () = yystack_[1].value.as< std::shared_ptr<ast::StatementList> > ();
	}
#line 856 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 9:
#line 122 "src/scratch-code.ypp" // lalr1.cc:859
    {
		auto stmtBlock = std::make_shared<ast::StatementList>(nullptr);
		stmtBlock->addStatement(yystack_[0].value.as< std::shared_ptr<ast::Statement> > ());
		yylhs.value.as< std::shared_ptr<ast::StatementList> > () = stmtBlock;
	}
#line 866 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 10:
#line 129 "src/scratch-code.ypp" // lalr1.cc:859
    {
		for(auto stmt : yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ()->getStatements())
			stmt->setParent(yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ());
		auto i = driver.variableDefinitions.begin();
		while(i != driver.variableDefinitions.end())
		{
			if((*i)->hasParent<ast::StatementList>(yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ()))
				i = driver.variableDefinitions.erase(i);
			else
				++i;
		}
		yylhs.value.as< std::shared_ptr<ast::StatementList> > () = yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ();
	}
#line 884 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 11:
#line 147 "src/scratch-code.ypp" // lalr1.cc:859
    {
		if(std::find_if(driver.variableDefinitions.begin(), driver.variableDefinitions.end(), [&](auto& varDef) { return (varDef->getName() == yystack_[0].value.as< std::string > ()); }) != driver.variableDefinitions.end())
			throw yy::ScratchCodeParser::syntax_error(yylhs.location, "'" + yystack_[0].value.as< std::string > () + "' is already declared");
		yylhs.value.as< std::shared_ptr<ast::VariableDefinition> > () = std::make_shared<ast::VariableDefinition>(nullptr, ast::Lexer::ParsedVariableType::Invalid, yystack_[0].value.as< std::string > ());
	}
#line 894 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 12:
#line 154 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::VariableDefinitionList> > () = std::make_shared<ast::VariableDefinitionList>(nullptr);
	}
#line 902 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 13:
#line 158 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yystack_[2].value.as< std::shared_ptr<ast::VariableDefinitionList> > ()->addVarDef(yystack_[0].value.as< std::shared_ptr<ast::VariableDefinition> > ());
		yylhs.value.as< std::shared_ptr<ast::VariableDefinitionList> > () = yystack_[2].value.as< std::shared_ptr<ast::VariableDefinitionList> > ();
	}
#line 911 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 14:
#line 164 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yystack_[1].value.as< std::shared_ptr<ast::VariableDefinitionList> > ()->getVarDefs().insert(yystack_[1].value.as< std::shared_ptr<ast::VariableDefinitionList> > ()->getVarDefs().begin(), yystack_[2].value.as< std::shared_ptr<ast::VariableDefinition> > ());
		for(auto varDef : yystack_[1].value.as< std::shared_ptr<ast::VariableDefinitionList> > ()->getVarDefs())
		{
			varDef->setType(yystack_[3].value.as< ast::Lexer::ParsedVariableType > ());
			driver.variableDefinitions.push_back(varDef);
		}
		yylhs.value.as< std::shared_ptr<ast::VariableDefinitionList> > () = yystack_[1].value.as< std::shared_ptr<ast::VariableDefinitionList> > ();
	}
#line 925 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 15:
#line 178 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::Conditional> > () = yystack_[0].value.as< std::shared_ptr<ast::Conditional> > ();
	}
#line 933 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 16:
#line 182 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ()->setParent(yystack_[2].value.as< std::shared_ptr<ast::Conditional> > ());
		yystack_[2].value.as< std::shared_ptr<ast::Conditional> > ()->setAlternativeBody(yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ());
		yylhs.value.as< std::shared_ptr<ast::Conditional> > () = yystack_[2].value.as< std::shared_ptr<ast::Conditional> > ();
	}
#line 943 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 17:
#line 189 "src/scratch-code.ypp" // lalr1.cc:859
    {
		auto newCond = std::make_shared<ast::Conditional>(nullptr);
		yystack_[2].value.as< std::shared_ptr<ast::Value> > ()->setParent(newCond);
		yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ()->setParent(newCond);
		newCond->addCondition(yystack_[2].value.as< std::shared_ptr<ast::Value> > ());
		newCond->addConsequenceBody(yystack_[0].value.as< std::shared_ptr<ast::StatementList> > ());
		yylhs.value.as< std::shared_ptr<ast::Conditional> > () = newCond;
	}
#line 956 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 18:
#line 202 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::Value> > () = yystack_[1].value.as< std::shared_ptr<ast::Value> > ();
	}
#line 964 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 206 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Value> > () = yystack_[0].value.as< std::shared_ptr<ast::LValue> > (); }
#line 970 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 20:
#line 207 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Value> > () = yystack_[0].value.as< std::shared_ptr<ast::RValueValue> > (); }
#line 976 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 21:
#line 208 "src/scratch-code.ypp" // lalr1.cc:859
    { yylhs.value.as< std::shared_ptr<ast::Value> > () = yystack_[0].value.as< std::shared_ptr<ast::BinaryOperation> > (); }
#line 982 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 211 "src/scratch-code.ypp" // lalr1.cc:859
    {
		std::vector<std::shared_ptr<ast::VariableDefinition>>::iterator assocVarDef = std::find_if(driver.variableDefinitions.begin(), driver.variableDefinitions.end(), [&](auto& varDef) { return (varDef->getName() == yystack_[0].value.as< std::string > ()); });
		if(assocVarDef == driver.variableDefinitions.end())
			throw yy::ScratchCodeParser::syntax_error(yylhs.location, "'" + yystack_[0].value.as< std::string > () + "' was not declared in this scope");
		yylhs.value.as< std::shared_ptr<ast::LValue> > () = std::make_shared<ast::LValue>(nullptr, *assocVarDef);
	}
#line 993 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 219 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::RValueValue> > () = yystack_[0].value.as< std::shared_ptr<ast::RValueValue> > ();
	}
#line 1001 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;

  case 24:
#line 224 "src/scratch-code.ypp" // lalr1.cc:859
    {
		yylhs.value.as< std::shared_ptr<ast::BinaryOperation> > () = std::make_shared<ast::BinaryOperation>(nullptr, yystack_[2].value.as< std::shared_ptr<ast::Value> > (), ast::Lexer::ParsedBinaryOperation::Assignment, yystack_[0].value.as< std::shared_ptr<ast::Value> > ());
	}
#line 1009 "gen/scratch-code.tab.cpp" // lalr1.cc:859
    break;


#line 1013 "gen/scratch-code.tab.cpp" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  ScratchCodeParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  ScratchCodeParser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char ScratchCodeParser::yypact_ninf_ = -20;

  const signed char ScratchCodeParser::yytable_ninf_ = -1;

  const signed char
  ScratchCodeParser::yypact_[] =
  {
     -20,     8,     0,   -20,   -20,     9,   -20,    -3,   -20,   -20,
     -20,   -20,    16,   -20,   -12,   -20,   -20,   -20,   -18,   -20,
     -20,     6,   -20,   -18,    -9,    -1,   -20,   -20,   -20,   -20,
      10,     6,    -3,   -20,     3,   -20,   -20,   -20
  };

  const unsigned char
  ScratchCodeParser::yydefact_[] =
  {
       5,     0,     0,     1,     2,     0,    22,     0,    23,     6,
       7,     4,    15,     3,     0,    19,    20,    21,     0,    11,
      12,     0,    18,     0,     0,     0,     5,     9,    10,    16,
      24,     0,     0,    14,     0,    17,    13,     8
  };

  const signed char
  ScratchCodeParser::yypgoto_[] =
  {
     -20,   -20,   -19,    -4,   -20,     2,    -2,   -20,   -20,   -20,
     -20,   -20,    -7,   -20,   -20,   -20
  };

  const signed char
  ScratchCodeParser::yydefgoto_[] =
  {
      -1,     1,     9,     2,    28,    29,    20,    25,    10,    11,
      12,    13,    14,    15,    16,    17
  };

  const unsigned char
  ScratchCodeParser::yytable_[] =
  {
       4,    31,    27,     5,    22,     6,     5,     8,     3,     5,
      23,    24,    27,    23,    32,    33,    30,    37,    18,    26,
      19,    21,    34,     6,     7,     8,     6,     7,     8,     6,
      36,     8,    23,    35
  };

  const unsigned char
  ScratchCodeParser::yycheck_[] =
  {
       0,    10,    21,     3,    16,    23,     3,    25,     0,     3,
      22,    18,    31,    22,    15,    16,    23,    14,     9,    13,
      23,     5,    26,    23,    24,    25,    23,    24,    25,    23,
      32,    25,    22,    31
  };

  const unsigned char
  ScratchCodeParser::yystos_[] =
  {
       0,    27,    29,     0,     0,     3,    23,    24,    25,    28,
      34,    35,    36,    37,    38,    39,    40,    41,     9,    23,
      32,     5,    16,    22,    38,    33,    13,    28,    30,    31,
      38,    10,    15,    16,    29,    31,    32,    14
  };

  const unsigned char
  ScratchCodeParser::yyr1_[] =
  {
       0,    26,    27,    28,    28,    29,    29,    29,    30,    30,
      31,    32,    33,    33,    34,    35,    35,    36,    37,    38,
      38,    38,    39,    40,    41
  };

  const unsigned char
  ScratchCodeParser::yyr2_[] =
  {
       0,     2,     2,     1,     1,     0,     2,     2,     3,     1,
       1,     1,     0,     3,     4,     1,     3,     5,     2,     1,
       1,     1,     1,     1,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const ScratchCodeParser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"if\"", "THEN", "\"else\"",
  "\"while\"", "\"for\"", "\"return\"", "\"(\"", "\")\"", "\"[\"", "\"]\"",
  "\"{\"", "\"}\"", "\",\"", "\";\"", "\"*\"", "\"/\"", "\"%\"", "\"+\"",
  "\"-\"", "\"=\"", "\"identifier\"", "\"variable type\"",
  "\"rvalue value\"", "$accept", "unit", "statement", "statements",
  "statementsBlockInternal", "statementsBlock", "localVariableDefinition",
  "localVariableDefinitions", "localVariableDefinitionList", "conditional",
  "conditionalIf", "valueStandalone", "value", "lValue", "rValueValue",
  "binaryOperation", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  ScratchCodeParser::yyrline_[] =
  {
       0,    88,    88,    98,    99,   101,   105,   110,   117,   121,
     128,   146,   153,   157,   163,   177,   181,   188,   201,   206,
     207,   208,   210,   218,   223
  };

  // Print the state stack on the debug stream.
  void
  ScratchCodeParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  ScratchCodeParser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 1406 "gen/scratch-code.tab.cpp" // lalr1.cc:1167
#line 246 "src/scratch-code.ypp" // lalr1.cc:1168




#include "Main.hpp"

void yy::ScratchCodeParser::error(const location_type& loc, const std::string& message)
{
	driver.handleError(loc, message);
}

