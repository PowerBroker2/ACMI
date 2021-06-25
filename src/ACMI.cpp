#include "ACMI.h"




void acmi::begin()
{
  memset(header,        '\0', sizeof(header));
  memset(frame,         '\0', sizeof(frame));
  memset(extraVals,     '\0', sizeof(extraVals));
  
  memset(fileType,      '\0', sizeof(fileType));
  memset(fileVersion,   '\0', sizeof(fileVersion));
  memset(referenceTime, '\0', sizeof(referenceTime));
  memset(dataSource,    '\0', sizeof(dataSource));
  memset(dataRecorder,  '\0', sizeof(dataRecorder));
  memset(author,        '\0', sizeof(author));
  memset(title,         '\0', sizeof(title));
  memset(comments,      '\0', sizeof(comments));
  memset(latStr,        '\0', sizeof(latStr));
  memset(lonStr,        '\0', sizeof(lonStr));

  year   = 0;
  month  = 0;
  day    = 0;
  hour   = 0;
  min    = 0;
  second = 0;
  refLat = 0;
  refLon = 0;
  
  timeDelta      = 0;
  objectID       = 0;
  memset(objectName, '\0', sizeof(objectName));
  lat            = 0;
  lon            = 0;
  useXY          = false;
  x              = 0;
  y              = 0;
  useOrientation = false;
  pitch          = 0;
  roll           = 0;
  yaw            = 0;
  useHeading     = false;
  heading        = 0;
  altitude       = 0;
  memset(color, '\0', sizeof(color));
  useVals        = false;
}




void acmi::setFileType(const char _fileType[])
{
  if (sizeof(fileType) >= strlen(_fileType) + 1)
    memcpy(fileType, _fileType, strlen(_fileType) + 1);
  else
    memcpy(fileType, _fileType, sizeof(fileType));
}




void acmi::setFileVersion(const char _fileVersion[])
{
  if (sizeof(fileVersion) >= strlen(_fileVersion) + 1)
    memcpy(fileVersion, _fileVersion, strlen(_fileVersion) + 1);
  else
    memcpy(fileVersion, _fileVersion, sizeof(fileVersion));
}




void acmi::setReferenceTime(const int& _year, const int& _month, const int& _day, const int& _hour, const int& _min, const float& _second)
{
  year   = _year;
  month  = _month;
  day    = _day;
  hour   = _hour;
  min    = _min;
  second = _second;
}




void acmi::setDataSource(const char _dataSource[])
{
  if (sizeof(dataSource) >= strlen(_dataSource) + 1)
    memcpy(dataSource, _dataSource, strlen(_dataSource) + 1);
  else
    memcpy(dataSource, _dataSource, sizeof(dataSource));
}




void acmi::setDataRecorder(const char _dataRecorder[])
{
  if (sizeof(dataRecorder) >= strlen(_dataRecorder) + 1)
    memcpy(dataRecorder, _dataRecorder, strlen(_dataRecorder) + 1);
  else
    memcpy(dataRecorder, _dataRecorder, sizeof(dataRecorder));
}




void acmi::setAuthor(const char _author[])
{
  if (sizeof(author) >= strlen(_author) + 1)
    memcpy(author, _author, strlen(_author) + 1);
  else
    memcpy(author, _author, sizeof(author));
}




void acmi::setTitle(const char _title[])
{
  if (sizeof(title) >= strlen(_title) + 1)
    memcpy(title, _title, strlen(_title) + 1);
  else
    memcpy(title, _title, sizeof(title));
}




void acmi::setComments(const char _comments[])
{
  if (sizeof(comments) >= strlen(_comments) + 1)
    memcpy(comments, _comments, strlen(_comments) + 1);
  else
    memcpy(comments, _comments, sizeof(comments));
}




void acmi::setReferenceLongitude(const float& _lat)
{
  refLat = _lat;
}




void acmi::setReferenceLatitude(const float& _lon)
{
  refLon = _lon;
}




void acmi::createHeader()
{
  begin();
  
  char secBuff[15];
  dtostrf(second, 15, 10, secBuff);
  char latBuff[15];
  dtostrf(refLat, 15, 10, latBuff);
  char lonBuff[15];
  dtostrf(refLon, 15, 10, lonBuff);

  sprintf(header, headerTemplate, fileType, fileVersion, year, month, day, hour, min, secBuff, dataSource, dataRecorder, author, title, comments, latBuff, lonBuff);
}




void acmi::setTimeDelta(const float& _timeDelta)
{
  timeDelta = _timeDelta;
}




void acmi::setObjectID(const uint64_t& _objectID)
{
  objectID = _objectID;
}




void acmi::setObjectName(const char _objectName[])
{
  if (sizeof(objectName) >= strlen(_objectName) + 1)
    memcpy(objectName, _objectName, strlen(_objectName) + 1);
  else
    memcpy(objectName, _objectName, sizeof(objectName));
}




void acmi::setPosition(const float& _lat, const float& _lon)
{
  lat = _lat;
  lon = _lon;
}




void acmi::setPositionXY(const float& _x, const float& _y)
{
  useXY = true;
  x = _x;
  y = _y;
}




void acmi::setOrientation(const float& _pitch, const float& _roll, const float& _yaw)
{
  useOrientation = true;
  pitch = _pitch;
  roll  = _roll;
  yaw   = _yaw;
}




void acmi::setHeading(const float& _heading)
{
  useHeading = true;
  heading = _heading;
}




void acmi::setAltitude(const float& _altitude)
{
  altitude = _altitude;
}




void acmi::setColor(const char _color[])
{
  if (sizeof(color) >= strlen(_color) + 1)
    memcpy(color, _color, strlen(_color) + 1);
  else
    memcpy(color, _color, sizeof(color));
}




void acmi::setValue(const char _valueName[], const char _value[])
{
  int nextIndex = strlen(extraVals);
  int nameLen   = strlen(_valueName) + 1;
  int valueLen  = strlen(_value) + 1;

  if ((nextIndex + nameLen + valueLen + 3) <= (int)sizeof(extraVals))
  {
    useVals = true;

    extraVals[nextIndex] = ',';
    nextIndex++;
    
    memcpy(extraVals + nextIndex, _valueName, nameLen);
    nextIndex += nameLen;

    extraVals[nextIndex] = '=';
    nextIndex++;
    
    memcpy(extraVals + nextIndex, _value, valueLen);
  }
}




void acmi::createEntry(char _header[])
{
  int nextIndex = strlen(frame);
}
