<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="html" version="1.0" indent="yes"/>
  
   <xsl:template match="/">
   	<xsl:apply-templates select="//event"></xsl:apply-templates>
   </xsl:template>
  
  <xsl:template match="event">
	 <ul class="media-list"  id="workaholic">
	 	 <li class="media">
	 	 	<div class="media-body">
	     			 <h4 class="media-heading" >Title</h4>
					 <div id="titre">
						<xsl:value-of select="./title"/>
					 </div>
	     		</div>
	     	</li>
	     	<li class="media">
	 	 	<div class="media-body">
	     			 <h4 class="media-heading">Date</h4>
					 <div id="date">
						 <xsl:text>le </xsl:text>
						 <xsl:value-of select="substring(./dtstart, 7, 2)"/>
						 <xsl:text>-</xsl:text>
						 <xsl:value-of select="substring(./dtstart, 5, 2)"/>
						 <xsl:text>-</xsl:text>
						 <xsl:value-of select="substring(./dtstart, 1, 4)"/>
						  <xsl:text> de </xsl:text>
						  <xsl:value-of select="substring(./dtstart, 10, 2)"/>
						  <xsl:text>h</xsl:text>
						  <xsl:value-of select="substring(./dtstart, 12, 2)"/>
						   <xsl:text> à </xsl:text>
						  <xsl:value-of select="substring(./dtend, 10, 2)"/>
						  <xsl:text>h</xsl:text>
						  <xsl:value-of select="substring(./dtend, 12, 2)"/>
					 </div>
	     		</div>
	     	</li>
	     	<li class="media">
	 	 	<div class="media-body">
	     			 <h4 class="media-heading">Summary</h4>
					 <div id="resume">
						<xsl:value-of select="./summary"/>
					 </div>
	     		</div>
	     	</li>
	     	<li class="media">
	 	 	<div class="media-body">
	     			 <h4 class="media-heading">Url</h4>
					 <div id="url">
						<xsl:value-of select="./url"/>
					 </div>
	     		</div>
	     	</li>
	     	<li class="media">
	 	 	<div class="media-body">
	     			 <h4 class="media-heading">Description</h4>
					 <div id="description">
						<xsl:value-of select="./description"/>
					 </div>
	     		</div>
	     	</li>
	</ul>
  </xsl:template>

</xsl:stylesheet>
