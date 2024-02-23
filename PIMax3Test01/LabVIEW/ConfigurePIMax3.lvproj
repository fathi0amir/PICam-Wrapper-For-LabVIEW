<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="24008000">
	<Property Name="NI.LV.All.SourceOnly" Type="Bool">true</Property>
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="Backups" Type="Folder">
			<Item Name="Main_Backup00.vi" Type="VI" URL="../Backups/Main_Backup00.vi"/>
			<Item Name="Main_Backup01.vi" Type="VI" URL="../Backups/Main_Backup01.vi"/>
		</Item>
		<Item Name="Main.vi" Type="VI" URL="../Main.vi"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="ConfigPIMax3Two.dll" Type="Document" URL="../../ConfigPIMax3Two/x64/Release/ConfigPIMax3Two.dll"/>
			<Item Name="PIMax3Test01.dll" Type="Document" URL="../../PIMax3Test01/x64/Debug/PIMax3Test01.dll"/>
			<Item Name="PIMax3Test02.dll" Type="Document" URL="../../PIMax3Test01/x64/Debug/PIMax3Test02.dll"/>
			<Item Name="PIMax3Test02.dll" Type="Document" URL="../../../PIMax3Test01/x64/Debug/PIMax3Test02.dll"/>
		</Item>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
