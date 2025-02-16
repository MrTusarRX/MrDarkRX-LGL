#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <dlfcn.h>
#include <stdio.h>
#include "Includes/Logger.h"
#include "Includes/obfuscate.h"
#include "Includes/Utils.h"

#include "KittyMemory/MemoryPatch.h"
#include "Menu.h"

#define targetLibName OBFUSCATE("libil2cpp.so")

#include "Includes/Macros.h"




bool Drone, Guns, Skins, Gloves, Play;

 // void (*gun)(void *instance,int value);
void (*play)(void *instance,int value);
/*   void (*skin)(void *instance,int value);
void (*glove)(void *instance,int value);
void (*dronea)(void *instance,int droneid);
void (*droneb)(void *instance,int droneid);
void (*dronec)(void *instance,int droneid); */





float   LightRadius = 1, PlayerSpeed = 0;

struct My_Patches {
    MemoryPatch Bypass, AntiBan, AntiBanx, NoAds, NoRecord, Opgun, SpeedHack, DarkBule, LigthBule, Pink, Yellow, YRed, Fov, Gravity, Flyme, BERed, BRed, Grenade, Money, Kills, Ammo, Cilp, Time, BotMove, AntiFlash, Ghostmode, BH, Recoil;
} hexPatches;
bool feature1, feature2, feature3, feature4, feature5, feature6, feature7, feature8, feature9, feature10, feature11, feature12, feature13, feature14, feature15, feature16, feature17, feature18, feature19, feature20, feature21, feature22, feature23, feature24, feature25;


float (*old_lightradius)(void *instance);
float lightradius(void *instance) {
    if (instance != NULL && LightRadius > 50) {
        return (float) LightRadius;
    }
    return old_lightradius(instance);
}

/*

void(*old_GameUpdate)(void *instance);
void GameUpdate(void *instance) {
        if (instance != NULL) {
        if (Guns) {
          gun(instance, 1);
   }
if (Skins) {
          skin(instance, 1);
   }
if (Gloves) {
          glove(instance, 1);
   }
   
if (Drone) {
          dronea(instance,1);
          droneb(instance,2);
          dronec(instance,3);
   }
   }
  return old_GameUpdate(instance);
}
*/

void(*old_GameUpdatenew)(void *instance);
void GameUpdatenew(void *instance) {
        if (instance != NULL) {
        if (Play) {
          play(instance, 0);
   
   }
   }
  return old_GameUpdatenew(instance);
}
void (*old_playerspeed)(void *instance);
void playerspeed(void *instance) {
    if (instance != NULL) {
        if (PlayerSpeed >= 40) {
    //if PlayerSpeed is equal to or greater than 1 then it will modify the offset else it will return original value
            *(float *) ((uint32_t) instance + 0xD8) = PlayerSpeed;
        }
    }
    return old_playerspeed(instance);
}






void *hack_thread(void *) {
    LOGI(OBFUSCATE("pthread created"));

    
    do {
        sleep(1);
    } while (!isLibraryLoaded(targetLibName));


    
    LOGI(OBFUSCATE("%s has been loaded"), (const char *) targetLibName);

#if defined(__aarch64__)

#else 
HOOK_LIB("libil2cpp.so", "0x3BB044", lightradius, old_lightradius);
HOOK_LIB("libil2cpp.so", "0x5FF51A0", playerspeed, old_playerspeed);












//Bypassed
//hexPatches.Bypass = MemoryPatch::createWithHex("libUE4.so",0x13C8634,"0201E0E31EFF2FE1");
//hexPatches.AntiBan = MemoryPatch::createWithHex("libUE4.so",0x000000,"0100A0E31EFF2FE1");
hexPatches.AntiBanx = MemoryPatch::createWithHex("libil2cpp.so",0x1B159D8,"0F0702E31EFF2FE1");
hexPatches.NoAds = MemoryPatch::createWithHex("libil2cpp.so",0x176B3A0,"0F0702E31EFF2FE1");
hexPatches.NoRecord = MemoryPatch::createWithHex("libil2cpp.so",0x1A0F2BC,"0F0702E31EFF2FE1");

//Random hacks
hexPatches.Opgun = MemoryPatch::createWithHex("libil2cppso",0x2B9BECC,"270440E31EFF2FE1");
hexPatches.SpeedHack = MemoryPatch::createWithHex("libil2cpp.so",0x9D72A4,"270440E31EFF2FE1");
hexPatches.Fov = MemoryPatch::createWithHex("libil2cpp.so",0x1773CE4,"270440E31EFF2FE1");
hexPatches.AntiFlash = MemoryPatch::createWithHex("libil2cpp.so",0x2986250,"270440E31EFF2FE1");
hexPatches.BotMove = MemoryPatch::createWithHex("libil2cpp.so",0x1A0AD4C,"270440E31EFF2FE1");
hexPatches.Recoil = MemoryPatch::createWithHex("libil2cpp.so",0x1B158E4,"0F0702E31EFF2FE1");

//Cool Mods
hexPatches.Gravity = MemoryPatch::createWithHex("libil2cpp.so",0xD95148,"270440E31EFF2FE1");
hexPatches.Flyme = MemoryPatch::createWithHex("libil2cpp.so",0x2AFD338,"270440E31EFF2FE1");
hexPatches.Ghostmode = MemoryPatch::createWithHex("libUE4.so",0x028da528,"0000A0E31EFF2FE1");

//Unlimted Menu
hexPatches.Grenade = MemoryPatch::createWithHex("libUE4.so",0x292e9f0,"0100A0E31EFF2FE1");
hexPatches.Money = MemoryPatch::createWithHex("libUE4.so",0x0295b988,"0F0702E31EFF2FE1");
hexPatches.Ammo = MemoryPatch::createWithHex("libUE4.so",0x0291c678,"0F0702E31EFF2FE1");
hexPatches.Cilp = MemoryPatch::createWithHex("libUE4.so",0x0291c690,"0F0702E31EFF2FE1E1");
hexPatches.Kills = MemoryPatch::createWithHex("libUE4.so",0x0291168c,"0F0702E31EFF2FE1");
hexPatches.Time = MemoryPatch::createWithHex("libUE4.so",0x028c5db0,"0100A0E31EFF2FE1");


//Body colour
hexPatches.BERed = MemoryPatch::createWithHex("libUE4.so",0x33d8018,"00009643");
hexPatches.BRed = MemoryPatch::createWithHex("libUE4.so",0x33d809c,"00009643");

//Layouts
hexPatches.DarkBule = MemoryPatch::createWithHex("libUE4.so",0x551092c,"0100A0E31EFF2FE1");
hexPatches.LigthBule = MemoryPatch::createWithHex("libUE4.so",0x551092c,"00000000");
hexPatches.Pink = MemoryPatch::createWithHex("libUE4.so",0x5510930,"00000000");
hexPatches.Yellow = MemoryPatch::createWithHex("libUE4.so",0x5510934,"00000000");
hexPatches.YRed = MemoryPatch::createWithHex("libUE4.so",0x5510930,"FA0444E31EFF2FE1");


/*

MSHookFunction((void *)getAbsoluteAddress("libil2cpp.so", 0x35EECD8), (void *) GameUpdate, (void **) &old_GameUpdate);
gun = (void (*)(void *, int)) getAbsoluteAddress(targetLibName, 0x362C144);

skin = (void (*)(void *, int)) getAbsoluteAddress(targetLibName, 0x362D520);
glove = (void (*)(void *, int)) getAbsoluteAddress(targetLibName, 0x362D980);
dronea = (void (*)(void *, int)) getAbsoluteAddress(targetLibName, 0x362D1D4);
droneb = (void (*)(void *, int)) getAbsoluteAddress(targetLibName, 0x362D1D4);
dronec = (void (*)(void *, int)) getAbsoluteAddress(targetLibName, 0x362D1D4);

*/




MSHookFunction((void *)getAbsoluteAddress("libil2cpp.so", 0x270BBA4), (void *) GameUpdatenew, (void **) &old_GameUpdatenew);

play = (void (*)(void *, int)) getAbsoluteAddress(targetLibName, 0x270D764);





    LOGI(OBFUSCATE("Done"));
#endif

    return NULL;
}


extern "C" {


JNIEXPORT jobjectArray
JNICALL
Java_tusar_khan_modmenu_FloatingModMenuService_getFeatureList(JNIEnv *env, jobject context) {
    jobjectArray ret;


    MakeToast(env, context, OBFUSCATE("Modded By MrTusarRX"), Toast::LENGTH_LONG);

    const char *features[] = {
            //Bypass
		    OBFUSCATE("Category_Unlimited"),
		    OBFUSCATE("1_ButtonOnOff_Unlimited Ammo"),		    		    
		    OBFUSCATE("5_ButtonOnOff_On Hit Kill"),
	        OBFUSCATE("4_ButtonOnOff_Unlimited Grenade"),
		  OBFUSCATE("Category_Unlock"),
           OBFUSCATE("90_ButtonOnOff_Unlock All Skins"),
            OBFUSCATE("91_ButtonOnOff_Unlock All Gloves"),
            OBFUSCATE("92_ButtonOnOff_Unlock All Drones"),
            OBFUSCATE("93_ButtonOnOff_Unlock All Guns"), 
		    OBFUSCATE("Category_Player"),
 	 //   OBFUSCATE("Category_Player Speed"), 
		  OBFUSCATE("55_SeekBar_Run Speed_0_100"),
          OBFUSCATE("60_SeekBar_Speed_1_60"), 
       OBFUSCATE("95_ButtonOnOff_Auto Kill (Auto Win)"),
	      OBFUSCATE("0_ButtonOnOff_Unlimited Medikits"),
		  OBFUSCATE("2_ButtonOnOff_Get Level"),		    
		   // OBFUSCATE("Category_Zombie"), 
		//    OBFUSCATE("9_CheckBox_Get Energy"), 
		//    OBFUSCATE("Category_Money"),
	//	    OBFUSCATE("7_CheckBox_Unlimited Gold"),
//		    OBFUSCATE("6_CheckBox_Test Mrp Gold"), 
	     //   OBFUSCATE("8_CheckBox_Unlimited Money"),
		//    OBFUSCATE("0_CheckBox_Unlimited Currency"),
		
		    
		    
            

    };

  
    int Total_Feature = (sizeof features / sizeof features[0]);
    ret = (jobjectArray)
            env->NewObjectArray(Total_Feature, env->FindClass(OBFUSCATE("java/lang/String")),
                                env->NewStringUTF(""));

    for (int i = 0; i < Total_Feature; i++)
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));

    pthread_t ptid;
    pthread_create(&ptid, NULL, antiLeech, NULL);

    return (ret);
}

JNIEXPORT void JNICALL
Java_tusar_khan_modmenu_Preferences_Changes(JNIEnv *env, jclass clazz, jobject obj,
                                        jint featNum, jstring featName, jint value,
                                        jboolean boolean, jstring str) {

    LOGD(OBFUSCATE("Feature name: %d - %s | Value: = %d | Bool: = %d | Text: = %s"), featNum,
         env->GetStringUTFChars(featName, 0), value,
         boolean, str != NULL ? env->GetStringUTFChars(str, 0) : "");



    switch (featNum) {
		case 0:
            feature1 = boolean;
            if (feature1) {
                
                hexPatches.AntiBanx.Modify();
            } else {
                
                hexPatches.AntiBanx.Restore();
            }
            break;
            case 1:
            feature2 = boolean;
            if (feature2) {
                hexPatches.NoAds.Modify();
            } else {
                hexPatches.NoAds.Restore();
            }
            break;
            case 2:
            feature3 = boolean;
            if (feature3) {
                hexPatches.NoRecord.Modify();
            } else {
                hexPatches.NoRecord.Restore();
            }
            break;
            case 3:
            feature4 = boolean;
            if (feature4) {
                hexPatches.Opgun.Modify();
            } else {
                hexPatches.Opgun.Restore();
            }
            break;
            case 4:
            feature5 = boolean;
            if (feature5) {
                hexPatches.Recoil.Modify();
            } else {
                hexPatches.Recoil.Restore();
            }
            break;
            case 5:
            feature6 = boolean;
            if (feature6) {
                hexPatches.Fov.Modify();
            } else {
                hexPatches.Fov.Restore();
            }
            break;
            case 6:
            feature7 = boolean;
            if (feature7) {
                hexPatches.SpeedHack.Modify();
            } else {
                hexPatches.SpeedHack.Restore();
            }
            break;
            case 7:
            feature8 = boolean;
            if (feature8) {
                hexPatches.AntiFlash.Modify();
            } else {
                hexPatches.AntiFlash.Restore();
            }
            break;
            case 8:
            feature9 = boolean;
            if (feature9) {
                hexPatches.BotMove.Modify();
            } else {
                hexPatches.BotMove.Restore();
            }
            break;
            case 9:
            feature10 = boolean;
            if (feature10) {
                hexPatches.Gravity.Modify();
            } else {
                hexPatches.Gravity.Restore();
            }
            break;
            case 10:
            feature11 = boolean;
            if (feature11) {
                hexPatches.Flyme.Modify();
            } else {
                hexPatches.Flyme.Restore();
            }
            break;
            case 11:
            feature12 = boolean;
            if (feature12) {
                hexPatches.Ghostmode.Modify();
            } else {
                hexPatches.Ghostmode.Restore();
            }
            break;
            case 12:
            feature13 = boolean;
            if (feature13) {
                hexPatches.Grenade.Modify();
            } else {
                hexPatches.Grenade.Restore();
            }
            break;
            case 13:
            feature14 = boolean;
            if (feature14) {
                hexPatches.Money.Modify();
            } else {
                hexPatches.Money.Restore();
            }
            break;
            case 14:
            feature15 = boolean;
            if (feature15) {
                hexPatches.Ammo.Modify();
            } else {
                hexPatches.Ammo.Restore();
            }
            break;
            case 15:
            feature16 = boolean;
            if (feature16) {
                hexPatches.Cilp.Modify();
            } else {
                hexPatches.Cilp.Restore();
            }
            break;
            case 16:
            feature17 = boolean;
            if (feature17) {
                hexPatches.Kills.Modify();
            } else {
                hexPatches.Kills.Restore();
            }
            break;
            case 17:
            feature18 = boolean;
            if (feature18) {
                hexPatches.Time.Modify();
            } else {
                hexPatches.Time.Restore();
            }
            break;
            case 18:
            feature19 = boolean;
            if (feature19) {
                hexPatches.BERed.Modify();
            } else {
                hexPatches.BERed.Restore();
            }
            break;
            case 19:
            feature20 = boolean;
            if (feature20) {
                hexPatches.BRed.Modify();
            } else {
                hexPatches.BRed.Restore();
            }
            break;
            case 20:
            feature21 = boolean;
            if (feature21) {
                hexPatches.DarkBule.Modify();
            } else {
                hexPatches.DarkBule.Restore();
            }
            break;
            case 21:
            feature22 = boolean;
            if (feature22) {
                hexPatches.LigthBule.Modify();
            } else {
                hexPatches.LigthBule.Restore();
            }
            break;
            case 22:
            feature23 = boolean;
            if (feature23) {
                hexPatches.Pink.Modify();
            } else {
                hexPatches.Pink.Restore();
            }
            break;
            case 23:
            feature24 = boolean;
            if (feature24) {
                hexPatches.Yellow.Modify();
            } else {
                hexPatches.Yellow.Restore();
            }
            break;
            case 24:
            feature25 = boolean;
            if (feature25) {
                hexPatches.YRed.Modify();
            } else {
                hexPatches.YRed.Restore();
            }
            break;
            case 55:
           LightRadius = value;
            break;
            case 60:
              PlayerSpeed = value;
              case 93:
            Guns = boolean;
            break;
        case 90:
            Skins = boolean;
            break;
        case 91:
            Gloves = boolean;
            break;
        case 92:
            Drone = boolean;
            break;
            case 95:
            Play = boolean;
            break;
      }
   }
}


__attribute__((constructor))
void lib_main() {
    
    pthread_t ptid;
    pthread_create(&ptid, NULL, hack_thread, NULL);
}
