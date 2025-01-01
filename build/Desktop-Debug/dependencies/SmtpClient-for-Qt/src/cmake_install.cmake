# Install script for directory: /home/pyarla/dev/cpp/projects/QuizMania/dependencies/SmtpClient-for-Qt/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSmtpMime.so.2.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSmtpMime.so.2"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/pyarla/dev/cpp/projects/QuizMania/build/Desktop-Debug/dependencies/SmtpClient-for-Qt/src/libSmtpMime.so.2.0"
    "/home/pyarla/dev/cpp/projects/QuizMania/build/Desktop-Debug/dependencies/SmtpClient-for-Qt/src/libSmtpMime.so.2"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSmtpMime.so.2.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSmtpMime.so.2"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/pyarla/dev/cpp/projects/QuizMania/build/Desktop-Debug/dependencies/SmtpClient-for-Qt/src/libSmtpMime.so")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/smtpmime" TYPE FILE FILES
    "/home/pyarla/dev/cpp/projects/QuizMania/dependencies/SmtpClient-for-Qt/src/SmtpMime"
    "/home/pyarla/dev/cpp/projects/QuizMania/dependencies/SmtpClient-for-Qt/src/emailaddress.h"
    "/home/pyarla/dev/cpp/projects/QuizMania/dependencies/SmtpClient-for-Qt/src/mimeattachment.h"
    "/home/pyarla/dev/cpp/projects/QuizMania/dependencies/SmtpClient-for-Qt/src/mimefile.h"
    "/home/pyarla/dev/cpp/projects/QuizMania/dependencies/SmtpClient-for-Qt/src/mimehtml.h"
    "/home/pyarla/dev/cpp/projects/QuizMania/dependencies/SmtpClient-for-Qt/src/mimeinlinefile.h"
    "/home/pyarla/dev/cpp/projects/QuizMania/dependencies/SmtpClient-for-Qt/src/mimemessage.h"
    "/home/pyarla/dev/cpp/projects/QuizMania/dependencies/SmtpClient-for-Qt/src/mimepart.h"
    "/home/pyarla/dev/cpp/projects/QuizMania/dependencies/SmtpClient-for-Qt/src/mimetext.h"
    "/home/pyarla/dev/cpp/projects/QuizMania/dependencies/SmtpClient-for-Qt/src/smtpclient.h"
    "/home/pyarla/dev/cpp/projects/QuizMania/dependencies/SmtpClient-for-Qt/src/SmtpMime"
    "/home/pyarla/dev/cpp/projects/QuizMania/dependencies/SmtpClient-for-Qt/src/quotedprintable.h"
    "/home/pyarla/dev/cpp/projects/QuizMania/dependencies/SmtpClient-for-Qt/src/mimemultipart.h"
    "/home/pyarla/dev/cpp/projects/QuizMania/dependencies/SmtpClient-for-Qt/src/smtpmime_global.h"
    "/home/pyarla/dev/cpp/projects/QuizMania/dependencies/SmtpClient-for-Qt/src/mimecontentencoder.h"
    "/home/pyarla/dev/cpp/projects/QuizMania/dependencies/SmtpClient-for-Qt/src/mimebase64encoder.h"
    "/home/pyarla/dev/cpp/projects/QuizMania/dependencies/SmtpClient-for-Qt/src/mimeqpencoder.h"
    "/home/pyarla/dev/cpp/projects/QuizMania/dependencies/SmtpClient-for-Qt/src/mimeqpformatter.h"
    "/home/pyarla/dev/cpp/projects/QuizMania/dependencies/SmtpClient-for-Qt/src/mimebase64formatter.h"
    "/home/pyarla/dev/cpp/projects/QuizMania/dependencies/SmtpClient-for-Qt/src/mimecontentformatter.h"
    "/home/pyarla/dev/cpp/projects/QuizMania/dependencies/SmtpClient-for-Qt/src/mimebytearrayattachment.h"
    )
endif()

