// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "VRPawn.h"

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

	if (HandControllerClass)
	{
		RightHandController = GetWorld()->SpawnActor<AHandController>(HandControllerClass);
		RightHandController->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
		RightHandController->SetOwner(this);
	}

	UPainterSaveGame* Painting =  UPainterSaveGame::Create();
	Painting->Save();
}

void AVRPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("RightTrigger"), EInputEvent::IE_Pressed, this, &AVRPawn::RightTriggerPressed);
	PlayerInputComponent->BindAction(TEXT("RightTrigger"), EInputEvent::IE_Released, this, &AVRPawn::RightTriggerReleased);
}
