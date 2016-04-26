<?xml version="1.0" encoding="UTF-8"?>

<!-- New document created with EditiX at Mon Apr 04 15:04:10 CEST 2016 -->

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

	<xsl:output method="html"/>
	
	<xsl:template match="/">
	<html>
		<head>
			<title>
				<xsl:value-of select="//titre"/>
				<xsl:text> de </xsl:text>
				<xsl:value-of select="//infos/auteur"/>
			</title>
		</head>
		<body style="background-color:white;" >
			<xsl:apply-templates></xsl:apply-templates>
			
<h3>

				Fin du texte.

			</h3>

			<hr/>
		</body>
	</html>
	</xsl:template>
	
	<xsl:template match="lien"/>
	
	
<xsl:template match="entete">
	
	<table cellspacing="50"  align="center" >
	
		<tbody>
	
			<tr>
	
				<td>
	
					<img src="images/prince.png" />
	
				</td>
	
				<td>
	
					<xsl:apply-templates/>
	
				</td>
	
			</tr>
	
		</tbody>
	
	</table>
	
	<hr/>
		<h3>
			Début du texte:
		</h3>
	
</xsl:template>
	
	<xsl:template match="titre">
		<h1 style="text-align:center; color:blue;">
			<xsl:apply-templates/>
		</h1>
	</xsl:template>
	
	<xsl:template match="infos/auteur">
		<h2 style="text-align:center; font-style:italic;">
			<xsl:apply-templates/>
		</h2>
	</xsl:template>
	
	<xsl:template match="infos" name="infos">
	<xsl:apply-templates select="//infos/titre"/>
	<xsl:apply-templates select="//infos/auteur"/>
		<blockquote  style="color :darkgreen;" >
			<xsl:text>But du TP du </xsl:text>
			<xsl:value-of select="//date"/>
			<xsl:text> : </xsl:text>
			<xsl:value-of select="//but"/>
			<br/>
			<xsl:text>Auteurs : </xsl:text>
			<xsl:value-of select="(//mise_en_forme_par/auteur)[1]"/>
			<xsl:text> ( </xsl:text>
			<xsl:value-of select="(//mise_en_forme_par/auteur)[1]/@NoBinome"/>
			<xsl:text> ) </xsl:text>
			<xsl:for-each select="//mise_en_forme_par/auteur[position()>1]">
				<xsl:text> et </xsl:text>
				<xsl:value-of select="//mise_en_forme_par/auteur[position()>1]"/>
				<xsl:text> ( </xsl:text>
				<xsl:value-of select="//mise_en_forme_par/auteur[position()>1]/@NoBinome"/>
				<xsl:text> ) </xsl:text>
			</xsl:for-each>
			<br/>
			<xsl:text>Email du responsable : </xsl:text>
			<xsl:value-of select="//email"/>
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
	
	<xsl:template match="paragr">
		<p>
			<xsl:apply-templates/>
		</p>
	</xsl:template>
	
	<xsl:template match="paragr[@type='narration']/phrase[@langue='hu'][position()=1]">
		<br/>
		<phrase style="color:brown;  font-style:italic;">
			<xsl:apply-templates/>
		</phrase>
	</xsl:template>
	
	<xsl:template match="paragr[@type='narration']/phrase[@langue='hu'][position()>1]">
		<phrase style="color:brown;  font-style:italic;">
			<xsl:apply-templates/>
		</phrase>
	</xsl:template>
	
	<xsl:template match="paragr[@type='dialogue']">
		<table width="90%" align="center">
			<tbody>
				<tr>
					<td width = "45%" >
						<table width="100%" cellpadding="10" border="1" >
							<tbody>
								<xsl:apply-templates select="descendant-or-self::phrase[@langue='fr']"/>
							</tbody>
						</table>
					</td>
					<td>
					</td>
					<td width ="45%" >
						<table width="100%" cellpadding="10" border="1" >
							<tbody>
								<xsl:apply-templates select="descendant-or-self::phrase[@langue='hu']"/>
							</tbody>
						</table>
					</td>
					
				</tr>
			</tbody>
			
		</table>
	</xsl:template>
	
	<xsl:template match="paragr[@type='dialogue']/phrase[@langue='fr']">
		<tr>
			<td width="50" >
				
 <img src="images/{@locuteur}.png"/>
			</td>
			
			<td>
				<span >
					<xsl:apply-templates/>
				</span>
			
			</td>
		</tr>
		
	</xsl:template>
	
	<xsl:template match="paragr[@type='dialogue']/phrase[@langue='fr' and contains(., 'mouton')]">
		<tr>
			<td width="50" >
				
 <img src="images/{@locuteur}.png"/>
			</td>
			
			<td>
				<span style="font-size:24; font-weight:bold;" >
					<xsl:apply-templates/>
					<img src="images/moutonDessin.png"/>
				</span>
			
			</td>
		</tr>
		
	</xsl:template>
	
	
	<xsl:template match="paragr[@type='dialogue']/phrase[@langue='hu']">
		<tr>
			<td width="50" >
				

 <img src="images/{@locuteur}.png"/>
			</td>
			
			<td>
				<span style="font-size:italic; color:brown;" >
					<xsl:apply-templates/>
				</span>
			
			</td>
		</tr>
	</xsl:template>
	
	


</xsl:stylesheet>


