// Fill out your copyright notice in the Description page of Project Settings.


#include "HandControllerBase.h"

// Sets default values
AHandControllerBase::AHandControllerBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionController"));
	SetRootComponent(MotionController);
	MotionController->SetTrackingSource(EControllerHand::Right); // 오른손에 설정
	MotionController->SetShowDeviceModel(true); // 자동으로 모델 인식
}
