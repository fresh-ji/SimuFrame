
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

void parse(const char *projdir, char *xml);

int main(int argc, char* argv[]) {
	argv[1] = "C:\\Users\\jihang\\Desktop\\MY\\SimuFrame\\autoGenerate\\";
	argv[2] = "model.xml";
	parse(argv[1], argv[2]);
	return 1;
}

//向fileName文件中替代指定串
void substitute(char *fileName, char *feature, char *target) {
	fstream fs;
	stringstream ss;
	fs.open(fileName);
	ss << fs.rdbuf();
	string strBuffer = ss.str();
	ss.str("");
	fs.close();
	int offset = strBuffer.find(feature, 0);
	while(offset != -1) {
		strBuffer.erase(offset, strlen(feature));
		strBuffer.insert(offset, target);
		offset = strBuffer.find(feature, 0);
	}
	ss << strBuffer;
	ofstream ofs;
	ofs.open(fileName);
	ofs.write(ss.str().c_str(), ss.str().size());
	ofs.close();
}

//向已有文件中写其他文件内容
void transfer(char *destFile, char *srcFile) {
	fstream fs;
	stringstream ss;
	fs.open(srcFile);
	ss << fs.rdbuf();
	string strBuffer = ss.str();
	fs.close();
	ofstream ofs;
	ofs.open(destFile);
	ofs.write(ss.str().c_str(), ss.str().size());
	ofs.close();
}

//一般传入的projdir为autoGenerate的路径
void parse(const char *projdir, char *xml) {

	//char类型的文件路径
	char *dir = new char[256];
	vector<string>topicList;
	vector<string>::iterator it;
	
	//定位输入xml文件位置
	XMLDocument doc;
	strcpy(dir, projdir);
	doc.LoadFile(strcat(dir, xml));
	XMLElement *frame = doc.RootElement();
	XMLElement *manager, *variableDef, *model;
	XMLElement *event;

	//定义Slice输出位置
	FILE *slicefp;
	strcpy(dir, projdir);
	if((slicefp = fopen(strcat(dir, "targetSystem\\sliceDef.ice"), "wb+")) == NULL)
		printf("Can not open SLICE file!\n");

	/**********1.写SLICE文件部分**********/
	//1.1定位slice输出，并写头部
	fprintf(slicefp, "#pragma once\r\n\r\n");
	fprintf(slicefp, "module Demo {\r\n\r\n");

	//1.2声明变量
	variableDef = frame->FirstChildElement("variableDef");
	while(variableDef) {
		fprintf(slicefp, "%s\r\n\r\n", variableDef->GetText());
		variableDef = variableDef->NextSiblingElement("variableDef");
	}
	
	//1.3写eventManager
	fprintf(slicefp, "\tinterface eventManager {\r\n");
	fprintf(slicefp, "\t\tvoid initList();\r\n");
	fprintf(slicefp, "\t\tvoid initProxy(eventManager* proxy);\r\n");
	fprintf(slicefp, "\t\tvoid SENDevent(event ev);\r\n");
	fprintf(slicefp, "\t\tvoid shutdown();\r\n");
	fprintf(slicefp, "\t};\r\n\r\n");

	//1.4写timeManager
	fprintf(slicefp, "\tinterface timeManager {\r\n");
	fprintf(slicefp, "\t\tvoid initList();\r\n");
	fprintf(slicefp, "\t\tvoid initProxy(timeManager* proxy, double startTime, double step);\r\n");
	fprintf(slicefp, "\t\tbool checkList();\r\n");
	fprintf(slicefp, "\t\tvoid confirmTime(string modelName);\r\n");
	fprintf(slicefp, "\t\tvoid SENDtime(double currentTime);\r\n");
	fprintf(slicefp, "\t\tvoid shutdown();\r\n");
	fprintf(slicefp, "\t};\r\n\r\n");
	
	//1.5写model
	model = frame->FirstChildElement("model");
	char *modelName = new char[100];//模型名
	while(model) {
		fprintf(slicefp, "\tinterface %s {\r\n", model->FirstAttribute()->Value());
		fprintf(slicefp, "\t\tvoid initEvent(eventManager* proxy);\r\n");
		fprintf(slicefp, "\t\tvoid initTime(timeManager* proxy, double startTime, double step);\r\n");
		fprintf(slicefp, "\t\tvoid HANDLEevent(event ev);\r\n");
		fprintf(slicefp, "\t\tvoid HANDLEtime(double currentTime);\r\n");
		fprintf(slicefp, "\t\tvoid shutdown();\r\n");
		fprintf(slicefp, "\t};\r\n\r\n");
		model = model->NextSiblingElement("model");
	}
	fprintf(slicefp, "};");

	//1.6编译并修正cpp文件
	fclose(slicefp);
	char* cmd = new char[256];
	strcpy(cmd, "slice2cpp ");
	system(strcat(cmd, dir));//此时dir正好是ice文件，所以不用strcpy
	strcpy(dir, projdir);
	strcat(dir, "setFrame\\Debug\\sliceDef.cpp");
	substitute(dir, "<sliceDef.h>", "\"sliceDef.h\"");
	/**********1.写SLICE文件部分**********/
	


	char *target = new char[2048];
	int modelNumber = 0;//作为计数
	char *tempNumber = new char[4];//作为拷贝
	/************2.写eventManager部分*************/
	//2.1复制eventManager模板
	strcpy(dir, projdir);
	strcpy(cmd, "md ");
	strcat(cmd, dir);
	strcat(cmd, "targetSystem\\eventManager");
	system(cmd);
	strcpy(cmd, "xcopy ");
	strcat(cmd, dir);
	strcat(cmd, "setFrame\\frame\\eventManager ");
	strcat(cmd, dir);
	strcat(cmd, "targetSystem\\eventManager");
	strcat(cmd, " /e/y");
	system(cmd);
	
	//2.2写通信文件到eventManager
	strcpy(dir, projdir);
	strcat(dir, "setFrame\\Debug\\sliceDef.h");
	strcpy(target, projdir);
	strcat(target, "targetSystem\\eventManager\\eventManager\\sliceDef.h");
	transfer(target, dir);
	strcpy(dir, projdir);
	strcat(dir, "setFrame\\Debug\\sliceDef.cpp");
	strcpy(target, projdir);
	strcat(target, "targetSystem\\eventManager\\eventManager\\sliceDef.cpp");
	transfer(target, dir);
	
	//2.3修正managerI.h模板
	//暂无
	
	//2.4修正managerI.cpp模板
	strcpy(dir, projdir);
	strcat(dir, "targetSystem\\eventManager\\eventManager\\managerI.cpp");
	manager = frame->FirstChildElement("manager");

	/***/
	//事件管理器初始化列表
	strcpy(target, "\n");
	model = frame->FirstChildElement("model");
	while(model) {
		itoa(modelNumber, tempNumber, 10);
		strcat(target, "\tVec[");
		strcat(target, tempNumber);
		strcat(target, "].modelName = \"");
		strcat(target, model->FirstAttribute()->Value());
		strcat(target, "\";\n");

		strcat(target, "\tVec[");
		strcat(target, tempNumber);
		strcat(target, "].location = \"sentinel:tcp ");
		strcat(target, model->FirstAttribute()->Next()->Value());
		strcat(target, "\";\n");
		modelNumber++;
		model = model->NextSiblingElement();
	}
	substitute(dir, "$INITIALLISTLOOP$", target);
	/***/
	/***/
	//代理分发初始化列表
	modelNumber = 0;
	strcpy(target, "\n");
	model = frame->FirstChildElement("model");
	while(model) {
		itoa(modelNumber, tempNumber, 10);
		strcat(target, "\t\t");
		strcat(target, model->FirstAttribute()->Value());
		strcat(target, "Prx ");
		strcat(target, model->FirstAttribute()->Value());
		strcat(target, "P = ");
		strcat(target, model->FirstAttribute()->Value());
		strcat(target, "Prx::checkedCast(ic->stringToProxy(Vec[");
		strcat(target, tempNumber);
		strcat(target, "].location));\n");
		strcat(target, "\t\t");
		strcat(target, model->FirstAttribute()->Value());
		strcat(target, "P->initEvent(proxy);\n");
		modelNumber++;
		model = model->NextSiblingElement();
	}
	substitute(dir, "$INITIALPROXYLOOP$", target);
	itoa(modelNumber, tempNumber, 10);
	/***/
	/***/
	//事件路由列表
	strcpy(target, "\n");
	model = frame->FirstChildElement("model");
	while(model) {
		event = model->FirstChildElement("event");
		while(event) {
			strcat(target, "\t\t");
			strcat(target, "if(\"");
			strcat(target, event->FirstAttribute()->Value());
			strcat(target, "\" == ev.name) {\n");
			strcat(target, "\t\t\t");
			strcat(target, "for(int i=0;i<");
			strcat(target, tempNumber);
			strcat(target, ";++i) {\n");
			strcat(target, "\t\t\t\t");
			strcat(target, "if(\"");
			strcat(target, model->FirstAttribute()->Value());
			strcat(target, "\" == Vec[i].modelName) {\n");
			strcat(target, "\t\t\t\t\t");
			strcat(target, model->FirstAttribute()->Value());
			strcat(target, "Prx ");
			strcat(target, model->FirstAttribute()->Value());
			strcat(target, "P = ");
			strcat(target, model->FirstAttribute()->Value());
			strcat(target, "Prx::checkedCast(ic->stringToProxy(Vec[i].location));\n");
			strcat(target, "\t\t\t\t\t");
			strcat(target, model->FirstAttribute()->Value());
			strcat(target, "P->HANDLEevent(ev);\n");
			strcat(target, "\t\t\t\t\tbreak;\n");
			strcat(target, "\t\t\t\t}\n");
			strcat(target, "\t\t\t}\n");
			strcat(target, "\t\t}\n");
			event = event->NextSiblingElement();
		}
		model = model->NextSiblingElement();
	}
	substitute(dir, "$SENDEVENTLOOP$", target);
	/***/
	/***/
	//模型数量
	strcpy(target, tempNumber);
	substitute(dir, "$MODELNUMBER$", target);//模型总数量
	/***/
	
	//2.5修正managerMain.cpp模板
	strcpy(dir, projdir);
	strcat(dir, "targetSystem\\eventManager\\eventManager\\managerMain.cpp");
	manager = frame->FirstChildElement("manager");
	/***/
	//事件管理器位置
	strcpy(target, "tcp ");
	strcat(target, manager->FirstChildElement("eManager")->GetText());
	substitute(dir, "$EVENTMANAGERLOCATION$", target);
	/***/
	/************2.写eventManager部分*************/



	/************3.写timeManager部分*************/
	//3.1复制timeManager模板
	strcpy(dir, projdir);
	strcpy(cmd, "md ");
	strcat(cmd, dir);
	strcat(cmd, "targetSystem\\timeManager");
	system(cmd);
	strcpy(cmd, "xcopy ");
	strcat(cmd, dir);
	strcat(cmd, "setFrame\\frame\\timeManager ");
	strcat(cmd, dir);
	strcat(cmd, "targetSystem\\timeManager");
	strcat(cmd, " /e/y");
	system(cmd);
	
	//3.2写通信文件到timeManager
	strcpy(dir, projdir);
	strcat(dir, "setFrame\\Debug\\sliceDef.h");
	strcpy(target, projdir);
	strcat(target, "targetSystem\\timeManager\\timeManager\\sliceDef.h");
	transfer(target, dir);
	strcpy(dir, projdir);
	strcat(dir, "setFrame\\Debug\\sliceDef.cpp");
	strcpy(target, projdir);
	strcat(target, "targetSystem\\timeManager\\timeManager\\sliceDef.cpp");
	transfer(target, dir);
	
	//3.3修正managerI.h模板
	//暂无
	
	//3.4修正managerI.cpp模板
	strcpy(dir, projdir);
	strcat(dir, "targetSystem\\timeManager\\timeManager\\managerI.cpp");
	manager = frame->FirstChildElement("manager");

	/***/
	//时间管理器初始化列表
	modelNumber = 0;
	strcpy(target, "\n");
	model = frame->FirstChildElement("model");
	while(model) {
		itoa(modelNumber, tempNumber, 10);
		strcat(target, "\tVec[");
		strcat(target, tempNumber);
		strcat(target, "].modelName = \"");
		strcat(target, model->FirstAttribute()->Value());
		strcat(target, "\";\n");

		strcat(target, "\tVec[");
		strcat(target, tempNumber);
		strcat(target, "].isConfirm = false;\n");
		modelNumber++;
		model = model->NextSiblingElement();
	}
	substitute(dir, "$INITIALLISTLOOP$", target);
	/***/
	/***/
	//代理分发初始化列表
	strcpy(target, "\n");
	model = frame->FirstChildElement("model");
	while(model) {
		strcat(target, "\t\t");
		strcat(target, model->FirstAttribute()->Value());
		strcat(target, "Prx ");
		strcat(target, model->FirstAttribute()->Value());
		strcat(target, "P = ");
		strcat(target, model->FirstAttribute()->Value());
		strcat(target, "Prx::checkedCast(ic->stringToProxy(\"sentinel:tcp ");
		strcat(target, model->FirstAttribute()->Next()->Value());
		strcat(target, "\"));\n");
		strcat(target, "\t\t");
		strcat(target, model->FirstAttribute()->Value());
		strcat(target, "P->initTime(proxy, startTime, step);\n");
		model = model->NextSiblingElement();
	}
	substitute(dir, "$INITIALPROXYLOOP$", target);
	/***/
	/***/
	//发送时间列表
	strcpy(target, "\n");
	model = frame->FirstChildElement("model");
	while(model) {
		strcat(target, "\t\t");
		strcat(target, model->FirstAttribute()->Value());
		strcat(target, "Prx ");
		strcat(target, model->FirstAttribute()->Value());
		strcat(target, "P = ");
		strcat(target, model->FirstAttribute()->Value());
		strcat(target, "Prx::checkedCast(ic->stringToProxy(\"sentinel:tcp ");
		strcat(target, model->FirstAttribute()->Next()->Value());
		strcat(target, "\"));\n");
		strcat(target, "\t\t");
		strcat(target, model->FirstAttribute()->Value());
		strcat(target, "P->HANDLEtime(currentTime);\n");
		model = model->NextSiblingElement();
	}
	substitute(dir, "$SENDTIMELOOP$", target);
	/***/
	/***/
	//模型数量
	itoa(modelNumber, tempNumber, 10);
	strcpy(target, tempNumber);
	substitute(dir, "$MODELNUMBER$", target);//模型总数量
	/***/
	
	//3.5修正managerMain.cpp模板
	strcpy(dir, projdir);
	strcat(dir, "targetSystem\\timeManager\\timeManager\\managerMain.cpp");
	manager = frame->FirstChildElement("manager");
	/***/
	//时间管理器位置
	strcpy(target, "tcp ");
	strcat(target, manager->FirstChildElement("tManager")->GetText());
	substitute(dir, "$TIMEMANAGERLOCATION$", target);
	/***/
	/***/
	//起始时间
	strcpy(target, manager->FirstChildElement("sTime")->GetText());
	substitute(dir, "$THESTARTTIME$", target);
	/***/
	/***/
	//步长
	strcpy(target, manager->FirstChildElement("step")->GetText());
	substitute(dir, "$THESTEP$", target);
	/***/
	/************3.写timeManager部分*************/



	/************4.写worker部分******************/
	//4.1复制worker模板，并写入通信文件
	model = frame->FirstChildElement("model");
	while(model) {
		strcpy(dir, projdir);
		strcpy(cmd, "md ");
		strcat(cmd, dir);
		strcat(cmd,"targetSystem\\");
		strcat(cmd, model->FirstAttribute()->Value());
		system(cmd);
		strcpy(cmd, "xcopy ");
		strcat(cmd, dir);
		strcat(cmd, "setFrame\\frame\\worker ");
		strcat(cmd, dir);
		strcat(cmd,"targetSystem\\");
		strcat(cmd, model->FirstAttribute()->Value());
		strcat(cmd, " /e/y");
		system(cmd);

		strcpy(dir, projdir);
		strcat(dir, "setFrame\\Debug\\sliceDef.h");
		strcpy(target, projdir);
		strcat(target, "targetSystem\\");
		strcat(target, model->FirstAttribute()->Value());
		strcat(target, "\\worker\\sliceDef.h");
		transfer(target, dir);
		strcpy(dir, projdir);
		strcat(dir, "setFrame\\Debug\\sliceDef.cpp");
		strcpy(target, projdir);
		strcat(target, "targetSystem\\");
		strcat(target, model->FirstAttribute()->Value());
		strcat(target, "\\worker\\sliceDef.cpp");
		transfer(target, dir);
		
		model = model->NextSiblingElement("model");
	}	

	//4.2修正worker
	model = frame->FirstChildElement("model");
	while(model) {
		//4.2.1修正workerI.h模板
		strcpy(dir, projdir);
		strcat(dir, "targetSystem\\");
		strcat(dir, model->FirstAttribute()->Value());
		strcat(dir, "\\worker\\workerI.h");
		/***/
		//模型名
		strcpy(target, model->FirstAttribute()->Value());
		substitute(dir, "$MODELNAME$", target);
		/***/
		/***/
		//事件处理声明
		strcpy(target, "\n");
		event = model->FirstChildElement("event");
		while(event) {
			strcat(target, "\tvoid ");
			strcat(target, event->GetText());
			strcat(target, "(event ev);\n");
			event = event->NextSiblingElement();
		}
		substitute(dir, "$EVENTPROCESSDECLARE$", target);

		//4.2.2修正workerI.cpp模板
		strcpy(dir, projdir);
		strcat(dir, "targetSystem\\");
		strcat(dir, model->FirstAttribute()->Value());
		strcat(dir, "\\worker\\workerI.cpp");
		/***/
		//模型名
		strcpy(target, model->FirstAttribute()->Value());
		substitute(dir, "$MODELNAME$", target);
		/***/
		/***/
		//事件处理调用
		strcpy(target, "\n");
		event = model->FirstChildElement("event");
		while(event) {
			strcat(target, "\t\tif(\"");
			strcat(target, event->FirstAttribute()->Value());
			strcat(target, "\" == FEL[0].name)\n");
			strcat(target, "\t\t\t");
			strcat(target, event->GetText());
			strcat(target, "(FEL[0]);\n");
			event = event->NextSiblingElement("event");
		}
		substitute(dir, "$EVENTPROCESSCALL$", target);
		/***/
		/***/
		//事件处理
		strcpy(target, "\n");
		event = model->FirstChildElement("event");
		while(event) {
			strcat(target, "void ");
			strcat(target, model->FirstAttribute()->Value());
			strcat(target, "I::");
			strcat(target, event->GetText());
			strcat(target, "(event ev) {\n\n");
			strcat(target, "}\n");
			event = event->NextSiblingElement("event");
		}
		substitute(dir, "$EVENTPROCESS$", target);
		/***/

		//4.2.3修正workerMainI.cpp模板
		strcpy(dir, projdir);
		strcat(dir, "targetSystem\\");
		strcat(dir, model->FirstAttribute()->Value());
		strcat(dir, "\\worker\\workerMain.cpp");
		/***/
		//模型名
		strcpy(target, model->FirstAttribute()->Value());
		substitute(dir, "$MODELNAME$", target);
		/***/
		/***/
		//worker位置
		strcpy(target, "tcp ");
		strcat(target, model->FirstAttribute()->Next()->Value());
		substitute(dir, "$MODELLOCATION$", target);
		/***/

		model = model->NextSiblingElement("model");
	}
	/************4.写worker部分******************/

	//清空sliceDef
	strcpy(dir, projdir);
	strcat(dir, "setFrame\\Debug\\sliceDef.h");
	fstream f1(dir, ios::out|ios::trunc);
	f1.close();

	strcpy(dir, projdir);
	strcat(dir, "setFrame\\Debug\\sliceDef.cpp");
	fstream f2(dir, ios::out|ios::trunc);
	f2.close();

	//内存释放且没有内存泄漏
	delete dir;
	dir = NULL;
	delete modelName;
	modelName = NULL;
	delete cmd;
	cmd = NULL;
	delete target;
	target = NULL;
	delete tempNumber;
	tempNumber = NULL;
}
