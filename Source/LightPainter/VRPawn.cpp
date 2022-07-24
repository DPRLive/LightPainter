// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPawn.h"
#include "Engine/World.h"

#include "Saving/PainterSaveGame.h"

AVRPawn::AVRPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	VRRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VRRoot"));
	SetRootComponent(VRRoot);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(VRRoot);
}

void AVRPawn::BeginPlay()
{
	Super::BeginPlay();

	if (PaintBrushHandControllerClass)
	{
		RightPaintBrushHandController = GetWorld()->SpawnActor<AHandControllerBase>(PaintBrushHandControllerClass);
		RightPaintBrushHandController->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
		RightPaintBrushHandController->SetOwner(this);
	}
}

void AVRPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("RightTrigger"), EInputEvent::IE_Pressed, this, &AVRPawn::RightTriggerPressed);
	PlayerInputComponent->BindAction(TEXT("RightTrigger"), EInputEvent::IE_Released, this, &AVRPawn::RightTriggerPressed);

	PlayerInputComponent->BindAction(TEXT("Save"), EInputEvent::IE_Pressed, this, &AVRPawn::Save);
	PlayerInputComponent->BindAction(TEXT("Load"), EInputEvent::IE_Pressed, this, &AVRPawn::Load);
}

void AVRPawn::Save()
{
	UPainterSaveGame* Painting = UPainterSaveGame::Create();
	Painting->SetState("Hello World!");
	Painting->SerializeFromWorld(GetWorld());
	Painting->Save();
}

void AVRPawn::Load()
{
	UPainterSaveGame* Painting = UPainterSaveGame::Load();
	if (Painting)
	{
		Painting->DeserializeToWorld(GetWorld());
		UE_LOG(LogTemp, Warning, TEXT("Painting state %s"), *Painting->GetState());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Not found"));
	}
}