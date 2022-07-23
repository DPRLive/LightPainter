// Fill out your copyright notice in the Description page of Project Settings.


#include "Kismet/GameplayStatics.h"
#include "PainterSaveGame.h"

// TSubclassOf<A클래스>는, 클래스의 안정성을 보장해준다.
// ex) TSubclassOf<SaveGame>은 SaveGame에서 파생된 클래스만 선택가능함.
UPainterSaveGame* UPainterSaveGame::Create()
{
	// StaticClass는 컴파일 타임에 클래스에 대한 정보를 가져옴
	USaveGame* NewSaveGame = UGameplayStatics::CreateSaveGameObject(StaticClass());
	return Cast<UPainterSaveGame>(NewSaveGame);
}

bool UPainterSaveGame::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, TEXT("Test"), 0);
}
