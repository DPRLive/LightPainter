// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/WidgetInteractionComponent.h"

#include "HandControllerBase.h"

#include "UIPointerHandController.generated.h"

UCLASS()
class LIGHTPAINTER_API AUIPointerHandController : public AHandControllerBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUIPointerHandController();

	virtual void TriggerPressed() override;
	virtual void TriggerReleased() override;

private:
	UPROPERTY(VisibleAnywhere)
		UWidgetInteractionComponent* Pointer;

};
