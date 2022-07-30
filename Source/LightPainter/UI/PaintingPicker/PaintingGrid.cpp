// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/SizeBox.h"
#include "Components/PanelWidget.h"
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

void UPaintingGrid::ClearPaintings()
{
	for (int32 i = 0; i < PaintingGrid->GetChildrenCount(); i++)
	{
		USizeBox* CardContainer = Cast<USizeBox>(PaintingGrid->GetChildAt(i));
		if (!CardContainer) continue;

		CardContainer->ClearChildren();
	}
}
