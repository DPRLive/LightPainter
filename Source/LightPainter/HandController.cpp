// Fill out your copyright notice in the Description page of Project Settings.


#include "HandController.h"

AHandController::AHandController()
{
	PrimaryActorTick.bCanEverTick = true;

	MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionController"));
	SetRootComponent(MotionController);
	MotionController->SetTrackingSource(EControllerHand::Right); // 오른손에 설정
	MotionController->SetShowDeviceModel(true); // 자동으로 모델 인식
}

void AHandController::TriggerPressed()
{
	CurrentStroke = GetWorld()->SpawnActor<AStroke>(StrokeClass);
	CurrentStroke->SetActorLocation(GetActorLocation());
}

void AHandController::TriggerReleased()
{
	CurrentStroke = nullptr;
}

void AHandController::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHandController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(CurrentStroke != nullptr)
		CurrentStroke->Update(GetActorLocation());
}

