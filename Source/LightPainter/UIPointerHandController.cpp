// Fill out your copyright notice in the Description page of Project Settings.


#include "UIPointerHandController.h"
#include "InputCoreTypes.h"

// Sets default values
AUIPointerHandController::AUIPointerHandController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Pointer = CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("Pointer"));
	Pointer->SetupAttachment(GetRootComponent());
}

void AUIPointerHandController::TriggerPressed()
{
	// �� Ű�� ���콺 ����Ŭ�� �ѰŸ��� ����
	Pointer->PressPointerKey(EKeys::LeftMouseButton);
}

void AUIPointerHandController::TriggerReleased()
{
	Pointer->ReleasePointerKey(EKeys::LeftMouseButton);
}

