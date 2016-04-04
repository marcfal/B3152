<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="html"/>
  <xsl:template match="/">
    <html>
      <head/>
      <body style="background-color:white;">
        <xsl:apply-templates select="//event[contains(title,'Workaholics')]"/>
      </body>
    </html>
  </xsl:template>
  <xsl:template match="event">
    <ul class="media-list">
      <li class="media">
        <div class="media-body">
          <xsl:value-of select ="title"/>
        </div>
        <div class="media-body">
          <xsl:text>le </xsl:text>
          <xsl:value-of select ="substring(dtstart/text(),7,2)"/>
          <xsl:text>-</xsl:text>
          <xsl:value-of select ="substring(dtstart/text(),5,2)"/>
          <xsl:text>-</xsl:text>
          <xsl:value-of select ="substring(dtstart/text(),1,4)"/>
          <xsl:text> de </xsl:text>
          <xsl:value-of select ="substring(dtstart/text(),10,2)"/>
          <xsl:text>h</xsl:text>
          <xsl:value-of select ="substring(dtstart/text(),12,2)"/>
          <xsl:text> à </xsl:text>
          <xsl:value-of select ="substring(dtend/text(),10,2)"/>
          <xsl:text>h</xsl:text>
          <xsl:value-of select ="substring(dtend/text(),12,2)"/>
        </div>
        <div class="media-body">
          <a>
          <xsl:attribute name="href">
          <xsl:value-of select="url"/>
          </xsl:attribute>
          <xsl:value-of select ="summary"/>
          </a>
        </div>
        <div class="media-body">
          <xsl:value-of select ="url"/>
        </div>
        <div class="media-body">
          <xsl:value-of select ="description"/>
        </div>
      </li>
    </ul>
  </xsl:template>
</xsl:stylesheet>










