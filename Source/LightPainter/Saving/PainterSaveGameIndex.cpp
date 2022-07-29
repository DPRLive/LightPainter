// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "PainterSaveGameIndex.h"

const FString UPainterSaveGameIndex::SLOT_NAME = "PaintingIndex";

UPainterSaveGameIndex* UPainterSaveGameIndex::Load()
{
	auto Index = Cast<UPainterSaveGameIndex>(UGameplayStatics::LoadGameFromSlot(SLOT_NAME, 0));

	if (!Index)
	{
		Index = Cast<UPainterSaveGameIndex>(UGameplayStatics::CreateSaveGameObject(StaticClass()));
		Index->Save();
	}

	return Index;
}

bool UPainterSaveGameIndex::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, SLOT_NAME, 0);
}

void UPainterSaveGameIndex::AddSaveGame(UPainterSaveGame* SaveGame)
{
	SlotNames.Add(SaveGame->GetSlotName());
}
