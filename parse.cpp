#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

class ParsePAT {
    public:  	
        const uint8_t syncByte = 0X47;
        uint16_t packetId;
        uint16_t sectionLength;
        uint16_t programNumber;
        uint16_t programMapPid;

	int parsePATInfo();
	virtual int parsePMTInfo() = 0;
};

class ParsePMT : public ParsePAT {
    public:
        uint16_t sectionLengthPMT;
        uint16_t programInfoLength;
        uint8_t streamType;
        uint16_t esInfoLength; 
	
	int parsePMTInfo();
};

int ParsePAT :: parsePATInfo() {
    ifstream parsePAT;
    unsigned char patBuffer[188];
    int index = 0;
    int numberOfProgram;

    parsePAT.open("786MHz.ts", ios::binary);

    if(!parsePAT.is_open()) {
        printf("could not open the TS file\n");
        return 1;
    }

    while(parsePAT.read((char*)patBuffer, 188)) {
        if (patBuffer[0] != syncByte) {
            printf("Packet header does not have sync byte\n");
            return 1;
        }
	
	packetId = (((patBuffer[1] & 0x1f) << 8) | patBuffer[2]);
	
	if (packetId ==0X0000) {
            printf("\n***PROGRAM ASSOCIATION TABLE***\n");
            printf("Packet identifies for PAT:0x%04x\n", packetId);
            sectionLength = ((patBuffer[6] & 0x0f) << 8) | patBuffer[7];
            printf("section length : %d\n", sectionLength);
	    numberOfProgram = (sectionLength - 9) / 4;
	    
	    for(index = 0; index < numberOfProgram ; index ++) {
                programNumber = ((patBuffer[13 + index * 4]  << 8) | patBuffer[14 + index * 4]);
		printf("***PROGRAM DETAILS***\n");
                printf("program number: %x\n", programNumber);

                if(programNumber == 0) {
                    programMapPid = (((patBuffer[15 + index * 4] & 0x1f) << 8) | patBuffer[16 + index * 4]);
                    printf("Network PID: %x\n", programMapPid);
		} else {
                      programMapPid = (((patBuffer[15 + index * 4] & 0x1f) << 8) | patBuffer[16 + index * 4]);
                      printf("program map PID: 0x%02x\n", programMapPid);
	              parsePMTInfo();
		}
	    }
	    exit(0);
	}
    }
    parsePAT.close();
    return 0;
}

int ParsePMT :: parsePMTInfo() {
    ifstream parsePMT;
    unsigned char pmtBuffer[188];
    int index = 0;

    parsePMT.open("786MHz.ts", ios::binary);

    if(!parsePMT.is_open()) {
        printf("could not open the TS file");
        return 1;
    }

    while(parsePMT.read((char*)pmtBuffer, 188)) {
        packetId = (((pmtBuffer[1] & 0x1f) << 8) | pmtBuffer[2]);

	if (programMapPid == packetId) {
		printf("\n***PROGRAM MAP TABLE***\n");
		printf("packet identifies for PMT %x\n", packetId);
                sectionLengthPMT = ((pmtBuffer[6] & 0x0f) << 8) | pmtBuffer[7];
                printf("section length of PMT : %d\n", sectionLengthPMT);
                programNumber = ((pmtBuffer[8] << 8) | pmtBuffer[9]);
                printf("program number : %x\n", programNumber);
                programInfoLength = (((pmtBuffer[15] & 0x0f) << 8) | pmtBuffer[16]);
                printf("program info length : %x\n", programInfoLength);
		int numberOfStream = (sectionLengthPMT - 12) / 5;
                
		parsePMT.seekg(-188, ios::cur);
                parsePMT.seekg(17, ios::cur);

		printf("***STREAM TYPE***\n");

                for(index = 0; index < numberOfStream; index ++) {
                    parsePMT.read((char*)&streamType, 1);
                    switch(streamType) {
                        case 0x00:
                            printf("Reserved\n");
                            break;
			case 0x01:	
			    printf("MPEG-1 video\n");
	                    break;
			case 0x02:
			    printf("MPEG-2 video\n");
                            break;
			case 0x03:	
			    printf("MPEG-1 audio\n");
			    break;
			case 0x04:
		    	    printf("MPEG-2 audio\n");
			    break;
			case 0x05:
			    printf("MPEG-2 tabled data\n");
			    break;
			case 0x06:  	
			    printf("MPEG-2 packetized data - subtitles\n");
			    break;
			case 0x07:
			    printf("PES packets containing private data\n");
			    break;
			case 0x08:
                            printf("DSM CC in a packetized stream\n");
                            break;
			case 0x09:
                            printf("Auxiliary data\n");
                            break;
			case 0x0a:
			    printf("DSM CC multiprotocol encapsulation\n");
		            break;
			case 0x0b:
                            printf("DSM CC U-N messages\n");
                            break;
			case 0x0c:
                            printf("DSM CC stream descriptors\n");
                            break;
			case 0x0d:
                            printf("DSM CC tabled data\n");
                            break;
			case 0x0e:
                            printf("auxiliary data\n");
                            break;
			case 0x0f: 	
			    printf("MPEG-2 lower bit-rate audio\n");
		    	    break;
			case 0x1b:	
			    printf("lower bit-rate video\n");
		    	    break;
			case 0xc3 ... 0xce: 
			    printf("privately defined\n");
                            break;
		        default:
                            printf("Other stream type\n");
		    }
		    esInfoLength = (((pmtBuffer[20] & 0x0f) << 8) | pmtBuffer[21]);
		    if (esInfoLength == 0) {
                        parsePMT.seekg(4, ios::cur);
		    } else {
                        parsePMT.seekg((4 + esInfoLength), ios::cur);
		      }
		}
		break;
	}
    }
    parsePMT.close();
    return 0;
}

int main () {
    ParsePAT *patPtr = new ParsePMT();
    patPtr->parsePATInfo();

    delete patPtr;
    return 0;
}
