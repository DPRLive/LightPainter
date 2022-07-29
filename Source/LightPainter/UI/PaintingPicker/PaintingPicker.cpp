// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingGrid.h"

#include "../../Saving/PainterSaveGameIndex.h"

#include "PaintingPicker.h"

APaintingPicker::APaintingPicker()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	PaintingGrid = CreateDefaultSubobject<UWidgetComponent>(TEXT("PaintingGrid"));
	PaintingGrid->SetupAttachment(Root);

	ActionBar = CreateDefaultSubobject<UWidgetComponent>(TEXT("ActionBar"));
	ActionBar->SetupAttachment(Root);
}

void APaintingPicker::BeginPlay()
{
	Super::BeginPlay();

	UPaintingGrid* PaintingGridWidget = Cast<UPaintingGrid>(PaintingGrid->GetUserWidgetObject());
	if (!PaintingGridWidget) return;

	int32 Index = 0;
	for (FString SlotName : UPainterSaveGameIndex::Load()->GetSlotNames())
	{
		PaintingGridWidget->AddPainting(Index, SlotName);
		++Index;
	}
}


