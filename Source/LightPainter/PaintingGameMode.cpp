// Fill out your copyright notice in the Description page of Project Settings.

#include "Saving/PainterSaveGame.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/StereoLayerFunctionLibrary.h"
#include "PaintingGameMode.h"

void APaintingGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	
	// PaintingGridCard���� openlevel�� �����ߴ� �ɼ� �޾ƿͼ� �Ľ�
	SlotName = UGameplayStatics::ParseOption(Options, "SlotName");
	UE_LOG(LogTemp, Warning, TEXT("SlotName = %s"), *SlotName);
}

void APaintingGameMode::BeginPlay()
{
	Super::BeginPlay();

	Load();
	//UStereoLayerFunctionLibrary::HideSplashScreen();

}

void APaintingGameMode::Save()
{
	UPainterSaveGame* Painting = UPainterSaveGame::Load(SlotName);

	if (Painting)
	{
		Painting->SerializeFromWorld(GetWorld());
		Painting->Save();
	}
}

void APaintingGameMode::Load()
{
	UPainterSaveGame* Painting = UPainterSaveGame::Load(SlotName);
	if (Painting)
	{
		Painting->DeserializeToWorld(GetWorld());
		UE_LOG(LogTemp, Warning, TEXT("Painting state %s"), *Painting->GetState());

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Game slot not fount : %s"), *SlotName);
	}
}