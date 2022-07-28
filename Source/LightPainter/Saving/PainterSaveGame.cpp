// Fill out your copyright notice in the Description page of Project Settings.


#include "PainterSaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"

#include "../Stroke.h"

// TSubclassOf<A클래스>는, 클래스의 안정성을 보장해준다.
// ex) TSubclassOf<SaveGame>은 SaveGame에서 파생된 클래스만 선택가능함.
UPainterSaveGame* UPainterSaveGame::Create()
{
	// StaticClass는 컴파일 타임에 클래스에 대한 정보를 가져옴
	UPainterSaveGame* NewSaveGame = Cast<UPainterSaveGame>(UGameplayStatics::CreateSaveGameObject(StaticClass()));
	NewSaveGame->SlotName = FGuid::NewGuid().ToString();
	return NewSaveGame;
}

bool UPainterSaveGame::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, SlotName, 0);
}

UPainterSaveGame* UPainterSaveGame::Load(FString SlotName)
{
	return Cast<UPainterSaveGame>(UGameplayStatics::LoadGameFromSlot(SlotName, 0));
}

void UPainterSaveGame::SerializeFromWorld(UWorld* World)
{
	Strokes.Empty();
	for (TActorIterator<AStroke> StrokeItr(World); StrokeItr; ++StrokeItr)
	{
		Strokes.Add(StrokeItr->SerializeToStruct());
	}
}

void UPainterSaveGame::DeserializeToWorld(UWorld* World)
{
	ClearWorld(World);
	for (FStrokeState StorkeState : Strokes)
	{
		AStroke::SpawnAndDeserializeFromStruct(World, StorkeState);
	}
}

void UPainterSaveGame::ClearWorld(UWorld* World)
{
	for (TActorIterator<AStroke> StrokeItr(World); StrokeItr; ++StrokeItr)
	{
		StrokeItr->Destroy();
	}
}
