// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "PaintingPicker.h"
#include "ActionBar.generated.h"

/**
 * 
 */
UCLASS()
class LIGHTPAINTER_API UActionBar : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual bool Initialize() override;

	void SetParentPicker(APaintingPicker* NewParentPicker) { ParentPicker = NewParentPicker; }
protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
		UButton* DelButton;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
		UButton* AddButton;

private:
	UFUNCTION()
		void DelButtonClicked();
	
	UFUNCTION()
		void AddButtonClicked();

	UPROPERTY() // 나를 가지고있는 액터의 포인터를 들고있어 그 액터의 메소드 호출 가능
		APaintingPicker* ParentPicker;
};
