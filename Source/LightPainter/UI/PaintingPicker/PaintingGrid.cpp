// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/SizeBox.h"
#include "PaintingGrid.h"

void UPaintingGrid::AddPainting(int32 PaintingIndex, FString PaintingName)
{
	if (!PaintingGrid) return;
	UPaintingGridCard* NewWidget = CreateWidget<UPaintingGridCard>(GetWorld(), GirdCardClass);

	if (!NewWidget) return;
	NewWidget->SetPaintingName(PaintingName);
	USizeBox* CardContainer = Cast<USizeBox>(PaintingGrid->GetChildAt(PaintingIndex));

	if (!CardContainer) return;
	CardContainer->AddChild(NewWidget);
}
