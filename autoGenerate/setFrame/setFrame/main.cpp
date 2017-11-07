
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

//��fileName�ļ������ָ����
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

//�������ļ���д�����ļ�����
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

//һ�㴫���projdirΪautoGenerate��·��
void parse(const char *projdir, char *xml) {

	//char���͵��ļ�·��
	char *dir = new char[256];
	vector<string>topicList;
	vector<string>::iterator it;
	
	//��λ����xml�ļ�λ��
	XMLDocument doc;
	strcpy(dir, projdir);
	doc.LoadFile(strcat(dir, xml));
	XMLElement *frame = doc.RootElement();
	XMLElement *manager, *variableDef, *model;
	XMLElement *event;

	//����Slice���λ��
	FILE *slicefp;
	strcpy(dir, projdir);
	if((slicefp = fopen(strcat(dir, "targetSystem\\sliceDef.ice"), "wb+")) == NULL)
		printf("Can not open SLICE file!\n");

	/**********1.дSLICE�ļ�����**********/
	//1.1��λslice�������дͷ��
	fprintf(slicefp, "#pragma once\r\n\r\n");
	fprintf(slicefp, "module Demo {\r\n\r\n");

	//1.2��������
	variableDef = frame->FirstChildElement("variableDef");
	while(variableDef) {
		fprintf(slicefp, "%s\r\n\r\n", variableDef->GetText());
		variableDef = variableDef->NextSiblingElement("variableDef");
	}
	
	//1.3дeventManager
	fprintf(slicefp, "\tinterface eventManager {\r\n");
	fprintf(slicefp, "\t\tvoid initList();\r\n");
	fprintf(slicefp, "\t\tvoid initProxy(eventManager* proxy);\r\n");
	fprintf(slicefp, "\t\tvoid SENDevent(event ev);\r\n");
	fprintf(slicefp, "\t\tvoid shutdown();\r\n");
	fprintf(slicefp, "\t};\r\n\r\n");

	//1.4дtimeManager
	fprintf(slicefp, "\tinterface timeManager {\r\n");
	fprintf(slicefp, "\t\tvoid initList();\r\n");
	fprintf(slicefp, "\t\tvoid initProxy(timeManager* proxy, double startTime, double step);\r\n");
	fprintf(slicefp, "\t\tbool checkList();\r\n");
	fprintf(slicefp, "\t\tvoid confirmTime(string modelName);\r\n");
	fprintf(slicefp, "\t\tvoid SENDtime(double currentTime);\r\n");
	fprintf(slicefp, "\t\tvoid shutdown();\r\n");
	fprintf(slicefp, "\t};\r\n\r\n");
	
	//1.5дmodel
	model = frame->FirstChildElement("model");
	char *modelName = new char[100];//ģ����
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

	//1.6���벢����cpp�ļ�
	fclose(slicefp);
	char* cmd = new char[256];
	strcpy(cmd, "slice2cpp ");
	system(strcat(cmd, dir));//��ʱdir������ice�ļ������Բ���strcpy
	strcpy(dir, projdir);
	strcat(dir, "setFrame\\Debug\\sliceDef.cpp");
	substitute(dir, "<sliceDef.h>", "\"sliceDef.h\"");
	/**********1.дSLICE�ļ�����**********/
	


	char *target = new char[2048];
	int modelNumber = 0;//��Ϊ����
	char *tempNumber = new char[4];//��Ϊ����
	/************2.дeventManager����*************/
	//2.1����eventManagerģ��
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
	
	//2.2дͨ���ļ���eventManager
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
	
	//2.3����managerI.hģ��
	//����
	
	//2.4����managerI.cppģ��
	strcpy(dir, projdir);
	strcat(dir, "targetSystem\\eventManager\\eventManager\\managerI.cpp");
	manager = frame->FirstChildElement("manager");

	/***/
	//�¼���������ʼ���б�
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
	//����ַ���ʼ���б�
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
	//�¼�·���б�
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
	//ģ������
	strcpy(target, tempNumber);
	substitute(dir, "$MODELNUMBER$", target);//ģ��������
	/***/
	
	//2.5����managerMain.cppģ��
	strcpy(dir, projdir);
	strcat(dir, "targetSystem\\eventManager\\eventManager\\managerMain.cpp");
	manager = frame->FirstChildElement("manager");
	/***/
	//�¼�������λ��
	strcpy(target, "tcp ");
	strcat(target, manager->FirstChildElement("eManager")->GetText());
	substitute(dir, "$EVENTMANAGERLOCATION$", target);
	/***/
	/************2.дeventManager����*************/



	/************3.дtimeManager����*************/
	//3.1����timeManagerģ��
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
	
	//3.2дͨ���ļ���timeManager
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
	
	//3.3����managerI.hģ��
	//����
	
	//3.4����managerI.cppģ��
	strcpy(dir, projdir);
	strcat(dir, "targetSystem\\timeManager\\timeManager\\managerI.cpp");
	manager = frame->FirstChildElement("manager");

	/***/
	//ʱ���������ʼ���б�
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
	//����ַ���ʼ���б�
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
	//����ʱ���б�
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
	//ģ������
	itoa(modelNumber, tempNumber, 10);
	strcpy(target, tempNumber);
	substitute(dir, "$MODELNUMBER$", target);//ģ��������
	/***/
	
	//3.5����managerMain.cppģ��
	strcpy(dir, projdir);
	strcat(dir, "targetSystem\\timeManager\\timeManager\\managerMain.cpp");
	manager = frame->FirstChildElement("manager");
	/***/
	//ʱ�������λ��
	strcpy(target, "tcp ");
	strcat(target, manager->FirstChildElement("tManager")->GetText());
	substitute(dir, "$TIMEMANAGERLOCATION$", target);
	/***/
	/***/
	//��ʼʱ��
	strcpy(target, manager->FirstChildElement("sTime")->GetText());
	substitute(dir, "$THESTARTTIME$", target);
	/***/
	/***/
	//����
	strcpy(target, manager->FirstChildElement("step")->GetText());
	substitute(dir, "$THESTEP$", target);
	/***/
	/************3.дtimeManager����*************/



	/************4.дworker����******************/
	//4.1����workerģ�壬��д��ͨ���ļ�
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

	//4.2����worker
	model = frame->FirstChildElement("model");
	while(model) {
		//4.2.1����workerI.hģ��
		strcpy(dir, projdir);
		strcat(dir, "targetSystem\\");
		strcat(dir, model->FirstAttribute()->Value());
		strcat(dir, "\\worker\\workerI.h");
		/***/
		//ģ����
		strcpy(target, model->FirstAttribute()->Value());
		substitute(dir, "$MODELNAME$", target);
		/***/
		/***/
		//�¼���������
		strcpy(target, "\n");
		event = model->FirstChildElement("event");
		while(event) {
			strcat(target, "\tvoid ");
			strcat(target, event->GetText());
			strcat(target, "(event ev);\n");
			event = event->NextSiblingElement();
		}
		substitute(dir, "$EVENTPROCESSDECLARE$", target);

		//4.2.2����workerI.cppģ��
		strcpy(dir, projdir);
		strcat(dir, "targetSystem\\");
		strcat(dir, model->FirstAttribute()->Value());
		strcat(dir, "\\worker\\workerI.cpp");
		/***/
		//ģ����
		strcpy(target, model->FirstAttribute()->Value());
		substitute(dir, "$MODELNAME$", target);
		/***/
		/***/
		//�¼��������
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
		//�¼�����
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

		//4.2.3����workerMainI.cppģ��
		strcpy(dir, projdir);
		strcat(dir, "targetSystem\\");
		strcat(dir, model->FirstAttribute()->Value());
		strcat(dir, "\\worker\\workerMain.cpp");
		/***/
		//ģ����
		strcpy(target, model->FirstAttribute()->Value());
		substitute(dir, "$MODELNAME$", target);
		/***/
		/***/
		//workerλ��
		strcpy(target, "tcp ");
		strcat(target, model->FirstAttribute()->Next()->Value());
		substitute(dir, "$MODELLOCATION$", target);
		/***/

		model = model->NextSiblingElement("model");
	}
	/************4.дworker����******************/

	//���sliceDef
	strcpy(dir, projdir);
	strcat(dir, "setFrame\\Debug\\sliceDef.h");
	fstream f1(dir, ios::out|ios::trunc);
	f1.close();

	strcpy(dir, projdir);
	strcat(dir, "setFrame\\Debug\\sliceDef.cpp");
	fstream f2(dir, ios::out|ios::trunc);
	f2.close();

	//�ڴ��ͷ���û���ڴ�й©
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
