// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton interface for Bison LALR(1) parsers in C++

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

/**
 ** \file gen/scratch-code.tab.hpp
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_YY_GEN_SCRATCH_CODE_TAB_HPP_INCLUDED
# define YY_YY_GEN_SCRATCH_CODE_TAB_HPP_INCLUDED
// //                    "%code requires" blocks.
#line 29 "src/scratch-code.ypp" // lalr1.cc:377

	#include <string>
	#include <vector>
	#include <algorithm>
	#include <memory>
	#include <utility>
	#include <typeinfo>
	#include <ast/AST.hpp>
	
	namespace sc { class Driver; }																					//one does not simply    do "class sc::Driver;" (from http://stackoverflow.com/q/2059665)

#line 56 "gen/scratch-code.tab.hpp" // lalr1.cc:377

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>
# include "stack.hh"
# include "location.hh"
#include <typeinfo>
#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
#endif


#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif


namespace yy {
#line 133 "gen/scratch-code.tab.hpp" // lalr1.cc:377



  /// A char[S] buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current state.
  template <size_t S>
  struct variant
  {
    /// Type of *this.
    typedef variant<S> self_type;

    /// Empty construction.
    variant ()
      : yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    variant (const T& t)
      : yytypeid_ (&typeid (T))
    {
      YYASSERT (sizeof (T) <= S);
      new (yyas_<T> ()) T (t);
    }

    /// Destruction, allowed only if empty.
    ~variant ()
    {
      YYASSERT (!yytypeid_);
    }

    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    build ()
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= S);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T;
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    build (const T& t)
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= S);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as ()
    {
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= S);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const
    {
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= S);
      return *yyas_<T> ();
    }

    /// Swap the content with \a other, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsability.
    /// Swapping between built and (possibly) non-built is done with
    /// variant::move ().
    template <typename T>
    void
    swap (self_type& other)
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == *other.yytypeid_);
      std::swap (as<T> (), other.as<T> ());
    }

    /// Move the content of \a other to this.
    ///
    /// Destroys \a other.
    template <typename T>
    void
    move (self_type& other)
    {
      build<T> ();
      swap<T> (other);
      other.destroy<T> ();
    }

    /// Copy the content of \a other to this.
    template <typename T>
    void
    copy (const self_type& other)
    {
      build<T> (other.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
    /// Prohibit blind copies.
    self_type& operator=(const self_type&);
    variant (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ ()
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[S];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };


  /// A Bison parser.
  class ScratchCodeParser
  {
  public:
#ifndef YYSTYPE
    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // "loop control statement"
      char dummy1[sizeof(ast::Lexer::ParsedLoopControlStatement)];

      // "variable type"
      char dummy2[sizeof(ast::Lexer::ParsedVariableType)];

      // conditional
      // conditionalIf
      char dummy3[sizeof(std::shared_ptr<ast::Conditional>)];

      // forLoop
      char dummy4[sizeof(std::shared_ptr<ast::ForLoop>)];

      // functionModifier
      // functionCall
      char dummy5[sizeof(std::shared_ptr<ast::FunctionCall>)];

      // functionDefinition
      char dummy6[sizeof(std::shared_ptr<ast::FunctionDefinition>)];

      // lValue
      char dummy7[sizeof(std::shared_ptr<ast::LValue>)];

      // loopControlStatement
      char dummy8[sizeof(std::shared_ptr<ast::LoopControlStatement>)];

      // operation
      char dummy9[sizeof(std::shared_ptr<ast::Operation>)];

      // rValue
      char dummy10[sizeof(std::shared_ptr<ast::RValue>)];

      // "rvalue value"
      char dummy11[sizeof(std::shared_ptr<ast::RValueValue>)];

      // returnStatement
      char dummy12[sizeof(std::shared_ptr<ast::ReturnStatement>)];

      // statement
      char dummy13[sizeof(std::shared_ptr<ast::Statement>)];

      // statements
      // statementsBlockInternal
      // statementsBlock
      char dummy14[sizeof(std::shared_ptr<ast::StatementList>)];

      // valueStandalone
      // value
      char dummy15[sizeof(std::shared_ptr<ast::Value>)];

      // forLoopHeader
      // functionCallParameters
      // functionCallParametersMore
      char dummy16[sizeof(std::shared_ptr<ast::ValueList>)];

      // localVariableDefinition
      // functionDefinitionParameter
      char dummy17[sizeof(std::shared_ptr<ast::VariableDefinition>)];

      // localVariableDefinitionList
      // localVariableDefinitions
      // functionDefinitionParameters
      // functionDefinitionParametersMore
      char dummy18[sizeof(std::shared_ptr<ast::VariableDefinitionList>)];

      // whileLoop
      char dummy19[sizeof(std::shared_ptr<ast::WhileLoop>)];

      // "identifier"
      char dummy20[sizeof(std::string)];
};

    /// Symbol semantic values.
    typedef variant<sizeof(union_type)> semantic_type;
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m);
      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        TOK_END = 0,
        TOK_IF = 258,
        TOK_ELSE = 259,
        TOK_WHILE = 260,
        TOK_FOR = 261,
        TOK_RETURN = 262,
        TOK_ROUND_BRACKET_OPEN = 263,
        TOK_ROUND_BRACKET_CLOSED = 264,
        TOK_SQUARE_BRACKET_OPEN = 265,
        TOK_SQUARE_BRACKET_CLOSED = 266,
        TOK_CURLY_BRACKET_OPEN = 267,
        TOK_CURLY_BRACKET_CLOSED = 268,
        TOK_COMMA = 269,
        TOK_SEMICOLON = 270,
        TOK_COLON = 271,
        TOK_OP_PLUS = 272,
        TOK_OP_MINUS = 273,
        TOK_OP_INCREMENT = 274,
        TOK_OP_DECREMENT = 275,
        TOK_OP_LOGICAL_NOT = 276,
        TOK_OP_BITWISE_NOT = 277,
        TOK_OP_TYPECAST_BOOL = 278,
        TOK_OP_TYPECAST_INT = 279,
        TOK_OP_TYPECAST_REAL = 280,
        TOK_OP_TYPECAST_STRING = 281,
        TOK_OP_MULTIPLY = 282,
        TOK_OP_DIVIDE = 283,
        TOK_OP_MODULO = 284,
        TOK_OP_BITWISE_AND = 285,
        TOK_OP_BITWISE_OR = 286,
        TOK_OP_BITWISE_XOR = 287,
        TOK_OP_BITSHIFT_LEFT = 288,
        TOK_OP_BITSHIFT_RIGHT = 289,
        TOK_OP_LOGICAL_AND = 290,
        TOK_OP_LOGICAL_OR = 291,
        TOK_OP_LESS_THAN = 292,
        TOK_OP_LESS_THAN_OR_EQUAL = 293,
        TOK_OP_GREATER_THAN = 294,
        TOK_OP_GREATER_THAN_OR_EQUAL = 295,
        TOK_OP_EQUAL = 296,
        TOK_OP_NOT_EQUAL = 297,
        TOK_OP_ASSIGNMENT = 298,
        TOK_OP_ADD_ASSIGNMENT = 299,
        TOK_OP_SUBTRACT_ASSIGNMENT = 300,
        TOK_OP_MULTIPLY_ASSIGNMENT = 301,
        TOK_OP_DIVIDE_ASSIGNMENT = 302,
        TOK_OP_MODULO_ASSIGNMENT = 303,
        TOK_OP_BITWISE_AND_ASSIGNMENT = 304,
        TOK_OP_BITWISE_OR_ASSIGNMENT = 305,
        TOK_OP_BITWISE_XOR_ASSIGNMENT = 306,
        TOK_OP_BITSHIFT_LEFT_ASSIGNMENT = 307,
        TOK_OP_BITSHIFT_RIGHT_ASSIGNMENT = 308,
        TOK_IDENTIFIER = 309,
        TOK_VARIABLE_TYPE = 310,
        TOK_LOOP_CONTROL_STATEMENT = 311,
        TOK_RVALUE_VALUE = 312,
        TOK_UNOP_UNARY_PLUS = 314,
        TOK_UNOP_UNARY_MINUS = 315,
        TOK_UNOP_POSTFIX_INCREMENT = 316,
        TOK_UNOP_POSTFIX_DECREMENT = 317
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ();

      /// Copy constructor.
      basic_symbol (const basic_symbol& other);

      /// Constructor for valueless symbols, and symbols from each type.

  basic_symbol (typename Base::kind_type t, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::Lexer::ParsedLoopControlStatement v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::Lexer::ParsedVariableType v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::Conditional> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::ForLoop> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::FunctionCall> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::FunctionDefinition> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::LValue> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::LoopControlStatement> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::Operation> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::RValue> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::RValueValue> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::ReturnStatement> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::Statement> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::StatementList> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::Value> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::ValueList> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::VariableDefinition> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::VariableDefinitionList> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::WhileLoop> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::string v, const location_type& l);


      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    const semantic_type& v,
                    const location_type& l);

      /// Destroy the symbol.
      ~basic_symbol ();

      /// Destroy contents, and record that is empty.
      void clear ();

      /// Whether empty.
      bool empty () const;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

      /// Copy constructor.
      by_type (const by_type& other);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    typedef basic_symbol<by_type> symbol_type;

    // Symbol constructors declarations.
    static inline
    symbol_type
    make_END (const location_type& l);

    static inline
    symbol_type
    make_IF (const location_type& l);

    static inline
    symbol_type
    make_ELSE (const location_type& l);

    static inline
    symbol_type
    make_WHILE (const location_type& l);

    static inline
    symbol_type
    make_FOR (const location_type& l);

    static inline
    symbol_type
    make_RETURN (const location_type& l);

    static inline
    symbol_type
    make_ROUND_BRACKET_OPEN (const location_type& l);

    static inline
    symbol_type
    make_ROUND_BRACKET_CLOSED (const location_type& l);

    static inline
    symbol_type
    make_SQUARE_BRACKET_OPEN (const location_type& l);

    static inline
    symbol_type
    make_SQUARE_BRACKET_CLOSED (const location_type& l);

    static inline
    symbol_type
    make_CURLY_BRACKET_OPEN (const location_type& l);

    static inline
    symbol_type
    make_CURLY_BRACKET_CLOSED (const location_type& l);

    static inline
    symbol_type
    make_COMMA (const location_type& l);

    static inline
    symbol_type
    make_SEMICOLON (const location_type& l);

    static inline
    symbol_type
    make_COLON (const location_type& l);

    static inline
    symbol_type
    make_OP_PLUS (const location_type& l);

    static inline
    symbol_type
    make_OP_MINUS (const location_type& l);

    static inline
    symbol_type
    make_OP_INCREMENT (const location_type& l);

    static inline
    symbol_type
    make_OP_DECREMENT (const location_type& l);

    static inline
    symbol_type
    make_OP_LOGICAL_NOT (const location_type& l);

    static inline
    symbol_type
    make_OP_BITWISE_NOT (const location_type& l);

    static inline
    symbol_type
    make_OP_TYPECAST_BOOL (const location_type& l);

    static inline
    symbol_type
    make_OP_TYPECAST_INT (const location_type& l);

    static inline
    symbol_type
    make_OP_TYPECAST_REAL (const location_type& l);

    static inline
    symbol_type
    make_OP_TYPECAST_STRING (const location_type& l);

    static inline
    symbol_type
    make_OP_MULTIPLY (const location_type& l);

    static inline
    symbol_type
    make_OP_DIVIDE (const location_type& l);

    static inline
    symbol_type
    make_OP_MODULO (const location_type& l);

    static inline
    symbol_type
    make_OP_BITWISE_AND (const location_type& l);

    static inline
    symbol_type
    make_OP_BITWISE_OR (const location_type& l);

    static inline
    symbol_type
    make_OP_BITWISE_XOR (const location_type& l);

    static inline
    symbol_type
    make_OP_BITSHIFT_LEFT (const location_type& l);

    static inline
    symbol_type
    make_OP_BITSHIFT_RIGHT (const location_type& l);

    static inline
    symbol_type
    make_OP_LOGICAL_AND (const location_type& l);

    static inline
    symbol_type
    make_OP_LOGICAL_OR (const location_type& l);

    static inline
    symbol_type
    make_OP_LESS_THAN (const location_type& l);

    static inline
    symbol_type
    make_OP_LESS_THAN_OR_EQUAL (const location_type& l);

    static inline
    symbol_type
    make_OP_GREATER_THAN (const location_type& l);

    static inline
    symbol_type
    make_OP_GREATER_THAN_OR_EQUAL (const location_type& l);

    static inline
    symbol_type
    make_OP_EQUAL (const location_type& l);

    static inline
    symbol_type
    make_OP_NOT_EQUAL (const location_type& l);

    static inline
    symbol_type
    make_OP_ASSIGNMENT (const location_type& l);

    static inline
    symbol_type
    make_OP_ADD_ASSIGNMENT (const location_type& l);

    static inline
    symbol_type
    make_OP_SUBTRACT_ASSIGNMENT (const location_type& l);

    static inline
    symbol_type
    make_OP_MULTIPLY_ASSIGNMENT (const location_type& l);

    static inline
    symbol_type
    make_OP_DIVIDE_ASSIGNMENT (const location_type& l);

    static inline
    symbol_type
    make_OP_MODULO_ASSIGNMENT (const location_type& l);

    static inline
    symbol_type
    make_OP_BITWISE_AND_ASSIGNMENT (const location_type& l);

    static inline
    symbol_type
    make_OP_BITWISE_OR_ASSIGNMENT (const location_type& l);

    static inline
    symbol_type
    make_OP_BITWISE_XOR_ASSIGNMENT (const location_type& l);

    static inline
    symbol_type
    make_OP_BITSHIFT_LEFT_ASSIGNMENT (const location_type& l);

    static inline
    symbol_type
    make_OP_BITSHIFT_RIGHT_ASSIGNMENT (const location_type& l);

    static inline
    symbol_type
    make_IDENTIFIER (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_VARIABLE_TYPE (const ast::Lexer::ParsedVariableType& v, const location_type& l);

    static inline
    symbol_type
    make_LOOP_CONTROL_STATEMENT (const ast::Lexer::ParsedLoopControlStatement& v, const location_type& l);

    static inline
    symbol_type
    make_RVALUE_VALUE (const std::shared_ptr<ast::RValueValue>& v, const location_type& l);

    static inline
    symbol_type
    make_UNOP_UNARY_PLUS (const location_type& l);

    static inline
    symbol_type
    make_UNOP_UNARY_MINUS (const location_type& l);

    static inline
    symbol_type
    make_UNOP_POSTFIX_INCREMENT (const location_type& l);

    static inline
    symbol_type
    make_UNOP_POSTFIX_DECREMENT (const location_type& l);


    /// Build a parser object.
    ScratchCodeParser (sc::Driver& driver_yyarg);
    virtual ~ScratchCodeParser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

  private:
    /// This class is not copyable.
    ScratchCodeParser (const ScratchCodeParser&);
    ScratchCodeParser& operator= (const ScratchCodeParser&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (token_type t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const short int yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const signed char yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const short int yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const unsigned char yytable_[];

  static const short int yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned short int yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    // Debugging.
    int yydebug_;
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state ();

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s);

      /// Copy constructor.
      by_state (const by_state& other);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const;

      /// The state number used to denote an empty symbol.
      enum { empty_state = -1 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, symbol_type& sym);
      /// Assignment, needed by push_back.
      stack_symbol_type& operator= (const stack_symbol_type& that);
    };

    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, stack_symbol_type& s);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, state_type s, symbol_type& sym);

    /// Pop \a n symbols the three stacks.
    void yypop_ (unsigned int n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 834,     ///< Last index in yytable_.
      yynnts_ = 29,  ///< Number of nonterminal symbols.
      yyfinal_ = 3, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 63  ///< Number of tokens.
    };


    // User arguments.
    sc::Driver& driver;
  };

  // Symbol number corresponding to token number t.
  inline
  ScratchCodeParser::token_number_type
  ScratchCodeParser::yytranslate_ (token_type t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62
    };
    const unsigned int user_token_number_max_ = 317;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

  inline
  ScratchCodeParser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  ScratchCodeParser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  ScratchCodeParser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
      switch (other.type_get ())
    {
      case 56: // "loop control statement"
        value.copy< ast::Lexer::ParsedLoopControlStatement > (other.value);
        break;

      case 55: // "variable type"
        value.copy< ast::Lexer::ParsedVariableType > (other.value);
        break;

      case 72: // conditional
      case 73: // conditionalIf
        value.copy< std::shared_ptr<ast::Conditional> > (other.value);
        break;

      case 75: // forLoop
        value.copy< std::shared_ptr<ast::ForLoop> > (other.value);
        break;

      case 82: // functionModifier
      case 88: // functionCall
        value.copy< std::shared_ptr<ast::FunctionCall> > (other.value);
        break;

      case 78: // functionDefinition
        value.copy< std::shared_ptr<ast::FunctionDefinition> > (other.value);
        break;

      case 86: // lValue
        value.copy< std::shared_ptr<ast::LValue> > (other.value);
        break;

      case 77: // loopControlStatement
        value.copy< std::shared_ptr<ast::LoopControlStatement> > (other.value);
        break;

      case 91: // operation
        value.copy< std::shared_ptr<ast::Operation> > (other.value);
        break;

      case 87: // rValue
        value.copy< std::shared_ptr<ast::RValue> > (other.value);
        break;

      case 57: // "rvalue value"
        value.copy< std::shared_ptr<ast::RValueValue> > (other.value);
        break;

      case 83: // returnStatement
        value.copy< std::shared_ptr<ast::ReturnStatement> > (other.value);
        break;

      case 65: // statement
        value.copy< std::shared_ptr<ast::Statement> > (other.value);
        break;

      case 66: // statements
      case 67: // statementsBlockInternal
      case 68: // statementsBlock
        value.copy< std::shared_ptr<ast::StatementList> > (other.value);
        break;

      case 84: // valueStandalone
      case 85: // value
        value.copy< std::shared_ptr<ast::Value> > (other.value);
        break;

      case 74: // forLoopHeader
      case 89: // functionCallParameters
      case 90: // functionCallParametersMore
        value.copy< std::shared_ptr<ast::ValueList> > (other.value);
        break;

      case 71: // localVariableDefinition
      case 81: // functionDefinitionParameter
        value.copy< std::shared_ptr<ast::VariableDefinition> > (other.value);
        break;

      case 69: // localVariableDefinitionList
      case 70: // localVariableDefinitions
      case 79: // functionDefinitionParameters
      case 80: // functionDefinitionParametersMore
        value.copy< std::shared_ptr<ast::VariableDefinitionList> > (other.value);
        break;

      case 76: // whileLoop
        value.copy< std::shared_ptr<ast::WhileLoop> > (other.value);
        break;

      case 54: // "identifier"
        value.copy< std::string > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  ScratchCodeParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      case 56: // "loop control statement"
        value.copy< ast::Lexer::ParsedLoopControlStatement > (v);
        break;

      case 55: // "variable type"
        value.copy< ast::Lexer::ParsedVariableType > (v);
        break;

      case 72: // conditional
      case 73: // conditionalIf
        value.copy< std::shared_ptr<ast::Conditional> > (v);
        break;

      case 75: // forLoop
        value.copy< std::shared_ptr<ast::ForLoop> > (v);
        break;

      case 82: // functionModifier
      case 88: // functionCall
        value.copy< std::shared_ptr<ast::FunctionCall> > (v);
        break;

      case 78: // functionDefinition
        value.copy< std::shared_ptr<ast::FunctionDefinition> > (v);
        break;

      case 86: // lValue
        value.copy< std::shared_ptr<ast::LValue> > (v);
        break;

      case 77: // loopControlStatement
        value.copy< std::shared_ptr<ast::LoopControlStatement> > (v);
        break;

      case 91: // operation
        value.copy< std::shared_ptr<ast::Operation> > (v);
        break;

      case 87: // rValue
        value.copy< std::shared_ptr<ast::RValue> > (v);
        break;

      case 57: // "rvalue value"
        value.copy< std::shared_ptr<ast::RValueValue> > (v);
        break;

      case 83: // returnStatement
        value.copy< std::shared_ptr<ast::ReturnStatement> > (v);
        break;

      case 65: // statement
        value.copy< std::shared_ptr<ast::Statement> > (v);
        break;

      case 66: // statements
      case 67: // statementsBlockInternal
      case 68: // statementsBlock
        value.copy< std::shared_ptr<ast::StatementList> > (v);
        break;

      case 84: // valueStandalone
      case 85: // value
        value.copy< std::shared_ptr<ast::Value> > (v);
        break;

      case 74: // forLoopHeader
      case 89: // functionCallParameters
      case 90: // functionCallParametersMore
        value.copy< std::shared_ptr<ast::ValueList> > (v);
        break;

      case 71: // localVariableDefinition
      case 81: // functionDefinitionParameter
        value.copy< std::shared_ptr<ast::VariableDefinition> > (v);
        break;

      case 69: // localVariableDefinitionList
      case 70: // localVariableDefinitions
      case 79: // functionDefinitionParameters
      case 80: // functionDefinitionParametersMore
        value.copy< std::shared_ptr<ast::VariableDefinitionList> > (v);
        break;

      case 76: // whileLoop
        value.copy< std::shared_ptr<ast::WhileLoop> > (v);
        break;

      case 54: // "identifier"
        value.copy< std::string > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  ScratchCodeParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  ScratchCodeParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::Lexer::ParsedLoopControlStatement v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  ScratchCodeParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::Lexer::ParsedVariableType v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  ScratchCodeParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::Conditional> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  ScratchCodeParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::ForLoop> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  ScratchCodeParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::FunctionCall> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  ScratchCodeParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::FunctionDefinition> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  ScratchCodeParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::LValue> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  ScratchCodeParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::LoopControlStatement> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  ScratchCodeParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::Operation> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  ScratchCodeParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::RValue> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  ScratchCodeParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::RValueValue> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  ScratchCodeParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::ReturnStatement> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  ScratchCodeParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::Statement> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  ScratchCodeParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::StatementList> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  ScratchCodeParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::Value> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  ScratchCodeParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::ValueList> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  ScratchCodeParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::VariableDefinition> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  ScratchCodeParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::VariableDefinitionList> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  ScratchCodeParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::WhileLoop> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  ScratchCodeParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  inline
  ScratchCodeParser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  ScratchCodeParser::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 56: // "loop control statement"
        value.template destroy< ast::Lexer::ParsedLoopControlStatement > ();
        break;

      case 55: // "variable type"
        value.template destroy< ast::Lexer::ParsedVariableType > ();
        break;

      case 72: // conditional
      case 73: // conditionalIf
        value.template destroy< std::shared_ptr<ast::Conditional> > ();
        break;

      case 75: // forLoop
        value.template destroy< std::shared_ptr<ast::ForLoop> > ();
        break;

      case 82: // functionModifier
      case 88: // functionCall
        value.template destroy< std::shared_ptr<ast::FunctionCall> > ();
        break;

      case 78: // functionDefinition
        value.template destroy< std::shared_ptr<ast::FunctionDefinition> > ();
        break;

      case 86: // lValue
        value.template destroy< std::shared_ptr<ast::LValue> > ();
        break;

      case 77: // loopControlStatement
        value.template destroy< std::shared_ptr<ast::LoopControlStatement> > ();
        break;

      case 91: // operation
        value.template destroy< std::shared_ptr<ast::Operation> > ();
        break;

      case 87: // rValue
        value.template destroy< std::shared_ptr<ast::RValue> > ();
        break;

      case 57: // "rvalue value"
        value.template destroy< std::shared_ptr<ast::RValueValue> > ();
        break;

      case 83: // returnStatement
        value.template destroy< std::shared_ptr<ast::ReturnStatement> > ();
        break;

      case 65: // statement
        value.template destroy< std::shared_ptr<ast::Statement> > ();
        break;

      case 66: // statements
      case 67: // statementsBlockInternal
      case 68: // statementsBlock
        value.template destroy< std::shared_ptr<ast::StatementList> > ();
        break;

      case 84: // valueStandalone
      case 85: // value
        value.template destroy< std::shared_ptr<ast::Value> > ();
        break;

      case 74: // forLoopHeader
      case 89: // functionCallParameters
      case 90: // functionCallParametersMore
        value.template destroy< std::shared_ptr<ast::ValueList> > ();
        break;

      case 71: // localVariableDefinition
      case 81: // functionDefinitionParameter
        value.template destroy< std::shared_ptr<ast::VariableDefinition> > ();
        break;

      case 69: // localVariableDefinitionList
      case 70: // localVariableDefinitions
      case 79: // functionDefinitionParameters
      case 80: // functionDefinitionParametersMore
        value.template destroy< std::shared_ptr<ast::VariableDefinitionList> > ();
        break;

      case 76: // whileLoop
        value.template destroy< std::shared_ptr<ast::WhileLoop> > ();
        break;

      case 54: // "identifier"
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  ScratchCodeParser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  ScratchCodeParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 56: // "loop control statement"
        value.move< ast::Lexer::ParsedLoopControlStatement > (s.value);
        break;

      case 55: // "variable type"
        value.move< ast::Lexer::ParsedVariableType > (s.value);
        break;

      case 72: // conditional
      case 73: // conditionalIf
        value.move< std::shared_ptr<ast::Conditional> > (s.value);
        break;

      case 75: // forLoop
        value.move< std::shared_ptr<ast::ForLoop> > (s.value);
        break;

      case 82: // functionModifier
      case 88: // functionCall
        value.move< std::shared_ptr<ast::FunctionCall> > (s.value);
        break;

      case 78: // functionDefinition
        value.move< std::shared_ptr<ast::FunctionDefinition> > (s.value);
        break;

      case 86: // lValue
        value.move< std::shared_ptr<ast::LValue> > (s.value);
        break;

      case 77: // loopControlStatement
        value.move< std::shared_ptr<ast::LoopControlStatement> > (s.value);
        break;

      case 91: // operation
        value.move< std::shared_ptr<ast::Operation> > (s.value);
        break;

      case 87: // rValue
        value.move< std::shared_ptr<ast::RValue> > (s.value);
        break;

      case 57: // "rvalue value"
        value.move< std::shared_ptr<ast::RValueValue> > (s.value);
        break;

      case 83: // returnStatement
        value.move< std::shared_ptr<ast::ReturnStatement> > (s.value);
        break;

      case 65: // statement
        value.move< std::shared_ptr<ast::Statement> > (s.value);
        break;

      case 66: // statements
      case 67: // statementsBlockInternal
      case 68: // statementsBlock
        value.move< std::shared_ptr<ast::StatementList> > (s.value);
        break;

      case 84: // valueStandalone
      case 85: // value
        value.move< std::shared_ptr<ast::Value> > (s.value);
        break;

      case 74: // forLoopHeader
      case 89: // functionCallParameters
      case 90: // functionCallParametersMore
        value.move< std::shared_ptr<ast::ValueList> > (s.value);
        break;

      case 71: // localVariableDefinition
      case 81: // functionDefinitionParameter
        value.move< std::shared_ptr<ast::VariableDefinition> > (s.value);
        break;

      case 69: // localVariableDefinitionList
      case 70: // localVariableDefinitions
      case 79: // functionDefinitionParameters
      case 80: // functionDefinitionParametersMore
        value.move< std::shared_ptr<ast::VariableDefinitionList> > (s.value);
        break;

      case 76: // whileLoop
        value.move< std::shared_ptr<ast::WhileLoop> > (s.value);
        break;

      case 54: // "identifier"
        value.move< std::string > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
  ScratchCodeParser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  ScratchCodeParser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  ScratchCodeParser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  ScratchCodeParser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  ScratchCodeParser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  ScratchCodeParser::by_type::type_get () const
  {
    return type;
  }

  inline
  ScratchCodeParser::token_type
  ScratchCodeParser::by_type::token () const
  {
    // YYTOKNUM[NUM] -- (External) token number corresponding to the
    // (internal) symbol number NUM (which must be that of a token).  */
    static
    const unsigned short int
    yytoken_number_[] =
    {
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317
    };
    return static_cast<token_type> (yytoken_number_[type]);
  }
  // Implementation of make_symbol for each symbol type.
  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_END (const location_type& l)
  {
    return symbol_type (token::TOK_END, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_IF (const location_type& l)
  {
    return symbol_type (token::TOK_IF, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_ELSE (const location_type& l)
  {
    return symbol_type (token::TOK_ELSE, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_WHILE (const location_type& l)
  {
    return symbol_type (token::TOK_WHILE, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_FOR (const location_type& l)
  {
    return symbol_type (token::TOK_FOR, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_RETURN (const location_type& l)
  {
    return symbol_type (token::TOK_RETURN, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_ROUND_BRACKET_OPEN (const location_type& l)
  {
    return symbol_type (token::TOK_ROUND_BRACKET_OPEN, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_ROUND_BRACKET_CLOSED (const location_type& l)
  {
    return symbol_type (token::TOK_ROUND_BRACKET_CLOSED, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_SQUARE_BRACKET_OPEN (const location_type& l)
  {
    return symbol_type (token::TOK_SQUARE_BRACKET_OPEN, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_SQUARE_BRACKET_CLOSED (const location_type& l)
  {
    return symbol_type (token::TOK_SQUARE_BRACKET_CLOSED, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_CURLY_BRACKET_OPEN (const location_type& l)
  {
    return symbol_type (token::TOK_CURLY_BRACKET_OPEN, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_CURLY_BRACKET_CLOSED (const location_type& l)
  {
    return symbol_type (token::TOK_CURLY_BRACKET_CLOSED, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_COMMA (const location_type& l)
  {
    return symbol_type (token::TOK_COMMA, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_SEMICOLON (const location_type& l)
  {
    return symbol_type (token::TOK_SEMICOLON, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_COLON (const location_type& l)
  {
    return symbol_type (token::TOK_COLON, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_PLUS (const location_type& l)
  {
    return symbol_type (token::TOK_OP_PLUS, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_MINUS (const location_type& l)
  {
    return symbol_type (token::TOK_OP_MINUS, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_INCREMENT (const location_type& l)
  {
    return symbol_type (token::TOK_OP_INCREMENT, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_DECREMENT (const location_type& l)
  {
    return symbol_type (token::TOK_OP_DECREMENT, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_LOGICAL_NOT (const location_type& l)
  {
    return symbol_type (token::TOK_OP_LOGICAL_NOT, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_BITWISE_NOT (const location_type& l)
  {
    return symbol_type (token::TOK_OP_BITWISE_NOT, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_TYPECAST_BOOL (const location_type& l)
  {
    return symbol_type (token::TOK_OP_TYPECAST_BOOL, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_TYPECAST_INT (const location_type& l)
  {
    return symbol_type (token::TOK_OP_TYPECAST_INT, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_TYPECAST_REAL (const location_type& l)
  {
    return symbol_type (token::TOK_OP_TYPECAST_REAL, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_TYPECAST_STRING (const location_type& l)
  {
    return symbol_type (token::TOK_OP_TYPECAST_STRING, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_MULTIPLY (const location_type& l)
  {
    return symbol_type (token::TOK_OP_MULTIPLY, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_DIVIDE (const location_type& l)
  {
    return symbol_type (token::TOK_OP_DIVIDE, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_MODULO (const location_type& l)
  {
    return symbol_type (token::TOK_OP_MODULO, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_BITWISE_AND (const location_type& l)
  {
    return symbol_type (token::TOK_OP_BITWISE_AND, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_BITWISE_OR (const location_type& l)
  {
    return symbol_type (token::TOK_OP_BITWISE_OR, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_BITWISE_XOR (const location_type& l)
  {
    return symbol_type (token::TOK_OP_BITWISE_XOR, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_BITSHIFT_LEFT (const location_type& l)
  {
    return symbol_type (token::TOK_OP_BITSHIFT_LEFT, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_BITSHIFT_RIGHT (const location_type& l)
  {
    return symbol_type (token::TOK_OP_BITSHIFT_RIGHT, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_LOGICAL_AND (const location_type& l)
  {
    return symbol_type (token::TOK_OP_LOGICAL_AND, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_LOGICAL_OR (const location_type& l)
  {
    return symbol_type (token::TOK_OP_LOGICAL_OR, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_LESS_THAN (const location_type& l)
  {
    return symbol_type (token::TOK_OP_LESS_THAN, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_LESS_THAN_OR_EQUAL (const location_type& l)
  {
    return symbol_type (token::TOK_OP_LESS_THAN_OR_EQUAL, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_GREATER_THAN (const location_type& l)
  {
    return symbol_type (token::TOK_OP_GREATER_THAN, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_GREATER_THAN_OR_EQUAL (const location_type& l)
  {
    return symbol_type (token::TOK_OP_GREATER_THAN_OR_EQUAL, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_EQUAL (const location_type& l)
  {
    return symbol_type (token::TOK_OP_EQUAL, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_NOT_EQUAL (const location_type& l)
  {
    return symbol_type (token::TOK_OP_NOT_EQUAL, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_ASSIGNMENT (const location_type& l)
  {
    return symbol_type (token::TOK_OP_ASSIGNMENT, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_ADD_ASSIGNMENT (const location_type& l)
  {
    return symbol_type (token::TOK_OP_ADD_ASSIGNMENT, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_SUBTRACT_ASSIGNMENT (const location_type& l)
  {
    return symbol_type (token::TOK_OP_SUBTRACT_ASSIGNMENT, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_MULTIPLY_ASSIGNMENT (const location_type& l)
  {
    return symbol_type (token::TOK_OP_MULTIPLY_ASSIGNMENT, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_DIVIDE_ASSIGNMENT (const location_type& l)
  {
    return symbol_type (token::TOK_OP_DIVIDE_ASSIGNMENT, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_MODULO_ASSIGNMENT (const location_type& l)
  {
    return symbol_type (token::TOK_OP_MODULO_ASSIGNMENT, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_BITWISE_AND_ASSIGNMENT (const location_type& l)
  {
    return symbol_type (token::TOK_OP_BITWISE_AND_ASSIGNMENT, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_BITWISE_OR_ASSIGNMENT (const location_type& l)
  {
    return symbol_type (token::TOK_OP_BITWISE_OR_ASSIGNMENT, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_BITWISE_XOR_ASSIGNMENT (const location_type& l)
  {
    return symbol_type (token::TOK_OP_BITWISE_XOR_ASSIGNMENT, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_BITSHIFT_LEFT_ASSIGNMENT (const location_type& l)
  {
    return symbol_type (token::TOK_OP_BITSHIFT_LEFT_ASSIGNMENT, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_OP_BITSHIFT_RIGHT_ASSIGNMENT (const location_type& l)
  {
    return symbol_type (token::TOK_OP_BITSHIFT_RIGHT_ASSIGNMENT, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_IDENTIFIER (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TOK_IDENTIFIER, v, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_VARIABLE_TYPE (const ast::Lexer::ParsedVariableType& v, const location_type& l)
  {
    return symbol_type (token::TOK_VARIABLE_TYPE, v, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_LOOP_CONTROL_STATEMENT (const ast::Lexer::ParsedLoopControlStatement& v, const location_type& l)
  {
    return symbol_type (token::TOK_LOOP_CONTROL_STATEMENT, v, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_RVALUE_VALUE (const std::shared_ptr<ast::RValueValue>& v, const location_type& l)
  {
    return symbol_type (token::TOK_RVALUE_VALUE, v, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_UNOP_UNARY_PLUS (const location_type& l)
  {
    return symbol_type (token::TOK_UNOP_UNARY_PLUS, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_UNOP_UNARY_MINUS (const location_type& l)
  {
    return symbol_type (token::TOK_UNOP_UNARY_MINUS, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_UNOP_POSTFIX_INCREMENT (const location_type& l)
  {
    return symbol_type (token::TOK_UNOP_POSTFIX_INCREMENT, l);
  }

  ScratchCodeParser::symbol_type
  ScratchCodeParser::make_UNOP_POSTFIX_DECREMENT (const location_type& l)
  {
    return symbol_type (token::TOK_UNOP_POSTFIX_DECREMENT, l);
  }



} // yy
#line 2143 "gen/scratch-code.tab.hpp" // lalr1.cc:377




#endif // !YY_YY_GEN_SCRATCH_CODE_TAB_HPP_INCLUDED
