#include "/home/codeleaded/System/Static/Library/ConsoleEngine.h"
#include "/home/codeleaded/System/Static/Library/Rect.h"


CSprite dino;
CSprite spike;

Vec2 dino_p;
Vec2 dino_v;
Vector spikes; // Vector<Vec2>

void Reset(){
	Vector_Clear(&spikes);

	dino_p.x = 2.0f;
	dino_p.y = 10.0f;
	dino_v.x = 0.0f;
	dino_v.y = 0.0f;
}

void Setup(Console* c){
	dino = CSprite_By(16,8,(wchar_t*)
		L"           ___  "
		L"         ███ ███"
		L"        ██████__"
		L"      █████_    "
		L"     █████  █   "
		L"  __████        "
		L" █   ██         "
		L"     ████       "
	);
	spike = CSprite_By(16,8,(wchar_t*)
		L"       ██       "
		L"      ████      "
		L"      ████  ██  "
		L"  ██  ████████  "
		L"  ████████      "
		L"      ████      "
		L"      ████      "
		L"      ████      "
	);

	dino_p = (Vec2){ 0.0f,0.0f };
	dino_v = (Vec2){ 0.0f,0.0f };
	spikes = Vector_New(sizeof(Vec2));

	Reset();
}
void Update(Console* c){
	if(Console_Stroke(c,ALX_KEY_W).PRESSED)
		dino_v.y = -10.0f;
	if(Console_Stroke(c,ALX_KEY_S).PRESSED)
		dino_v.y = 10.0f;

	if(Console_Stroke(c,ALX_KEY_A).PRESSED)
		dino_v.x = -10.0f;
	if(Console_Stroke(c,ALX_KEY_D).PRESSED)
		dino_v.x = 10.0f;

	if(Console_Stroke(c,ALX_KEY_R).PRESSED)
		Reset();

	if(Console_Stroke(c,ALX_KEY_Q).PRESSED)
		c->Running = 0;
	

	dino_v.x += 0.1f * c->ElapsedTime;
	dino_p.x += dino_v.x * c->ElapsedTime;

	dino_v.y += 1.0f * c->ElapsedTime;
	dino_p.y += dino_v.y * c->ElapsedTime;
	
	if(dino_p.y < 30.0f){
		dino_p.y = 30.0f;
		dino_v.y = 0.0f;
	}
	if(dino_v.x > 10.0f){
		dino_v.x = 10.0f;
	}

	for(int i = 0;i<spikes.size;i++){
		Vec2 p = *(Vec2*)Vector_Get(&spikes,i);
		
		if(Rect_Overlap(Rect_New(dino_p,(Vec2){ dino.w,dino.h }),Rect_New(p,(Vec2){ spike.w,spike.h }))){
			Reset();
		}
	}

    Console_Clear(c,CPIXEL_SOLID,FG_BLACK);
	Console_RenderRect(c,0.0f,20.0f,c->ScreenWidth,c->ScreenHeight,CPIXEL_SOLID,FG_WHITE);

	for(int i = 0;i<spikes.size;i++){
		Vec2 p = *(Vec2*)Vector_Get(&spikes,i);
		Console_RenderCSpriteFast(c,&spike,p.x - dino_p.x,p.y);
	}
	
	Console_RenderCSpriteFast(c,&spike,2.0f,dino_p.y);
}
void Delete(Console* c){
    CSprite_Free(&dino);
    CSprite_Free(&spike);
    Vector_Free(&spikes);
}

int main(){
    Console c;
    
	if(Console_Create(&c,L"Game Dino",130,40,8,8,Setup,Update,Delete)){
		Console_Start(&c);
	}
	
    return 0;
}