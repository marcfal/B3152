<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:output method="html"/>



<xsl:template match="/">
<html>
<head>
<title>
<xsl:value-of select="//titre"/>
<xsl:text> de </xsl:text>
<xsl:value-of select="//auteur"/>
</title>
</head>
<body style="background-color:white;">
<table cellspacing="50" align="center">
<tbody>
<tr>
<td>
<xsl:apply-templates select="//couverture"/>
</td>
<td>
<xsl:apply-templates select="//titre"/>
<xsl:apply-templates select="//auteur"/>
<xsl:apply-templates select="//info_traitements"/>
</td>
</tr>
</tbody>
</table>
<hr/>
<h3>Début du texte:</h3>
<xsl:apply-templates select="//corps"/>
<h3>Fin du texte.</h3>
<hr/>
</body>
</html>
</xsl:template>


<xsl:template match="titre">
<h1 style="text-align:center; color:blue;">
<xsl:value-of select="text()"/>
</h1>
</xsl:template>

<xsl:template match="auteur">
<h2 style="text-align:center; font-style: italic;">
<xsl:value-of select="text()"/>
</h2>
</xsl:template>


<xsl:template match="info_traitements">
<blockquote style="color: darkgreen;">
<xsl:text>But du TP du </xsl:text>
<xsl:value-of select="date/text()"/>
<xsl:text> : </xsl:text>
<xsl:value-of select="but/text()"/>
<br/>
<xsl:text>Auteurs: </xsl:text>
<xsl:value-of select="//unCreateur[1]/text()"/>
<xsl:text> et </xsl:text>
<xsl:value-of select="//unCreateur[2]/text()"/>
<xsl:text>(</xsl:text>
<xsl:value-of select="//NoBinome/text()"/>
<xsl:text>)</xsl:text>
<br/>
<xsl:text>Email du responsable: </xsl:text>
<xsl:value-of select="email/text()"/>
</blockquote>
</xsl:template>

<xsl:template match="image">
<div align="center">
<img>
<xsl:attribute name="src">
<xsl:value-of select="@chemin"/>
</xsl:attribute>
</img>
</div>
</xsl:template>

<xsl:template match="couverture">
<div align="center">
<img>
<xsl:attribute name="src">
<xsl:value-of select="@chemin"/>
</xsl:attribute>
</img>
</div>
</xsl:template>

<xsl:template match="paragraphe">
<p>
<xsl:apply-templates select="phrase[@langue='francais']"/>
<br/>
<xsl:apply-templates select="phrase[@langue='hongrois']"/>
</p>
</xsl:template>


<xsl:template match="paragraphe[@type='dialogue']">
<p>
<table width="90%" align="center">
<tbody>
<tr>

<td width="45%">
<table width="100%" cellpadding="10" border="1">
<tbody>
<xsl:for-each select="phrase[@langue='francais']">
<tr>
<td width="50">

<xsl:choose>
<xsl:when test="@locuteur='Narrateur'">
<div align="center">
<img>
<xsl:attribute name="src">
<xsl:text>images/Narrateur.png</xsl:text>
</xsl:attribute>
</img>
</div>
</xsl:when>
<xsl:otherwise>
<div align="center">
<img>
<xsl:attribute name="src">
<xsl:text>images/LePetitPrince.png</xsl:text>
</xsl:attribute>
</img>
</div>
</xsl:otherwise>
</xsl:choose>

</td>
<td>
<xsl:apply-templates select="."/>
</td>
</tr>
</xsl:for-each>
</tbody>
</table>
</td>

<td width="45%">
<table width="100%" cellpadding="10" border="1">
<tbody>
<xsl:for-each select="phrase[@langue='hongrois']">
<tr>
<td width="50">
<xsl:choose>
<xsl:when test="@locuteur='Narrateur'">
<div align="center">
<img>
<xsl:attribute name="src">
<xsl:text>images/Narrateur.png</xsl:text>
</xsl:attribute>
</img>
</div>
</xsl:when>
<xsl:otherwise>
<div align="center">
<img>
<xsl:attribute name="src">
<xsl:text>images/LePetitPrince.png</xsl:text>
</xsl:attribute>
</img>
</div>
</xsl:otherwise>
</xsl:choose>
</td>
<td>
<xsl:apply-templates select="."/>
</td>
</tr>
</xsl:for-each>
</tbody>
</table>
</td>

</tr>
</tbody>
</table>
</p>
</xsl:template>

<xsl:template match="phrase">
<xsl:choose>
<xsl:when test="contains(.,'mouton')">
<span style="font-size: 24; font-weight: bold;">
<xsl:value-of select="text()"/>
</span>
<img>
<xsl:attribute name="src">
<xsl:text>images/moutonDessin.png</xsl:text>
</xsl:attribute>
</img>
</xsl:when>
<xsl:otherwise>
<xsl:value-of select="text()"/>
</xsl:otherwise>
</xsl:choose>
</xsl:template>


<xsl:template match="phrase[@langue='hongrois']">
<span style="font-style: italic; color: brown;">
<xsl:value-of select="text()"/>
</span>
</xsl:template>


</xsl:stylesheet>


