// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "Kismet/StereoLayerFUnctionLibrary.h"
#include "PaintingGridCard.h"

void UPaintingGridCard::SetPaintingName(FString NewPaintingName)
{
	PaintingName = NewPaintingName;
	SlotName->SetText(FText::FromString(PaintingName));

	CardButton->OnClicked.AddDynamic(this, &UPaintingGridCard::CardButtonClicked);
}

void UPaintingGridCard::CardButtonClicked()
{
	//UStereoLayerFunctionLibrary::ShowSplashScreen();
	// ������ �μ��� �ɼ� ����
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("/Game/Maps/Canvas"), true, "SlotName="+PaintingName);
}
