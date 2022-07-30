// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionBar.h"

bool UActionBar::Initialize()
{
	if (!Super::Initialize()) return false;

	if (!DelButton) return false;
	DelButton->OnClicked.AddDynamic(this, &UActionBar::DelButtonClicked);

	if (!AddButton) return false;
	AddButton->OnClicked.AddDynamic(this, &UActionBar::AddButtonClicked);

	return true;
}

void UActionBar::DelButtonClicked()
{
	if (ParentPicker) ParentPicker->ToggleDeleteMode();
}

void UActionBar::AddButtonClicked()
{
	if (ParentPicker) ParentPicker->AddPainting();
}
