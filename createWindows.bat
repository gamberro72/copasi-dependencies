@echo off
SET BASE_DIR=%~dp0
Setlocal EnableDelayedExpansion

IF "%1"=="" (
  SET TO_BE_BUILD=expat raptor clapack SBW libSBML libnuml libSEDML mml qwt qwtplot3d 
) ELSE (
  SET TO_BE_BUILD=%*
)

if "%BUILD_TYPE%"=="" SET BUILD_TYPE=Release
if "%BUILD_TOOL%"=="" SET BUILD_TOOL=nmake

SET BUILD_COMMAND=
SET INSTALL_COMMAND=install

SET CMAKE=cmake -G "NMake Makefiles" %CMAKE_OVERRIDES% -DCMAKE_BUILD_TYPE=%BUILD_TYPE% -DCMAKE_INSTALL_PREFIX=%BASE_DIR%\bin

if not exist %BASE_DIR%\tmp mkdir %BASE_DIR%\tmp
if not exist %BASE_DIR%\bin mkdir %BASE_DIR%\bin
if not exist %BASE_DIR%\bin\include mkdir %BASE_DIR%\bin\include
if not exist %BASE_DIR%\bin\lib mkdir %BASE_DIR%\bin\lib

FOR %%A IN (%TO_BE_BUILD%) DO (
  ECHO Building:  %%A

  IF %%A==clapack (
    REM Build Clapack
    mkdir %BASE_DIR%\tmp\clapack
    cd /d %BASE_DIR%\tmp\clapack
    %CMAKE% -DBUILD_TESTING=OFF %BASE_DIR%\src\clapack
  )

  IF %%A==cppunit (
    REM Build CPP Unit
    mkdir %BASE_DIR%\tmp\cppunit
    cd /d %BASE_DIR%\tmp\cppunit
    %CMAKE% %BASE_DIR%\src\cppunit
  )

  IF %%A==expat (
    REM Build Expat
    mkdir %BASE_DIR%\tmp\expat
    cd /d %BASE_DIR%\tmp\expat
    %CMAKE% -DBUILD_shared=OFF -DBUILD_tests=OFF -DBUILD_tools=OFF -DBUILD_examples=OFF %BASE_DIR%\src\expat
  )

  IF %%A==raptor (
    REM Build Raptor
    mkdir %BASE_DIR%\tmp\raptor
    cd /d %BASE_DIR%\tmp\raptor
    %CMAKE% %BASE_DIR%\src\raptor
  )

  IF %%A==SBW (
    REM Build SBW
    mkdir %BASE_DIR%\tmp\SBW
    cd /d %BASE_DIR%\tmp\SBW
    %CMAKE% -DWITH_BUILD_BROKER=OFF -DWITH_BUILD_SHARED=OFF %BASE_DIR%\src\core
  )

  IF %%A==libSBML (
    REM Build libSBML
    mkdir %BASE_DIR%\tmp\libsbml
    cd /d %BASE_DIR%\tmp\libsbml
    %CMAKE% -DENABLE_COMP=ON -DENABLE_LAYOUT=ON -DENABLE_REQUIREDELEMENTS=OFF -DLIBSBML_USE_LEGACY_MATH=ON -DENABLE_RENDER=ON -DENABLE_COMP=ON -DENABLE_FBC=OFF -DENABLE_SPATIAL=OFF -DENABLE_GROUPS=OFF -DWITH_EXPAT=ON -DWITH_LIBXML=OFF -DLIBSBML_DEPENDENCY_DIR=%BASE_DIR%\bin -DLIBSBML_SKIP_SHARED_LIBRARY=ON -DWITH_BZIP2=OFF -DWITH_ZLIB=OFF -DENABLE_UNIVERSAL=ON %BASE_DIR%/src/libSBML
  )

  IF %%A==libnuml (
    REM build libnuml
    mkdir %BASE_DIR%\tmp\libnuml
    cd /d %BASE_DIR%\tmp\libnuml
    %CMAKE% -DLIBSBML_STATIC=ON -DLIBNUML_SHARED_VERSION=OFF -DLIBNUML_SKIP_SHARED_LIBRARY=ON -DLIBSBML_INCLUDE_DIR=%BASE_DIR%/bin/include/sbml -DLIBSBML_LIBRARY=%BASE_DIR%/bin/lib/libsbml-static.a -DLIBNUML_DEPENDENCY_DIR=%BASE_DIR%/bin -DEXTRA_LIBS=%BASE_DIR%/bin/lib/expat.lib -DWITH_ZLIB=OFF %BASE_DIR%/src/libnuml
  )

  IF %%A==libSEDML (
    REM build libSEDML
    mkdir %BASE_DIR%\tmp\libSEDML
    cd /d %BASE_DIR%\tmp\libSEDML
    %CMAKE% -DLIBSBML_STATIC=ON -DLIBSEDML_SHARED_VERSION=OFF  -DLIBSEDML_SKIP_SHARED_LIBRARY=ON -DLIBSEDML_DEPENDENCY_DIR=%BASE_DIR%/bin -DEXTRA_LIBS=%BASE_DIR%/bin/lib/expat.lib %BASE_DIR%/src/libSEDML
  )

  IF %%A==mml (
    REM mml
    mkdir %BASE_DIR%\tmp\mml
    cd /d %BASE_DIR%\tmp\mml
    %CMAKE% %BASE_DIR%\src\mml
  )

  IF %%A==qwt (
    REM Build QWT
    mkdir %BASE_DIR%\tmp\qwt
    cd /d %BASE_DIR%\tmp\qwt
    %CMAKE% %BASE_DIR%\src\qwt
  )

  IF %%A==qwtplot3d (
    REM Build QWT Plot
    mkdir %BASE_DIR%\tmp\qwtplot3d
    cd /d %BASE_DIR%\tmp\qwtplot3d
    %CMAKE% %BASE_DIR%\src\qwtplot3d-qt4
  )

  %BUILD_TOOL% %BUILD_COMMAND%
  %BUILD_TOOL% %INSTALL_COMMAND%

  cd /d %BASE_DIR%
)

