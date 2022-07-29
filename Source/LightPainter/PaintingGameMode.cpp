// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "PaintingGameMode.h"

void APaintingGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	
	// PaintingGridCard에서 openlevel시 전달했던 옵션 받아와서 파싱
	SlotName = UGameplayStatics::ParseOption(Options, "SlotName");
	UE_LOG(LogTemp, Warning, TEXT("SlotName = %s"), *SlotName);
}
