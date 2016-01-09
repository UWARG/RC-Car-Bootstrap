#!/bin/bash -x

#
# Generated - do not edit!
#

# Macros
TOP=`pwd`
CND_CONF=default
CND_DISTDIR=dist
TMPDIR=build/${CND_CONF}/${IMAGE_TYPE}/tmp-packaging
TMPDIRNAME=tmp-packaging
<<<<<<< HEAD
OUTPUT_PATH=dist/${CND_CONF}/${IMAGE_TYPE}/RC-Car-Bootstrap.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
OUTPUT_BASENAME=RC-Car-Bootstrap.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
PACKAGE_TOP_DIR=rc-car-bootstrap/
=======
OUTPUT_PATH=dist/${CND_CONF}/${IMAGE_TYPE}/RC-Car-Bootstrap-Competition.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
OUTPUT_BASENAME=RC-Car-Bootstrap-Competition.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
PACKAGE_TOP_DIR=rc-car-bootstrap-competition/
>>>>>>> abb0cf7cda997dddb3dcb17354f80584db0cc025

# Functions
function checkReturnCode
{
    rc=$?
    if [ $rc != 0 ]
    then
        exit $rc
    fi
}
function makeDirectory
# $1 directory path
# $2 permission (optional)
{
    mkdir -p "$1"
    checkReturnCode
    if [ "$2" != "" ]
    then
      chmod $2 "$1"
      checkReturnCode
    fi
}
function copyFileToTmpDir
# $1 from-file path
# $2 to-file path
# $3 permission
{
    cp "$1" "$2"
    checkReturnCode
    if [ "$3" != "" ]
    then
        chmod $3 "$2"
        checkReturnCode
    fi
}

# Setup
cd "${TOP}"
mkdir -p ${CND_DISTDIR}/${CND_CONF}/package
rm -rf ${TMPDIR}
mkdir -p ${TMPDIR}

# Copy files and create directories and links
cd "${TOP}"
<<<<<<< HEAD
makeDirectory ${TMPDIR}/rc-car-bootstrap/bin
=======
makeDirectory ${TMPDIR}/rc-car-bootstrap-competition/bin
>>>>>>> abb0cf7cda997dddb3dcb17354f80584db0cc025
copyFileToTmpDir "${OUTPUT_PATH}" "${TMPDIR}/${PACKAGE_TOP_DIR}bin/${OUTPUT_BASENAME}" 0755


# Generate tar file
cd "${TOP}"
<<<<<<< HEAD
rm -f ${CND_DISTDIR}/${CND_CONF}/package/rc-car-bootstrap.tar
cd ${TMPDIR}
tar -vcf ../../../../${CND_DISTDIR}/${CND_CONF}/package/rc-car-bootstrap.tar *
=======
rm -f ${CND_DISTDIR}/${CND_CONF}/package/rc-car-bootstrap-competition.tar
cd ${TMPDIR}
tar -vcf ../../../../${CND_DISTDIR}/${CND_CONF}/package/rc-car-bootstrap-competition.tar *
>>>>>>> abb0cf7cda997dddb3dcb17354f80584db0cc025
checkReturnCode

# Cleanup
cd "${TOP}"
rm -rf ${TMPDIR}
