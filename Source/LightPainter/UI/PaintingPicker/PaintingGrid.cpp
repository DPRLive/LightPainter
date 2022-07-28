// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/SizeBox.h"

#include "PaintingGrid.h"

void UPaintingGrid::AddPainting()
{
	if (!PaintingGrid) return;
	UUserWidget* NewWidget = CreateWidget<UUserWidget>(GetWorld(), GirdCardClass);

	if (!NewWidget) return;
	USizeBox* CardContainer = Cast<USizeBox>(PaintingGrid->GetChildAt(0));

	if (!CardContainer) return;
	CardContainer->AddChild(NewWidget);
}
