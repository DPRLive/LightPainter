// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/UniformGridPanel.h"
#include "PaintingGridCard.h"
#include "PaintingGrid.generated.h"

/**
 * 
 */
UCLASS()
class LIGHTPAINTER_API UPaintingGrid : public UUserWidget
{
	GENERATED_BODY()
		
public:
	UFUNCTION(BlueprintCallable)
		void AddPainting(int32 PaintingIndex, FString PaintingName);
	
	void ClearPaintings();
protected:
	// 블루프린트 위젯 바인딩
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
		UUniformGridPanel* PaintingGrid;

private:
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UPaintingGridCard> GirdCardClass;
};
